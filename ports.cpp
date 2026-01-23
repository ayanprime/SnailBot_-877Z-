#include "main.h"

//main devices
brain Brain;
controller Controller1 = controller(primary);

//motors
motor rmf = motor(PORT10, ratio18_1, false);
motor rmb = motor(PORT20, ratio18_1, false);
motor_group Right = motor_group(rmf, rmb);

motor lmf = motor(PORT1, ratio18_1, true);
motor lmb = motor(PORT11, ratio18_1, true);
motor_group Left = motor_group(lmf, lmb);

motor intake = motor(PORT19, ratio18_1, false);
motor conveyor = motor(PORT9, ratio18_1, true);
motor convertor = motor(PORT2, ratio18_1, false);
motor top = motor(PORT12, ratio18_1, false);

motor fingerer = motor(PORT13, ratio18_1, false);

//pods
rotation PodLeft = rotation(PORT13, false);
rotation PodRight = rotation(PORT15, false);
