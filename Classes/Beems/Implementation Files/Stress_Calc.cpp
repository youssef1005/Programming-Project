#include "..\Header Files\Beams_Class.hpp"
#include <cmath>

// takes the dimensions according to the choice of 0: circular, 1: rectangular.
// and outputs it in the volume (mm^3).
void beam::beam_volume()
{
    if (choice == CIRCULAR_CHOICE)
    {
        v = l * M_PI * ( h * h ) / 4.0;
    }
    else if (choice == RECTANGULAR_CHOICE)
    {
        v = l * b * h;
    }
}

// takes the dimension according to the choice of 0: circular, 1: rectangular.
// and outputs it in the Moment of Inertia (mm^4).
void beam::beam_moment_of_inertia()
{
    if (choice == CIRCULAR_CHOICE)
    {
        I = ( M_PI * pow(h / 2, 4) ) / 4;
    }
    else if (choice == RECTANGULAR_CHOICE)
    {
        I = ( b * pow(h, 3) ) / 12;
    }
}

// calculates the beam's mass (Kg).
// inputs:
// ro: density of the beam (unit not defined yet).
double beam::beam_mass()
{
    double mass = v * ( pow(10, -9) ) * ro; // the 10 ^-9 to convert mm^3 to m^3
    return mass;
}

// calculates the bending moment (N.m).
double beam::bending_moment()
{
    double m = beam_mass();
    double M = m * 9.81 * (l / 2) + (m_p * 9.81 * l) + (m * pow((l / 2), 2) * alpha + m_p * pow(l, 2) * alpha);
    return M;
}

// calculates the Inertial force due to angular acceleration (N).
double beam::Inertial_force()
{     
    double acc = alpha * l;
    return beam::beam_mass() * acc;
}
// ---------------- end ----------------

// ---------------- Stress Calculations ---------------------

// calculates the beam's stress (Mpa).
double beam::beam_stress()
{
    beam::beam_volume();
    beam::beam_moment_of_inertia();
    beam::Inertial_force();
    double stress = (beam::bending_moment() * h) / (2 * I); // in N/mm^2 = Mpa
    
    return stress;
}