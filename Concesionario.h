/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 27/05/2024
 * Version: 2
 * Esta clase definida como Concesionario contiene todas las operaciones
 * para agregar vehiculos (autos, buses, motocicletas), asi tambien sirve para
 * calcular el precio, mostrar las caracteristicas de cada tipo de vehiculo y buscar un
 * vehiculo con caracteristicas especificas
 */

#ifndef CONCESIONARIO_H_
#define CONCESIONARIO_H_

#include <string>
#include <iostream>
#include "Vehiculo.h" // Biblioteca con objetos a usar
using namespace std;

const int MAX = 1000; // Constante de tamaño de arreglos

class Concesionario {
    private:
        Vehiculo *vehiculos [MAX]; // Definimos como apuntador para polimorfismo
        int posicion;
    public:
        Concesionario() : posicion(0) {}; // Se declara constructor por default
        void crea_ejemplos();
        void imprime_vehiculos();
        void imprime_vehiculos(string);
        void imprime_vehiculos(string, float);
        void imprime_vehiculos(float);
        void agrega_auto(string, string, string, string, float, int, bool, string); // Sobrecarga
        void agrega_auto(string, string, string, int, bool, string); // Sobrecarga
        void agrega_auto(string, string, string, bool); // Sobrecarga
        void agrega_bus(string, string, string, string, float, int, string); // Sobrecarga
        void agrega_bus(string, string, string, int); // Sobrecarga
        void agrega_moto(string, string, string, string, float, bool);
        void liberar_espacio();
};

/*
* El metodo crea_ejemplos() se encarga de crear objetos en el vector vehiculos[]
* Dicho metodo genera objetos de tipo Auto, Bus y Motocicleta con el fin de poder hacer pruebas y
* que el programa posea algunos ejemplos y que no este vacio. Es importante mencionar que estos
* ejemplos son datos inventados, por lo que no se debe usar este metodo si se va a usar el programa
* en produccion.
*/

void Concesionario::crea_ejemplos(){
    vehiculos[posicion] = new Auto("Audi", "A4", "Negro", "Gasolina", 5000, 4, true, "Automatico");
    posicion++;
    vehiculos[posicion] = new Auto("Mercedes Benz", "CLA", "Azul", 2, false, "Automatico");
    posicion++;
    vehiculos[posicion] = new Auto("Nissan", "Versa", "Rojo", true);
    posicion++;
    vehiculos[posicion] = new Bus("Volvo", "XC90", "Gris", "Diesel", 10000, 80, "Manual");
    posicion++;
    vehiculos[posicion] = new Bus("Mercedes Benz", "Sprinter", "Blanco", "Diesel", 12000, 30, "Automatico");
    posicion++;
    vehiculos[posicion] = new Bus("MAN", "Lion's Coach", "Azul", 50);
    posicion++;
    vehiculos[posicion] = new Motocicleta("Harley-Davidson", "Sportster", "Rojo", "Gasolina", 2000, true);
    posicion++;
    vehiculos[posicion] = new Motocicleta("Honda", "CBR", "Negro", "Gasolina", 3000, false);
    posicion++;
    vehiculos[posicion] = new Motocicleta("Yamaha", "MT-07", "Azul", "Gasolina", 500, true);
    posicion++;
}

void Concesionario::agrega_auto(string marca, string modelo, string color, string tipo_energia, float kilometraje, int nro_puerta, bool techo, string tipo_caja){
    vehiculos[posicion] = new Auto(marca, modelo, color, tipo_energia, kilometraje, nro_puerta, techo, tipo_caja);
    posicion++;
}

void Concesionario::agrega_auto(string marca, string modelo, string color, int nro_puerta, bool techo, string tipo_caja){
    vehiculos[posicion] = new Auto(marca, modelo, color, nro_puerta, techo, tipo_caja);
    posicion++;
}

void Concesionario::agrega_auto(string marca, string modelo, string color, bool techo){
    vehiculos[posicion] = new Auto(marca, modelo, color, techo);
    posicion++;
}

