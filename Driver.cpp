#include "main.h"
#include "Driver.hpp"


// change block flow from scoring to going into our storage
// 

int level = 1;

bool curveToggle = true;

bool finger = false;



void curvature() {

    if (curveToggle) {

        Left.setVelocity(((Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0, percent);

        Right.setVelocity(((Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0, percent);
    
    } else {

        Left.setVelocity(Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
        Right.setVelocity(Controller1.Axis3.position() - Controller1.Axis1.position(), percent);

    }


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

void CurveToggle() {

    curveToggle = !curveToggle;

}


void descore() {

    finger = true;

}

void Finger() {

    if (finger == true) {

        fingerer.spinToPosition(360, degrees, false);
        if (fingerer.position(degrees) == 360) {

            fingerer.setStopping(coast);
            fingerer.setPosition(0, degrees);
            finger = false;

        }

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

        intake.spin(reverse);
    
    } else if (level == 2) {

        intake.spin(forward);

    } else if (level == 3) {

        intake.spin(forward);

    }
}



void Default() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    intake.setVelocity(100, percent);
    fingerer.setVelocity(100, percent);

    if (Controller1.ButtonR1.pressing()) {

        Level();
        fingerer.spin(forward);

    } else {

        intake.stop();

    }

    if (Controller1.ButtonR2.pressing()) {

        fingerer.spin(forward);

    } else {

        fingerer.stop();

    }

    Controller1.ButtonL1.pressed(descore);

    Controller1.ButtonA.pressed(CurveToggle);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);

    Finger();
    
}
void Alivia() {

    arcade();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);

}

void Andrew() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);

}

void Ayan() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);

}

void Bennet() {

    arcade();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);
}



void Brian() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);
}

void Connor() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    intake.setVelocity(100, percent);

    if (Controller1.ButtonR1.pressing()) {

        Level();

    } else {

        intake.stop();

    }

    Controller1.ButtonR2.pressed(CurveToggle);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);
}

void Grace() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);
}

void Maria() {

    halo();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonR1.pressed(descore);
}
