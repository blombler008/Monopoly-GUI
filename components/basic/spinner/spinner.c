#include "spinner_gen.h"
#include "spinner.h"
#include "Monopoly.h"

lv_obj_t * super_spinner_create(lv_obj_t * parent) {
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_obj_0 = lv_spinner_create(parent);
    lv_obj_set_name_static(lv_obj_0, "spinner_#");
    lv_obj_set_height(lv_obj_0, 100);
    lv_obj_set_width(lv_obj_0, 100);
 
    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}  