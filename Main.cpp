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
        std::cout << "\n\n ---------- first we need to define the beam's parameters ---------- \n\n";
        a.beam::Mat_Sel();
        a.beam::set_n();
        a.beam::set_choice();
        if(a.beam::get_choice() == 0) a.beam::set_h();
        else {a.beam::set_b(); a.beam::set_h();}
        a.beam::set_l();
        a.beam::set_alpha();
        a.beam::set_m_p();

        std::cout << "\n\n ---------------- The Final Results ------------------- \n";
        std::cout << "The beam's Stress: " << a.beam::beam_stress_optimizer() << " MPa";

        // ---------- motors test -----------
        motor b(a.get_m_p(), a.get_alpha(), a.get_l(), a.beam_mass());
        b.calc_torque_required();

        // ----------end -----------

        std::cout << "\n\nTo Re-run the program enter 1, to exit enter any number else: ";
        std::cin >> z;
        } while (z == 1);

    return 0;
}

