/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 22/05/2024
 * Version: 1
 * Esta clase definida como Concesionario contiene todas las operaciones
 * para agregar vehiculos (autos, buses, motocicletas), asi tambien sirve para
 * calcular el precio y mostrar las caracteristicas de cada tipo de vehiculo
 */

#ifndef CONCESIONARIO_H_
#define CONCESIONARIO_H_

#include <string>
#include <iostream>
#include "Vehiculo.h" // Biblioteca con objetos a usar
using namespace std;

class Concesionario {
    private:
        Auto autos[100];
        Bus buses[100];
        Motocicleta motos[100];
    public:
        void muestra_autos();
        void muestra_buses();
        void muestra_motos();
        void agrega_auto(string, string, string, string, float, int, bool, string, int); // Sobrecarga
        void agrega_auto(string, string, string, int, bool, string, int); // Sobrecarga
        void agrega_auto(string, string, string, bool, int); // Sobrecarga
        void agrega_bus(string, string, string, string, float, int, string, int); // Sobrecarga
        void agrega_bus(string, string, string, int, int); // Sobrecarga
        void agrega_moto(string, string, string, string, float, bool, int);
};

void Concesionario::agrega_auto(string marca, string modelo, string color, string tipo_energia, float kilometraje, int nro_puerta, bool techo, string tipo_caja, int posicion){
    autos[posicion] = Auto(marca, modelo, color, tipo_energia, kilometraje, nro_puerta, techo, tipo_caja);
}

void Concesionario::agrega_auto(string marca, string modelo, string color, int nro_puerta, bool techo, string tipo_caja, int posicion){
    autos[posicion] = Auto(marca, modelo, color, nro_puerta, techo, tipo_caja);
}

void Concesionario::agrega_auto(string marca, string modelo, string color, bool techo, int posicion){
    autos[posicion] = Auto(marca, modelo, color, techo);
}

void Concesionario::agrega_bus(string marca, string modelo, string color, string tipo_energia, float kilometraje, int capacidad, string tipo_caja, int posicion){
    buses[posicion] = Bus(marca, modelo, color, tipo_energia, kilometraje, capacidad, tipo_caja);
}

void Concesionario::agrega_bus(string marca, string modelo, string color, int capacidad, int posicion){
    buses[posicion] = Bus(marca, modelo, color, capacidad);
}

void Concesionario::agrega_moto(string marca, string modelo, string color, string tipo_energia, float kilometraje, bool deportiva, int posicion){
    motos[posicion] = Motocicleta(marca, modelo, color, tipo_energia, kilometraje, deportiva);
}

void Concesionario::muestra_autos(){
    for (int i = 0; i < 3; i++){
        cout<<"Auto "<<i+1<<endl;
        cout<<autos[i].mostrar_caracteristicas()<<endl;
    }
}

void Concesionario::muestra_buses(){
    for (int i = 0; i < 3; i++){
        cout<<"Bus "<<i+1<<endl;
        cout<<buses[i].mostrar_caracteristicas()<<endl;
    }
}

void Concesionario::muestra_motos(){
    for (int i = 0; i < 3; i++){
        cout<<"Motocicleta "<<i+1<<endl;
        cout<<motos[i].mostrar_caracteristicas()<<endl;
    }
}

#endif // CONCESIONARIO_H
