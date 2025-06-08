#include <iostream>
#include <cmath>
#include "Gearbox_Data.hpp"

using namespace std;

void Gearbox_Initial_Set()
{
    // Define the Gearboxes initial set sepecifications
    gear_name = { "GB58", "GB9" }; // Gearbox Name
    gear_specs[0] = { 15.0f, 4.0f }; // Gearbox Ratio (Unitless)
    gear_specs[1] = { 0.85f, 0.85f }; // Gearbox Efficiency (Unitless)
    gear_specs[2] = { 0.3f, 2.3f }; // Gearbox Mass (Kg)
    gear_specs[3] = { 5.0f, 7.5f }; // Gearbox Diameter (mm)
    gear_specs[4] = { 53.0f, 73.0f }; // Gearbox Width (mm)
}

void Gearbox_add()
{
    int choice = EXIT;
    do {
       
        for (int i = 0; i < gear_name.size(); i++)// print gears data
        {
            
                cout << i + 1 << ": ";
                cout << "gear name: " << gear_name[i]
                << " | gear ratio: " << gear_specs[0][i]
                << " | gear efficiency: " << gear_specs[1][i]
                << " | gear Mass: " << gear_specs[2][i]
                << " Kg | gear diameter: " << gear_specs[3][i]
                << " mm | gear width: " << gear_specs[4][i] << " mm\n";
            
        }

        
        cout << "\nDo you want to insert another gearbox? (1: Yes | 0: No): ";
        cin >> choice;
        cout << "\n";

        if (choice == ADD_NEW_GEARBOX)//enter gear data
        {
            string name;
            float ratio, efficiency, mass, diameter, width;

            cout << "Please Enter the gear box name: ";
            cin >> name;
            cout << "Please Enter the gear box ratio: ";
            cin >> ratio;
            cout << "Please Enter the gear box efficiency: ";
            cin >> efficiency;
            cout << "Please Enter the gear box mass (Kg): ";
            cin >> mass;
            cout << "Please Enter the gear box diameter (mm): ";
            cin >> diameter;
            cout << "Please Enter the gear box width (mm): ";
            cin >> width;

           // Add data to vectors
            gear_name.push_back(name);
            gear_specs[0].push_back(ratio);
            gear_specs[1].push_back(efficiency);
            gear_specs[2].push_back(mass);
            gear_specs[3].push_back(diameter);
            gear_specs[4].push_back(width);
        }

        n_gear = gear_name.size();
        cout << "The number of gearboxes is: " << n_gear << endl;

    } while (choice == ADD_NEW_GEARBOX);
}