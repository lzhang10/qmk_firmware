EXTRAKEY_ENABLE  = yes     # Audio control and System control
#COMBO_ENABLE = yes
MOUSEKEY_ENABLE  = no  # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
COMBO_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes # use 700 bytes

# Easy definition of combos
VPATH +=  keyboards/gboards/

# space saving options
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
CAPS_WORD_ENABLE = yes

SRC += common/my_keycode.c common/layermodes.c
