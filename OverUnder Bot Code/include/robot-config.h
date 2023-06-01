#pragma once
using namespace vex;

extern brain Brain;
extern controller Controller;

extern motor LeftFront;
extern motor LeftMid;
extern motor LeftBack;

extern motor_group LeftDrive;

extern motor RightFront;
extern motor RightMid;
extern motor RightBack;

extern motor_group RightDrive;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
