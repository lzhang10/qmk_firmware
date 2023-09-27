# Have to disable combo after rebasing to c49438feec (Tue Feb 8 21:51:51 2022 -0800) to save space
# to enable combo rebase to eee553337a (Mon Sep 13 18:01:23 2021), which lacks autoshift finetune and retro shift
CONSOLE_ENABLE = yes  # This allows you to print messages that can be read using hid_listen.
COMBO_ENABLE = no
MOUSEKEY_ENABLE = no  # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
LTO_ENABLE = yes

# Easy definition of combos
VPATH +=  keyboards/gboards/

# space saving options
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += casemodes.c layermodes.c my_keycode.c #repeat.c

# https://github.com/qmk/qmk_firmware/tree/master/users/spacebarracecar
#SRC += spacebarracecar.c
