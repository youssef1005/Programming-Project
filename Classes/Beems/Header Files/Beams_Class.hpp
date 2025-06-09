#pragma once

#include <iostream>
#include <cmath>
#include "..\Header Files\Beams_Class.hpp"

#define CIRCULAR_CHOICE 0 // General for circular choice.
#define RECTANGULAR_CHOICE 1 // General for rectangular choice.

class beam
{
private:
    // requested from user to choose the cross-section
    int choice = CIRCULAR_CHOICE;
    // 0: circular cross-section (circular by defalt).
    // 1: rectangular cross-section.

    // requested from the user directly (has get and set funcs)
    float l, b, h, alpha, m_p = (0, 0, 0, 0, 0);
    // l: beam's length defined for all casses (mm).
    // b: beam's Width (rectangular) (mm).
    // h: beam's Height (rectangular) (mm), beam's Diameter (Circular) (mm).
    // alpha: Maximum angular acceleration (rad / sec^2).
    // m_p: Payload mass (Kg).

    // calculated to get rid of the choices (cross-section properties) (has get func only)
    double v, I = (0, 0);
    // v: volume of the beam (mm^3).
    // i: Second Moment of Inertia for the cross-section  (mm^4).

    double sigma_y, ro, n= (0, 0, 0);
    // sigma_y: is the yield strength of the material (N/mm^2 = Mpa).
    // n: safety factor (unitless).

public:

    // ---------------- Get Functions ----------------
    // implemented in: ../Implementation Files/Beam_Class.cpp

    // gets the choice value to use it deciding wether it is circular or rectangular and to use it in other files:
    // ../../../Main.cpp
    int get_choice();

    // gets the length value to use it in other files:
    // ../../Motors/Implementaion Files/Motors.cpp
    float get_l();

    // gets the payload mass value to use it in other files:
    // ../../Motors/Implementaion Files/Motors.cpp
    float get_m_p();

    // gets the maximum alpha value to use it in other files:
    // ../../Motors/Implementaion Files/Motors.cpp
    float get_alpha();
    // ------------------ End ---------------------

    // -------------------- Set Funcitons ----------------------
    // implemented in: ../Implementation Files/Beam_Class.cpp

    // sets the beam's cross-section type checks if the value is 1 or 0 only(asks the user).
    void set_choice();

    // sets the beam's length value and checks if the value is positive (asks the user).
    void set_l();

    // sets the beam's width (rectangular) value and checks if the value is Positive (asks the user).
    void set_b();

    // sets the beam's height (rectangular), Diameter (Circular) value and checks if the value is Positive (asks the user).
    void set_h();

    // sets the beam's  Payload mass value and checks if the value is Positive (asks the user).
    void set_m_p();

    // sets the beam's Maximum angular acceleration value and checks if the value is Positive (asks the user).
    void set_alpha();

    // sets the safty factor value and checks if the value is bigger than 1 (asks the user).
    void set_n();
    // ------------------ End ---------------------

    // ---------------- Beam's Stress Optimizer ----------------
    // implemented in: ../Implementation Files/Stress_Optimizer.cpp

    // takes the dimensions according to the choice of 0: circular, 1: rectangular.
    // and outputs it in the volume (mm^3).
    void beam_volume();

    // takes the dimension according to the choice of 0: circular, 1: rectangular.
    // and outputs it in the Moment of Inertia (mm^4).
    void beam_moment_of_inertia();

    // calculates the beam's mass (Kg).
    double beam_mass();

    // calculates the bending moment (N.m).
    double bending_moment();

    // calculates the Inertial force due to angular acceleration (N).
    double Inertial_force();

    // calculates the beam's stress (Mpa).
    double beam_stress();

    // optimizer that changes the dimensions of the beam and recaculate the stress.
    // gives:
    // the optimized dimensions of the beam.
    // the optimized stress of the beam.
    // the mass of the beam.
    double beam_stress_optimizer();
    // ---------------- End ----------------

    // ----------- Material Selection -----------
    // implemented in: ../Implementation Files/Material_Selection.cpp

    void Mat_Sel();
    // ------------------ End ------------------
};
