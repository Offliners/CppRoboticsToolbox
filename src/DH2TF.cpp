#include<iostream>
#include"Link.h"
#include"Manipulator.h"

using namespace std;

void menu();

int main(int argc, char** argv)
{
    int num_of_joints;
    cout << "Input amount of joint : ";
    cin >> num_of_joints;

    Manipulator DHTable;
    DHTable.addJoint(num_of_joints);

    int select;
    bool flag = false;
    while(1)
    {
        menu();
        cin >> select;
        cin.ignore();

        switch(select)
        {
            case 1:
                DHTable.ShowDHTable();
                break;
            case 2:
                int a, b;
                cout << "B relate to A" << endl
                     << "Input A : ";
                cin >> a;    
                cin.ignore();

                cout << "Input B : ";
                cin >> b;    
                cin.ignore();
                DHTable.ShowTransformMatrix(a, b);
                break;
            case 3:
                flag = true;
                break;
            default:
                cout << "Error Input" << endl;
                break;
        }

        if(flag)
            break;
    }

    return 0;
}

void menu()
{
    cout << "====== Menu ======" << endl
         << "1. Show DH Table" << endl
         << "2. Find TF Matrix" << endl
         << "3. Quit" << endl
         << "==================" << endl
         << "Input your select : " << endl;
}