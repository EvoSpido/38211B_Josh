#include "main.h"

//objects
lv_obj_t* matchBtn;
lv_obj_t* skillsBtn;
lv_obj_t* diagBtn;

//value used by the confirmation screen to tell which tab/selector it is on
//(1 = Match, 2 = Skills)
int tabToggled;


//action to be executed on the press of a tab/btn
lv_res_t btnAction(lv_obj_t * btn) {

    //static variables to store whether a tab is on its first press or not -- initially set to true
    static bool matchFirstPress = true;
    static bool skillsFirstPress = true;
    static bool diagFirstPress = true;

    if(btn == matchBtn) {

        //changes all buttons that arent match to be disabled
        lv_btn_set_state(matchBtn, LV_BTN_STYLE_PR);
        lv_btn_set_state(skillsBtn, LV_BTN_STYLE_REL);
        lv_btn_set_state(diagBtn, LV_BTN_STYLE_REL);
        
        //sets the current tab to Match
        tabToggled = 1;

        //resets the other 2 static variables back to true
        skillsFirstPress = true;
        diagFirstPress = true;

        //if it was the first time pressing the tab, it will execute the following -- will not execute again if the tab were to be pressed again
        if(matchFirstPress) {

            matchSelector();
            matchFirstPress = false;
        }
        
    }

    if(btn == skillsBtn) {
        //changes all buttons that arent skills to be disabled
        lv_btn_set_state(matchBtn, LV_BTN_STYLE_REL);
        lv_btn_set_state(skillsBtn, LV_BTN_STYLE_PR);
        lv_btn_set_state(diagBtn, LV_BTN_STYLE_REL);

        //sets the current tab to Skills
        tabToggled = 2;

        //resets the other 2 static variables back to true
        matchFirstPress = true;
        diagFirstPress = true;

        //if it was the first time pressing the tab, it will execute the following -- will not execute again if the tab were to be pressed again
        if(skillsFirstPress) {

            skillsSelector();
            skillsFirstPress = false;
        }
    }

    if(btn == diagBtn) {
        //changes all buttons that arent diag to be disabled
        lv_btn_set_state(matchBtn, LV_BTN_STYLE_REL);
        lv_btn_set_state(skillsBtn, LV_BTN_STYLE_REL);
        lv_btn_set_state(diagBtn, LV_BTN_STYLE_PR);
        
        //resets the other 2 static variables back to true
        matchFirstPress = true;
        skillsFirstPress = true;

        //if it was the first time pressing the tab, it will execute the following -- will not execute again if the tab were to be pressed again
        if(diagFirstPress) {

            diagScreen();
            diagFirstPress = false;
        }
    }

    return LV_RES_OK;
}


void matchTab() {

    matchBtn = lv_btn_create(lv_layer_top(), NULL); //creates button and puts on top layer
    lv_btn_set_toggle(matchBtn, true); //sets button to be toggleable
    lv_btn_set_action(matchBtn, LV_BTN_ACTION_CLICK, btnAction); //set function to be called on button click
   
    lv_btn_set_style(matchBtn, LV_BTN_STYLE_REL, &matchBtnStyleREL); //set the released style
    lv_btn_set_style(matchBtn, LV_BTN_STYLE_TGL_PR, &matchBtnStylePR); //set the released style
   
    lv_btn_set_style(matchBtn, LV_BTN_STYLE_TGL_REL, &matchBtnStylePR); //set the pressed style
    lv_btn_set_style(matchBtn, LV_BTN_STYLE_PR, &matchBtnStylePR); //set the pressed style
    
    lv_obj_set_size(matchBtn, 160, 30); //set the button size
    lv_obj_align(matchBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0); //set the position to top left
    

    lv_obj_t* matchBtnLabel = lv_label_create(matchBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(matchBtnLabel, "MATCH"); //sets label text

}

void skillsTab() {

    skillsBtn = lv_btn_create(lv_layer_top(), NULL); //creates button and puts on top layer
    lv_btn_set_toggle(skillsBtn, true); //sets button to be toggleable
    lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, btnAction); //set function to be called on button click
   
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_REL, &skillsBtnStyleREL); //set the released style
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_TGL_PR, &skillsBtnStylePR); //set the released style
   
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_TGL_REL, &skillsBtnStylePR); //set the pressed style
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_PR, &skillsBtnStylePR); //set the pressed style
    
    lv_obj_set_size(skillsBtn, 160, 30); //set the button size
    lv_obj_align(skillsBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 160, 0); //set the position to top left
    

    lv_obj_t* skillsBtnLabel = lv_label_create(skillsBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(skillsBtnLabel, "SKILLS"); //sets label text

}

void diagTab() {

    diagBtn = lv_btn_create(lv_layer_top(), NULL); //creates button and puts on top layer
    lv_btn_set_toggle(diagBtn, true); //sets button to be toggleable
    lv_btn_set_action(diagBtn, LV_BTN_ACTION_CLICK, btnAction); //set function to be called on button click
   
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_REL, &diagBtnStyleREL); //set the released style
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_TGL_PR, &diagBtnStylePR); //set the released style
   
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_TGL_REL, &diagBtnStylePR); //set the pressed style
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_PR, &diagBtnStylePR); //set the pressed style
    
    lv_obj_set_size(diagBtn, 160, 30); //set the button size
    lv_obj_align(diagBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 320, 0); //set the position to top left
    

    lv_obj_t* diagBtnLabel = lv_label_create(diagBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(diagBtnLabel, "DIAG"); //sets label text

}


//function to be called when initializing all tabs together 
void tabsInit() {
    matchTab();
    skillsTab();
    diagTab();
}