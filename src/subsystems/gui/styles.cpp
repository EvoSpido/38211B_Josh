#include "main.h"

//////////////
//TAB STYLES//
//////////////
lv_style_t matchBtnStylePR;
lv_style_t matchBtnStyleREL;
lv_style_t skillsBtnStylePR;
lv_style_t skillsBtnStyleREL;
lv_style_t diagBtnStylePR;
lv_style_t diagBtnStyleREL;

///////////////////
//scrMatch STYLES//
///////////////////
lv_style_t scrMatchStyle;
lv_style_t scrMatchBtnmStylePR;
lv_style_t scrMatchBtnmStyleREL;

////////////////////
//scrSkills STYLES//
////////////////////
lv_style_t scrSkillsStyle;
lv_style_t scrSkillsBtnmStylePR;
lv_style_t scrSkillsBtnmStyleREL;

//////////////////
//scrDiag STYLES//
//////////////////
lv_style_t scrDiagStyle;

/////////////////////
//scrConfirm STYLES//
/////////////////////
lv_style_t scrConfirmBtnYStylePR;
lv_style_t scrConfirmBtnYStyleREL;
lv_style_t scrConfirmBtnNStylePR;
lv_style_t scrConfirmBtnNStyleREL;

//////////////////////
//scrCougears STYLES//
//////////////////////
lv_style_t scrCougearsStyle;


