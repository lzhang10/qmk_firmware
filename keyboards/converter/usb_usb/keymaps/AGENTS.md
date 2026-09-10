Run this qmk command at repo root to compile or flash the keyboard firmware:


```sh
# build
qmk compile -kb converter/usb_usb/leonardo -km <keymap>
# flash
qmk flash -kb converter/usb_usb/leonardo -km <keymap>
```

Do not run flash command in sandbox: the command needs to access the USB device on the host.

You should run compile command to ensure code compiles clean.