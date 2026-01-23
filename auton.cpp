#include "main.h"
#ifndef PI
#define PI 3.14159265358979323846
#endif
double wheelrad = 1.25; //inches
double wheelcirc = 2 * PI * wheelrad; //inches

double Rerror;
double Lerror;
double Rintegral = 0;
double Lintegral = 0;
double derivative;
double prevRerror = 0;
double prevLerror = 0;
double pwrR;
double pwrL;
double kP = 10;
double kI = 0;
double kD = 0.01;

bool move1 = true;
bool move2 = true;
bool move3 = true;
bool move4 = true;

void FWD(double dis, double spd) {

    double rot = dis / (PI * 3.25);
    Right.setVelocity(spd, percent);
    Left.setVelocity(spd, percent);
    Right.spinFor(rot, turns, false);
    Left.spinFor(rot, turns, true);

}

void TRN(double deg, double spd) {

    double rot = (deg / 360) * (PI * 15.342) / (PI * 3.25);
    Right.setVelocity(spd, percent);
    Left.setVelocity(spd, percent);
    Left.spinFor(-rot, turns, false);
    Right.spinFor(rot, turns, true);

}

double RPIDpwr(double target) {
    Rerror = target - PodRight.position(turns) * wheelcirc;
    Rintegral += Rerror;
    if(Rerror == 0 || Rerror < 0) {
        Rintegral = 0;
    }
    if(Rerror < 0.001 && Rerror > -0.001) {
        Rintegral = 0;
    }
    derivative = Rerror - prevRerror;
    prevRerror = Rerror;
    pwrR = Rerror * kP + Rintegral * kI + derivative * kD;
    return pwrR;
}

double LPIDpwr(double target) {
    Lerror = target - PodRight.position(turns) * wheelcirc;
    Lintegral += Lerror;
    if(Lerror == 0 || Lerror < 0) {
        Lintegral = 0;
    }
    if(Lerror < 0.001 && Lerror > -0.001) {
        Lintegral = 0;
    }
    derivative = Lerror - prevLerror;
    prevLerror = Lerror;
    pwrL = Lerror * kP + Lintegral * kI + derivative * kD;
    return pwrL;

}

void resetPods() {
    
    PodRight.setPosition(0, turns);
    PodLeft.setPosition(0, turns);

}

void LRBauto() {

    intake.setVelocity(100, percent);
    conveyor.setVelocity(100, percent);

    while(move1) {

        Right.setVelocity(RPIDpwr(41.5), percent);
        Left.setVelocity(LPIDpwr(41.5), percent);

        Right.spin(forward);
        Left.spin(forward);

        if(Right.velocity(percent) == 0 && Left.velocity(percent) == 0 && PodRight.position(degrees) != 0) {

            wait(15, msec);


            move1 = false;

        }

    }

    Right.setVelocity(70, percent);
    Left.setVelocity(70, percent);

    Left.spinFor(-0.425, turns, false);
    Right.spinFor(0.425, turns, true);

    Left.spinFor(0.4, turns, false);
    Right.spinFor(0.4, turns, true);

    intake.spin(reverse);

    conveyor.spin(reverse);


    resetPods();
    
}

void RRBauto(){

    intake.setVelocity(100, percent);
    conveyor.setVelocity(70, percent);

    while(move1) {

        Right.setVelocity(RPIDpwr(3.55), percent);
        Left.setVelocity(LPIDpwr(3.55), percent);

        Right.spin(forward);
        Left.spin(forward);

        if(Right.velocity(percent) == 0 && Left.velocity(percent) == 0 && PodRight.position(degrees) != 0 && PodLeft.position(degrees) != 0) {

            wait(15, msec);


            move1 = false;

        }

    }

    Right.setVelocity(70, percent);
    Left.setVelocity(70, percent);

    Left.spinFor(-1.5, turns, false);
    Right.spinFor(1.5, turns, true);

    resetPods();

    while(move2) {

        intake.spin(forward);
        conveyor.spin(forward);

        Right.setVelocity(RPIDpwr(27.15), percent);
        Left.setVelocity(LPIDpwr(27.15), percent);

        Right.spin(forward);
        Left.spin(forward);

        if(Right.velocity(percent) == 0 && Left.velocity(percent) == 0 && PodRight.position(degrees) != 0 && PodLeft.position(degrees) != 0) {

            wait(15, msec);


            move2 = false;

        }

    }

    resetPods();

    while(move3) {

        intake.spin(forward);
        conveyor.spin(forward);

        Right.setVelocity(RPIDpwr(-4.4), percent);
        Left.setVelocity(LPIDpwr(-4.4), percent);

        Right.spin(forward);
        Left.spin(forward);

        if(Right.velocity(percent) == 0 && Left.velocity(percent) == 0 && PodRight.position(degrees) != 0 && PodLeft.position(degrees) != 0) {

            wait(15, msec);


            move3 = false;

        }

    }

    Right.setVelocity(70, percent);
    Left.setVelocity(70, percent);

    Left.spinFor(-0.75, turns, false);
    Right.spinFor(0.75, turns, true);

    resetPods();

    while(move4) {

        intake.spin(reverse);
        conveyor.spin(reverse);

        Right.setVelocity(RPIDpwr(11), percent);
        Left.setVelocity(LPIDpwr(11), percent);

        Right.spin(forward);
        Left.spin(forward);


    }

}

void RBBauto(){

    FWD(5.5, 70);

    wait(1, sec); 

    FWD(-5.5, 60);
    wait(1, sec); 
    TRN(-90, 70); 
    wait(1, sec); 
    TRN(180, 70);
    wait(1, sec); 
    TRN(-90, 10);
}
