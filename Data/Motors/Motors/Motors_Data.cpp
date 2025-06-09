#include "..\..\..\Classes\Motors\Header Files\Motors_Class.hpp"

using namespace std;

void motor::Motor_Initial_Set()
{
    // Define the motor initial set sepecifications
    motor_name = { "EC frameless DT 50 S", "EC frameless DT 85 M", "ECX FLAT 22 l", "ECX FLAT 32 l", "ECX speed 10 l" }; // motors names
    motor_specs[0] = { 5630 * (2.0 * M_PI / 60), 2850 * (2.0 * M_PI / 60), 8520 * (2.0 * M_PI / 60), 8070 * (2.0 * M_PI / 60), 51600 * (2.0 * M_PI / 60) }; // motor speed (Rad/s)
    motor_specs[1] = { 1.89f, 1.71f, 0.028f, 0.0944f, 0.00338f }; // motor torque (Nm)
    motor_specs[2] = { 0.225f, 0.741f, 0.032f, 0.071f, 0.020f }; // motor mass (Kg)
    motor_specs[3] = { 20.0f, 5.0f, 20.0f, 30.0f, 75.0f }; // motor diameter (mm)
}

void motor::motor_set()
{
    int choice = EXIT;
    do {
        for (int i = 0; i < motor_name.size(); i++) //print motors data
        {
            cout << "\n" << i + 1 << " : ";
            cout << " motor name: " << motor_name[i]
            << " | motor speed: " << motor_specs[0][i]
            << " rad/s | motor torque: " << motor_specs[1][i]
            << " Nm | motor mass: " << motor_specs[2][i]
            << " Kg | motor diameter: " << motor_specs[3][i] << " mm\n";
        }

        cout << "\nDo you want to insert other motors data? (1: Yes | 0: No): ";
        cin >> choice;
        cout << "\n";

        if (choice == ADD_NEW_MOTOR) //enter motors data
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

            // Add data to vectors
            motor_name.push_back(name);
            motor_specs[0].push_back(speed * (2 * M_PI / 60)); // convert rpm to rad/s
            motor_specs[1].push_back(torque);
            motor_specs[2].push_back(mass);
            motor_specs[3].push_back(diameter);
        }

        n_motor = motor_name.size();
        cout << "\nThe number of motors is: " << n_motor << "\n\n";

    } while (choice == ADD_NEW_MOTOR);
}