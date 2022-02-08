#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <stdlib.h>
#include "ABB.h"
#include "producto.h"

using namespace std;

class Interfaz {
    public:
        Interfaz ();

        void respaldarArchivo ();
        void cargarArchivo ();

    private:
        ABB<Producto> arbol;
};

#endif