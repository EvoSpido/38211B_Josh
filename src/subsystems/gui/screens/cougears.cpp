#include "display/lv_core/lv_obj.h"
#include "main.h"

//will comment later -adrian


lv_obj_t* scrCougears;

LV_IMG_DECLARE(cougears);


void cougearsScreen() {
    
    scrCougears = lv_obj_create(NULL, NULL);
    lv_obj_t* imgCougears = lv_img_create(scrCougears, NULL);
    lv_img_set_src(imgCougears, &cougears);
    lv_obj_align(imgCougears, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    lv_obj_t* labelCougears = lv_label_create(scrCougears, NULL);
    lv_label_set_style(labelCougears, &scrCougearsStyle);
    lv_label_set_long_mode(labelCougears, LV_LABEL_LONG_BREAK);
    lv_label_set_align(labelCougears, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_width(labelCougears, 480);
    lv_obj_align(labelCougears, NULL, LV_ALIGN_CENTER, 80, 105);
    

    if(tabToggled == 1) { //Match -- autoSelected 1-5

        uint16_t btnid = lv_btnm_get_toggled(scrMatchBtnm);

        switch (btnid) {
            
            case 0:
                autoSelected = 1;
                lv_label_set_text(labelCougears, "AUTO SELECTED: L Full AWP");
                controller.set_text(2, 6, "L Full AWP");
            break;
            case 1:
                autoSelected = 2;
                lv_label_set_text(labelCougears, "AUTO SELECTED: R Full AWP");
                controller.set_text(2, 6, "R Full AWP");
            break;
            case 2:
                autoSelected = 3;
                lv_label_set_text(labelCougears, "AUTO SELECTED: Spin Roller");
                controller.set_text(2, 9, "Roller");
            break;
            case 3:
                autoSelected = 4;
                lv_label_set_text(labelCougears, "AUTO SELECTED: L 1/2 AWP");
                controller.set_text(2, 6, "L 1/2 AWP");
            break;
            case 4:
                autoSelected = 5;
                lv_label_set_text(labelCougears, "AUTO SELECTED: R 1/2 AWP");
                controller.set_text(2, 6, "R 1/2 AWP");
            break;
            case 5:
                lv_label_set_text(labelCougears, "AUTO SELECTED: No Autonomous");
                controller.set_text(2, 7, "No Auto");
            break;
        }
    }

    if(tabToggled == 2) { //Skills -- autoSelected 6 and 7

        uint16_t btnid = lv_btnm_get_toggled(scrSkillsBtnm);

        switch (btnid) {

            case 0:
                autoSelected = 6;
                lv_label_set_text(labelCougears, "AUTO SELECTED: skills route 1");
                controller.set_text(2, 6, "skillsroute1");
            break;
            case 1:
                autoSelected = 7;
                lv_label_set_text(labelCougears, "AUTO SELECTED: skills route 2");
                controller.set_text(2, 6, "skillsroute2");
            break;
        }
    }

    //if the the controller is connected to the field and is not in the disabled state (aka driver control/autonomous), the selected autonomous will not show up on the brain
    if(pros::competition::is_connected() && !pros::competition::is_disabled()) {

        lv_label_set_text(labelCougears, "");
        controller.clear_line(2);
    }
    
    lv_scr_load(scrCougears);
}