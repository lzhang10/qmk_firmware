#!/usr/bin/env python3
"""
QMK Keymap Reference Generator
Automatically generates an HTML quick reference sheet from keymap.c, combos.def, and related files.
Usage: python3 generate_reference.py
"""

import re
import os
from pathlib import Path
from datetime import datetime

class KeymapParser:
    def __init__(self, keymap_dir):
        self.keymap_dir = Path(keymap_dir)
        self.layers = {}
        self.combos = []
        self.custom_keycodes = {}
        self.modtap_keys = {}
        
    def parse_keymap(self):
        """Parse keymap.c to extract layer definitions"""
        keymap_file = self.keymap_dir / "keymap.c"
        with open(keymap_file, 'r') as f:
            content = f.read()
        
        # Extract layer definitions
        layer_pattern = r'\[(\w+)\]\s*=\s*LAYOUT_\w+\((.*?)\)'
        matches = re.finditer(layer_pattern, content, re.DOTALL)
        
        for match in matches:
            layer_name = match.group(1)
            layer_content = match.group(2)
            # Split by comma and clean up
            keys = [k.strip() for k in layer_content.split(',') if k.strip()]
            self.layers[layer_name] = keys
            
    def parse_combos(self):
        """Parse combos.def to extract combo definitions"""
        combos_file = self.keymap_dir / "combos.def"
        if not combos_file.exists():
            return
            
        with open(combos_file, 'r') as f:
            content = f.read()
        
        # Parse COMB(name, output, key1, key2, ...) // comment
        combo_pattern = r'COMB\((\w+),\s*(\w+),\s*([^)]+)\)\s*(?://\s*(.+))?'
        matches = re.finditer(combo_pattern, content)
        
        for match in matches:
            name = match.group(1)
            output = match.group(2)
            keys = [k.strip() for k in match.group(3).split(',')]
            comment = match.group(4).strip() if match.group(4) else ""
            
            self.combos.append({
                'name': name,
                'output': output,
                'keys': keys,
                'description': comment
            })
    
    def parse_custom_keycodes(self):
        """Parse my_keycode.h to extract custom keycode definitions"""
        keycode_file = self.keymap_dir / "common" / "my_keycode.h"
        if not keycode_file.exists():
            return
            
        with open(keycode_file, 'r') as f:
            content = f.read()
        
        # Parse #define statements
        define_pattern = r'#define\s+(\w+)\s+([^\n]+?)(?://\s*(.+))?$'
        matches = re.finditer(define_pattern, content, re.MULTILINE)
        
        for match in matches:
            name = match.group(1)
            value = match.group(2).strip()
            comment = match.group(3).strip() if match.group(3) else ""
            
            # Skip common defines
            if name not in ['XXX', 'TRNS']:
                self.custom_keycodes[name] = {
                    'value': value,
                    'comment': comment
                }
        
        # Parse modtap keys
        modtap_pattern = r'#define\s+(CMD_\w+|SFT_\w+|ALT_\w+|CTL_\w+)\s+[LR](?:GUI|SFT|ALT|CTL)_T\(KC_(\w+)\)'
        matches = re.finditer(modtap_pattern, content)
        
        for match in matches:
            name = match.group(1)
            key = match.group(2)
            mod_type = 'CMD' if 'CMD' in name else 'SFT' if 'SFT' in name else 'ALT' if 'ALT' in name else 'CTL'
            self.modtap_keys[name] = {
                'key': key,
                'modifier': mod_type
            }

