#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
controller Controller1;
brain Brain;
competition Competition;

motor FLMotor = motor(PORT20, ratio6_1, false);
motor FRMotor = motor(PORT19, ratio6_1, true);
motor MLMotor = motor(PORT10, ratio6_1, false);
motor MRMotor = motor(PORT1, ratio6_1, true);
motor BLMotor = motor(PORT9, ratio6_1, true);
motor BRMotor = motor(PORT4, ratio6_1, false);

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