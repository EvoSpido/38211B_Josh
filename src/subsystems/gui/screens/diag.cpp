#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_btn.h"
#include "display/lv_objx/lv_label.h"
#include "main.h"  
#include "pros/misc.hpp"

//objects
lv_obj_t* scrDiag;

lv_obj_t* scrDiagLabel;

lv_obj_t* scrDiagLabel0;
lv_obj_t* scrDiagLabel1;
lv_obj_t* scrDiagLabel2;
lv_obj_t* scrDiagLabel3;
lv_obj_t* scrDiagLabel4;
lv_obj_t* scrDiagLabel5;
lv_obj_t* scrDiagLabel6;
lv_obj_t* scrDiagLabel7;
lv_obj_t* scrDiagLabel8;
lv_obj_t* scrDiagLabel9;

lv_obj_t* scrDiagDispBtn;
lv_obj_t* scrDiagDispBtnLabel;

static bool isToggled = false;

lv_res_t scrDiagDispBtnAction(lv_obj_t * btn) {

    if(!isToggled) {

        lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_TGL_PR, &scrConfirmBtnYStylePR); //set the released style
        lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_TGL_REL, &scrConfirmBtnYStyleREL); //set the pressed style

        isToggled = true;
    } else if (isToggled) {

        lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_REL, &scrConfirmBtnNStyleREL); //set the released style
        lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_PR, &scrConfirmBtnNStylePR);

        isToggled = false;
    }

    return LV_RES_OK;
}



void diagScreen() {
    
    scrDiag = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scrDiag, &scrDiagStyle);
    lv_obj_set_size(scrDiag, 480, 240); 
    
    scrDiagLabel = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel, "");
    lv_label_set_long_mode(scrDiagLabel, LV_LABEL_LONG_BREAK);
    lv_label_set_align(scrDiagLabel, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_width(scrDiagLabel, 480);
    lv_obj_align(scrDiagLabel, scrDiag, LV_ALIGN_IN_TOP_MID, 0, 8);

    scrDiagLabel0 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel0, "");
    lv_obj_align(scrDiagLabel0, scrDiag, LV_ALIGN_IN_TOP_LEFT, 5, 35);
    lv_obj_set_width(scrDiagLabel0, 460);

    scrDiagLabel1 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel1, "");
    lv_obj_align(scrDiagLabel1, scrDiagLabel0, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel1, 460);

    scrDiagLabel2 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel2, "");
    lv_obj_align(scrDiagLabel2, scrDiagLabel1, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel2, 460);

    scrDiagLabel3 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel3, "");
    lv_obj_align(scrDiagLabel3, scrDiagLabel2, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel3, 460);

    scrDiagLabel4 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel4, "");
    lv_obj_align(scrDiagLabel4, scrDiagLabel3, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel4, 460);

    scrDiagLabel5 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel5, "");
    lv_obj_align(scrDiagLabel5, scrDiagLabel4, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel5, 460);

    scrDiagLabel6 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel6, "");
    lv_obj_align(scrDiagLabel6, scrDiagLabel5, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel6, 460);
    
    scrDiagLabel7 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel7, "");
    lv_obj_align(scrDiagLabel7, scrDiagLabel6, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel7, 460);
    
    scrDiagLabel8 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel8, "");
    lv_obj_align(scrDiagLabel8, scrDiagLabel7, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel8, 460);

    scrDiagLabel9 = lv_label_create(scrDiag, NULL);
    lv_label_set_text(scrDiagLabel9, "");
    lv_obj_align(scrDiagLabel9, scrDiagLabel8, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    lv_obj_set_width(scrDiagLabel6, 460);

    if (pros::competition::is_connected()) {
        scrDiagDispBtn = lv_btn_create(scrDiag, NULL);
        lv_btn_set_toggle(scrDiagDispBtn, true);
        lv_btn_set_action(scrDiagDispBtn, LV_BTN_ACTION_CLICK, scrDiagDispBtnAction);
        if (!isToggled) {
        
            lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_REL, &scrConfirmBtnNStyleREL); //set the released style
            lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_PR, &scrConfirmBtnNStylePR);

        } else if (isToggled) {

            lv_btn_set_state(scrDiagDispBtn, LV_BTN_STYLE_TGL_REL);
            lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_TGL_PR, &scrConfirmBtnYStylePR); //set the released style
            lv_btn_set_style(scrDiagDispBtn, LV_BTN_STYLE_TGL_REL, &scrConfirmBtnYStyleREL); //set the pressed style
        }
        lv_obj_set_size(scrDiagDispBtn, 113, 200); //set the button size
        lv_obj_align(scrDiagDispBtn, scrDiag, LV_ALIGN_IN_TOP_RIGHT, -5, 35); //set the position to top left
    }
    
    scrDiagDispBtnLabel = lv_label_create(scrDiagDispBtn, NULL); //create label and puts it inside of the button
    lv_label_set_long_mode(scrDiagDispBtnLabel, LV_LABEL_LONG_BREAK);
    lv_label_set_align(scrDiagDispBtnLabel, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_width(scrDiagDispBtnLabel, 113);
    lv_label_set_text(scrDiagDispBtnLabel, "Display on\nCompetiton\nEnable");

    lv_scr_load(scrDiag);
}

