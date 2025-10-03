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
bool descoreMode = false;



//descore mech callback function
void descoreCallback() {
  descoreMode = !descoreMode;
  if(descoreMode) {
    descore.set(true);
  } else {
    descore.set(false);
  }
}

void pre_auton(void) {

  while(true) {
    screenControl();
  }

}



void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}



void usercontrol(void) {
  // User control code here, inside the loop
  Controller1.Screen.clearScreen();
  while (1) {
    
    //joystick control (robot movement)
    Left.setVelocity(Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
    Right.setVelocity(Controller1.Axis3.position() - Controller1.Axis1.position(), percent);
    Left.spin(forward);
    Right.spin(forward);

    

    //button controls
    Controller1.ButtonB.pressed(descoreCallback);

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
