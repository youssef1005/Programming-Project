#include "..\..\..\Classes\Motors\Header Files\Motors_Class.hpp"

// calculate the torque coming out of the motor with the gear.
void motor::Combination_Name()
{ 
    string name;
    for (int z = 0; z < (n_motor * n_gear); z++)
    {
        if (motor_specs[3] == gear_specs[3]) // if motor diameter equals Gearbox bore diameter
        {
            for (int i =0 ; i < n_motor ; i++)
            {
                for (int j=0 ; j < n_gear; j++)
                {
                    name = motor_name[i] + " and " + gear_name[j]; 
                    combination_name.push_back(name);
                }
            }
        }
    }
}

// calculate the output torque coming out of the motor with the gear.
void motor::calc_output_torque()
{
    float T;
    for (int z = 0; z < (n_motor * n_gear); z++)
    {
        if (motor_specs[3] == gear_specs[3]) // if motor diameter equals Gearbox bore diameter
        {
            for (int i = 0 ; i < n_motor ; i++)
            {
                for (int j = 0 ; j< n_gear; j++)
                {
                    T = gear_specs[0][j] * motor_specs[1][i] * gear_specs[1][j] ; // [0*0, 0*1, 0*2, 0*3, 1*0, 1*1, 1*2, 1*3, 2*0, 2*1, 2*2, 2*3]
                    Combination_specs[0].push_back(T);
                }
            }
        }
    }
}

// calculate the output speed coming out of the motor with the gear.
void motor::calc_output_speed()
{
    float w;
    for (int z = 0; z < (n_motor * n_gear); z++)
    {
        if (motor_specs[3] == gear_specs[3]) // if motor diameter equals Gearbox bore diameter
        {
            for (int i = 0 ; i< n_motor ; i++){
                for (int j = 0 ; j < n_gear; j++)
                {
                    w = motor_specs[0][i] / gear_specs[0][j]; //[0*0,0*1,0*2,0*3,1*0,1*1,1*2,1*3,2*0,2*1,2*2,2*3]
                    Combination_specs[1].push_back(w);
                }
            }
        }
    }
}

// calculate the cost coming out of the motor with the gear.
void motor::calc_cost ()
{ 
    float c;
    for (int z = 0; z < (n_motor * n_gear); z++)
    {
        if (motor_specs[3] == gear_specs[3]) // if motor diameter equals Gearbox bore diameter
        {
            for (int i =0 ; i< n_motor ; i++){
                for (int j=0 ; j< n_gear; j++)
                {
                    c = (motor_specs[2][i] + gear_specs[2][j]) + (motor_specs[3][i] + gear_specs[3][j])/100 + ( gear_specs[4][j])/100 ; //[0*0,0*1,0*2,0*3,1*0,1*1,1*2,1*3,2*0,2*1,2*2,2*3]
                    Combination_specs[2].push_back(c);
                }
            }
        }
    }

}
