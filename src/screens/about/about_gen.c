/**
 * @file about_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "about_gen.h"
#include "../../Monopoly.h"

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

lv_obj_t * about_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "about_#");

    lv_obj_t * header_0 = header_create(lv_obj_0, "about");
    
    lv_obj_t * content_0 = content_create(lv_obj_0);
    lv_obj_t * lv_qrcode_0 = lv_qrcode_create(content_0);
    lv_qrcode_set_data(lv_qrcode_0, "https://tattyhost.com");
    
    lv_obj_t * button_0 = button_create(content_0, "back", 2);
    lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, settings, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

