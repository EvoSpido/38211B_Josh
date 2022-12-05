#include "main.h"

//objects
lv_obj_t* scrMatch;
lv_obj_t* scrMatchBtnm;
lv_obj_t* scrMatchLabel;
const char* scrMatchBtnMap[] = {"L Full AWP", "R Full AWP", "Roller", "\n", "L 1/2 AWP", "R 1/2 AWP", "None", ""};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description Update Code
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool scrMatchBtnmPressed = false;

lv_res_t scrMatchBtnmAction(lv_obj_t *, const char *) {
    
    scrMatchBtnmPressed = true;
    return LV_RES_OK;
}

void scrMatchBtnmUpdate() {
    
    if(scrMatchBtnmPressed) {   
        
        uint16_t btnid = lv_btnm_get_toggled(scrMatchBtnm);

        switch (btnid) { //Takes which button is currently toggled on the Btnm and displays the corresponding description
        
            case 0:
                lv_label_set_text(scrMatchLabel, "Completes the full Autonomous Winpoint.\nBegins on the Left side.");
            break;
            case 1:
                lv_label_set_text(scrMatchLabel, "Completes the full Autonomous Winpoint.\nBegins on the Right side.");
            break;
            case 2:
                lv_label_set_text(scrMatchLabel, "Stays in place and spins the roller.");
            break;
            case 3:
                lv_label_set_text(scrMatchLabel, "Completes half of the Autonomous Winpoint.\nBegins on the Left side.");
            break;
            case 4:
                lv_label_set_text(scrMatchLabel, "Completes half of the Autonomous Winpoint.\nBegins on the Right side.");
            break;
            case 5:
                lv_label_set_text(scrMatchLabel, "No Autonomous routine is performed.");
            break;
        }

        scrMatchBtnmPressed = false;
    }
}


void matchSelector() {

    
    scrMatch = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scrMatch, &scrMatchStyle);
    lv_obj_set_size(scrMatch, 480, 240); 

    scrMatchBtnm = lv_btnm_create(scrMatch, NULL);
    lv_btnm_set_style(scrMatchBtnm, LV_BTNM_STYLE_BTN_REL, &scrMatchBtnmStyleREL);
    lv_btnm_set_style(scrMatchBtnm, LV_BTNM_STYLE_BTN_TGL_REL, &scrMatchBtnmStylePR);
    lv_btnm_set_style(scrMatchBtnm, LV_BTNM_STYLE_BTN_PR, &scrMatchBtnmStylePR);
    lv_btnm_set_style(scrMatchBtnm, LV_BTNM_STYLE_BTN_TGL_PR, &scrMatchBtnmStyleREL);
    lv_btnm_set_map(scrMatchBtnm, scrMatchBtnMap);
    lv_btnm_set_toggle(scrMatchBtnm, true, 6);
    lv_btnm_set_action(scrMatchBtnm, scrMatchBtnmAction);
    lv_obj_set_size(scrMatchBtnm, 355, 100);
    lv_obj_align(scrMatchBtnm, scrMatch, LV_ALIGN_CENTER, -50, -25);

    scrMatchLabel = lv_label_create(scrMatch, NULL);
    lv_label_set_style(scrMatchLabel, &scrMatchStyle);
    lv_label_set_text(scrMatchLabel, "No Autonomous routine is performed.");
    lv_label_set_align(scrMatchLabel, LV_LABEL_ALIGN_CENTER);
    lv_label_set_long_mode(scrMatchLabel, LV_LABEL_LONG_BREAK);
    lv_obj_set_width(scrMatchLabel, 440);
    lv_obj_align(scrMatchLabel, scrMatch, LV_ALIGN_IN_LEFT_MID, 20, 70);

    createConfirmBtn(scrMatch, -14, 45);

    lv_scr_load(scrMatch); //loads the match screen
}

