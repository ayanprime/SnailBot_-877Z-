#include "main.h"

//main devices
brain Brain;
controller Controller1 = controller(primary);

//motors
motor rmf = motor(PORT1, ratio18_1, false);
motor rmb = motor(PORT2, ratio18_1, false);
motor_group Right = motor_group(rmf, rmb);

motor lmf = motor(PORT3, ratio18_1, true);
motor lmb = motor(PORT4, ratio18_1, true);
motor_group Left = motor_group(lmf, lmb);

motor intake = motor(PORT5, ratio18_1, false);

motor fingerer = motor(PORT8, ratio18_1, false);

//pods
rotation PodLeft = rotation(PORT6, true);
rotation PodRight = rotation(PORT7, false);

//pistons
digital_out rPiston = digital_out(Brain.ThreeWirePort.B);
digital_out lPiston = digital_out(Brain.ThreeWirePort.C);
digital_out trap = digital_out(Brain.ThreeWirePort.D);
