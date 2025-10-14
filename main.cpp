/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       877Z                                                      */
/*    Created:      9/27/2025, 3:54:44 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "main.h"

using namespace vex;

competition Competition;

//auton select variable
bool SELECTING = true;



//descore mech callback function
void pre_auton(void) {

  while(SELECTING == true) {
    screenControl();

    if(selected == true) {

      SELECTING = false;

    }
  }
}



void autonomous(void) {
  autonDisplay();
  resetPods();
  if(autonSelected == 1) {

    LRBauto();

  }
}



void usercontrol(void) {

  while (1) {
    if (SELECTING == false){

      driveDisplay();

    }

    if(driver == 0){

      Default();

    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
