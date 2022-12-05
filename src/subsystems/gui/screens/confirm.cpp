#include "main.h"

lv_obj_t* confirmBtn;
lv_obj_t* confirmBtnLabel;

lv_obj_t* scrConfirm;
lv_obj_t* scrConfirmLabel;
lv_obj_t* scrConfirmBtnY;
lv_obj_t* scrConfirmBtnN;

lv_res_t scrConfirmBtnYAction(lv_obj_t * btn) {

    if (lv_btn_get_state(scrDiagDispBtn) == 0) {

        cougearsScreen();
    } else if (lv_btn_get_state(scrDiagDispBtn) == 2) { 

        diagScreen();
        dispAutoDiag();
    }
    

    return LV_RES_OK;
    
}

lv_res_t scrConfirmBtnNAction(lv_obj_t * btn) {

    if (tabToggled == 1) { //Match
        tabsInit();
        matchSelector();
        lv_btn_set_state(matchBtn, LV_BTN_STYLE_PR);
    }
    
    if (tabToggled == 2) { //Skills
        tabsInit();
        skillsSelector();
        lv_btn_set_state(skillsBtn, LV_BTN_STYLE_PR);
    }

    return LV_RES_OK;
}

lv_res_t confirmBtnAction(lv_obj_t* btn) {

    confirmationScreen();

    return LV_RES_OK;
}


void confirmationScreen() {
    
    lv_obj_clean(lv_layer_top());

    scrConfirm = lv_obj_create(NULL, NULL);
    lv_obj_set_size(scrConfirm, 480, 240);
        
    lv_obj_t* scrConfirmLabel0 = lv_label_create(scrConfirm, NULL);
    lv_label_set_text(scrConfirmLabel0, "ARE YOU SURE?");
    lv_obj_align(scrConfirmLabel0, scrConfirm, LV_ALIGN_CENTER, -5, -90);

    scrConfirmBtnY = lv_btn_create(scrConfirm, NULL);
    lv_btn_set_action(scrConfirmBtnY, LV_BTN_ACTION_CLICK, scrConfirmBtnYAction); //set function to be called on button click
    lv_btn_set_style(scrConfirmBtnY, LV_BTN_STYLE_REL, &scrConfirmBtnYStyleREL); //set the released style
    lv_btn_set_style(scrConfirmBtnY, LV_BTN_STYLE_PR, &scrConfirmBtnYStylePR); //set the pressed style
    lv_obj_set_size(scrConfirmBtnY, 175, 50); //set the button size
    lv_obj_align(scrConfirmBtnY, scrConfirm, LV_ALIGN_CENTER, -86, 60);

    lv_obj_t* scrConfirmBtnYLabel = lv_label_create(scrConfirmBtnY, NULL); //create label and puts it inside of the button
    lv_label_set_text(scrConfirmBtnYLabel, "YES"); //sets label text

    scrConfirmBtnN = lv_btn_create(scrConfirm, NULL);
    lv_btn_set_action(scrConfirmBtnN, LV_BTN_ACTION_CLICK, scrConfirmBtnNAction); //set function to be called on button click
    lv_btn_set_style(scrConfirmBtnN, LV_BTN_STYLE_REL, &scrConfirmBtnNStyleREL); //set the released style
    lv_btn_set_style(scrConfirmBtnN, LV_BTN_STYLE_PR, &scrConfirmBtnNStylePR); //set the pressed style
    lv_obj_set_size(scrConfirmBtnN, 175, 50); //set the button size
    lv_obj_align(scrConfirmBtnN, scrConfirm, LV_ALIGN_CENTER, 86, 60); 

    lv_obj_t* scrConfirmBtnNLabel = lv_label_create(scrConfirmBtnN, NULL); //create label and puts it inside of the button
    lv_label_set_text(scrConfirmBtnNLabel, "NO"); //sets label text

    lv_obj_t* scrConfirmLabel1 = lv_label_create(scrConfirm, NULL);
    lv_label_set_long_mode(scrConfirmLabel1, LV_LABEL_LONG_BREAK);
    lv_label_set_align(scrConfirmLabel1, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_width(scrConfirmLabel1, 440);
    lv_obj_align(scrConfirmLabel1, scrConfirm, LV_ALIGN_CENTER, 0, -60);

    if(tabToggled == 1) { //Match

        lv_obj_set_style(scrConfirm, &scrMatchStyle);
        uint16_t btnid = lv_btnm_get_toggled(scrMatchBtnm);
        
        switch (btnid) {
            case 0:
                lv_label_set_text(scrConfirmLabel1, "Left Full Autonomous Winpoint\n\nCompletes the Full Autonomous Winpoint.\nBegins on the Left side.");
            break;
            case 1:
                lv_label_set_text(scrConfirmLabel1, "Right Full Autonomous Winpoint\n\nCompletes the Full Autonomous Winpoint.\nBegins on the Right side.");
            break;
            case 2:
                lv_label_set_text(scrConfirmLabel1, "Spin Roller\n\nStays in place and spins the roller.");
            break;
            case 3:
                lv_label_set_text(scrConfirmLabel1, "Left 1/2 Autonomous Winpoint\n\nCompletes half of the Autonomous Winpoint.\nBegins on the Left side.");
            break;
            case 4:
                lv_label_set_text(scrConfirmLabel1, "Right 1/2 Autonomous Winpoint\n\nCompletes half of the Autonomous Winpoint.\nBegins on the Right side.");
            break;
            case 5:
                lv_label_set_text(scrConfirmLabel1, "No Autonomous\n\nNo Autonomous routine is performed.");
            break;

        }

    }
    
    if(tabToggled == 2) { //Skills

        lv_obj_set_style(scrConfirm, &scrSkillsStyle);
        uint16_t btnid = lv_btnm_get_toggled(scrSkillsBtnm);
        
        switch (btnid) {
            case 0:
                lv_label_set_text(scrConfirmLabel1, "skills route 1\n\nit does something");
            break;
            case 1:
                lv_label_set_text(scrConfirmLabel1, "skills route 2\n\nit does something again");
            break;

        }

    }

    lv_scr_load(scrConfirm);
}


void createConfirmBtn(lv_obj_t* screen, int x_mod, int y_mod) {
    confirmBtn = lv_btn_create(screen, NULL);
    lv_btn_set_action(confirmBtn, LV_BTN_ACTION_CLICK, confirmBtnAction); //set function to be called on button click
    lv_btn_set_style(confirmBtn, LV_BTN_STYLE_REL, &scrConfirmBtnYStyleREL); //set the released style
    lv_btn_set_style(confirmBtn, LV_BTN_STYLE_PR, &scrConfirmBtnYStylePR); //set the pressed style
    lv_obj_set_size(confirmBtn, 100, 100); //set the button size
    lv_obj_align(confirmBtn, screen, LV_ALIGN_IN_TOP_RIGHT, x_mod, y_mod); //set the position to top right //-13, 45

    confirmBtnLabel = lv_label_create(confirmBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(confirmBtnLabel, "CONFIRM"); //sets label text
}