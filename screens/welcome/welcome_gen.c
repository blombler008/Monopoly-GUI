/**
 * @file welcome_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "welcome_gen.h"
#include "Monopoly.h"

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

lv_obj_t * welcome_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    if (welcome == NULL) welcome = lv_obj_create(NULL);
    lv_obj_t * lv_obj_0 = welcome;
    lv_obj_set_name_static(lv_obj_0, "welcome_#");

    lv_obj_t * header_0 = header_create(lv_obj_0, "Monopoly");
    
    lv_obj_t * content_0 = content_create(lv_obj_0);
    lv_obj_t * card_0 = card_create(content_0);
    lv_obj_t * label_0 = label_create(card_0, "text_welcome");
    lv_obj_set_width(label_0, lv_pct(100));
    lv_obj_set_style_text_align(label_0, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(label_0, RobotoB_24, 0);
    lv_obj_set_style_text_letter_space(label_0, 1, 0);
    
    lv_obj_t * label_1 = label_create(card_0, "text_welcome_info");
    lv_obj_set_width(label_1, lv_pct(100));
    lv_obj_set_style_text_align(label_1, LV_TEXT_ALIGN_CENTER, 0);
    
    lv_obj_t * card_1 = card_create(content_0);
    lv_obj_t * label_2 = label_create(card_1, "gameinfo display");
    
    lv_obj_t * button_0 = button_create(card_1, "settings", 0);
    lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, settings, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    
    lv_obj_t * button_1 = button_create(content_0, "game_start", 1);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

