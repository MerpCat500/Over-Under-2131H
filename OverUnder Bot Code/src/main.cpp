/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\merpl                                            */
/*    Created:      Wed May 31 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Movement/DriverControl.h"
#include "Screen/Screen.h" 

using namespace vex;

TerminalLogger Terminal = TerminalLogger();

void NONE(){}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Terminal.Log("Start", "Main Started");
  vexcodeInit();
  file(NONE, "NONE", "None", "None", "None");

  file File1 = file(NONE, "NONE", "None", "None", "None");

  folder Root = folder("R", File1);
  // Root.terminalLog();
  Competition.drivercontrol(DriverControl);
  while (true) {
    wait(20, msec); 
  }
}
