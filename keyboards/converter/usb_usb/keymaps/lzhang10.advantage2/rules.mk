

# due to memory constraint can only enable one of
# CONSOLE_ENABLE or COMBO_ENABLE
CONSOLE_ENABLE = no  # use 756 bytes, this allows you to print messages that can be read using hid_listen.
COMBO_ENABLE = yes   # uses 1800 bytes

MOUSEKEY_ENABLE = no  # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
LTO_ENABLE = yes

TAP_DANCE_ENABLE = yes # use 700 bytes

# Easy definition of combos
VPATH +=  keyboards/gboards/

# space saving options
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += casemodes.c layermodes.c my_keycode.c #repeat.c

# https://github.com/qmk/qmk_firmware/tree/master/users/spacebarracecar
#SRC += spacebarracecar.c
