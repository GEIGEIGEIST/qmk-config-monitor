# MCU name
MCU = RP2040
BOOTLOADER = rp2040

ALLOW_WARNINGS = yes
#PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS!
VIA_ENABLE = no
SHARED_EP_ENABLE = no
CONSOLE_ENABLE = yes
LTO_ENABLE = no
#OPT_DEFS = -O2 

SRC += karlk90.qgf.c
SRC += animation.qgf.c
SRC += instaclip_16colors.qgf.c
SRC += iosevka11.qff.c

QUANTUM_PAINTER_ENABLE             = yes
QUANTUM_PAINTER_DRIVERS            += ili9341_spi st7789_spi rgb565_surface
DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

LAYOUTS = ortho_1x1
