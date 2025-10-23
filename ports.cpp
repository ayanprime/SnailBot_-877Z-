#include "main.h"

//main devices
brain Brain;
controller Controller1 = controller(primary);

//motors
motor rmf = motor(PORT19, ratio18_1, false);
motor rmb = motor(PORT20, ratio18_1, false);
motor_group Right = motor_group(rmf, rmb);

motor lmf = motor(PORT12, ratio18_1, true);
motor lmb = motor(PORT11, ratio18_1, true);
motor_group Left = motor_group(lmf, lmb);

motor intake = motor(PORT5, ratio18_1, false);

motor converter = motor(PORT9, ratio18_1, false);

motor conveyor = motor(PORT10, ratio18_1, false);

motor fingerer = motor(PORT8, ratio18_1, false);

//pods
rotation PodLeft = rotation(PORT13, true);
rotation PodRight = rotation(PORT18, false);

