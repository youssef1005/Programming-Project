#include <iostream>
#include <vector>
#include <array>
#include "..\Header Files\Beams_Class.hpp"


using namespace std;

void beam::Mat_Sel()
{
    // var decleration
    int y = 0; // the position of the last added value
    int chooser = -1; // checks if the user want to add more materials
    vector<int> ch_mat(12); // counts the number of materials
    vector<string> name_mat(12); // Material name
    vector <array<float, 2>> sp_mat(12); // for Yield Strength (MPa) and Density (Kg/m^3) (In that order) 

    // data fill
    name_mat[0] = "Cast Iron"; // choice 1
    name_mat[1] = "Copper Nickel"; // choice 2
    name_mat[2] = "Brass"; // choice 3
    name_mat[3] = "Aluminum"; // choice 4
    name_mat[4] = "Steel"; // choice 5
    name_mat[5] = "Acrylic"; // choice 6
    name_mat[6] = "Copper"; // choice 7
    name_mat[7] = "Stainless Steel"; // choice 8
    name_mat[8] = "Tungsten"; // choice 9

    // Yield Strength (MPa) and Density (Kg/m^3).
    sp_mat[0] = {130.0f, 7300.0f}; // #1: Cast Iron
    sp_mat[1] = {130.0f, 8940.0f}; // #2: Copper Nickel
    sp_mat[2] = {200.0f, 8730.0f}; // #3: Brass
    sp_mat[3] = {241.0f, 2700.0f}; // #4: Aluminum
    sp_mat[4] = {247.0f, 7580.0f}; // #5: Steel
    sp_mat[5] = {72.0f, 1160.0f}; // #6: Acrylic
    sp_mat[6] = {70.0f, 8920.0f}; // #7: Copper
    sp_mat[7] = {275.0f, 7860.0f}; // #8: Stainless Steel
    sp_mat[8] = {941.0f, 19250.0f}; // #9: Tungsten

    do
    {
        for (int i = 0; i < name_mat.size(); i++)
        {
            if (sp_mat[i][0] != 0)
            {
                ch_mat.at(i) = i + 1;
                cout << ch_mat[i] << ": ";
                cout << name_mat[i] << " | " << sp_mat[i][0] << " | " << sp_mat[i][1] <<"\n";
                y = i;
            }
        }
        cout << "\nChoose the beem's material (if you want to add a material press 0): ";
        cin >> chooser;

        if (chooser == 0) // Add a new material
        {
            int z = 0; // checker for the user's data
            do
            {
                // req the material's name
                string n_mat_name = "";
                cout << "\nEnter the material's name (max 40 char): ";
                cin >> n_mat_name;
                while (n_mat_name.length() == 0 || n_mat_name.length() > 40)
                {
                    cout << "Invalid Input!, " << "Enter the material's name (max 40 char): ";
                    cin >> n_mat_name;
                }

                // req the material's Yield Strength
                float n_mat_ys = 0;
                cout << "Enter the material's Yield Strength (in MPa): ";
                cin >> n_mat_ys;
                while (n_mat_ys == 0 || n_mat_ys > 1500 )
                {
                    cout << "Invalid Input!, " << "Enter the material's name (max 1500 MPa): ";
                    cin >> n_mat_ys;
                }
                
                // req the material's Density
                float n_mat_ro = 0;
                cout << "Enter the material's Yield Strength (in Kg/m^3): ";
                cin >> n_mat_ro;
                while (n_mat_ro == 0 || n_mat_ro > 22000 )
                {
                    cout << "Invalid Input!, " << "Enter the material's name (max 22000 Kg/m^3): ";
                    cin >> n_mat_ro;
                }

                cout << "\nAre you sure of the inserted data ( Material's Name: " << n_mat_name << " | Yield Strength: " << n_mat_ys << " | Density: " << n_mat_ro << " ) if yes press 0, to insert again press anyting else: ";
                cin >> z;
                cout << "\n";
                if (z == 0)
                {
                    name_mat.at(y + 1) = n_mat_name;
                    sp_mat.at(y + 1) = {n_mat_ys, n_mat_ro};
                }
                
            } while (z != 0);
        }
        else
        {
            sigma_y = sp_mat[chooser - 1][0];
            ro = sp_mat[chooser - 1][1];
            cout << "\nare you sure of your seleciton ( Material's Name: " << name_mat[chooser - 1] << " | Yield Strength: " << sigma_y << " | Density: " << ro << " ) to choose again press 0, if yes press anyting else: ";
            cin >> chooser;
            cout << "\n";
        }
        
    } while (chooser == 0);
}