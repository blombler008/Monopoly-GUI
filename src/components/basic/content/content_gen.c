/**
 * @file content_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "content_gen.h"
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

lv_obj_t * content_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_content;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_content);
        lv_style_set_bg_color(&style_content, lv_color_hex(0x131313));
        lv_style_set_bg_grad_dir(&style_content, LV_GRAD_DIR_VER);
        lv_style_set_bg_grad_color(&style_content, lv_color_hex(0x191919));
        lv_style_set_align(&style_content, LV_ALIGN_BOTTOM_MID);
        lv_style_set_height(&style_content, 210);
        lv_style_set_width(&style_content, 320);
        lv_style_set_border_side(&style_content, LV_BORDER_SIDE_NONE);
        lv_style_set_pad_row(&style_content, UNIT_MD);
        lv_style_set_radius(&style_content, 0);
        lv_style_set_flex_track_place(&style_content, LV_FLEX_ALIGN_CENTER);
        lv_style_set_layout(&style_content, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_content, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_content, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&style_content, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }

    lv_obj_t * content = lv_obj_create(parent);
    lv_obj_set_name_static(content, "content_#");
    lv_obj_set_name(content, "content");
    lv_obj_set_scrollbar_mode(content, LV_SCROLLBAR_MODE_ACTIVE);

    lv_obj_add_style(content, &style_content, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return content;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

