#include "main.h"
#include <Driver.hpp>
#ifndef PI
#define PI 3.14159265358979323846
#endif
double wheelrad = 1.25; //inches
double wheelcirc = 2 * PI * wheelrad; //inches
//hi
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

    double rot = (deg / 360) * (PI * 12.25) / (PI * 3.25);
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
// move 1
    FWD(22.549, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    //move 2
    FWD(7.342, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 3
    FWD(16.75, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 4: intake blocks
    level = 4;
    Level();
    FWD(29, 30);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 5
    FWD(24, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    //move 6
    FWD(17.25, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 7: go to match loader
    stickBenis.set(true);
    Level();
    FWD(10, 30);
    wait(15, sec);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    stickBenis.set(false);
    FWD(-10, 30);
    wait(0.5, sec);
    TRN(180, 30); 
    wait(0.5, sec);
    // move 8: go to score
    FWD(10, 30);
    wait(0.5, sec);
    level = 3;
    Level();

    
    
}

void LRWPauto(){

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
// move 1
    FWD(22.549, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    //move 2
    FWD(7.342, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 3
    FWD(16.75, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 4: intake blocks
    level = 4;
    Level();
    FWD(29, 30);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 5
    FWD(24, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    //move 6
    FWD(17.25, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 7: go to match loader
    stickBenis.set(true);
    Level();
    FWD(10, 30);
    wait(15, sec);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    stickBenis.set(false);
    FWD(-10, 30);
    wait(0.5, sec);
    TRN(180, 30); 
    wait(0.5, sec);
    // move 8: go to score
    FWD(10, 30);
    wait(0.5, sec);
    level = 3;
    Level();



}

void RRWPauto(){
     
    

}

void LBBauto(){

  // move 1
    FWD(22.549, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    //move 2
    FWD(7.342, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 3
    FWD(16.75, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 4: intake blocks
    level = 4;
    Level();
    FWD(29, 30);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 5
    FWD(24, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    //move 6
    FWD(17.25, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    // move 7: go to match loader
    stickBenis.set(true);
    Level();
    FWD(10, 30);
    wait(15, sec);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    stickBenis.set(false);
    FWD(-10, 30);
    wait(0.5, sec);
    TRN(180, 30); 
    wait(0.5, sec);
    // move 8: go to score
    FWD(10, 30);
    wait(0.5, sec);
    level = 3;
    Level();

    

}

void LBWPauto(){

    

}

void RBBauto(){

    // move 1
    FWD(22.549, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    //move 2
    FWD(7.342, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 3
    FWD(16.75, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 4: intake blocks
    level = 4;
    Level();
    FWD(29, 30);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 5
    FWD(24, 30);
    wait(0.5, sec);
    TRN(90, 30);
    wait(0.5, sec);
    //move 6
    FWD(17.25, 30);
    wait(0.5, sec);
    TRN(-90, 30);
    wait(0.5, sec);
    // move 7: go to match loader
    stickBenis.set(true);
    Level();
    FWD(10, 30);
    wait(15, sec);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    stickBenis.set(false);
    FWD(-10, 30);
    wait(0.5, sec);
    TRN(180, 30); 
    wait(0.5, sec);
    // move 8: go to score
    FWD(10, 30);
    wait(0.5, sec);
    level = 3;
    Level();

}

void RBWPauto(){

    

}

void Skillsauto(){
    
    FWD(22.5, 40);
    wait(0.5, sec);
    TRN(-90, 40);
    wait(0.5, sec);
    stickBenis.set(true);
    FWD(10.5, 70);
    wait(0.5, sec);
    level = 4;
    Level();
    FWD(1, 100);
    FWD(-1, 100);
    FWD(1, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    FWD(1.5, 100);
    FWD(-1, 100);
    wait(3, sec);
    top.stop();
    conveyor.stop();
    intake.stop();
    convertor.stop();
    FWD(-10.5, 70);
    stickBenis.set(false);
    wait(0.5, sec);
    TRN(-90, 40);
    wait(0.5, sec);
    FWD(45, 40);

}
