# MCU name
MCU = RP2040
BOOTLOADER = rp2040

ALLOW_WARNINGS = yes
#PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS!
VIA_ENABLE = no
SHARED_EP_ENABLE = no
CONSOLE_ENABLE = yes
LTO_ENABLE = no
OPT_DEFS = -O2

#SRC += karlk90.qgf.c
#SRC += animation.qgf.c
#SRC += instaclip_16colors.qgf.c
#SRC += geist.qgf.c
#SRC += iosevka11.qff.c
#SRC += gangbang.qgf.c
#SRC += monitormund.qgf.c
#SRC += geist_raw.c
#SRC += matrix_80.c
#SRC += mund_small.c
#SRC += mund_small_still.c
#SRC += mund_small_alpha.c

BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality


QUANTUM_PAINTER_ENABLE             = yes
QUANTUM_PAINTER_DRIVERS            += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF = yes

DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

LAYOUTS = ortho_1x1


# AUDIO 
AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware