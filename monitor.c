/* Copyright 2022
 * GEIST @geigeigeist
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
#include "animation.qgf.h"
#include "instaclip_16colors.qgf.h"
#include "iosevka11.qff.h"
#include "karlk90.qgf.h"
#include "qp.h"

#define LCD_CS_PIN GP21
#define LCD_DC_PIN GP27
#define LCD_RST_PIN GP26

static painter_device_t display;
static painter_image_handle_t image;
static painter_font_handle_t font;
static painter_image_handle_t animation;
static deferred_token animation_token;
#endif

void keyboard_post_init_user(void) {
  debug_enable = true;
#ifdef QUANTUM_PAINTER_ENABLE
  display = qp_st7789_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN,
                                      LCD_RST_PIN, 1, 3);
  // display = qp_ili9341_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN,
  // LCD_RST_PIN, 2, 0);
  qp_init(display, QP_ROTATION_0); // Initialise the display
  qp_power(display, true);
  qp_rect(display, 0, 0, 239, 319, 0, 0, 0, true);
#if 1

#if 1
  animation = qp_load_image_mem(gfx_instaclip_16colors);
#else
  animation = qp_load_image_mem(gfx_animation);
#endif

  if (animation != NULL) {
    animation_token = qp_animate(display, (240 - animation->width),
                                 (240 - animation->height), animation);
  }
#endif

#if 0
    image = qp_load_image_mem(gfx_karlk90);
    if (image != NULL) {
        qp_drawimage(display, 0, 0, image);
        qp_flush(display);
    }
  font = qp_load_font_mem(font_iosevka11);
  if (font != NULL) {
    qp_drawtext(display, 40, 160, font, "QUANTUM PAINTER @ RP2040");
  }
#endif

#endif
}

void housekeeping_task_user(void) {
#if 0
  static uint32_t last_draw = 0;
  if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
    last_draw = timer_read32();
    // Draw 8px-wide rainbow down the left side of the display
    for (int i = 240; i < 320; ++i) {
      qp_line(display, 0, i, 239, i, i, 255, 255);
    }
    qp_flush(display);
  }
#endif
}

void board_init(void) {}