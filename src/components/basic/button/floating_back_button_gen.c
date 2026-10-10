/**
 * @file floating_back_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "floating_back_button_gen.h"
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

lv_obj_t * floating_back_button_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button;
    static lv_style_t style_button_activ;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_button);
        lv_style_init(&style_button_activ);

        lv_style_set_bg_color(&style_button, lv_color_hex(0x131313));
        lv_style_set_border_side(&style_button, LV_BORDER_SIDE_FULL);
        lv_style_set_border_width(&style_button, 1);
        lv_style_set_border_color(&style_button, lv_color_hex(0x020202));
        lv_style_set_shadow_width(&style_button, 0);
        lv_style_set_bg_opa(&style_button, 255);
        lv_style_set_height(&style_button, 40);
        lv_style_set_width(&style_button, 40);
        lv_style_set_radius(&style_button, lv_pct(50));
        lv_style_set_pad_all(&style_button, 0);
        lv_style_set_bg_opa(&style_button_activ, 127);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if MONOPOLY_CHECK_COMPILE_TARGET(MONOPOLY_TARGET_ALL)
    if (Monopoly_check_target(MONOPOLY_TARGET_ALL)) {
        lv_obj_t * lv_button_0 = lv_button_create(parent);
        lv_obj_set_name_static(lv_button_0, "floating_back_button_#");
        lv_obj_set_flag(lv_button_0, LV_OBJ_FLAG_FLOATING, true);
        lv_obj_set_align(lv_button_0, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_x(lv_button_0, -8);
        lv_obj_set_y(lv_button_0, -8);

        lv_obj_t * image = lv_image_create(lv_button_0);
        lv_obj_set_name(image, "image");
        lv_image_set_src(image, back_arrow);
        lv_obj_set_align(image, LV_ALIGN_CENTER);
        lv_obj_set_width(image, 20);
        lv_obj_set_height(image, 20);

        lv_obj_add_style(lv_button_0, &style_button_activ, LV_STATE_PRESSED);
        lv_obj_add_style(lv_button_0, &style_button, 0);
        lv_obj_add_event_cb(lv_button_0, back_button_handler, LV_EVENT_CLICKED, NULL);

        the_root = lv_button_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

