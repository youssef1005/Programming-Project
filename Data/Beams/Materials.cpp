#include <iostream>
#include "Materials.hpp"

void Material_Initial_Set()
{
    // Initial data fill
    name_mat[0] = "Cast Iron"; // choice 1
    name_mat[1] = "Copper Nickel"; // choice 2
    name_mat[2] = "Brass"; // choice 3
    name_mat[3] = "Aluminum"; // choice 4
    name_mat[4] = "Steel"; // choice 5
    name_mat[5] = "Acrylic"; // choice 6
    name_mat[6] = "Copper"; // choice 7
    name_mat[7] = "Stainless Steel"; // choice 8
    name_mat[8] = "Tungsten"; // choice 9

    // Yield Strength (MPa) and Density (Kg/m^3) in order.
    sp_mat[0] = {130.0f, 7300.0f}; // #1: Cast Iron
    sp_mat[1] = {130.0f, 8940.0f}; // #2: Copper Nickel
    sp_mat[2] = {200.0f, 8730.0f}; // #3: Brass
    sp_mat[3] = {241.0f, 2700.0f}; // #4: Aluminum
    sp_mat[4] = {247.0f, 7580.0f}; // #5: Steel
    sp_mat[5] = {72.0f, 1160.0f}; // #6: Acrylic
    sp_mat[6] = {70.0f, 8920.0f}; // #7: Copper
    sp_mat[7] = {275.0f, 7860.0f}; // #8: Stainless Steel
    sp_mat[8] = {941.0f, 19250.0f}; // #9: Tungsten
}

// fills the data in the material lists
void material_add()
{

    int Add_Checker = -1; // checks if the user want to add more materials (-1 is just a random value)
    int Data_Ensure = SURE; // ensures that the user inserts true data

    do
    {
        do
        {
            // request the material's name
            string n_mat_name = "";
            cout << "\nEnter the material's name (max 40 char): ";
            cin >> n_mat_name;
            while (n_mat_name.length() == 0 || n_mat_name.length() > 40)
            {
                cout << "Invalid Input!, " << "Enter the material's name (max 40 char): ";
                cin >> n_mat_name;
            }

            // request the material's Yield Strength
            float n_mat_ys = 0;
            cout << "Enter the material's Yield Strength (in MPa): ";
            cin >> n_mat_ys;
            while (n_mat_ys == 0 || n_mat_ys > 1000 )
            {
                cout << "Invalid Input!, " << "Enter the material's name (max 1000 MPa): ";
                cin >> n_mat_ys;
            }
            
            // request the material's Density
            float n_mat_ro = 0;
            cout << "Enter the material's Yield Strength (in Kg/m^3): ";
            cin >> n_mat_ro;
            while (n_mat_ro == 0 || n_mat_ro > 22000 )
            {
                cout << "Invalid Input!, " << "Enter the material's name (max 22000 Kg/m^3): ";
                cin >> n_mat_ro;
            }

            cout << "\nAre you sure of the inserted data ( Material's Name: " << n_mat_name << " | Yield Strength: " << n_mat_ys << " | Density: " << n_mat_ro << " ) if yes press 0, to insert again press anyting else: ";
            cin >> Data_Ensure;
            cout << "\n";

            // if the user sure then it will place the data
            if (Data_Ensure == SURE)
            {
                last_added_mat += 1;
                name_mat.at(last_added_mat) = n_mat_name;
                sp_mat.at(last_added_mat) = {n_mat_ys, n_mat_ro};   
            }
            
        } while (Data_Ensure != SURE);

        // to show the data to the user after adding any new material
        for (int i = 0; i < (last_added_mat + 1); i++) // +1 beacause the last_added_mat deals with index
        {
            if (sp_mat[i][0] != 0)
            {
                ch_mat.at(i) = i + 1;
                cout << ch_mat[i] << ": ";
                cout << name_mat[i] << " | " << sp_mat[i][0] << " | " << sp_mat[i][1] <<"\n";
            }
        }

        cout << "\nDo you want to add a new material (if yes press 0, if no press any number else): ";
        cin >> Add_Checker;

    } while (Add_Checker == ADD_NEW_MATERIAL);
}
