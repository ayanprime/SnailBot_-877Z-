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
double kP = 18;
double kI = 0.000004;
double kD = 0.07;

bool move1 = true;

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
    
    PodRight.setPosition(0, degrees);
    PodLeft.setPosition(0, degrees);

}

void LRBauto() {

    while(move1) {

        Right.setVelocity(RPIDpwr(24), percent);
        Left.setVelocity(LPIDpwr(24), percent);

        Right.spin(forward);
        Left.spin(forward);

    }

}
