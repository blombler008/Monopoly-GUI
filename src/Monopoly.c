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
static void language_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
 
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

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
}

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
/**********************
 *   STATIC FUNCTIONS
 **********************/
