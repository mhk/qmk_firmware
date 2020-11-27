# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# reduce size
EXTRAFLAGS += -flto

# Build Options
#   comment out to disable the options.
#
#BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration
MOUSEKEY_ENABLE  = yes  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
LEADER_ENABLE  = yes    # Leader key
#CONSOLE_ENABLE   = yes  # Console for debug
#COMMAND_ENABLE   = yes  # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
#NKRO_ENABLE      = yes  # USB Nkey Rollover - not yet supported in LUFA
#BACKLIGHT_ENABLE = yes
USB_HID_ENABLE   = yes
CUSTOM_MATRIX    = yes
TAP_DANCE_ENABLE = yes

SRC = custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu
