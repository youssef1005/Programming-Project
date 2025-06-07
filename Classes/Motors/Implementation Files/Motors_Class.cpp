#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "../Header Files/Motors_Class.hpp"

using namespace std;

// data fill
// 1. motor name (string)
void motor::speed()
{
    float w;
    cout << " Enter speed required ";
    cin >> w;
    speed_required = w;
}

void motor::calc_torque_required()
{
    double T;
    T = a->beam_mass() * g * (a->get_l() / 2) + (a->get_m_p() * g * a->get_l()) + (a->beam_mass() * pow((a->get_l() / 2), 2) * a->get_alpha() + a->beam_mass() * pow(a->get_l(), 2) * a->get_alpha());
    T_required = T;
}

void motor::motor_set()
{

// define first motor specifications
    motor_name.push_back("EC frameless DT 50 S");
    motor_specs[0].push_back(5630 * (2.0 * M_PI / 60)); // convert to rad/s
    motor_specs[1].push_back(1.89); // Nm
    motor_specs[2].push_back(225 * pow(10, -3)); // Kg
    motor_specs[3].push_back(54); // mm;

// define second motor specifications
    motor_name.push_back("EC frameless DT 85 M");
    motor_specs[0].push_back(2850 * (2.0 * M_PI / 60)); // convert to rad/s
    motor_specs[1].push_back(1.71); // Nm
    motor_specs[2].push_back(741 * pow(10, -3)); // Kg
    motor_specs[3].push_back(90); // mm

// define third motor specifications
    motor_name.push_back("ECX FLAT 22 l");
    motor_specs[0].push_back(8520 * (2.0 * M_PI / 60)); // convert to rad/s
    motor_specs[1].push_back(0.028); // Nm
    motor_specs[2].push_back(32 * pow(10, -3)); // Kg
    motor_specs[3].push_back(22); // mm

// define forth motor specifications
    motor_name.push_back("ECX FLAT 32 l");
    motor_specs[0].push_back(8070 * (2.0 * M_PI / 60)); // convert to rad/s
    motor_specs[1].push_back(0.0944); // Nm
    motor_specs[2].push_back(71 * pow(10, -3)); // Kg
    motor_specs[3].push_back(32); // mm

// define fifth motor specifications
    motor_name.push_back("ECX speed 10 l");
    motor_specs[0].push_back(51600 * (2.0 * M_PI / 60)); // convert to rad/s
    motor_specs[1].push_back(0.00338); // Nm
    motor_specs[2].push_back(20 * pow(10, -3)); // Kg
    motor_specs[3].push_back(10); // mm

    int choice = 0;
    do 
    {
        for (int i = 0; i < motor_name.size(); i++)
        {
            if (motor_name[i] != "")
            {
                cout << i + 1 << ": ";
                cout <<"motor name" << motor_name[i] << " | motor speed" << motor_specs[0][i] << " | motor_torque " << motor_specs[1][i] << " | motor mass" << motor_specs[2][i] << " | motor diameter" << motor_specs[3][i] << "\n";
            }
        }

        cout << "Do you want to insert other motors data? (1: Yes | 0: No): ";
        cin >> choice;

        while (choice == 1)
        {
            string name;
            float speed, torque, mass, diameter;
            cout << "Please Enter the motor name: ";
            cin >> name;
            cout << "Please Enter the motor speed (rpm): ";
            cin >> speed;
            cout << "Please Enter the motor torque (Nm): ";
            cin >> torque;
            cout << "Please Enter the motor mass (Kg): ";
            cin >> mass;
            cout << "Please Enter the motor diameter (mm): ";
            cin >> diameter;

            // add the data to the vectors
            motor_name.push_back(name);
            motor_specs[0].push_back(speed * (2* 3.14 / 60)); // convert to rad/s
            motor_specs[1].push_back(torque);
            motor_specs[2].push_back(mass); // Kg
            motor_specs[3].push_back(diameter); // mm

            cout << "Do you want to insert other motors data? (1: Yes | 0: No): ";
            cin >> choice;
            if (choice == 0)
            {
                break;
            }

        }
        int n = motor_name.size();
        n_motor = n;
        cout << "The number of motors is: " << n_motor << endl;


	} while (choice == 1);
}

