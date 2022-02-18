#include <iostream>
#include <stdlib.h>
#include "Interfaz.h"

using namespace std;

int main (){
    Interfaz arbol;

    // Producto p1;
    // Producto p2;
    // Producto p3;
    // Producto p4;

    // p1.setNombre ("Maruchan");
    // p1.setPrecio (14.50);
    // p1.setExistencia (100);

    // p2.setNombre ("Guantes");
    // p2.setPrecio (99.99);
    // p2.setExistencia (40);

    // p3.setNombre ("Agua Ciel");
    // p3.setPrecio (10.00);
    // p3.setExistencia (154);

    // p4.setNombre ("Zapato Verde");
    // p4.setPrecio (299.99);
    // p4.setExistencia (10);

    // arbol.insertar (p1);
    // arbol.insertar (p2);
    // arbol.insertar (p3);
    // arbol.insertar (p4);

    // arbol.respaldarArchivo ();
    
    arbol.cargarArchivo ();

    arbol.imprimirArbol ();

    system ("pause");
    return 0;
}
