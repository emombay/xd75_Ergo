# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

COMMAND_ENABLE   = no  # Commands for debug and configuration
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif