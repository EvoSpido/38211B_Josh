#include "main.h"
#include "ARMS/config.h"

//SPAGHETTI CODE GALORE

int autoSelected;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    stylesInit();
    diagScreen();
    driveInit();
    //arms::init();

    //finish after Vaughn
    //pros::Task odomTask(algorithmMain);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
        
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    
    tabsInit();
    lv_btn_set_state(diagBtn, LV_BTN_STYLE_PR);
    while(true) {
        
        //constantly updates the auto selector descriptions
        
        scrMatchBtnmUpdate();
        scrSkillsBtnmUpdate();
        pros::delay(20);
        
    }

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

    switch (autoSelected) {

        case 1:
            LFullAWP();
        break;
        case 2:
            RFullAWP();
        break;
        case 3:
            SpinRoller();
        break;
        case 4:
            LHalfAWP();
        break;
        case 5:
            RHalfAWP();
        break;
        case 6:
            Skills1();
        break;
        case 7:
            Skills2();
        break;
    }

    lv_obj_clean(lv_layer_top());
    if (lv_btn_get_state(scrDiagDispBtn) == 0) {
    
        cougearsScreen();
    } else if (lv_btn_get_state(scrDiagDispBtn) == 2) {
        
        dispAutoDiag();
    }
    matchTimer(15);
    
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

    pros::Task driveTask(drive);
    pros::Task rollerTask(rollerControl);
    pros::Task slingshotTask(slingshotControl);
    pros::Task intakeTask(spinIntake);
    pros::Task endgameTask(endgameControl);

    if (pros::competition::is_connected()) {

        lv_obj_clean(lv_layer_top());
        if (lv_btn_get_state(scrDiagDispBtn) == 0) {

            cougearsScreen();
        } else if (lv_btn_get_state(scrDiagDispBtn) == 2) {
            
            dispAutoDiag();
        }
        matchTimer(105);
    } 
    
    //enablePID = false;
    //pros::delay(1500);
    //enablePID = true;
    //pros::Task PIDTask(PID);


    //driverScr();
    //ratio bozo
}