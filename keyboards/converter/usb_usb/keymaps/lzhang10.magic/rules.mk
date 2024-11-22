EXTRAKEY_ENABLE  = no     # Audio control and System control
#COMBO_ENABLE = yes
MOUSEKEY_ENABLE  = no  # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
COMBO_ENABLE = yes
LTO_ENABLE = yes

# Easy definition of combos
VPATH +=  keyboards/gboards/

# space saving options
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += casemodes.c

# make ... USR_STR_A=abc\\\\tdef USR_STR_B=abc\\\\n
# here \\\\t outputs \t
OPT_DEFS += -DUSR_STR_A=\"${USR_STR_A}\" -DUSR_STR_B=\"${USR_STR_B}\"
