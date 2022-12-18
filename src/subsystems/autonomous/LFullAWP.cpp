#include "ARMS/chassis.h"
#include "main.h"

//ARMS DOCS
//https://arms.readthedocs.io/api/#arms-api

void LFullAWP() {

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

    leftChassis.move(60);
    rightChassis.move(-60);
    pros::delay(500);
    leftChassis.move(0);
    rightChassis.move(0);
    pros::delay(100);
    leftChassis.move(60);
    rightChassis.move(60);
    pros::delay(400);
    leftChassis.move(0);
    rightChassis.move(0);

    slingshot1.move(127);
    slingshot2.move(127);
    pros::delay(300); //delay time between firing and priming
    slingshot1.move(-127);
    slingshot2.move(-127);
    pros::delay(3000); //delay time for how long it should prime
    slingshot1.brake();
    slingshot2.brake();

}