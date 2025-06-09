#include "../../../Data/Beams/Materials.hpp"

using namespace std;

void beam::Mat_Sel()
{
    // to choose from the materials
    // also if want to add press 0
    int chooser = -1;
    Material_Initial_Set();
    do
    {
        cout << " # | Material Name             | Yield Strength | Density ";
        cout << "\n----------------------------------------------------------\n";
        for (int i = 0; i < name_mat.size(); i++)
        {
            if (sp_mat[i][0] != 0)
            {
                ch_mat.at(i) = i + 1;
                cout << ch_mat[i];

                if(ch_mat[i] < 10) cout << "  | ";
                else cout << " | "; 

                cout << name_mat[i];
                for (int j = 0; j < (25 - name_mat[i].length()); j++)
                {
                    cout << " ";
                }
                
                cout << " | " << sp_mat[i][0];
                if (sp_mat[i][0] < 10) cout << "             ";
                else if (sp_mat[i][0] < 100) cout << "            ";
                else if (sp_mat[i][0] < 1000) cout << "           ";
                else if (sp_mat[i][0] < 10000) cout << "          ";

                cout << " | " << sp_mat[i][1] <<"\n";
                last_added_mat = i;
            }
        }

        cout << "\nChoose the beem's material (if you want to add a material press 0): ";
        cin >> chooser;

        if (chooser == ADD_NEW_MATERIAL)
        {
            // to add new materials as the user wants
            material_add();
        }

        cout << "\nChoose the beem's material: ";
        cin >> chooser;

        sigma_y = sp_mat[chooser - 1][0]; // -1 to make it in index
        ro = sp_mat[chooser - 1][1]; // -1 to make it in index
        cout << "\nAre you sure of your seleciton ( Material's Name: " << name_mat[chooser - 1] << " | Yield Strength: " << sigma_y << " | Density: " << ro << " ) to choose again or to add new material press 0, if you are sure press any other number: ";
        cin >> chooser;
        cout << "\n";

    } while (chooser == ADD_NEW_MATERIAL);
}