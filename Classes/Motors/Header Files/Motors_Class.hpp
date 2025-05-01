#pragma once

class motor {
private:
    double T_required = 0;
    float  l, m_l, m_p, alpha_max =(0, 0, 0, 0);
    // l: length of link
    // m_l: link mass
    // m_p: payload mass
    // alpha_max: maximum angular acceleration

    const float g = 9.81;

public:
    motor(float m_p, float alpha_max, float l, float m_l);
    void calc_torque_required();
};
