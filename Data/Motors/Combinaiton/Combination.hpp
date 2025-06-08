#pragma once

#include "../Motors/Motors_Data.hpp"
#include "../Gearboxes/Gearbox_Data.hpp"
#include <vector>
#include <array>

using namespace std;

vector <string> combination_name;// motor and gear box mame (string)
array<vector <float>, 3> Combination_specs;
// [0]: output torque
// [1]: output speed
// [2]: cost

void Combination_Name();
void calc_output_torque();
void calc_output_speed();
void calc_cost();