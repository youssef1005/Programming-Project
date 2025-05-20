#include <iostream>
#include "..\Header Files\Beams_Class.hpp"
using namespace std;

int beam::get_choice()
{
    return choice;
}
float beam::get_l()
{
    return l;
}
float beam::get_m_p()
{
    return m_p;
}
float beam::get_alpha()
{
    return alpha;
}

// sets the beam's cross-section type checks if the value is 1 or 0 only(asks the user).
void beam::set_choice()
{
    int c;
    cout << "Please Enter your beam's cross-section type (0: Circular | 1: Rectangular): ";
    cin >> c;
    while (c != CIRCULAR_CHOICE && c != RECTANGULAR_CHOICE)
        {
            cout << "Invalid Input!\n" << "Please re-enter the cross-section type (0: Circular | 1: Rectangular): ";
            cin >> c;
        }
    choice = c;
}


// sets the beam's length value and checks if the value is positive (asks the user).
void beam::set_l()
{
    float length;
    cout << "Please Enter your beam's length (in mm): ";
    cin >> length;
    while (length <= 0)
        {
            cout << "Invalid Input!\n" << "Please re-enter the length (in mm) (should be positive): ";
            cin >> length;
        }
    l = length;
}

// sets the beam's width (rectangular) value and checks if the value is Positive (asks the user).
void beam::set_b()
{
    float Width;
    cout << "Please Enter the width (in mm): ";
    cin >> Width;
    while (Width <= 0)
        {
            cout << "Invalid Input!\n" << "Please re-enter the width (in mm) (should be positive): ";
            cin >> Width;
        }
    b = Width;
}

// sets the beam's height (rectangular), Diameter (Circular) value and checks if the value is Positive (asks the user).
void beam::set_h()
{
    float height;
    if (choice == 0)
    {
        cout << "Please Enter the Diameter (in mm): ";
    }
    else
    {
        cout << "Please Enter the height (in mm): ";
    }
    cin >> height;
    while (height <= 0)
        {
            cout << "Invalid Input!\n" << "Please re-enter the ( height | Diameter ) (in mm) (should be positive): ";
            cin >> height;
        }
    h = height;
}

// sets the beam's  Payload mass value and checks if the value is Positive (asks the user).
void beam::set_m_p()
{    
    float mass_p;
    cout << "Please Enter the Payload mass (Kg) : ";
    cin >> mass_p;
    while(mass_p <= 0){
        cout << "Invalid Input!\n" << "Please re-enter the Payload mass (Kg) (should be positive): ";
        cin >> mass_p;
    }
    m_p = mass_p;
}

// sets the beam's Maximum angular acceleration value and checks if the value is Positive (asks the user).
void beam::set_alpha()
{    
    float a;
    cout << "Please Enter the Maximum angular acceleration (rad / s^2 ) : ";
    cin >> a;
    while(a <= 0){
        cout << "Invalid Input!\n" << "Please re-enter the Maximum angular acceleration (rad / s^2) (should be positive): ";
        cin >> a;
    }
    alpha = a;
}

void beam::set_n()
{    
    float n_safety;
    cout << "Please Enter the safety factor (grater than 1): ";
    cin >> n_safety;
    while(n_safety <= 1)
    {
        cout <<"Invalid Input!\n" << "Please re-enter the safety factor (should be grater than 1): ";
        cin >> n_safety;
    }
    n = n_safety;
}