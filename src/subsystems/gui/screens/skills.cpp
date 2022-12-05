#include "main.h"

//objects
lv_obj_t* scrSkills;
lv_obj_t* scrSkillsBtnm;
lv_obj_t* scrSkillsLabel;
const char* scrSkillsBtnMap[] = {"skills route 1", "skills route 2", ""};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description Update Code
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool scrSkillsBtnmPressed = false;

lv_res_t scrSkillsBtnmAction(lv_obj_t *, const char *) {
    
    scrSkillsBtnmPressed = true;
    return LV_RES_OK;
}

void scrSkillsBtnmUpdate() {
    
    if(scrSkillsBtnmPressed) {   
        
        uint16_t btnid = lv_btnm_get_toggled(scrSkillsBtnm);

        switch (btnid) { //Takes which button is currently toggled on the Btnm and displays the corresponding description
        
            case 0:
                lv_label_set_text(scrSkillsLabel, "it does something");
            break;
            case 1:
                lv_label_set_text(scrSkillsLabel, "it does something again");
            break;
        }

        scrSkillsBtnmPressed = false;
    }
}


void skillsSelector() {

    
    scrSkills = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scrSkills, &scrSkillsStyle);
    lv_obj_set_size(scrSkills, 480, 240); 

    scrSkillsBtnm = lv_btnm_create(scrSkills, NULL);
    lv_btnm_set_style(scrSkillsBtnm, LV_BTNM_STYLE_BTN_REL, &scrSkillsBtnmStyleREL);
    lv_btnm_set_style(scrSkillsBtnm, LV_BTNM_STYLE_BTN_TGL_REL, &scrSkillsBtnmStylePR);
    lv_btnm_set_style(scrSkillsBtnm, LV_BTNM_STYLE_BTN_PR, &scrSkillsBtnmStylePR);
    lv_btnm_set_style(scrSkillsBtnm, LV_BTNM_STYLE_BTN_TGL_PR, &scrSkillsBtnmStyleREL);
    lv_btnm_set_map(scrSkillsBtnm, scrSkillsBtnMap);
    lv_btnm_set_toggle(scrSkillsBtnm, true, 0);
    lv_btnm_set_action(scrSkillsBtnm, scrSkillsBtnmAction);
    lv_obj_set_size(scrSkillsBtnm, 355, 100);
    lv_obj_align(scrSkillsBtnm, scrSkills, LV_ALIGN_CENTER, -50, -25);

    scrSkillsLabel = lv_label_create(scrSkills, NULL);
    lv_label_set_style(scrSkillsLabel, &scrSkillsStyle);
    lv_label_set_text(scrSkillsLabel, "it does something");
    lv_label_set_align(scrSkillsLabel, LV_LABEL_ALIGN_CENTER);
    lv_label_set_long_mode(scrSkillsLabel, LV_LABEL_LONG_BREAK);
    lv_obj_set_width(scrSkillsLabel, 440);
    lv_obj_align(scrSkillsLabel, scrSkills, LV_ALIGN_IN_LEFT_MID, 20, 70);

    createConfirmBtn(scrSkills, -14, 45);

    lv_scr_load(scrSkills); //loads the match screen
}


