#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto{
    public:
        Producto ();

        string getNombre () const;
        void setNombre (const string &valor);
        float getPrecio () const;
        void setPrecio (float valor);
        int getExistencia () const;
        void setExistencia (int valor);

        friend ostream& operator << (ostream &os, const Producto &p){
            os << p.nombre << "|" << p.precio << "|" << p.existencia << "*";

            return os;
        }

        bool operator == (const Producto &p){
            return p.nombre == nombre;
        }

        bool operator == (const Producto &p) const{
            return p.nombre == nombre;
        }

        bool operator < (const Producto &p){
            return nombre < p.nombre;
        }

        bool operator < (const Producto &p) const{
            return nombre < p.nombre;
        }

        bool operator > (const Producto &p){
            return nombre > p.nombre;
        }

        bool operator > (const Producto &p) const{
            return nombre > p.nombre;
        }

    private:
        string nombre;
        float precio;
        int existencia;
};

#endif