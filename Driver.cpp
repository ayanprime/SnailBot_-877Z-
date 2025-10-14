#include "main.h"
#include "Driver.hpp"


// change block flow from scoring to going into our storage
// 

int level = 1;

void curvature() {

    Left.setVelocity(((Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0, percent);

    Right.setVelocity(((Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0, percent);

}

void halo() {

    Left.setVelocity(Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
    Right.setVelocity(Controller1.Axis3.position() - Controller1.Axis1.position(), percent);

}

void arcade() {

    Left.setVelocity(Controller1.Axis3.position() + Controller1.Axis4.position(), percent);
    Right.setVelocity(Controller1.Axis3.position() - Controller1.Axis4.position(), percent);

}

void tank() {

    Left.setVelocity(Controller1.Axis3.position(), percent);
    Right.setVelocity(Controller1.Axis2.position(), percent);

}

void hopper() {

    if(rPiston.value() == true && lPiston.value() == true) {

        rPiston.set(false); 
        lPiston.set(false);
    } else if(rPiston.value() == true && lPiston.value() == true) {
        rPiston.set(true); 
        lPiston.set(true);
    }

}

void descorecatch() {

    if (trap.value() == true) {

        trap.set(false);
    } else if (trap.value() == false) {
        trap.set(true);
    }


}

void descoreSetting() {

    if (descore.value() == true) {
        
        descore.set(false);
    
    } else if (descore.value() == false) {
        
        descore.set(true);
    
    }

}

void levelUP() {

    if (level < 3) {
    
        level++;
    
    }

}

void levelDOWN() {

    if (level > 1) {
    
        level--;
    
    }

}

void Level() {

    if(level == 1) {

        intake.setVelocity(100, percent);
        intake.spin(reverse);
    
    } else if (level == 2) {

        intake.setVelocity(100, percent);
        intake.spin(forward);

    } else if (level == 3) {



    } else {

        intake.stop();

    }
}



void Default() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    if (Controller1.ButtonR1.pressing() == true) {

        Level();

    } 
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
    
}
void Alivia() {

    arcade();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);

}

void Andrew() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);

}

void Ayan() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);

}

void Bennet() {

    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
}

void Brian() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
}

void Connor() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
}

void Grace() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
}

void Maria() {

    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descoreSetting);
    Controller1.ButtonR2.pressed(descorecatch);
    Controller1.ButtonL1.pressed(hopper);
}