void setDiagText(int line, const char* string) {

    switch (line) {

        case 0:
            
            lv_label_set_text(scrDiagLabel0, string);
        break;
        case 1:

            lv_label_set_text(scrDiagLabel1, string);
        break;
        case 2:

            lv_label_set_text(scrDiagLabel2, string);
        break;
        case 3:

            lv_label_set_text(scrDiagLabel3, string);
        break;
        case 4:

            lv_label_set_text(scrDiagLabel4, string);
        break;
        case 5:

            lv_label_set_text(scrDiagLabel5, string);
        break;
        case 6:

            lv_label_set_text(scrDiagLabel6, string);
        break;
        case 7:

            lv_label_set_text(scrDiagLabel7, string);
        break;
        case 8:

            lv_label_set_text(scrDiagLabel8, string);
        break;
        case 9:

            lv_label_set_text(scrDiagLabel9, string);
        break;

    }
}

void dispAutoDiag() {

    if(pros::competition::is_connected() && !pros::competition::is_disabled()) {

        lv_label_set_text(scrDiagLabel, "");
        controller.clear_line(2);
        lv_obj_del(scrDiagDispBtn);
    } else if(tabToggled == 1) { //Match

        uint16_t btnid = lv_btnm_get_toggled(scrMatchBtnm);

        switch (btnid) {
            
            case 0:
                autoSelected = 1;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: L Full AWP");
                controller.set_text(2, 6, "L Full AWP");
            break;
            case 1:
                autoSelected = 2;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: R Full AWP");
                controller.set_text(2, 6, "R Full AWP");
            break;
            case 2:
                autoSelected = 3;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: Spin Roller");
                controller.set_text(2, 9, "Roller");
            break;
            case 3:
                autoSelected = 4;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: L 1/2 AWP");
                controller.set_text(2, 6, "L 1/2 AWP");
            break;
            case 4:
                autoSelected = 5;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: R 1/2 AWP");
                controller.set_text(2, 6, "R 1/2 AWP");
            break;
            case 5:
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: No Autonomous");
                controller.set_text(2, 7, "No Auto");
            break;
        }
        
    } else if(tabToggled == 2) { //Skills

        uint16_t btnid = lv_btnm_get_toggled(scrSkillsBtnm);

        switch (btnid) {

            case 0:
                autoSelected = 6;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: skills route 1");
                controller.set_text(2, 6, "skillsroute1");
            break;
            case 1:
                autoSelected = 7;
                lv_label_set_text(scrDiagLabel, "AUTO SELECTED: skills route 2");
                controller.set_text(2, 6, "skillsroute2");
            break;
        }
    }


}