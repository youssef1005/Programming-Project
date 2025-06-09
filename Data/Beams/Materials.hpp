#pragma once

#include <iostream>
#include <vector>
#include <array>

#define ADD_NEW_MATERIAL 0
#define SURE 0

using namespace std;

// variables are made general to be permenet so if the user wants to use it again
// ------- Variable decleration ------

// the position of the last added value (0 is just a dummy value it will be updated once the material selection function runs)
int last_added_mat = 0;

// counts the number of materials
vector <int> ch_mat(12);

// Material name
vector <string> name_mat(12);

// For Yield Strength (MPa) and Density (Kg/m^3) (In that order) 
vector <array<float, 2>> sp_mat(12);

// ------- end -------

// ------- Function Decleratoin ------

// puts the built-in set of materials
void Material_Initial_Set();

// fills the data in the material lists
void material_add();

// ------- end -------