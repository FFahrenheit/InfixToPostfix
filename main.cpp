#include <iostream>
#include "Postfijo.h"

using namespace std;

int main()
{
    string input;
    do
    {
        cout << "Ingrese la expresion infija a convertir en postfija: ";
        getline(cin,input);

        cout << "Postifjo: " << Postfijo::infijoAPostfijo(input) << endl;

        cout << "Escriba Y/y para convertir de nuevo: ";
        getline(cin,input);

    }while(input == "y" || input == "Y");
    return 0;
}
