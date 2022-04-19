#include "Producto.h"
#include "Marcas.h"
#include <iostream>
#include <string>
using namespace  std;
int main()
{
    //Producto pr = Producto();
    //pr.leer();

    string producto;
    cout << "Ingrese producto:";
    getline(cin, producto);
    Producto pr = Producto(producto);
    pr.crear();
    pr.leer();

    string marca;
    cout << "Ingrese marca:";
    getline(cin, marca);
    Marca mr = Marca(marca);
    mr.crear();
    mr.leer();

    system("pause");
    return 0;
}