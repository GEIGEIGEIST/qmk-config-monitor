/* Copyright 2021 Stefan Kerkmann
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

#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
#include "woman.qgf.h"
#include "iosevka11.qff.h"
#include "qp.h"

static painter_device_t display;
static painter_image_handle_t image;
static painter_font_handle_t font;
static painter_image_handle_t animation;
static deferred_token animation_token;
#endif

void keyboard_post_init_user(void) {
  debug_enable = true;
  debug_keyboard=true;

#ifdef QUANTUM_PAINTER_ENABLE
  display = qp_ssd1351_make_spi_device(128, 128, OLED_CS_PIN, OLED_DC_PIN,
                                      OLED_RST_PIN, 1, 3);

  qp_init(display, QP_ROTATION_0); // Initialise the display
  qp_power(display, true);
  qp_rect(display, 0, 0, 127, 127, 0, 0, 0, true);

    image = qp_load_image_mem(gfx_woman);
    if (image != NULL) {
        qp_drawimage(display, 0, 0, image);
        qp_flush(display);
    }
  font = qp_load_font_mem(font_iosevka11);
  if (font != NULL) {
    qp_drawtext(display, 40, 160, font, "OLEDs are not fun");
  }

#endif
}

void housekeeping_task_user(void) {

}

void board_init(void) {}


