/**
 * @file Monopoly_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "Monopoly_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * game_start = NULL;
lv_obj_t * settings = NULL;
lv_obj_t * welcome = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * Roboto_16;
lv_font_t * Roboto_24;
lv_font_t * RobotoB_16;
lv_font_t * RobotoB_24;

/*----------------
 * Images
 *----------------*/

const void * bluetooth;
const void * wifi;
const void * nfc;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_text;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t start_cash;
lv_subject_t player_count;
lv_subject_t bluetooth_on;
lv_subject_t wifi_on;
lv_subject_t nfc_on;
lv_subject_t battery_level;
lv_subject_t time_minutes;
lv_subject_t time_hours;
lv_subject_t button_sec;
lv_subject_t button_pri;
lv_subject_t button_invis;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void Monopoly_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* create bin font 'Roboto_16' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "/fonts/Roboto_16");
    Roboto_16 = lv_binfont_create(buf);
    /* create bin font 'Roboto_24' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "/fonts/Roboto_24");
    Roboto_24 = lv_binfont_create(buf);
    /* create bin font 'RobotoB_16' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "/fonts/RobotoB_16");
    RobotoB_16 = lv_binfont_create(buf);
    /* create bin font 'RobotoB_24' from file */
    lv_snprintf(buf, 256, "%s%s", asset_path, "/fonts/RobotoB_24");
    RobotoB_24 = lv_binfont_create(buf);


    /*----------------
     * Images
     *----------------*/
    lv_snprintf(buf, 256, "%s%s", asset_path, "/images/bluetooth_20dp_E3E3E3_FILL0_wght400_GRAD0_opsz20.png");
    bluetooth = lv_strdup(buf);
    lv_snprintf(buf, 256, "%s%s", asset_path, "/images/wifi_20dp_E3E3E3_FILL0_wght400_GRAD0_opsz20.png");
    wifi = lv_strdup(buf);
    lv_snprintf(buf, 256, "%s%s", asset_path, "/images/contactless_20dp_E3E3E3_FILL0_wght400_GRAD0_opsz20.png");
    nfc = lv_strdup(buf);

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_text);
        lv_style_set_text_color(&style_text, TEXT_COLOR);
        lv_style_set_text_font(&style_text, Roboto_16);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&start_cash, 1500);
    lv_subject_set_min_value_int(&start_cash, 0);
    lv_subject_set_max_value_int(&start_cash, 500000);
    lv_subject_init_int(&player_count, 0);
    lv_subject_set_min_value_int(&player_count, 0);
    lv_subject_set_max_value_int(&player_count, 8);
    lv_subject_init_int(&bluetooth_on, 0);
    lv_subject_set_min_value_int(&bluetooth_on, 0);
    lv_subject_set_max_value_int(&bluetooth_on, 1);
    lv_subject_init_int(&wifi_on, 0);
    lv_subject_set_min_value_int(&wifi_on, 0);
    lv_subject_set_max_value_int(&wifi_on, 1);
    lv_subject_init_int(&nfc_on, 0);
    lv_subject_set_min_value_int(&nfc_on, 0);
    lv_subject_set_max_value_int(&nfc_on, 1);
    lv_subject_init_int(&battery_level, 50);
    lv_subject_set_min_value_int(&battery_level, 0);
    lv_subject_set_max_value_int(&battery_level, 100);
    lv_subject_init_int(&time_minutes, 34);
    lv_subject_set_min_value_int(&time_minutes, 0);
    lv_subject_set_max_value_int(&time_minutes, 59);
    lv_subject_init_int(&time_hours, 12);
    lv_subject_set_min_value_int(&time_hours, 0);
    lv_subject_set_max_value_int(&time_hours, 23);
    lv_subject_init_int(&button_sec, 0);
    lv_subject_init_int(&button_pri, 1);
    lv_subject_init_int(&button_invis, 2);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "Roboto_16", Roboto_16);
    lv_xml_register_font(NULL, "Roboto_24", Roboto_24);
    lv_xml_register_font(NULL, "RobotoB_16", RobotoB_16);
    lv_xml_register_font(NULL, "RobotoB_24", RobotoB_24);

    /* Register subjects */
    lv_xml_register_subject(NULL, "start_cash", &start_cash);
    lv_xml_register_subject(NULL, "player_count", &player_count);
    lv_xml_register_subject(NULL, "bluetooth_on", &bluetooth_on);
    lv_xml_register_subject(NULL, "wifi_on", &wifi_on);
    lv_xml_register_subject(NULL, "nfc_on", &nfc_on);
    lv_xml_register_subject(NULL, "battery_level", &battery_level);
    lv_xml_register_subject(NULL, "time_minutes", &time_minutes);
    lv_xml_register_subject(NULL, "time_hours", &time_hours);
    lv_xml_register_subject(NULL, "button_sec", &button_sec);
    lv_xml_register_subject(NULL, "button_pri", &button_pri);
    lv_xml_register_subject(NULL, "button_invis", &button_invis);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "bluetooth", bluetooth);
    lv_xml_register_image(NULL, "wifi", wifi);
    lv_xml_register_image(NULL, "nfc", nfc);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    game_start = lv_obj_create(NULL);
    settings = lv_obj_create(NULL);
    welcome = lv_obj_create(NULL);

    game_start_create();
    settings_create();
    welcome_create();
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/