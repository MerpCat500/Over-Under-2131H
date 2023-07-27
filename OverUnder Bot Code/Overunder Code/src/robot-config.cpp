#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
controller Controller1;
brain Brain;
competition Competition;

motor FLMotor = motor(PORT17, ratio6_1, true);
motor FRMotor = motor(PORT10, ratio6_1, false);
motor MLMotor = motor(PORT15, ratio6_1, true);
motor MRMotor = motor(PORT18, ratio6_1, false);
motor BLMotor = motor(PORT14, ratio6_1, false);
motor BRMotor = motor(PORT20, ratio6_1, true);

motor_group LeftDrive = motor_group(FLMotor, MLMotor, BLMotor);
motor_group RightDrive = motor_group(FRMotor, MRMotor, BRMotor);

motor Puncher = motor(PORT2, ratio18_1, false);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}