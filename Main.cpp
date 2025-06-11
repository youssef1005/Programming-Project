#include <iostream>

// Classes:
// 1. Beam class
//   . Header
#include "Classes\Beems\Header Files\Beams_Class.hpp"

//   . Implementation
#include "Classes\Beems\Implementation Files\Beam_Class.cpp"
#include "Classes\Beems\Implementation Files\Material_Selection.cpp"
#include "Classes\Beems\Implementation Files\Stress_Optimizer.cpp"

// 1. Motor class
//   . Header
#include "Classes\Motors\Header Files\Motors_Class.hpp"

//   . Implementation
#include "Classes\Motors\Implementation Files\Motors_Class.cpp"

// Data Base:
// 1. Beam Material
#include "Data/Beams/Materials.hpp"
#include "Data/Beams/Materials.cpp"

// 2. Motors and gear boxes
#include "Data/Motors/Motors/Motors_Data.cpp"
#include "Data/Motors/Gearboxes/Gearbox_Data.cpp"
#include "Data/Motors/Combinaiton/Combination.cpp"

using namespace std;

int main()
{
    int z = 1;
    do
    {
        beam a;
        motor n(a.get_l(), a.get_m_p(), a.get_alpha(), a.beam_mass());
        n.motor_add();
        // --------- set the beam's parameters form user -----------------
        cout << "\n\n ---------- first we need to define the beam's parameters ---------- \n\n";
        cout << " ----------- Defining Material -----------\n\n";
        a.Mat_Sel();
        cout << " ----------- A Nice Choise :) -----------\n\n";
        a.set_n();
        cout << "\n\n ----------- Defining Shape and Dimensions -----------\n\n";
        a.set_choice();
        if(a.get_choice() == 0) a.set_h();
        else {a.set_b(); a.set_h();}
        a.set_l();
        cout << "\n ------- About to finish the defining process :) -------\n\n";
        cout << "\n ----------- Defining external parameters -----------\n\n";
        a.set_alpha();
        a.set_m_p();
        cout << "\n ----------- Thanks for the effort :) -----------\n\n";
        // ---------- end -----------

        // -------------- Stress Optimizer final results --------------
        cout << "\n ------------ The Final Results ------------- \n\n";
        cout << "The beam's Stress: " << a.beam_stress_optimizer() << " MPa";
        cout << "\n\n --------- now you finish stress optimization ---------\n";
        // ---------- end -----------
        
        // ---------- motors test -----------
        cout << "\n\n ---------- For The Motor-Gearbox Selector ---------- \n\n";
        motor b(a.get_l(), a.get_m_p(), a.get_alpha(), a.beam_mass()); // passing the beam's diameter to the motor
        b.calc_speed_required();
        b.calc_torque_required();
        cout << " ----------- Preparing the motors' set -----------";
        b.motor_add();
        b.Gearbox_add();
        b.sortvector();
        b.selection();
        cout << "\n\n--------------- END ----------------\n\n";
        // ---------- end -----------

        cout << "\n\n ---------------- Thanks for using our app ------------------ ";
        cout << "\n\nTo Re-run the program enter 1, to exit enter any number else: ";
        cin >> z;
        } while (z == 1);

    return 0;
}