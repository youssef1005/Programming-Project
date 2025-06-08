#pragma once
#include <vector>
#include <array>
#include <string>
#include "../../Beems/Header Files/Beams_Class.hpp"
#include "../../../Data/Motors/Motors/Motors_Data.hpp"
#include "../../../Data/Motors/Gearboxes/Gearbox_Data.hpp"
#include "../../../Data/Motors/Combinaiton/Combination.hpp"


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

public:
    motor(float len, float mass_p, float al_max, double mass_l);
    void calc_speed_required();
    void calc_torque_required();
    void sortvector();
    void selection();
};
