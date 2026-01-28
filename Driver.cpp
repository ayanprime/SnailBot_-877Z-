#include "main.h"
#include "Driver.hpp"


// change block flow from scoring to going into our storage
// 

int level = 1;

bool convert = false;

bool trq = false;

bool curveToggle = true;

bool finger = false;

void batterylvl() {

    int x1 = Brain.Battery.capacity();
    int x2 = x1;
    Controller1.Screen.print("Battery: ");
    Controller1.Screen.print(x1);
    Controller1.Screen.print(" percent");

    if (x2 != x1) {

        Controller1.Screen.clearLine();
        x2 = x1;

    }

}

void leveldisp() {

    int lvl = 0;

    if (lvl != level) {

        Controller1.Screen.clearLine();

        if(level == 1) {

            Controller1.Screen.print("Scoring: LOW");

        } else if(level == 2) {

            Controller1.Screen.print("Scoring: MID");

        } else {

            Controller1.Screen.print("Scoring: HI");

        }

        lvl = level;

    }

}

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

void Level() {

    intake.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);
    convertor.setVelocity(100, percent);
    top.setVelocity(100, percent);

    if (level == 1) {
   
        if (convert) {

            convertor.spin(reverse);
            conveyor.setVelocity(50, percent);

        }

        intake.spin(reverse);
        conveyor.spin(reverse);
    
    } else if (level == 2) {

        intake.spin(forward);
        conveyor.spin(forward);
        top.spin(reverse);
        if (convert) {

            convertor.setVelocity(50, percent);
            convertor.spin(reverse);

        } else {

            convertor.spin(forward);

        }

    } else if (level == 3) {

        intake.spin(forward);
        conveyor.setVelocity(50, percent);
        conveyor.spin(forward);
        top.spin(forward);

        if (convert) {

            convertor.setVelocity(50, percent);
            convertor.spin(reverse);

        } else {

            convertor.spin(forward);

        }

    } else if (level == 4) {

        intake.spin(forward);
        conveyor.spin(forward);
        top.setVelocity(50, percent);
        top.spin(forward);

        if (convert) {

            convertor.setVelocity(50, percent);
            convertor.spin(reverse);

        } else {

            convertor.spin(forward);

        }

    }

}

void Default() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);
    intake.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);
    fingerer.setVelocity(100, percent);

    if (Controller1.ButtonR1.pressing()) {

        Level();

    } else {

        intake.stop();
        conveyor.stop();

    }
    
}

void Alivia() {

    arcade();
    Left.spin(forward);
    Right.spin(forward);

    Controller1.ButtonR1.pressed(descore);

}

void Andrew() {

    halo();
    Left.spin(forward);
    Right.spin(forward);

    Controller1.ButtonR1.pressed(descore);

}

void Ayan() {

    Right.setMaxTorque(100, percent);
    Left.setMaxTorque(100, percent);
    
    if (curveToggle) {

        curvature();

    } else {

        halo();

    }

    Left.spin(forward);
    Right.spin(forward);

    if (Controller1.ButtonDown.pressing()) {

        level = 1;

    } else if (Controller1.ButtonRight.pressing()) {

        level = 2;

    } else if (Controller1.ButtonUp.pressing()) {

        level = 3;

    } else if (Controller1.ButtonLeft.pressing()) {

        level = 4;

    } 
    
    if (Controller1.ButtonR1.pressing()) {

        Level();

    } else {

        intake.stop();
        conveyor.stop();
        convertor.stop();
        top.stop();

    }

    Controller1.ButtonR1.pressed(descore);

    Controller1.Screen.setCursor(1, 1);

    batterylvl();

    Controller1.Screen.setCursor(2, 1);

    leveldisp();

    Controller1.Screen.setCursor(3, 1);

}

void Bennet() {

    halo();
    Left.spin(forward);
    Right.spin(forward);

    fingerer.setVelocity(100, percent);
    intake.setVelocity(100, percent);
    conveyor.setVelocity(70, percent);

    if (Controller1.ButtonL2.pressing()) {

        level = 1;
        Level();

    } else if(Controller1.ButtonL1.pressing()){
        
        level = 2;
        Level();

    } else {

        intake.stop();
        conveyor.stop();

    }

    if (finger == true) {

        fingerer.spinFor(24, turns, false);
        finger = false;

    }


    Controller1.ButtonY.pressed(descore);
}

void Brian() {

    Right.setMaxTorque(100, percent);
    Left.setMaxTorque(100, percent);
    arcade();
    Left.spin(forward);
    Right.spin(forward);

    if (Controller1.ButtonR2.pressing()) {

        level = 1;
        Level();

    } else if (Controller1.ButtonR1.pressing()){
        
        level = 2;
        Level();

    } else if (Controller1.ButtonL2.pressing()) {

        level = 3;
        Level();

    } else if (Controller1.ButtonL1.pressing()) {

        level = 4;
        Level();

    } else {

        intake.stop();
        conveyor.stop();
        convertor.stop();
        top.stop();

    }

    if (Controller1.ButtonA.pressing()) {

        convert = false;

    } else if (Controller1.ButtonB.pressing()) {

        convert = true;

    }

    Controller1.ButtonR1.pressed(descore);
}

void Connor() {

    Right.setMaxTorque(100, percent);
    Left.setMaxTorque(100, percent);
    halo();
    Left.spin(forward);
    Right.spin(forward);
    fingerer.setVelocity(100, percent);

    if (Controller1.ButtonL2.pressing()) {

        Level();

    } else {

        intake.stop();
        conveyor.stop();
        convertor.stop();
        top.stop();

    }

    if (Controller1.ButtonDown.pressing()) {

        level = 1;

    } else if (Controller1.ButtonLeft.pressing()){
        
        level = 2;

    } else if (Controller1.ButtonUp.pressing()) {

        level = 3;

    } else if (Controller1.ButtonRight.pressing()) {

        level = 4;

    }

    if (Controller1.ButtonR1.pressing()) {

        convert = false;

    } else if (Controller1.ButtonR2.pressing()) {

        convert = true;

    }

    Controller1.ButtonA.pressed(descore);
    
}

void Grace() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);

    Controller1.ButtonR1.pressed(descore);
}

void Maria() {

    intake.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);

    tank();
    Left.spin(forward);
    Right.spin(forward);

    if(Controller1.ButtonR1.pressing()){

        Level();

    } else {

        intake.stop();
        conveyor.stop();

    }

}
