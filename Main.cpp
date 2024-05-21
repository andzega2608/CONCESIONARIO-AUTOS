/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 22/05/2024
 * Version: 1
 * El presente programa hace referencia a un algoritmo el cual se encarga de capturar
 * distintas caracteristicas de toda clase de vehiculos como ser autos, buses y motocicletas
 * con el fin de poder calcular el precio de cada uno de ellos y almacenar la informacion
 */

#include <string>
#include <iostream>
#include "Concesionario.h" // Biblioteca con las clases del proyecto
using namespace std;

int main() {
    Concesionario concesionario;
    concesionario.agrega_auto("Audi", "A4", "Negro", "Gasolina", 5000, 4, true, "Automatico", 0);
    concesionario.agrega_auto("Mercedes Benz", "CLA", "Azul", 2, false, "Automatico", 1);
    concesionario.agrega_auto("Nissan", "Versa", "Rojo", true, 2);
    cout << "Autos en el concesionario:\n";
    concesionario.muestra_autos();

    concesionario.agrega_bus("Volvo", "XC90", "Gris", "Diesel", 10000, 80, "Manual", 0);
    concesionario.agrega_bus("Mercedes Benz", "Sprinter", "Blanco", "Diesel", 12000, 30, "Automatico", 1);
    concesionario.agrega_bus("MAN", "Lion's Coach", "Azul", 50, 2);
    cout << "Buses en el concesionario:\n";
    concesionario.muestra_buses();

    concesionario.agrega_moto("Harley-Davidson", "Sportster", "Rojo", "Gasolina", 2000, true, 0);
    concesionario.agrega_moto("Honda", "CBR", "Negro", "Gasolina", 3000, false, 1);
    concesionario.agrega_moto("Yamaha", "MT-07", "Azul", "Gasolina", 500, true, 2);
    cout << "Motocicletas en el concesionario:\n";
    concesionario.muestra_motos();
    return 0;
}
