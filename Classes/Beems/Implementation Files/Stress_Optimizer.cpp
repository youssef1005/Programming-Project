#include "..\Header Files\Beams_Class.hpp"

using namespace std;

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

// ---------------- end ----------------

// ---------------- Stress Calculations ---------------------

// calculates the beam's stress (Mpa).
double beam::beam_stress()
{
    beam::beam_volume();
    beam::beam_moment_of_inertia();

    return (beam::bending_moment() * h) / (2 * I);// in N/mm^2 = Mpa
}

// optimizer that changes the dimensions of the beam and recaculate the stress.
// gives:
// the optimized dimensions of the beam.
// the optimized stress of the beam.
// the mass of the beam.
double beam::beam_stress_optimizer()
{
    double op_stress = beam::beam_stress(); // the original stress.

    do
    {
        if (op_stress >= (sigma_y / n))
        {

            cout << "\nThe beam's stress is: " << op_stress << " MPa\nwhich is higher than the allowable stress.\n";

            while (op_stress >= (sigma_y / n)) // incase the data from user is not suitable for the material then it will increase the dimensions.
            {
                h = h + 0.01 * h; // increase the height by 1 & to get the lower stress.
                b = b + 0.01 * b; // increase the width by 1 & to get the lower stress. (incase of rectangular cross-section).
                op_stress = beam::beam_stress();
            }

            if (choice == CIRCULAR_CHOICE)
            {
                cout << "So the dimensions need to be increased to: " << h << " mm\n";
            }
            else if (choice == RECTANGULAR_CHOICE)
            {
                cout << "So the dimensions need to be increased to: \nThe beam's width is: " << b << " mm\n" << "The beam's height is: " << h << " mm\n";
            }
        }

        if (op_stress <= (sigma_y / n) * (0.9)) // asks the user if he wants to optimize the beam's dimensions or not.
        {
            char opt;
            cout << "The stress is pretty low so\n";
            cout << "Do you want to optimize the beam's dimensions? if not press (n/N): ";
            cin >> opt;

            if (opt == 'n' || opt =='N') // if no it will give teh beam's data and exit the function
            {
                if (choice == CIRCULAR_CHOICE)
                {
                    cout << "\nThe beam's stress is: " << op_stress << " MPa\nthe dimensions need to be increased to: " << h << " mm\n" << "the beam's mass will be: " << beam::beam_mass() << " Kg\n";
                }
                else if (choice == RECTANGULAR_CHOICE)
                {
                    cout << "\nThe beam's stress is: " << op_stress << " MPa\nthe dimensions need to be increased to: \nThe beam's width is: " << b << " mm\n" << "The beam's height is: " << h << " mm\n" << "the beam's mass will be: " << beam_mass() << " Kg\n";
                }
                return op_stress;
            }
        }

        while (op_stress <= (sigma_y / n) * (0.9)) //
        {
            h = h - 0.01 * h; // decrase the height by 1 & to get the lower stress.
            b = b - 0.01 * b;// decrase the width by 1 & to get the lower stress. (incase of rectangular cross-section).
            op_stress = beam::beam_stress();

            if (h < 2) // if hight reaches a value less than 2 it will set it as 2 and end the function giving back the beam's data.
            {
                h = 2; // set the minimum height to 2 mm.
                op_stress = beam::beam_stress();
                if (choice == CIRCULAR_CHOICE)
                {
                    cout << "\nNo more optimization can be done since it will be irresonable\nthe minimum diameter is: " << h << " mm\n" << "The beam's mass will be: " << beam::beam_mass() << " Kg\n";
                }
                else if (choice == RECTANGULAR_CHOICE)
                {
                    cout << "\nNo more optimization can be done since it will be irresonable\nThe beam's width is: " << b << " mm\n" << "The beam's height is: " << h << " mm\n" << "The beam's mass will be: " << beam_mass() << " Kg\n";
                }
                return op_stress;
            }
        }

        if (op_stress <= (sigma_y / n))
        {
            if (choice == CIRCULAR_CHOICE)
            {
                cout <<"\nThe optimized diameter is: " << h << " mm\n";
            }
            else if (choice == RECTANGULAR_CHOICE)
            {
                cout <<"\nThe optimized dimensions are: \nThe beam's width is: " << b << " mm\n" << "The beam's height is: " << h << " mm\n";
            }
        }
    } while (op_stress >= (sigma_y / n)); // to make sure that the stress is less than the yield strength after decreasing the dimensions (just an extra check).

    cout << "The arm's mass will be: " << beam::beam_mass() << " Kg\n"; // final mass of the beam. (incase the programm completes without any special coditions)
    return op_stress; // final optimized stress. (incase the programm completes without any special coditions)
}
