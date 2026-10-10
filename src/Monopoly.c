/**
 * @file Monopoly.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "Monopoly.h"  

/*********************
 *      DEFINES
 *********************/

 
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static const char* screen_history[16];
static int screen_history_index = -1;
/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void Monopoly_init(const char * asset_path)
{
    Monopoly_init_gen(asset_path);

    /* Add your own custom code here if needed */

    lv_subject_add_observer(&language, language_observer_cb, NULL);

    lv_xml_register_event_cb(NULL, "back_button_handler", back_button_handler);
}

void load_screen(const char * name)
{
    if(screen_history_index < 15) {
        screen_history[++screen_history_index] = name;
    }
    lv_obj_t * scr = lv_xml_create_screen(name);
    lv_scr_load(scr);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void language_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    int32_t language = lv_subject_get_int(subject);
    
    switch (language)
    {
    case 0:
        lv_translation_set_language("en");
        break;
    case 1:
        lv_translation_set_language("de");
        break;
    default:
        lv_translation_set_language("en");
        break;
    }
}
void back_button_handler(lv_event_t * e)
{
    if(screen_history_index > 0) {
        screen_history_index--;
        const char* previous = screen_history[screen_history_index]; 
        lv_obj_t * scr = lv_xml_create_screen(previous);
        lv_scr_load(scr);
    }
}   