#include "main.h"
#include "Driver.hpp"


// change block flow from scoring to going into our storage
// 

int level = 2;
int transmode = 1;

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

void transdisp() {

    int tms = 0;

    if(tms != transmode) {

        Controller1.Screen.clearLine();

        if(transmode == 1) {

            Controller1.Screen.print("Transmission: STRONG");
        
        } else if(transmode == 2) {

            Controller1.Screen.print("Transmission: FAST");
        
        } else if((transmode != 1) && (transmode != 2)) {

            Controller1.Screen.print("your Transmission BROKE!");
        
        }

        tms = transmode;

    }    

}

void curvature() {

    if (curveToggle) {

        Left.setVelocity((((Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0) * 0.6, percent);

        Right.setVelocity((((Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)) 
/ std::max(1.0, std::max(fabs(Controller1.Axis3.position() / 100.0 + fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0)), 
fabs(Controller1.Axis3.position() / 100.0 - fabs(Controller1.Axis3.position() / 100.0) * (Controller1.Axis1.position() / 100.0))))) * 100.0) * 0.6, percent);
    
        if(Controller1.Axis3.position() == 0) {

            Right.setVelocity(-Controller1.Axis1.position() * 0.6, percent);
            Left.setVelocity(Controller1.Axis1.position() * 0.6, percent);

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

    curvature();
    Left.spin(forward);
    Right.spin(forward);

    Controller1.ButtonR1.pressed(descore);

    Controller1.Screen.setCursor(1, 1);

    batterylvl();

    Controller1.Screen.setCursor(2, 1);

    leveldisp();

    Controller1.Screen.setCursor(3, 1);

    transdisp();

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


    Controller1.ButtonY.pressed(descore);
}

void Brian() {

    arcade();
    Left.spin(forward);
    Right.spin(forward);

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
    
}

void Grace() {

    curvature();
    Left.spin(forward);
    Right.spin(forward);

    Controller1.ButtonR1.pressed(descore);
}

void Maria() {

    intake.setVelocity(100, percent);
    converter.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);

    tank();
    Left.spin(forward);
    Right.spin(forward);

    if(Controller1.ButtonR1.pressing()){

        Level();

    } else {

        intake.stop();
        converter.stop();
        conveyor.stop();

    }

}
