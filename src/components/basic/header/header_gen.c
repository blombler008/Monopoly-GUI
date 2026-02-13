/**
 * @file header_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "header_gen.h"
#include "../../../Monopoly.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * header_create(lv_obj_t * parent, const char * title)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_header_bar;
    static lv_style_t style_header_clock;
    static lv_style_t style_header_status_icons;
    static lv_style_t style_header_title;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_header_bar);
        lv_style_set_bg_color(&style_header_bar, lv_color_hex(0x080808));
        lv_style_set_width(&style_header_bar, 320);
        lv_style_set_height(&style_header_bar, 30);
        lv_style_set_border_side(&style_header_bar, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_radius(&style_header_bar, 0);
        lv_style_set_border_width(&style_header_bar, 1);
        lv_style_set_border_color(&style_header_bar, lv_color_hex(0x272727));
        lv_style_set_pad_all(&style_header_bar, 0);
        lv_style_set_margin_all(&style_header_bar, 0);

        lv_style_init(&style_header_clock);
        lv_style_set_text_align(&style_header_clock, LV_TEXT_ALIGN_CENTER);
        lv_style_set_align(&style_header_clock, LV_ALIGN_RIGHT_MID);
        lv_style_set_text_color(&style_header_clock, lv_color_hex(0xdddddd));
        lv_style_set_margin_ver(&style_header_clock, 7);
        lv_style_set_margin_right(&style_header_clock, 4);
        lv_style_set_pad_right(&style_header_clock, 0);
        lv_style_set_height(&style_header_clock, 16);
        lv_style_set_translate_y(&style_header_clock, 1);
        lv_style_set_translate_x(&style_header_clock, -4);

        lv_style_init(&style_header_status_icons);
        lv_style_set_flex_main_place(&style_header_status_icons, LV_FLEX_ALIGN_END);
        lv_style_set_height(&style_header_status_icons, 28);
        lv_style_set_translate_x(&style_header_status_icons, -52);
        lv_style_set_align(&style_header_status_icons, LV_ALIGN_RIGHT_MID);
        lv_style_set_margin_all(&style_header_status_icons, 0);
        lv_style_set_pad_all(&style_header_status_icons, 4);
        lv_style_set_pad_column(&style_header_status_icons, 8);
        lv_style_set_translate_y(&style_header_status_icons, 1);
        lv_style_set_width(&style_header_status_icons, 84);

        lv_style_init(&style_header_title);
        lv_style_set_align(&style_header_title, LV_ALIGN_LEFT_MID);
        lv_style_set_width(&style_header_title, 184);
        lv_style_set_pad_left(&style_header_title, 12);
        lv_style_set_height(&style_header_title, 20);
        lv_style_set_text_color(&style_header_title, lv_color_hex(0xdddddd));
        lv_style_set_translate_y(&style_header_title, 1);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "header_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_header_bar, 0);
    lv_obj_t * timehead_0 = timehead_create(lv_obj_0);
    lv_obj_add_style(timehead_0, &style_header_clock, 0);
    
    lv_obj_t * label_0 = label_create(lv_obj_0, " ");
    lv_label_set_translation_tag(label_0, title);
    lv_label_set_long_mode(label_0, LV_LABEL_LONG_MODE_DOTS);
    lv_obj_add_style(label_0, &style_header_title, 0);
    
    lv_obj_t * row_0 = row_create(lv_obj_0);
    lv_obj_add_style(row_0, &style_header_status_icons, 0);
    lv_obj_t * lv_image_0 = lv_image_create(row_0);
    lv_image_set_src(lv_image_0, bluetooth);
    lv_obj_bind_flag_if_eq(lv_image_0, &bluetooth_on, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_1 = lv_image_create(row_0);
    lv_image_set_src(lv_image_1, nfc);
    lv_obj_bind_flag_if_eq(lv_image_1, &nfc_on, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_2 = lv_image_create(row_0);
    lv_image_set_src(lv_image_2, wifi);
    lv_obj_bind_flag_if_eq(lv_image_2, &wifi_on, LV_OBJ_FLAG_HIDDEN, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

