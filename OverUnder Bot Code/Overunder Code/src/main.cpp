/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Hilton 2131H                                       */
/*    Created:      Mon Jul 10 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Screen.h"
#include "DriverControl.h"

using namespace vex;

Screen ScreenSel;

int main() 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Competition.drivercontrol(DriverControl);

  ScreenSel.Draw();

  while(1)
  { 
   
    ScreenSel.Update();
    wait(20, msec);
  }
}
