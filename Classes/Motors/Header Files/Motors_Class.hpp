#pragma once
#include <vector>
#include <array>
#include "../../Beems/Header Files/Beams_Class.hpp"

class motor {
private:
    beam *a;
    // beam's porperties inherited from beam class
    // to use:-
    // get_l(): length of link
    // beam_mass(): link mass
    // get_m_p(): payload mass
    // get_alpha(): maximum angular acceleration

    float speed_required, torque_motor, efficency = (0, 0, 0);

    double T_required = 0;

    int n_motor = 0; // number of motors
    int n_gear = 0; // number of gear boxes

    //------------- declare the vectors of moter specifications --------------//
    // var declerations for the motor specifications
    vector <string> motor_name; // 1. motor mame (string)
    array<vector <float>, 5> motor_specs;
    // [0]: motor_speed
    // [1]: motor_torque
    // [2]: motor_mass
    // [3]: motor_diameter
    // [4]: motor_width

    
    //------------- declare the vectors of gear box specifications --------------//
    // var declerations for the gear bix specifications
    vector <string> gear_name; // 1. gear box mame (string)
    array<vector <float>, 5> gear_specs;
    // [0]: gear_ratio
    // [1]: gear_effiency
    // [2]: gear_mass
    // [3]: gear_diameter
    // [4]: gear_width

    //------------- declare the vectors of output specifications --------------//

    vector <float> output_torque; // 1. output torque (Nm)
    vector <float> output_speed; // 2. output speed (rpm)
    vector <string> combination_name; // 3. motor and gear box mame (string)
    vector <float> cost;

    //------------- Error ------------------
    float w_output; // error for w_output you have to check its value
    const float g = 9.81;

public:
    void calc_torque_required();
    void motor_gearbox_sel();
    void speed();
    vector <float> motor_set();
    void gear_set();
    void calc_torque_required();
    void calc_output_torque();
    void calc_output_speed();
    void calc_cost();
    void sortvector();
    void selection();
    vector <vector<float>> get_motor_name();
};
