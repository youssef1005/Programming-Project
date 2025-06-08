#pragma once

#include <vector>
#include <array>
#include <string>


#define ADD_NEW_GEARBOX 1
#define EXIT 0

using namespace std;

//------------- declare the vectors of gear box specifications --------------//
// var declerations for the gear bix specifications
vector <string> gear_name; // 1. gear box mame (string)
array<vector <float>, 5> gear_specs;
// [0]: gear_ratio
// [1]: gear_effiency
// [2]: gear_mass
// [3]: gear_diameter
// [4]: gear_width

int n_gear = 0; // number of motors

void Gearbox_Initial_Set();
void Gearbox_add();