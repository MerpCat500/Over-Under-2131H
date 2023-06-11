#pragma once
using namespace vex;

extern brain Brain;
extern controller Controller;
extern competition Competition;

extern motor LeftFront;
extern motor LeftMid;
extern motor LeftBack;

extern motor_group LeftDrive;

extern motor RightFront;
extern motor RightMid;
extern motor RightBack;

extern motor_group RightDrive;
extern motor_group AllDriveMotors;

extern motor Puncher;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
