#include <iostream>

#include "Classes\Beems\Header Files\Beams_Class.hpp"
#include "Classes\Beems\Implementation Files\Beam_Class.cpp"
#include "Classes\Beems\Implementation Files\Material_Selection.cpp"
#include "Classes\Beems\Implementation Files\Stress_Optimizer.cpp"
#include "Data/Beams/Materials.hpp"
#include "Data/Beams/Materials.cpp"

#include "Classes\Motors\Header Files\Motors_Class.hpp"
#include "Classes\Motors\Implementation Files\Motors_Class.cpp"

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
        // ---------- end -----------
        
        // ---------- motors test -----------

        motor b;
        b.calc_torque_required();
        // ---------- end -----------

        cout << "\n\nTo Re-run the program enter 1, to exit enter any number else: ";
        cin >> z;
        } while (z == 1);

    return 0;
}



