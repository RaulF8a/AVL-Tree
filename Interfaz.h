#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <fstream>
#include "ArbolAVL.h"
#include "producto.h"

using namespace std;

class Interfaz {
    public:
        Interfaz ();

        void insertar (const Producto &valor);
        void eliminar (const Producto &valor);
        // Producto buscar (const Producto &valor);
        void imprimirArbol ();
        void respaldarArchivo ();
        void cargarArchivo ();

    private:
        ArbolAVL<Producto> arbol;
};

#endif