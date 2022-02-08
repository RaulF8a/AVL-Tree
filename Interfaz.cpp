#include "Interfaz.h"

Interfaz::Interfaz (){

}

void Interfaz::respaldarArchivo (){
    ofstream archivo ("file01.txt", ios::app);

    if (archivo.is_open ()){
        
    }
    else{
        throw runtime_error ("File could not be opened.");
    }

    archivo.close ();
}

void Interfaz::cargarArchivo (){

}