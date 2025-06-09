#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <array>
#include "../../Beems/Header Files/Beams_Class.hpp"

// Motor
#define ADD_NEW_MOTOR 1
#define EXIT 0

// Gearbox
#define ADD_NEW_GEARBOX 1
#define EXIT 0

using namespace std;

class motor {
private:
    // beam's porperties inherited from beam class
    // to use:-
    // get_l(): length of link
    // beam_mass(): link mass
    // get_m_p(): payload mass
    // get_alpha(): maximum angular acceleration
    float l, m_p, alpha_max = (0, 0, 0);
    double m_l = 0;

    float speed_required, torque_motor, efficency = (0, 0, 0);
    double T_required = 0;

    //------------- Error ------------------
    float w_output; // error for w_output you have to check its value
    const float g = 9.81;

    // Motors
    // var declerations for the motor specifications
    vector <string> motor_name; // 1. motor mame (string)
    array<vector <float>, 5> motor_specs;
    // [0]: motor_speed
    // [1]: motor_torque
    // [2]: motor_mass
    // [3]: motor_diameter
    // [4]: motor_width
    int n_motor = 0; // number of motors
    
    // Gearbox
    // var declerations for the gear bix specifications
    vector <string> gear_name; // 1. gear box mame (string)
    array<vector <float>, 5> gear_specs;
    // [0]: gear_ratio
    // [1]: gear_effiency
    // [2]: gear_mass
    // [3]: gear bore diameter
    // [4]: gear_width
    int n_gear = 0; // number of motors

    // Combination
    vector <string> combination_name;// motor and gear box mame (string)
    array <vector <float>, 3> Combination_specs;
    // [0]: output torque
    // [1]: output speed
    // [2]: cost

public:
    motor(float len, float mass_p, float al_max, double mass_l);

    // Motors Functions
    void Motor_Initial_Set();
    void motor_set();

    // Gearbox Functions
    void Gearbox_Initial_Set();
    void Gearbox_add();

    // Combination Functions
    void Combination_Name();
    void calc_output_torque();
    void calc_output_speed();
    void calc_cost();

    // Overall For Selection and sorting
    void calc_speed_required();
    void calc_torque_required();
    void sortvector();
    void selection();
};
