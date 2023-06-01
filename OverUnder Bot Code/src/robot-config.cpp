#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller;
                  
/**               _
 *  _____       (_)
 * | ___ \ _  __ _ _    __ _____
 * | |  | | / ___|| \  / /  __  \
 * | |__| |  /  | |\ \/ / |_____/
 * |_____/|_|   |_| \__/ \______/
 *
 */ 

motor LeftFront = motor(PORT7);
motor LeftMid = motor(PORT4);
motor LeftBack = motor(PORT3, true);

motor_group LeftDrive = motor_group(LeftFront, LeftMid, LeftBack);

motor RightFront = motor(PORT5, true);
motor RightMid = motor(PORT1, true);
motor RightBack = motor(PORT9, false);

motor_group RightDrive = motor_group(RightFront, RightMid, RightBack);


/** 
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}