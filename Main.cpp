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

        // --------- set the beam's parameters form user -----------------

        cout << "\n\n ---------- first we need to define the beam's parameters ---------- \n\n";
        a.Mat_Sel();
        a.set_n();
        a.set_choice();
        if(a.get_choice() == 0) a.set_h();
        else {a.set_b(); a.set_h();}
        a.set_l();
        a.set_alpha();
        a.set_m_p();
        // ---------- end -----------

        // -------------- Stress Optimizer final results --------------
        cout << "\n\n ---------------- The Final Results ------------------- \n";
        cout << "The beam's Stress: " << a.beam_stress_optimizer() << " MPa";
        cout << "\n\n--------------- END ----------------\n\n";
        // ---------- end -----------
        
        // ---------- motors test -----------

        cout << "\n\n ---------- For The Motor Selection ---------- \n\n";
        motor b(a.get_l(), a.get_m_p(), a.get_alpha(), a.beam_mass());
        b.calc_speed_required();
        b.calc_torque_required();
        b.Motor_Initial_Set();
        b.motor_set();
        b.Gearbox_Initial_Set();
        b.Gearbox_add();
        b.Combination_Name();
        b.calc_output_torque();
        b.calc_output_speed();
        b.calc_cost();
        b.sortvector();
        b.selection();
        cout << "\n\n--------------- END ----------------\n\n";

        // ---------- end -----------

        cout << "\n\nTo Re-run the program enter 1, to exit enter any number else: ";
        cin >> z;
        } while (z == 1);

    return 0;
}