//function to be called to initialize/set all styles
void stylesInit() {

    //////////////
    //TAB STYLES//
    //////////////

    //matchBtnStylePR
    lv_style_copy(&matchBtnStylePR, &lv_style_plain); 
    matchBtnStylePR.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    matchBtnStylePR.body.grad_color = LV_COLOR_MAKE(87, 168, 250);
    matchBtnStylePR.body.radius = 0;
    matchBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //matchBtnStyleREL
    lv_style_copy(&matchBtnStyleREL, &lv_style_plain);
    matchBtnStyleREL.body.main_color = LV_COLOR_MAKE(0, 120, 250);
    matchBtnStyleREL.body.grad_color = LV_COLOR_MAKE(0, 120, 250);
    matchBtnStyleREL.body.radius = 0;
    matchBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    //skillsBtnStylePR
    lv_style_copy(&skillsBtnStylePR, &lv_style_plain);
    skillsBtnStylePR.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    skillsBtnStylePR.body.grad_color = LV_COLOR_MAKE(255, 150, 150);
    skillsBtnStylePR.body.radius = 0;
    skillsBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //skillsBtnStyleREL
    lv_style_copy(&skillsBtnStyleREL, &lv_style_plain);
    skillsBtnStyleREL.body.main_color = LV_COLOR_MAKE(0, 120, 250);
    skillsBtnStyleREL.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    skillsBtnStyleREL.body.radius = 0;
    skillsBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    //diagBtnStylePR
    lv_style_copy(&diagBtnStylePR, &lv_style_plain);
    diagBtnStylePR.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    diagBtnStylePR.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    diagBtnStylePR.body.radius = 0;
    diagBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);
    
    //diagBtnStyleREL
    lv_style_copy(&diagBtnStyleREL, &lv_style_plain);
    diagBtnStyleREL.body.main_color = LV_COLOR_MAKE(79, 79, 79);
    diagBtnStyleREL.body.grad_color = LV_COLOR_MAKE(79, 79, 79);
    diagBtnStyleREL.body.radius = 0;
    diagBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);


    ///////////////////
    //scrMatch STYLES//
    ///////////////////

    //scrMatchStyle
    lv_style_copy(&scrMatchStyle, &lv_style_plain);
    scrMatchStyle.text.color = LV_COLOR_MAKE(0, 0, 0);
    scrMatchStyle.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    scrMatchStyle.body.grad_color = LV_COLOR_MAKE(87, 168, 250);

    //scrMatchBtnmStylePR
    lv_style_copy(&scrMatchBtnmStylePR, &lv_style_plain);
    scrMatchBtnmStylePR.body.main_color = LV_COLOR_MAKE(200, 200, 200);
    scrMatchBtnmStylePR.body.grad_color = LV_COLOR_MAKE(200, 200, 200);
    scrMatchBtnmStylePR.body.radius = 0;
    scrMatchBtnmStylePR.body.border.width = 2;
    scrMatchBtnmStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrMatchBtnmStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //scrMatchBtnmStyleREL
    lv_style_copy(&scrMatchBtnmStyleREL, &lv_style_plain);
    scrMatchBtnmStyleREL.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scrMatchBtnmStyleREL.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scrMatchBtnmStyleREL.body.radius = 0;
    scrMatchBtnmStyleREL.body.border.width = 2;
    scrMatchBtnmStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrMatchBtnmStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);


    ////////////////////
    //scrSkills STYLES//
    ////////////////////

    //scrSkillsStyle
    lv_style_copy(&scrSkillsStyle, &lv_style_plain);
    scrSkillsStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    scrSkillsStyle.body.main_color = LV_COLOR_MAKE(255, 150, 150);
    scrSkillsStyle.body.grad_color = LV_COLOR_MAKE(255, 150, 150);

    //scrSkillsBtnmStylePR
    lv_style_copy(&scrSkillsBtnmStylePR, &lv_style_plain);
    scrSkillsBtnmStylePR.body.main_color = LV_COLOR_MAKE(200, 200, 200);
    scrSkillsBtnmStylePR.body.grad_color = LV_COLOR_MAKE(200, 200, 200);
    scrSkillsBtnmStylePR.body.radius = 0;
    scrSkillsBtnmStylePR.body.border.width = 2;
    scrSkillsBtnmStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrSkillsBtnmStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //scrSkillsBtnmStyleREL
    lv_style_copy(&scrSkillsBtnmStyleREL, &lv_style_plain);
    scrSkillsBtnmStyleREL.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scrSkillsBtnmStyleREL.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scrSkillsBtnmStyleREL.body.radius = 0;
    scrSkillsBtnmStyleREL.body.border.width = 2;
    scrSkillsBtnmStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrSkillsBtnmStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);


    //////////////////
    //scrDiag STYLES//
    //////////////////

    //scrDiagStyle
    lv_style_copy(&scrDiagStyle, &lv_style_plain);
    scrDiagStyle.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scrDiagStyle.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scrDiagStyle.body.radius = 0;
    scrDiagStyle.text.color = LV_COLOR_MAKE(0, 0, 0);


    /////////////////////
    //scrConfirm STYLES//
    /////////////////////

    //scrConfirmBtnYStylePR
    lv_style_copy(&scrConfirmBtnYStylePR, &lv_style_plain);
    scrConfirmBtnYStylePR.body.main_color = LV_COLOR_MAKE(0, 255, 0);
    scrConfirmBtnYStylePR.body.grad_color = LV_COLOR_MAKE(0, 255, 0);
    scrConfirmBtnYStylePR.body.radius = 0;
    scrConfirmBtnYStylePR.body.border.width = 2;
    scrConfirmBtnYStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrConfirmBtnYStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //scrConfirmBtnYStyleREL
    lv_style_copy(&scrConfirmBtnYStyleREL, &lv_style_plain);
    scrConfirmBtnYStyleREL.body.main_color = LV_COLOR_MAKE(0, 200, 0);
    scrConfirmBtnYStyleREL.body.grad_color = LV_COLOR_MAKE(0, 200, 0);
    scrConfirmBtnYStyleREL.body.radius = 0;
    scrConfirmBtnYStyleREL.body.border.width = 2;
    scrConfirmBtnYStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrConfirmBtnYStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    //scrConfirmBtnNStylePR
    lv_style_copy(&scrConfirmBtnNStylePR, &lv_style_plain);
    scrConfirmBtnNStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    scrConfirmBtnNStylePR.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    scrConfirmBtnNStylePR.body.radius = 0;
    scrConfirmBtnNStylePR.body.border.width = 2;
    scrConfirmBtnNStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrConfirmBtnNStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    //scrConfirmBtnNStyleREL
    lv_style_copy(&scrConfirmBtnNStyleREL, &lv_style_plain);
    scrConfirmBtnNStyleREL.body.main_color = LV_COLOR_MAKE(200, 0, 0);
    scrConfirmBtnNStyleREL.body.grad_color = LV_COLOR_MAKE(200, 0, 0);
    scrConfirmBtnNStyleREL.body.radius = 0;
    scrConfirmBtnNStyleREL.body.border.width = 2;
    scrConfirmBtnNStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scrConfirmBtnNStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    //scrCougearsStyle
    lv_style_copy(&scrCougearsStyle, &lv_style_plain);
    scrCougearsStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    


    
}