void motor::gear_set()
{

// define first gear box specifications
    gear_name.push_back("GB58");
    motor_specs[0].push_back(15); // unitless
    motor_specs[1].push_back(0.85); // unitless
    motor_specs[2].push_back(0.3); // Kg
    motor_specs[3].push_back(5); // mm
    motor_specs[4].push_back(53); // mm

// define second gear box specifications
    gear_name.push_back("GB9");
    motor_specs[0].push_back(4); // unitless
    motor_specs[1].push_back(0.85);// unitless
    motor_specs[2].push_back(2.3);// Kg
    motor_specs[3].push_back(7.5);// mm
    motor_specs[4].push_back(73);// mm

    int choice;
    do {
            for (int i = 0; i < gear_name.size(); i++)
            {
                if (gear_name[i] != "")
                {
                    cout << i + 1 << ": ";
                    cout << "gear name" << gear_name[i] << " | gear ratio " << gear_specs[0][i] << " | gear effiency" << gear_specs[1][i] << " | gear diameter " << gear_specs[3][i] << " | gear width" << gear_specs[4][i] << "\n";
                }
            }
            cout << "Do you want to insert other gears box data? (1: Yes | 0: No): ";
            cin >> choice;

            while (choice == 1)
            {
                string name;
                float ratio, effciency, mass, diameter, width;
                cout << "Please Enter the motor name: ";
                cin >> name;
                cout << "Please Enter the gear box ratio: ";
                cin >> ratio;
                cout << "Please Enter the gear box effciency: ";
                cin >> effciency;
                cout << "Please Enter the gear box mass (Kg): ";
                cin >> mass;
                cout << "Please Enter the gear box diameter (mm): ";
                cin >> diameter;
                cout << "Please Enter the gear box width (mm): ";
                cin >> width;

                // add the data to the vectors
                gear_name.push_back(name);
                gear_specs[0].push_back(ratio); // unitless
                gear_specs[1].push_back(effciency); // unitless
                gear_specs[2].push_back(mass); // Kg
                gear_specs[3].push_back(diameter); // mm
                gear_specs[4].push_back(width); // mm
                cout << "Do you want to insert other gear boxes data? (1: Yes | 0: No): ";
                cin >> choice;
                if (choice == 0)
                {
                    break;
                }

            }
            int n = gear_name.size();
            n_gear = n;
            cout << "The number of motors is: " << n_gear << endl;

        } while (choice == 1);
    }

void motor::calc_output_torque()
{
    float T;
    string name;
        for (int i =0 ; i< n_motor ; i++){
            for (int j=0 ; j< n_gear; j++)
            {
                T = gear_specs[0][j] * motor_specs[1][i] * gear_specs[1][j] ; // [0*0, 0*1, 0*2, 0*3, 1*0, 1*1, 1*2, 1*3, 2*0, 2*1, 2*2, 2*3]
                output_torque.push_back(T);
                name = motor_name[i] + " and " + gear_name[j];
                combination_name.push_back(name);
            }
        }
    }

void motor::calc_output_speed()
{
        float w;
        for (int i =0 ; i< n_motor ; i++){
            for (int j=0 ; j< n_gear; j++)
            {
                w=  motor_specs[0][i] / gear_specs[0][j] ; //[0*0,0*1,0*2,0*3,1*0,1*1,1*2,1*3,2*0,2*1,2*2,2*3]
                output_speed.push_back(w);
            }
        }

    }

void motor::calc_cost()
{
        float c;
        for (int i =0 ; i< n_motor ; i++){
            for (int j=0 ; j< n_gear; j++)
            {
                c = (motor_specs[2][i] + gear_specs[2][j]) + (motor_specs[3][i] + gear_specs[3][j])/100 + ( motor_specs[4][j])/100 ; //[0*0,0*1,0*2,0*3,1*0,1*1,1*2,1*3,2*0,2*1,2*2,2*3]
                cost.push_back(c);
            }
        }

    }

void motor::sortvector()
{
    int n = cost.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (cost[j] > cost[j + 1]) {
                float new_cost = cost[j];
                cost[j] = cost[j + 1];
                cost[j + 1] = new_cost;

                float new_output_torque = output_torque[j];
                output_torque[j] = output_torque[j + 1];
                output_torque[j + 1] = new_output_torque;

                string new_combination_name = combination_name[j];
                combination_name[j] = combination_name[j + 1];
                combination_name[j + 1] = new_combination_name;
                
                float new_output_speed = output_speed[j];
                output_speed[j] = output_speed[j + 1];
                output_speed[j + 1] = new_output_speed;
                 
            }
        }
    }
}

void motor::selection()
{
    int n = cost.size();
            for (int i =0 ; i<= n ; i++){   
                if (output_torque[i] >= T_required && output_speed[i] >= speed_required){
                cout << " the best combination is "<< combination_name [i];
                break ;
                }
        }
}
