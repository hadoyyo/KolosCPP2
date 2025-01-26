#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

bool porownaj(int podana,int wylosowana)
{
    if (podana==wylosowana)
    {
        return true;
    }
    else
    {
        throw -1;
    }
}

int main()
{
    srand(time(0));
    int wylosowana = rand()%11; //0-10
    int podana;

    while(true)
    {
        cout<<"Podaj liczbe (0-10): ";
        cin>>podana;
        try
        {
            if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw -2;
                }
            if(porownaj(podana,wylosowana))
            {
                cout<<"Udalo ci sie!";
                break;
            }
        }
        catch(int wyjatek)
        {
        if (wyjatek==-1)
        {
            cerr<<"Nie odgadles, sprobuj ponownie"<<endl;
        }
        else if (wyjatek==-2)
        {
            cerr<<"Podaj liczbe calkowita"<<endl;
        }
        else
        {
            cerr<<"Nieznany wyjatek"<<endl;
        }
        }
    }
    return 0;
}
