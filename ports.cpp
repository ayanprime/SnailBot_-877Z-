#include "main.h"

//main devices
brain Brain;
controller Controller1 = controller(primary);

//motors
motor rmf = motor(PORT1, ratio18_1, true);
motor rmb = motor(PORT2, ratio18_1, true);
motor_group Right = motor_group(rmf, rmb);

motor lmf = motor(PORT3, ratio18_1, false);
motor lmb = motor(PORT4, ratio18_1, false);
motor_group Left = motor_group(lmf, lmb);

//pods
rotation PodLeft = rotation(PORT5, false);
rotation PodRight = rotation(PORT6, true);

//pistons
digital_out descore = digital_out(Brain.ThreeWirePort.A);
