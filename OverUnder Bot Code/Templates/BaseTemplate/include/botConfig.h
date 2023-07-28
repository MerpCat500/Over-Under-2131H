#pragma once

using namespace vex;

extern controller Controller1;
extern brain Brain;
extern competition Competition;

extern motor FLMotor;
extern motor FRMotor;
extern motor MLMotor;
extern motor MRMotor;
extern motor BLMotor;
extern motor BRMotor;

extern motor_group LeftDrive;
extern motor_group RightDrive;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);