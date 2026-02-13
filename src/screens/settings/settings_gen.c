/**
 * @file settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_gen.h"
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

lv_obj_t * settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    if (settings == NULL) settings = lv_obj_create(NULL);
    lv_obj_t * lv_obj_0 = settings;
    lv_obj_set_name_static(lv_obj_0, "settings_#");

    lv_obj_t * header_0 = header_create(lv_obj_0, "settings");
    
    lv_obj_t * content_0 = content_create(lv_obj_0);
    lv_obj_t * playerSettingsCard_0 = playerSettingsCard_create(content_0);
    
    lv_obj_t * connectionSettingsCard_0 = connectionSettingsCard_create(content_0);
    
    lv_obj_t * gameSettingsCard_0 = gameSettingsCard_create(content_0);
    
    lv_obj_t * audioSettingsCard_0 = audioSettingsCard_create(content_0);
    
    lv_obj_t * row_0 = row_create(content_0);
    lv_obj_set_style_pad_column(row_0, UNIT_XL, 0);
    lv_obj_t * button_0 = button_create(row_0, "back", 2);
    lv_obj_add_screen_load_event(button_0, LV_EVENT_CLICKED, welcome, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    
    lv_obj_t * button_1 = button_create(row_0, "about", 2);
    lv_obj_add_screen_create_event(button_1, LV_EVENT_CLICKED, about_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

