#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
//#include "anim_alpha.c"
//#include "still_alpha.c"
#include "number01.c"
#include "number02.c"
#include "number03.c"
#include "number04.c"
#include "number05.c"
#include "number06.c"
#include "number07.c"
#include "number08.c"
#include "number09.c"
#include "number10.c"
#include "number11.c"
#include "number12.c"
#include "number13.c"
#include "number14.c"
#include "number15.c"
#include "number16.c"
#include "number17.c"
#include "number18.c"
#include "number19.c"
#include "number20.c"
#include "number21.c"
#include "number22.c"
#include "number23.c"
#include "number24.c"
#include "number25.c"
#include "number26.c"
#include "number27.c"
#include "number28.c"
#include "number29.c"
#include "number30.c"
#include "number31.c"
#include "qp.h"
#include "qp_lvgl.h"

static painter_device_t qp_display;
#endif

static uint32_t user_data = 1;
//static uint32_t  my_frame = 0;
//LV_IMG_DECLARE(anim_alpha);
//LV_IMG_DECLARE(still_alpha);
LV_IMG_DECLARE(number01);
LV_IMG_DECLARE(number02);
LV_IMG_DECLARE(number03);
LV_IMG_DECLARE(number04);
LV_IMG_DECLARE(number05);
LV_IMG_DECLARE(number06);
LV_IMG_DECLARE(number07);
LV_IMG_DECLARE(number08);
LV_IMG_DECLARE(number09);
LV_IMG_DECLARE(number10);
LV_IMG_DECLARE(number11);
LV_IMG_DECLARE(number12);
LV_IMG_DECLARE(number13);
LV_IMG_DECLARE(number14);
LV_IMG_DECLARE(number15);
LV_IMG_DECLARE(number16);
LV_IMG_DECLARE(number17);
LV_IMG_DECLARE(number18);
LV_IMG_DECLARE(number19);
LV_IMG_DECLARE(number20);
LV_IMG_DECLARE(number21);
LV_IMG_DECLARE(number22);
LV_IMG_DECLARE(number23);
LV_IMG_DECLARE(number24);
LV_IMG_DECLARE(number25);
LV_IMG_DECLARE(number26);
LV_IMG_DECLARE(number27);
LV_IMG_DECLARE(number28);
LV_IMG_DECLARE(number29);
LV_IMG_DECLARE(number30);
LV_IMG_DECLARE(number31);


lv_obj_t * ui_Screen1;
//lv_obj_t * ui_Screen1_Label_RGB;
lv_obj_t * ui_boot_anim;
lv_obj_t * ui_back;


void my_timer(lv_timer_t * timer)
{
  //uint32_t * user_data = timer->user_data;
  //printf("my_timer called with user data: %d\n", *user_data);
 // lv_img_set_src(ui_back, &number02);

  ++user_data;

  if(user_data == 2){ lv_img_set_src(ui_back, &number02); }
  else if(user_data == 3){ lv_img_set_src(ui_back, &number03); }
  else if(user_data == 4){ lv_img_set_src(ui_back, &number04); }
  else if(user_data == 5){ lv_img_set_src(ui_back, &number05); }
  else if(user_data == 6){ lv_img_set_src(ui_back, &number06); }
  else if(user_data == 7){ lv_img_set_src(ui_back, &number07); }
  else if(user_data == 8){ lv_img_set_src(ui_back, &number08); }
  else if(user_data == 9){ lv_img_set_src(ui_back, &number09); }
  else if(user_data == 10){ lv_img_set_src(ui_back, &number10); }
  else if(user_data == 11){ lv_img_set_src(ui_back, &number11); }
  else if(user_data == 12){ lv_img_set_src(ui_back, &number12); }
  else if(user_data == 13){ lv_img_set_src(ui_back, &number13); }
  else if(user_data == 14){ lv_img_set_src(ui_back, &number14); }
  else if(user_data == 15){ lv_img_set_src(ui_back, &number15); }
  else if(user_data == 16){ lv_img_set_src(ui_back, &number16); }
  else if(user_data == 17){ lv_img_set_src(ui_back, &number17); }
  else if(user_data == 18){ lv_img_set_src(ui_back, &number18); }
  else if(user_data == 19){ lv_img_set_src(ui_back, &number19); }
  else if(user_data == 20){ lv_img_set_src(ui_back, &number20); }
  else if(user_data == 21){ lv_img_set_src(ui_back, &number21); }
  else if(user_data == 22){ lv_img_set_src(ui_back, &number22); }
  else if(user_data == 23){ lv_img_set_src(ui_back, &number23); }
  else if(user_data == 24){ lv_img_set_src(ui_back, &number24); }
  else if(user_data == 25){ lv_img_set_src(ui_back, &number25); }
  else if(user_data == 26){ lv_img_set_src(ui_back, &number26); }
  else if(user_data == 27){ lv_img_set_src(ui_back, &number27); }
  else if(user_data == 28){ lv_img_set_src(ui_back, &number28); }
  else if(user_data == 29){ lv_img_set_src(ui_back, &number29); }
  else if(user_data == 30){ lv_img_set_src(ui_back, &number30); }
  else if(user_data == 31){ lv_img_set_src(ui_back, &number31); }

}


void keyboard_post_init_user(void) {

  qp_display = qp_ssd1351_make_spi_device(128, 128, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 3, 0);
  //qp_set_viewport_offsets(display, 0, 34);
  qp_init(qp_display, QP_ROTATION_270); // Initialise the display
  qp_power(qp_display, true);
  qp_rect(qp_display, 0, 0, 127, 127, 0, 0, 0, true);
  qp_lvgl_attach(qp_display);

  if (qp_lvgl_attach(qp_display)) {     // Attach LVGL to the display
    wait_ms(50); 
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN);


  ui_back = lv_img_create(ui_Screen1);
  lv_img_set_src(ui_back, &number01); 
  //lv_gif_set_src(ui_back, "anim_alpha.gif");
  lv_obj_set_align(ui_back, LV_ALIGN_CENTER);

    lv_color_t mycolor2  = lv_color_hex(0x28cb97);
    lv_opa_t myintense2 = 255;
    lv_obj_set_style_img_recolor_opa(ui_back, myintense2, 0);
    lv_obj_set_style_img_recolor(ui_back, mycolor2, 0); 

    lv_disp_load_scr(ui_Screen1);
    lv_timer_t * timer = lv_timer_create(my_timer, 20,  &user_data);
    lv_timer_set_repeat_count(timer, 30);
  }
}


void board_init(void) {}