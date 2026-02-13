/**
 * @file timehead_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "timehead_gen.h"
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

lv_obj_t * timehead_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_header_clock;
    static lv_style_t style_time_hours;
    static lv_style_t style_time_div;
    static lv_style_t style_time_minutes;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_header_clock);
        lv_style_set_text_align(&style_header_clock, LV_TEXT_ALIGN_CENTER);
        lv_style_set_align(&style_header_clock, LV_ALIGN_RIGHT_MID);
        lv_style_set_text_color(&style_header_clock, lv_color_hex(0xdddddd));
        lv_style_set_margin_ver(&style_header_clock, 7);
        lv_style_set_margin_right(&style_header_clock, 0);
        lv_style_set_height(&style_header_clock, 16);
        lv_style_set_width(&style_header_clock, 48);
        lv_style_set_translate_y(&style_header_clock, 1);

        lv_style_init(&style_time_hours);
        lv_style_set_align(&style_time_hours, LV_ALIGN_LEFT_MID);
        lv_style_set_width(&style_time_hours, 20);
        lv_style_set_text_align(&style_time_hours, LV_TEXT_ALIGN_RIGHT);

        lv_style_init(&style_time_div);
        lv_style_set_align(&style_time_div, LV_ALIGN_CENTER);
        lv_style_set_width(&style_time_div, 4);
        lv_style_set_text_align(&style_time_div, LV_TEXT_ALIGN_CENTER);

        lv_style_init(&style_time_minutes);
        lv_style_set_align(&style_time_minutes, LV_ALIGN_RIGHT_MID);
        lv_style_set_width(&style_time_minutes, 20);
        lv_style_set_text_align(&style_time_minutes, LV_TEXT_ALIGN_LEFT);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "timehead_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_header_clock, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_0, &time_hours, "%02d");
    lv_obj_add_style(lv_label_0, &style_text, 0);
    lv_obj_add_style(lv_label_0, &style_time_hours, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_1, ":");
    lv_obj_add_style(lv_label_1, &style_text, 0);
    lv_obj_add_style(lv_label_1, &style_time_div, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_2, &time_minutes, "%02d");
    lv_obj_add_style(lv_label_2, &style_text, 0);
    lv_obj_add_style(lv_label_2, &style_time_minutes, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

