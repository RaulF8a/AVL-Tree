#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <fstream>
#include "ABB.h"
#include "producto.h"

using namespace std;

class Interfaz {
    public:
        Interfaz ();

        void insertar (const Producto &valor);
        void eliminar (const Producto &valor);
        Producto buscar (const Producto &valor);
        void imprimirArbol ();
        void respaldarArchivo ();
        void cargarArchivo ();

    private:
        ABB<Producto> arbol;
};

#endif