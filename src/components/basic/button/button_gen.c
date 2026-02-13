/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
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

lv_obj_t * button_create(lv_obj_t * parent, const char * tag, int32_t button_type)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button_invisible;
    static lv_style_t style_button_pri;
    static lv_style_t style_button;
    static lv_style_t style_button_activ;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button_invisible);
        lv_style_set_bg_color(&style_button_invisible, lv_color_hex(0x131313));
        lv_style_set_border_side(&style_button_invisible, LV_BORDER_SIDE_NONE);
        lv_style_set_bg_opa(&style_button_invisible, 0);

        lv_style_init(&style_button_pri);
        lv_style_set_bg_color(&style_button_pri, lv_color_hex(0x0a64a8));
        lv_style_set_border_side(&style_button_pri, LV_BORDER_SIDE_NONE);
        lv_style_set_bg_opa(&style_button_pri, 255);

        lv_style_init(&style_button);
        lv_style_set_bg_color(&style_button, lv_color_hex(0x131313));
        lv_style_set_border_side(&style_button, LV_BORDER_SIDE_FULL);
        lv_style_set_border_width(&style_button, 1);
        lv_style_set_border_color(&style_button, lv_color_hex(0x020202));
        lv_style_set_shadow_width(&style_button, 0);
        lv_style_set_bg_opa(&style_button, 255);
        lv_style_set_height(&style_button, LV_SIZE_CONTENT);
        lv_style_set_width(&style_button, LV_SIZE_CONTENT);
        lv_style_set_radius(&style_button, 4);
        lv_style_set_pad_all(&style_button, 8);

        lv_style_init(&style_button_activ);
        lv_style_set_bg_opa(&style_button_activ, 127);

        style_inited = true;
    }

    lv_obj_t * lv_button_0 = lv_button_create(parent);
    lv_obj_set_name_static(lv_button_0, "button_#");

    lv_obj_t * label_0 = label_create(lv_button_0, tag);
    
    lv_obj_add_style(lv_button_0, &style_button_activ, LV_STATE_PRESSED);
    lv_obj_add_style(lv_button_0, &style_button, 0);
    lv_obj_bind_style(lv_button_0, &style_button_pri, 0, &button_pri, button_type);
    lv_obj_bind_style(lv_button_0, &style_button_invisible, 0, &button_invis, button_type);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_button_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

