#include <cmath>
#include <iostream>
#include "..\Header Files\Motors_Class.hpp"

void motor::calc_torque_required ()
{
    double T;
    T = m_l * g *( l /2 ) +( m_p * g * l) + ( m_l * pow((l / 2),2) * alpha_max + m_l * pow(l,2) * alpha_max);
    T_required = T ;
}