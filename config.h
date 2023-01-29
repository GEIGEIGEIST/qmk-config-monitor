/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

// #define PRODUCT "Onekey Raspberry Pi Pico RP2040"
#define MATRIX_COL_PINS \
    { GP2 }
#define MATRIX_ROW_PINS \
    { GP3 }
// #define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

//#define RGB_DI_PIN A1

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23

/*
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE //FALSE by default
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
// #define QUANTUM_PAINTER_DEBUG
*/

#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
//#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_NUM_IMAGES 14
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE (48U * 1024U) //1024
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF


#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PWM_DRIVER PWMD6
#define BACKLIGHT_PWM_CHANNEL 2
#define BACKLIGHT_PIN GP29
#define BACKLIGHT_LEVELS 4
//#define BACKLIGHT_ON_STATE 0
#endif //BACKLIGHT_ENABLE


#define AUDIO_PIN GP9
#define AUDIO_VOICES
#define AUDIO_DAC_SAMPLE_MAX 4095U
#define AUDIO_PWM_DRIVER PWMD4
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_STATE_TIMER GPTD4

#ifdef AUDIO_ENABLE     
#    define MONITOR_SOUND B__NOTE(_REST), B__NOTE(_REST), H__NOTE(_C2), W__NOTE(_F3), H__NOTE(_REST),  Q__NOTE(_E2), W__NOTE(_B3), H__NOTE(_REST), S__NOTE(_D0), E__NOTE(_REST), W__NOTE(_F3), Q__NOTE(_D2)
#    define STARTUP_SONG SONG(MONITOR_SOUND)
#endif 