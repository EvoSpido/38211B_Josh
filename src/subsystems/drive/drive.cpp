#include "main.h"


/////////////////////////////////
//DRIVER CONTROL
/////////////////////////////////


void setDrive(int left, int right) {
    leftChassis.move(left);
    rightChassis.move(right);
}

void drive() {
    
    while (true) {

        //tank code
        /*
        int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        if (abs(leftJoystick) < 10) {
            leftJoystick = 0;
        }
        if (abs(rightJoystick) < 10) {
            rightJoystick = 0;
        }
        setDrive(leftJoystick, rightJoystick);
        */
        
        //split arcade code
        int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        int left = power + turn;
        int right = power - turn;

        setDrive(left, right);

        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {

            endgame.set_value('4095');
        }

        char powerstr[32];
        snprintf(powerstr, 32, "Power: %i", power);
        setDiagText(4, powerstr);

        char turnstr[32];
        snprintf(turnstr, 32, "Turn: %i", turn);
        setDiagText(5, turnstr);

        pros::delay(10);
    }
}


/////////////////////////////////
//INITIALIZE
/////////////////////////////////


void driveInit() {

    //Motor brake modes
    leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    //resetting encoders and IMU
    leftEncoder.reset();
    rightEncoder.reset();
    backEncoder.reset();
    inertial.reset();
    setDiagText(8, "IMU IS CALIBRATING...");
    setDiagText(9, "DO NOT TOUCH!!");
    pros::delay(3000);
    setDiagText(8, "");
    setDiagText(9, "");
}