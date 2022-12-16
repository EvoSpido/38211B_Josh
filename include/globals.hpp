#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "okapi/impl/device/rotarysensor/adiEncoder.hpp"

using namespace pros;

/////////////////////////////////
//DEVICES
/////////////////////////////////

//controller
extern Controller controller;

// # means number of motor (MAX 8 MOTORS)
// ":#" means port number

//drivetrain motors
extern Motor leftFront; //1 :1
extern Motor rightFront; //2 :2
extern Motor_Group leftChassis;
extern Motor leftBack; //3 :3
extern Motor rightBack; //4 :4
extern Motor_Group rightChassis;

extern Motor slingshot1; //6 :6
extern Motor slingshot2; //7 :7
extern Motor roller; //8 :9
extern Motor intake; //5 :10

extern ADIEncoder leftEncoder; //:A+B 
extern ADIEncoder rightEncoder; //:C+D 
extern ADIEncoder backEncoder; //:E+F 

extern Imu inertial; //:5

extern ADIDigitalOut endgame; //:H

/////////////////////////////////
//GLOBAL VARIABLES
/////////////////////////////////

extern bool enablePID; //drive.cpp
extern bool resetMotors; //drive.cpp
extern bool rejectDisks; //slingshot.cpp

extern int autoSelected; //gui.cpp