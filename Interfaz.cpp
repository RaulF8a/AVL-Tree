#include "Interfaz.h"

Interfaz::Interfaz (){

}

void Interfaz::insertar (const Producto &valor){
    arbol.insert (valor);
}

void Interfaz::eliminar (const Producto &valor){
    arbol.erase (valor);
}

Producto Interfaz::buscar (const Producto &valor){
    return *arbol.find (valor);
}

void Interfaz::imprimirArbol (){
    arbol.inOrder ();
}

void Interfaz::respaldarArchivo (){
    ofstream archivo ("file01.txt", ios::app);

    if (archivo.is_open ()){
        arbol.inOrderArchivo (archivo);
    }
    else{
        throw runtime_error ("File could not be opened.");
    }

    archivo.close ();
}

void Interfaz::cargarArchivo (){
    ifstream archivo ("file01.txt", ios::in);
    string auxString;
    Producto auxProducto;

    if (archivo.is_open ()){
        while (true){
            getline (archivo, auxString, '|');

            if (auxString.size () > 0){
                auxProducto.setNombre (auxString);
                
                getline (archivo, auxString, '|');
                auxProducto.setPrecio (stof (auxString));

                getline (archivo, auxString, '*');
                auxProducto.setExistencia (stoi (auxString));

                insertar (auxProducto);
            }
            else{
                break;
            }
        }
    }
    else{
        throw runtime_error ("File could not be opened.");
    }

    archivo.close ();
}