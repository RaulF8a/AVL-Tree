#include <iostream>
#include <stdlib.h>
#include "Interfaz.h"

using namespace std;

void prueba ();

int main (){
    // ABB <int> arbolito;

    // arbolito.insert (52);
    // arbolito.insert (28);
    // arbolito.insert (74);
    // arbolito.insert (13);
    // arbolito.insert (40);
    // arbolito.insert (63);
    // arbolito.insert (86);
    // arbolito.insert (4);
    // arbolito.insert (21);
    // arbolito.insert (32);
    // arbolito.insert (46);
    // arbolito.insert (57);
    // arbolito.insert (71);
    // arbolito.insert (93);
    // arbolito.insert (86);
    // arbolito.insert (2);
    // arbolito.insert (7);
    // arbolito.insert (16);
    // arbolito.insert (24);
    // arbolito.insert (29);
    // arbolito.insert (37);
    // arbolito.insert (50);
    // arbolito.insert (40);

    // arbolito.erase (52);

    // cout << "Direccion de 2: " << arbolito.find (52) << endl;
    // arbolito.inOrder ();
    // cout << "\nLa raiz es: " << arbolito.getValue () << endl;

    // arbolito.inOrder ();

    Interfaz arbol;

    arbol.cargarArchivo ();

    arbol.imprimirArbol ();
    
    system ("pause");
    return 0;
}

void prueba (){
    Interfaz arbol;
    Producto p1, p2, p3, p4, p5;

    p1.setNombre ("Sopa Maruchan");
    p1.setPrecio (13.50);
    p1.setExistencia (10);

    p2.setNombre ("Consome");
    p2.setPrecio (23.00);
    p2.setExistencia (14);

    p3.setNombre ("Integro");
    p3.setPrecio (5999.99);
    p3.setExistencia (5);

    p4.setNombre ("Queso");
    p4.setPrecio (59.34);
    p4.setExistencia (132);

    arbol.insertar (p1);
    arbol.insertar (p2);
    arbol.insertar (p3);
    arbol.insertar (p4);
    //arbol.insertar (p5);

    arbol.respaldarArchivo ();

    //cout << arbol.find (p5) << endl;
    //arbol.imprimirArbol ();
}