#include "main.h"

//ARMS DOCS
//https://arms.readthedocs.io/api/#arms-api

void SpinRoller() {
    
    leftChassis.move(-127);
    rightChassis.move(-127);
    pros::delay(100);
    leftChassis.move(0);
    rightChassis.move(0);
    roller.move(-70);
    pros::delay(1500);
    roller.brake();
    pros::delay(500);
    leftChassis.move(127);
    rightChassis.move(127);
    pros::delay(250);
    leftChassis.move(0);
    rightChassis.move(0);

}