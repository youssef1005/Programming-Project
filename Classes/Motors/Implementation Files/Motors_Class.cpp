#include "../Header Files/Motors_Class.hpp"

using namespace std;

motor::motor(float len, float mass_p, float al_max, double mass_l)
{
    l = len;
    m_p = mass_p;
    alpha_max = al_max;
    m_l = mass_l;
}

void motor::calc_speed_required()
{
    float w;
    cout << " Enter the required speed (RPM): ";
    cin >> w;
    while (w <= 0)
    {
        cout << "Invalid Input!\n" << "Please re-enter the required speed (RPM) (should be positive): ";
        cin >> w;
    }
    speed_required = w * (2 * M_PI / 60);
}

void motor::calc_torque_required()
{
    double T;
    T = m_l * g * ((l * pow(10, -3)) / 2) + (m_p * g * (l * pow(10, -3))) + (m_l * pow(((l * pow(10, -3)) / 2), 2) * alpha_max + m_l * pow((l * pow(10, -3)), 2) * alpha_max);
    T_required = T;
}

void motor::sortvector()
{
    Combination_Name();
    calc_output_torque();
    calc_output_speed();
    calc_cost();

    int n = Combination_specs[2].size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (Combination_specs[2][j] > Combination_specs[2][j + 1])
            {
                float new_cost = Combination_specs[2][j];
                Combination_specs[2][j] = Combination_specs[2][j + 1];
                Combination_specs[2][j + 1] = new_cost;

                float new_output_torque = Combination_specs[0][j];
                Combination_specs[0][j] = Combination_specs[0][j + 1];
                Combination_specs[0][j + 1] = new_output_torque;

                string new_combination_name = combination_name[j];
                combination_name[j] = combination_name[j + 1];
                combination_name[j + 1] = new_combination_name;
                
                float new_output_speed = Combination_specs[1][j];
                Combination_specs[1][j] = Combination_specs[1][j + 1];
                Combination_specs[1][j + 1] = new_output_speed;
            }
        }
    }
}

// compare the torque we want with the torque of the motors in order, and as soon as we find one, we print its data: cost, torque, and speed.
void motor::selection()
{
    int n = Combination_specs[2].size();
    int num = 0; // to check if there is a suitable combination or not
    int z = NOT_AVAILABLE; // to show the user multiple options
    float Motor_diameter = 0;
    float Gearbox_diameter = 0;
    
    do
    {
        for (int i = num; i < n; i++) 
        {
            if (Combination_specs[0][i] >= T_required && Combination_specs[1][i] >= speed_required) 
            {
                cout << "\nthe best combination motor and gear box is " << combination_name[i];
                num++;
                break; 
            }
            num++; // increment the number of combinations checked
        }

        if (num == n) 
        {
            cout << "\n\nThere is no suitable combination for the available coupler diameters.\n\n";
            break;
        }

        for (int i = 0; i < motor_name.size(); i++)
        {
            for (int j = 0; j < gear_name.size(); j++)
            {
                if (combination_name[num - 1] == motor_name[i] + " and " + gear_name[j])
                {
                    Motor_diameter = motor_specs[3][i];
                    Gearbox_diameter = gear_specs[3][j];
                }
            }
        }

        if (Motor_diameter == Gearbox_diameter)
        {
            break;
        }
        
        cout <<"\nbut you need a coupler between diameter: " << Motor_diameter << " mm and " << Gearbox_diameter << " mm";
        cout << "\nif not available (press 0), if available press anything else: ";
        cin >> z;

    } while (z == NOT_AVAILABLE);
    
    if (num != n)
    {
        cout << "\nThe output torque is: " << Combination_specs[0][num] << " Nm\n";
        cout << "The output speed is: " << Combination_specs[1][num] << " rad/s\n";
        cout << "The cost of the motor and gear box is: " << Combination_specs[2][num] << "\n";
    }
}