#include "main.h"
#include "Driver.hpp"


// change block flow from scoring to going into our storage
// 

int level = 2;

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
    
        if(Controller1.Axis3.position() == 0) {

            Right.setVelocity(-Controller1.Axis1.position(), percent);
            Left.setVelocity(Controller1.Axis1.position(), percent);

        }

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

void descore() {

    finger = true;

}

void levelUP() {

    if (level < 3) {
    
        level++;
        wait(300, msec);
    
    }

}

void levelDOWN() {

    if (level > 1) {
    
        level--;
        wait(1, sec);
    
    }

}

void Level() {

    if(level == 1) {

        intake.spin(reverse);
        converter.spin(reverse);
        conveyor.spin(reverse);
        top.spin(reverse);
    
    } else if (level == 2) {

        intake.spin(forward);
        converter.spin(forward);
        conveyor.spin(forward);
        top.spin(reverse);


    } else if (level == 3) {

        intake.spin(forward);
        converter.spin(forward);
        conveyor.spin(forward);
        top.spin(forward);

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

    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    
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

    halo();
    Left.spin(forward);
    Right.spin(forward);

    fingerer.setVelocity(100, percent);
    intake.setVelocity(100, percent);
    conveyor.setVelocity(70, percent);
    converter.setVelocity(100, percent);
    top.setVelocity(100, percent);

    if (Controller1.ButtonL2.pressing()) {

        level = 1;
        Level();

    } else if(Controller1.ButtonL1.pressing()){
        
        level = 2;
        Level();

    } else {

        intake.stop();
        converter.stop();
        conveyor.stop();
        top.stop();

    }

    if (finger == true) {

        fingerer.spinFor(24, turns, false);
        finger = false;

    }

    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    Controller1.ButtonY.pressed(descore);
}

void Brian() {

    arcade();
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
    fingerer.setVelocity(100, percent);
    intake.setVelocity(100, percent);
    conveyor.setVelocity(70, percent);
    converter.setVelocity(100, percent);
    top.setVelocity(100, percent);

    if (Controller1.ButtonR1.pressing()) {

        Level();

    } else {

        intake.stop();
        converter.stop();
        conveyor.stop();
        top.stop();

    }

    if (finger == true) {

        fingerer.spinFor(24, turns, false);
        finger = false;

    }

    Controller1.ButtonA.pressed(descore);

    //Levels 
    Controller1.ButtonDown.pressed(levelDOWN);
    Controller1.ButtonUp.pressed(levelUP);
    
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

    intake.setVelocity(100, percent);
    converter.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);

    tank();
    Left.spin(forward);
    Right.spin(forward);
    //Levels 
    Controller1.ButtonL2.pressed(levelDOWN);
    Controller1.ButtonL1.pressed(levelUP);
    if(Controller1.ButtonR1.pressing()){

        Level();

    } else {

        intake.stop();
        converter.stop();
        conveyor.stop();

    }

}
