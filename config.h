/*
Copyright 2023 GEIST <@geigeigeist>
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

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 500


// #define PRODUCT "Onekey Raspberry Pi Pico RP2040"
#define MATRIX_COL_PINS \
    { GP4 }
#define MATRIX_ROW_PINS \
    { GP5 }
// #define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RGB_DI_PIN A1

/*
#define AUDIO_PIN GP9
#define AUDIO_VOICES
#ifdef AUDIO_ENABLE  
#define AUDIO_DAC_SAMPLE_MAX 4095U   
#define MONITOR_SOUND B__NOTE(_REST), B__NOTE(_REST), H__NOTE(_C2), W__NOTE(_F3), H__NOTE(_REST),  Q__NOTE(_E2), W__NOTE(_B3), H__NOTE(_REST), S__NOTE(_D0), E__NOTE(_REST), W__NOTE(_F3), Q__NOTE(_D2)
#define STARTUP_SONG SONG(MONITOR_SOUND)
#endif 
*/
    
#define SPI_DRIVER SPID0
#define SPI_MISO_PIN GP20
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23

#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE FALSE
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
// #define QUANTUM_PAINTER_DEBUG