void Concesionario::agrega_bus(string marca, string modelo, string color, string tipo_energia, float kilometraje, int capacidad, string tipo_caja){
    vehiculos[posicion] = new Bus(marca, modelo, color, tipo_energia, kilometraje, capacidad, tipo_caja);
    posicion++;
}

void Concesionario::agrega_bus(string marca, string modelo, string color, int capacidad){
    vehiculos[posicion] = new Bus(marca, modelo, color, capacidad);
    posicion++;
}

void Concesionario::agrega_moto(string marca, string modelo, string color, string tipo_energia, float kilometraje, bool deportiva){
    vehiculos[posicion] = new Motocicleta(marca, modelo, color, tipo_energia, kilometraje, deportiva);
    posicion++;
}

/*
* El metodo imprime_vehiculos() se encarga de mostrar todas las caracteristicas de los vehiculos almacenados en el vector
* vehiculos[]. Para tal efecto, este metodo recorre todo el arreglo imprimiendo cada objeto con el
* metodo mostrar_caracteristicas()
*/

void Concesionario::imprime_vehiculos(){
    // Ciclo que recorre e imprime cada elemento del arreglo
    for (int i = 0; i < posicion; i++){
        cout<<"Vehiculo "<<i+1<<endl;
        cout<<vehiculos[i]->mostrar_caracteristicas()<<endl;
    }
}

/*
* El metodo imprime_vehiculos(tipo) se encarga de mostrar todas las caracteristicas de los vehiculos almacenados en el vector
* vehiculos[] que coincidan con el tipo de vehiculo que se quiere mostrar. Para tal efecto, este metodo recorre
* todo el arreglo verificando que el tipo de vehiculo sea igual al que desea mostrar. Si es el caso imprime cada objeto con el
* metodo mostrar_caracteristicas()
*/

void Concesionario::imprime_vehiculos(string _tipo) {
  for (int i = 0; i < posicion; i++) {
    if (vehiculos[i]->get_tipo() == _tipo)
      cout<<vehiculos[i]->mostrar_caracteristicas()<<endl;
  }
}

/*
* El metodo imprime_vehiculos(marca, km) se encarga de mostrar todas las caracteristicas de los vehiculos almacenados en el
* vector vehiculos[] que coincidan con la marca de vehiculo y con el kilometraje que se quiere mostrar. Para tal efecto, este
* metodo recorre todo el arreglo verificando que el tipo de vehiculo sea igual al que desea mostrar. Si es el caso imprime
* cada objeto con el metodo mostrar_caracteristicas()
*/

void Concesionario::imprime_vehiculos(string _marca, float _km) {
  for (int i = 0; i < posicion; i++) {
    if (vehiculos[i]->get_marca() == _marca && vehiculos[i]->get_km() <= _km)
      cout<<vehiculos[i]->mostrar_caracteristicas()<<endl;
  }
}

/*
* El metodo imprime_vehiculos(precio) se encarga de mostrar todas las caracteristicas de los vehiculos almacenados en el
* vector vehiculos[] los cuales poseen un precio menor o igual al precio que se quiero filtrar. Para tal efecto, este
* metodo recorre todo el arreglo verificando que el precio cumpla con los requerimientos anteriores. Si es el caso imprime
* cada objeto con el metodo mostrar_caracteristicas()
*/

void Concesionario::imprime_vehiculos(float _precio) {
  for (int i = 0; i < posicion; i++) {
    if (vehiculos[i]->calcular_precio()<=_precio)
      cout<<vehiculos[i]->mostrar_caracteristicas()<<endl;
  }
}

/*
* El metodo liberar_esoecio() actua como un destructor. Al implementar el concepto de polimorfismo y estar trabajando con
* la memoria dinamica, al finalizar el programa es necesario eliminar cada elemento creado, de esa forma es que se crea
* dicho metodo.
*/

void Concesionario::liberar_espacio() {
    for (int i = 0; i < posicion; i++) {
        delete vehiculos[i]; // Se elimina cada objeto creado en el arreglo
    }
}

#endif // CONCESIONARIO_H
