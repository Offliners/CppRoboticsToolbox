#include<iostream>
#include"Angle.h"

using namespace std;

void menu();
void inputFormat();

int main(int argc, char **argv)
{
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
                inputFormat();
                break;
            case 2:
            {
                double a1, a2, a3;
                cout << "Input angles in order (split by space) : ";
                cin >> a1 >> a2 >> a3;
                cin.ignore();

                string method, sequence;
                cout << "Input method (fixed or euler) : ";
                cin >> method;
                cin.ignore();
                cout << "Input axis sequence (ex: xyz) : ";
                cin >> sequence;
                cin.ignore();

                Angle angle(method, sequence, a1, a2, a3);
                angle.showRotateMatrix();
                break;
            }
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
    cout << "======+ Menu ======+" << endl
         << "1. Show angle format" << endl
         << "2. Input angles & Show Rotate Matrix" << endl
         << "3. Quit" << endl
         << "==================" << endl
         << "Input your select : " << endl;
}

void inputFormat()
{
    std::cout << "If rotation method is \"fixed\", the input sequence of angles is \"gamma->beta->alpha\"" << std::endl
              << "If rotation method is \"euler\", the input sequence of angles is \"alpha->beta->gamma\"" << std::endl;
}