class HTMLGenerator:
    def __init__(self, parser):
        self.parser = parser
        
    def get_key_class(self, key):
        """Determine CSS class for a key"""
        if key in ['TRNS', 'XXX', 'KC_NO', '—']:
            return 'key'
        elif 'LT(' in key or key.startswith('SPACE_'):
            return 'key special'
        elif any(mod in key for mod in ['CMD_', 'SFT_', 'ALT_', 'CTL_', 'O_']):
            return 'key modifier'
        elif key.startswith('KC_F') or key.startswith('U_') or key.startswith('M_'):
            return 'key function'
        elif 'KC_LEFT' in key or 'KC_RIGHT' in key or 'KC_UP' in key or 'KC_DOWN' in key or 'KC_PGUP' in key or 'KC_PGDN' in key or 'WIN_' in key or 'WHL' in key:
            return 'key nav'
        elif any(x in key for x in ['CPY', 'CUT', 'PASTE', 'WIN_', 'DSP_']):
            return 'key special'
        return 'key'
    
    def get_key_width(self, key, position):
        """Determine key width based on position and key type"""
        # You can customize this based on your keyboard layout
        if 'SPACE' in key or 'KC_SPC' in key:
            return 'key space'
        elif position in [0, 13, 14] or 'BSPC' in key or 'ENTER' in key:
            return 'wide'
        return ''
    
    def format_key_label(self, key):
        """Format key for display"""
        # Remove common prefixes
        key = key.replace('KC_', '').replace('TRNS', '—').replace('XXX', '—')
        
        # Handle special cases
        if 'LT(' in key:
            match = re.search(r'LT\((\w+),\s*KC_(\w+)\)', key)
            if match:
                return f"{match.group(2)} / {match.group(1)}"
        
        if key.startswith('LGUI_T') or key.startswith('RGUI_T'):
            return re.sub(r'[LR]GUI_T\(KC_(\w+)\)', r'\1 (⌘)', key)
        if key.startswith('LSFT_T') or key.startswith('RSFT_T'):
            return re.sub(r'[LR]SFT_T\(KC_(\w+)\)', r'\1 (⇧)', key)
        if key.startswith('LALT_T') or key.startswith('RALT_T'):
            return re.sub(r'[LR]ALT_T\(KC_(\w+)\)', r'\1 (⌥)', key)
        if key.startswith('LCTL_T') or key.startswith('RCTL_T'):
            return re.sub(r'[LR]CTL_T\(KC_(\w+)\)', r'\1 (⌃)', key)
        
        # Handle TD (tap dance)
        if 'TD(' in key:
            match = re.search(r'TD\((\w+)\)', key)
            if match:
                return match.group(1).replace('TD_', '')
        
        return key
    
    def generate_keyboard_row(self, keys, start_idx, count):
        """Generate HTML for a keyboard row"""
        html = '<div class="row">\n'
        for i in range(count):
            if start_idx + i < len(keys):
                key = keys[start_idx + i]
                key_class = self.get_key_class(key)
                width_class = self.get_key_width(key, i)
                if width_class:
                    key_class += f' {width_class}'
                
                label = self.format_key_label(key)
                
                # Split label for main and sub text
                if ' / ' in label:
                    parts = label.split(' / ')
                    html += f'    <div class="{key_class}"><div class="key-label">{parts[0]}</div><div class="key-sub">{parts[1]}</div></div>\n'
                elif '(' in label and ')' in label:
                    main = label[:label.index('(')].strip()
                    sub = label[label.index('('):].strip('()')
                    html += f'    <div class="{key_class}"><div class="key-label">{main}</div><div class="key-sub">{sub}</div></div>\n'
                else:
                    html += f'    <div class="{key_class}"><div class="key-label">{label}</div></div>\n'
        html += '</div>\n'
        return html
    
    def generate_layer_html(self, layer_name, keys):
        """Generate HTML for a complete layer"""
        html = f'<div class="layer">\n'
        html += f'<h2>Layer: {layer_name}</h2>\n'
        html += '<div class="keyboard">\n'
        
        # Apple Magic Keyboard layout: 14, 14, 14, 13, 13, 9 keys
        row_config = [
            (0, 14),   # Function row
            (14, 14),  # Number row
            (28, 14),  # QWERTY row
            (42, 13),  # Home row
            (55, 13),  # Bottom letter row
            (68, 9),   # Bottom modifier row
        ]
        
        for start, count in row_config:
            html += self.generate_keyboard_row(keys, start, count)
        
        html += '</div>\n</div>\n'
        return html
    
    def generate_combos_table(self):
        """Generate HTML table for combos"""
        if not self.parser.combos:
            return ''
        
        html = '''
        <div class="combos-section">
            <h2>⚡ Combos (Press Multiple Keys Together)</h2>
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Keys</th>
                        <th>Output</th>
                        <th>Description</th>
                    </tr>
                </thead>
                <tbody>
'''
        
        for combo in self.parser.combos:
            keys_str = ' + '.join([k.replace('KC_', '').replace('CMD_', '').replace('SFT_', '').replace('ALT_', '').replace('CTL_', '') for k in combo['keys']])
            output = combo['output'].replace('KC_', '')
            html += f'''                    <tr>
                        <td><strong>{combo['name']}</strong></td>
                        <td><span class="combo-keys">{keys_str}</span></td>
                        <td><strong>{output}</strong></td>
                        <td>{combo['description']}</td>
                    </tr>
'''
        
        html += '''                </tbody>
            </table>
        </div>
'''
        return html
    
    def generate_modtap_table(self):
        """Generate HTML table for home row mods"""
        modtap_info = [
            ('A', 'a', 'Command/GUI', '⌘'),
            ('S', 's', 'Shift', '⇧'),
            ('D', 'd', 'Alt/Option', '⌥'),
            ('F', 'f', 'Control', '⌃'),
            ('J', 'j', 'Control', '⌃'),
            ('K', 'k', 'Alt/Option', '⌥'),
            ('L', 'l', 'Shift', '⇧'),
            (';', ';', 'Command/GUI', '⌘'),
        ]
        
        html = '''
        <div class="modtap-section">
            <h2>🖐️ Home Row Mods (ModTap Keys)</h2>
            <table>
                <thead>
                    <tr>
                        <th>Key</th>
                        <th>Tap</th>
                        <th>Hold</th>
                        <th>Symbol</th>
                    </tr>
                </thead>
                <tbody>
'''
        
        for key, tap, hold, symbol in modtap_info:
            html += f'''                    <tr>
                        <td><strong>{key}</strong></td>
                        <td>Types '{tap}'</td>
                        <td>{hold}</td>
                        <td>{symbol}</td>
                    </tr>
'''
        
        html += '''                </tbody>
            </table>
        </div>
'''
        return html
    
    def generate_html(self, output_file):
        """Generate complete HTML reference sheet"""
        css = '''* {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Courier New', monospace;
            padding: 20px;
            background: #f5f5f5;
            font-size: 11px;
        }
        
        @media print {
            body {
                background: white;
                font-size: 9px;
            }
            .no-print {
                display: none;
            }
            .page-break {
                page-break-after: always;
            }
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            background: white;
            padding: 20px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }
        
        h1 {
            text-align: center;
            color: #333;
            margin-bottom: 20px;
            font-size: 24px;
        }
        
        h2 {
            color: #444;
            margin: 20px 0 10px 0;
            font-size: 18px;
            border-bottom: 2px solid #333;
            padding-bottom: 5px;
        }
        
        .layer {
            margin-bottom: 30px;
        }
        
        .keyboard {
            display: inline-block;
            background: #eee;
            padding: 15px;
            border-radius: 8px;
            margin: 10px 0;
        }
        
        .row {
            display: flex;
            gap: 3px;
            margin-bottom: 3px;
            justify-content: flex-start;
        }
        
        .key {
            background: linear-gradient(to bottom, #fff, #e0e0e0);
            border: 1px solid #999;
            border-radius: 3px;
            padding: 4px 6px;
            min-width: 35px;
            height: 32px;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            font-size: 9px;
            line-height: 1.2;
            text-align: center;
            box-shadow: 0 2px 3px rgba(0,0,0,0.2);
        }
        
        .key.wide { min-width: 55px; }
        .key.wider { min-width: 70px; }
        .key.widest { min-width: 90px; }
        .key.space { min-width: 250px; }
        
        .key.special {
            background: linear-gradient(to bottom, #ffd700, #ffb700);
            font-weight: bold;
        }
        
        .key.modifier {
            background: linear-gradient(to bottom, #87CEEB, #5F9EA0);
            font-weight: bold;
        }
        
        .key.function {
            background: linear-gradient(to bottom, #90EE90, #50C850);
        }
        
        .key.nav {
            background: linear-gradient(to bottom, #FFB6C1, #FF69B4);
        }
        
        .key-label {
            font-size: 8px;
            font-weight: bold;
        }
        
        .key-sub {
            font-size: 7px;
            color: #666;
            margin-top: 2px;
        }
        
        .combos-section, .modtap-section {
            margin: 20px 0;
        }
        
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 10px 0;
        }
        
        th, td {
            border: 1px solid #ddd;
            padding: 6px;
            text-align: left;
        }
        
        th {
            background: #333;
            color: white;
            font-weight: bold;
        }
        
        tr:nth-child(even) {
            background: #f9f9f9;
        }
        
        .combo-keys {
            font-family: monospace;
            background: #e8f4f8;
            padding: 2px 6px;
            border-radius: 3px;
        }
        
        .notes {
            background: #fffacd;
            border-left: 4px solid #ffd700;
            padding: 10px;
            margin: 15px 0;
        }'''
        
        html = f'''<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>QMK Keymap Reference - Auto-Generated</title>
    <style>
{css}
    </style>
</head>
<body>
    <div class="container">
        <h1>🎹 QMK Keymap Quick Reference</h1>
        
        <div class="notes no-print">
            <strong>Auto-generated on {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}</strong><br>
            This reference was automatically generated from keymap.c and combos.def
        </div>
'''
        
        # Generate layers
        for layer_name, keys in self.parser.layers.items():
            html += self.generate_layer_html(layer_name, keys)
            if layer_name == 'BASE':
                html += '<div class="page-break"></div>\n'
        
        # Generate combos table
        html += self.generate_combos_table()
        
        # Generate modtap table
        html += self.generate_modtap_table()
        
        html += '''
        <div class="notes" style="margin-top: 30px;">
            <strong>💡 Tips:</strong>
            <ul style="margin-left: 20px; margin-top: 5px;">
                <li><strong>OneShot Modifiers:</strong> Tap Shift keys once, they stay active for next keypress only</li>
                <li><strong>Tapping Term:</strong> Quickly tap ModTap keys to type letters; hold longer for modifiers</li>
                <li><strong>Layer Access:</strong> Hold layer keys to temporarily access different layers</li>
            </ul>
        </div>

        <div style="margin-top: 30px; text-align: center; color: #999; font-size: 10px;">
            Auto-generated from QMK keymap files • Generated: ''' + datetime.now().strftime('%Y-%m-%d %H:%M:%S') + '''
        </div>
    </div>
</body>
</html>'''
        
        with open(output_file, 'w') as f:
            f.write(html)
        
        print(f"✅ Generated reference sheet: {output_file}")

def main():
    # Get the directory of this script
    script_dir = Path(__file__).parent
    
    # Parse keymap files
    parser = KeymapParser(script_dir)
    
    print("📖 Parsing keymap files...")
    parser.parse_keymap()
    parser.parse_combos()
    parser.parse_custom_keycodes()
    
    print(f"   Found {len(parser.layers)} layers")
    print(f"   Found {len(parser.combos)} combos")
    print(f"   Found {len(parser.custom_keycodes)} custom keycodes")
    
    # Generate HTML
    print("🎨 Generating HTML reference sheet...")
    generator = HTMLGenerator(parser)
    output_file = script_dir / "keymap-reference-auto.html"
    generator.generate_html(output_file)
    
    print(f"\n✨ Done! Open {output_file.name} in your browser to view.")

if __name__ == "__main__":
    main()
