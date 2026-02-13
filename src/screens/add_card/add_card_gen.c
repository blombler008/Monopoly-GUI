/**
 * @file add_card_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "add_card_gen.h"
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

lv_obj_t * add_card_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t sometho;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&sometho);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "add_card_#");

    lv_obj_t * header_0 = header_create(lv_obj_0, "add_card");
    
    lv_obj_t * content_0 = content_create(lv_obj_0);
    lv_obj_t * lv_label_0 = lv_label_create(content_0);
    lv_label_set_translation_tag(lv_label_0, "searching_card");
    lv_obj_add_style(lv_label_0, &style_text, 0);
    
    lv_obj_t * spinner_0 = spinner_create(content_0);
    lv_obj_set_height(spinner_0, 100);
    
    lv_obj_t * button_0 = button_create(content_0, "cancel", 2);
    lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, settings, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

