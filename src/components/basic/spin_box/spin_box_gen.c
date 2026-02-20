/**
 * @file spin_box_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "spin_box_gen.h"
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

lv_obj_t * spin_box_create(lv_obj_t * parent, lv_subject_t * subject, int32_t max, int32_t min, int32_t digit_count)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t pg;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&pg);
        lv_style_set_bg_color(&pg, BG_TERTIARY_DARK);
        lv_style_set_layout(&pg, LV_LAYOUT_FLEX);
        lv_style_set_bg_opa(&pg, 255);
        lv_style_set_height(&pg, LV_SIZE_CONTENT);
        lv_style_set_width(&pg, LV_SIZE_CONTENT);
        lv_style_set_flex_flow(&pg, LV_FLEX_FLOW_ROW);
        lv_style_set_margin_all(&pg, 8);
        lv_style_set_pad_all(&pg, 8);
        lv_style_set_radius(&pg, 5);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "spin_box_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &pg, 0);
    lv_obj_t * button_0 = button_create(lv_obj_0, " +", 0);
    lv_obj_set_width(button_0, 37);
    lv_obj_set_height(button_0, 37);
    lv_obj_set_style_margin_right(button_0, 8, 0);
    lv_subject_increment_dsc_t * subject_increment_event_0 = lv_obj_add_subject_increment_event(button_0, subject, LV_EVENT_CLICKED, 1);
    lv_obj_set_subject_increment_event_rollover(button_0, subject_increment_event_0, true);
    lv_obj_set_subject_increment_event_max_value(button_0, subject_increment_event_0, max);
    lv_obj_set_subject_increment_event_min_value(button_0, subject_increment_event_0, min);
    
    lv_obj_t * lv_spinbox_0 = lv_spinbox_create(lv_obj_0);
    lv_spinbox_set_digit_count(lv_spinbox_0, digit_count);
    lv_obj_set_width(lv_spinbox_0, 37);
    lv_obj_set_height(lv_spinbox_0, 37);
    lv_spinbox_set_max_value(lv_spinbox_0, max);
    lv_spinbox_set_min_value(lv_spinbox_0, min);
    lv_spinbox_set_rollover(lv_spinbox_0, true);
    lv_spinbox_bind_value(lv_spinbox_0, subject);
    lv_obj_remove_style(lv_spinbox_0, NULL, LV_PART_CURSOR);
    
    lv_obj_t * button_1 = button_create(lv_obj_0, "  -", 0);
    lv_obj_set_width(button_1, 37);
    lv_obj_set_height(button_1, 37);
    lv_obj_set_style_margin_left(button_1, 8, 0);
    lv_subject_increment_dsc_t * subject_increment_event_1 = lv_obj_add_subject_increment_event(button_1, subject, LV_EVENT_CLICKED, -1);
    lv_obj_set_subject_increment_event_rollover(button_1, subject_increment_event_1, true);
    lv_obj_set_subject_increment_event_max_value(button_1, subject_increment_event_1, max);
    lv_obj_set_subject_increment_event_min_value(button_1, subject_increment_event_1, min);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

