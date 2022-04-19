// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Puesto.h"
#include <iostream>
#include <string>
using namespace  std;
int main()
{
    //Puesto p = Puesto();
    //p.leer();

    string puesto;
    cout << "Ingrese puesto:";
    getline(cin, puesto);
    Puesto p = Puesto(puesto);
    p.crear();
    p.leer();
    system("pause");
    return 0;
}



