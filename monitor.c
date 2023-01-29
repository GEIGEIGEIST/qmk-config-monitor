#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
//#include "gangbang.c"
//#include "boy.c"
//#include "geist_tc.c"
//#include "geist_raw.c"
#include "triple.c"
#include "triple_still.c"
#include "qp.h"
#include "qp_lvgl.h"

#define LCD_CS_PIN GP21
#define LCD_DC_PIN GP27
#define LCD_RST_PIN GP26

static painter_device_t qp_display;
#endif

static uint32_t user_data = 10;
//LV_IMG_DECLARE(gangbang);
//LV_IMG_DECLARE(boy);
//LV_IMG_DECLARE(geist_tc);
//LV_IMG_DECLARE(geist_raw);
//LV_IMG_DECLARE(matrix_80);
//LV_IMG_DECLARE(mund_small);
//LV_IMG_DECLARE(mund_small_still);
//LV_IMG_DECLARE(mund_small_alpha);
LV_IMG_DECLARE(triple);
LV_IMG_DECLARE(triple_still);


lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Label_RGB;
lv_obj_t * ui_boot_anim;
lv_obj_t * ui_back;
//lv_obj_t * lottie;

void my_timer(lv_timer_t * timer)
{
  /*Use the user_data*/
  uint32_t * user_data = timer->user_data;
  printf("my_timer called with user data: %d\n", *user_data);

  /*Do something with LVGL*/
  lv_obj_del(ui_boot_anim);
  ui_back = lv_img_create(ui_Screen1);
  lv_img_set_src(ui_back, &triple_still); 
  lv_obj_set_width(ui_back, LV_SIZE_CONTENT);   /// 81
  lv_obj_set_height(ui_back, LV_SIZE_CONTENT);    /// 55
  lv_obj_set_x(ui_back, 0);
  lv_obj_set_y(ui_back, 0);
  lv_obj_set_align(ui_back, LV_ALIGN_CENTER);
//  lv_color_t mycolor  = lv_color_hex(0xe981c3);
//  lv_opa_t myintense = 255;
//  lv_obj_set_style_img_recolor_opa(ui_back, myintense, 0);
//  lv_obj_set_style_img_recolor(ui_back, mycolor, 0); 
}


void keyboard_post_init_user(void) {

  qp_display = qp_st7789_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN,
                                      LCD_RST_PIN, 1, 3);
  //qp_set_viewport_offsets(display, 0, 34);
  qp_init(qp_display, QP_ROTATION_0); // Initialise the display
  qp_power(qp_display, true);
  qp_rect(qp_display, 0, 0, 239, 319, 0, 0, 0, true);
  qp_lvgl_attach(qp_display);

  if (qp_lvgl_attach(qp_display)) {     // Attach LVGL to the display
    wait_ms(50);
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN);


    ui_boot_anim = lv_gif_create(ui_Screen1);
    lv_gif_set_src(ui_boot_anim, &triple); 
    lv_obj_align(ui_boot_anim, LV_ALIGN_CENTER, 0, 0);
    //lv_color_t mycolor2  = lv_color_hex(0xe981c3);
    //lv_opa_t myintense2 = 255;
    //lv_obj_set_style_img_recolor_opa(ui_boot_anim, myintense2, 0);
    //lv_obj_set_style_img_recolor(ui_boot_anim, mycolor2, 0); 
/* 
    lottie = lv_rlottie_create_from_file(ui_Screen1, 200, 300,
            "bounce.json");
    lv_obj_center(lottie);
*/
  /*
    ui_boot_anim = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_boot_anim, &geist_raw); 
    lv_obj_set_width(ui_boot_anim, LV_SIZE_CONTENT);   /// 81
    lv_obj_set_height(ui_boot_anim, LV_SIZE_CONTENT);    /// 55
    lv_obj_set_x(ui_boot_anim, 0);
    lv_obj_set_y(ui_boot_anim, 0);
    lv_obj_set_align(ui_boot_anim, LV_ALIGN_CENTER);
*/
/*
   ui_Screen1_Label_RGB = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label_RGB, 150);
    lv_obj_set_style_text_font(ui_Screen1_Label_RGB, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(ui_Screen1_Label_RGB, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label_RGB, "LVGL IS NO FUN!");
*/
    lv_disp_load_scr(ui_Screen1);
    lv_timer_t * timer = lv_timer_create(my_timer, 9000,  &user_data);
  }
}


void board_init(void) {}