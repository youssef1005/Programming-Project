#include <iostream>
#include "Classes\Beems\Header Files\Beams_Class.hpp"
#include "Classes\Motors\Header Files\Motors_Class.hpp"


using namespace std;

int main()
{
    int z = 1;
    do
    {
        beam a;

        // set the beam's parameters form user
        cout << "\n\n ---------- first we need to define the beam's parameters ---------- \n\n";
        a.Mat_Sel();
        a.set_n();
        a.set_choice();
        if(a.get_choice() == 0) a.set_h();
        else {a.set_b(); a.set_h();}
        a.set_l();
        a.set_alpha();
        a.set_m_p();

        cout << "\n\n ---------------- The Final Results ------------------- \n";
        cout << "The beam's Stress: " << a.beam_stress_optimizer() << " MPa";

        // ---------- motors test -----------
        motor b(a.get_m_p(), a.get_alpha(), a.get_l(), a.beam_mass());
        b.calc_torque_required();

        // ---------- end -----------

        cout << "\n\nTo Re-run the program enter 1, to exit enter any number else: ";
        cin >> z;
        } while (z == 1);

    return 0;
}

