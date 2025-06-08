#pragma once

#include <vector>
#include <array>
#include <string>

#define ADD_NEW_MOTOR 1
#define EXIT 0

using namespace std;

//------------- declare the vectors of moter specifications --------------//
// var declerations for the motor specifications
vector <string> motor_name; // 1. motor mame (string)
array<vector <float>, 5> motor_specs;
// [0]: motor_speed
// [1]: motor_torque
// [2]: motor_mass
// [3]: motor_diameter
// [4]: motor_width

int n_motor = 0; // number of motors

void Motor_Initial_Set();
void motor_set();