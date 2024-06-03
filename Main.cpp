/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 05/06/2024
 * Version: 3
 *
 * El presente programa hace referencia a un algoritmo el cual se encarga de capturar
 * distintas caracteristicas de toda clase de vehiculos como ser autos, buses y motocicletas
 * con el fin de poder calcular el precio de cada uno de ellos y almacenar la informacion.
 * Adicionalmente, el programa es capaz de realizar la busqueda de un vehiculo con caracteristicas
 * especificas, como ser busqueda por marca, kilometraje y tipo de vehiculo.
 */

#include <string>
#include <iostream>
#include "Concesionario.h" // Biblioteca con las clases del proyecto
using namespace std;

int main() {
    cout<<"BIENVENIDO A CONCESIONARIO DE AUTOS INTERNATIONAL MOTORS"<<endl;
    Concesionario concesionario;
    int continua = 1; int opcion;
    string marca, modelo, color, tipo_energia, tipo_caja;
    bool techo, deportiva; int pue, km, nro_puerta, capacidad;
    float kilometraje;
    concesionario.crea_ejemplos();
    while (continua == 1){
        cout<<"1. Agregar auto"<<endl;
        cout<<"2. Agregar bus"<<endl;
        cout<<"3. Agregar motocicleta"<<endl;
        cout<<"4. Mostrar todo el catalogo"<<endl;
        cout<<"5. Mostrar por tipo de vehiculo"<<endl;
        cout<<"6. Mostrar por marca y kilometraje"<<endl;
        cout<<"7. Mostrar por precio"<<endl;
        cout<<"8. Salir: "<<endl;
        cout<<"Ingrese una opcion: "; cin>>opcion;
        cin.ignore();
        if (opcion == 1) {
            system("cls");
            // Ingresamos datos desde teclado
            cout<<"Ingresa los datos correspondientes"<<endl;
            cout<<"Marca: "; getline(cin, marca); // Se usa getline porque existen marcar como Mercedes Benz que utilizan espacio
            cout<<"Modelo: "; getline(cin, modelo); // Se utiliza getline porque existen modelos de autos
            cout<<"Color: "; cin>>color;
            cout<<"Tipo de energia (Gasolina/Electrico): "; cin>>tipo_energia;
            cout<<"Auto cero km (1 si es nuevo / 0 si no lo es): "; cin>>km;
            cout<<"Auto con 4 puertas (1 si tiene / 0 si no tiene): "; cin>>pue;
            cout<<"Auto con techo (1 si tiene / 0 si no tiene): "; cin>>techo;
            cout<<"Tipo de caja (Manual/Automatico): "; cin>>tipo_caja;
            if (km == 1 && pue == 1){
                // Usamos este metodo si el auto posee 4 puertas y es nuevo (0 kilometros)
                concesionario.agrega_auto(marca, modelo, color, techo); // Implementamos sobrecarga
            }
            else if (pue == 0 && km == 1){
                // Usamos este metodo si el auto NO posee 4 puertas y es nuevo (0 kilometros)
                concesionario.agrega_auto(marca, modelo, color, 4, techo, tipo_caja); // Implementamos sobrecarga
            }
            else {
                // En caso que el auto no sea nuevo, especificamos el kilometraje que posee
                cout<<"Ingrese el kilometraje del auto: "; cin>>kilometraje;
                cout<<"Ingrese el numero de puertas del vehiculo: "; cin>>nro_puerta;
                concesionario.agrega_auto(marca, modelo, color, tipo_energia, kilometraje, nro_puerta, techo, tipo_caja);
            }
            cout<<"AUTO AGREGADO"<<endl;
        }
        else if (opcion == 2){
            system("cls");
            // Ingresamos datos desde teclado
            cout<<"Ingresa los datos correspondientes"<<endl;
            cout<<"Marca: "; getline(cin, marca);
            cout<<"Modelo: "; getline(cin, modelo);
            cout<<"Color: "; cin>>color;
            cout<<"Tipo de energia (Gasolina/Electrico): "; cin>>tipo_energia;
            cout<<"Auto cero km (1 si es nuevo / 0 si no lo es): "; cin>>km;
            cout<<"Capacidad: "; cin>>capacidad;
            cout<<"Tipo de caja (Manual/Automatico): "; cin>>tipo_caja;
            if (km == 1 && tipo_caja == "Manual"){
                // Usamos este metodo si el bus es nuevo (0 kiloemtros) y posee caja manual
                concesionario.agrega_bus(marca, modelo, color, capacidad);
            }
            else {
                // Usamos este metodo para especificar el kilometraje del bus en caso que no sea nuevo
                cout<<"Ingrese el kilometraje del bus: "; cin>>kilometraje;
                concesionario.agrega_bus(marca, modelo, color, tipo_energia, kilometraje, capacidad, tipo_caja);
            }
            cout<<"BUS AGREGADO"<<endl;
        }
        else if (opcion == 3){
            system("cls");
            // Ingresamos datos desde teclado
            cout<<"Ingresa los datos correspondientes"<<endl;
            cout<<"Marca: "; getline(cin, marca);
            cout<<"Modelo: "; getline(cin, modelo);
            cout<<"Color: "; cin>>color;
            cout<<"Tipo de energía (Gasolina/Electrico): "; cin>>tipo_energia;
            cout<<"Kilometraje: "; cin>>kilometraje;
            cout<<"Deportiva (true, false): "; cin>>deportiva;
            concesionario.agrega_moto(marca, modelo, color, tipo_energia, kilometraje, deportiva);
            cout<<"MOTOCICLETA AGREGADA"<<endl;
        }
        else if (opcion == 4){
            system("cls");
            concesionario.imprime_vehiculos(); // Imprime todos los vehiculos del catalogo
        }
        else if (opcion == 5){
            system("cls");
            string tipo;
            cout<<"Ingresa el tipo de vehiculo (Auto, Bus, Motocicleta): "; getline(cin, tipo);
            if (tipo == "Auto") {
                cout<<"AUTOS EN EL CONCESIONARIO"<<endl;
                concesionario.imprime_vehiculos(tipo); // Imprime todos los autos del catalogo
            }
            else if (tipo == "Bus"){
                cout<<"BUSES EN EL CONCESIONARIO"<<endl;
                concesionario.imprime_vehiculos(tipo); // Imprime todos los buses del catalogo
            }
            else {
                cout<<"MOTOCICLETA EN EL CONCESIONARIO"<<endl;
                concesionario.imprime_vehiculos(tipo); // Imprime todas las motocicletas del catalogo
            }
        }
        else if (opcion == 6){
            system("cls");
            cout<<"Ingrese la marca a filtrar: "; getline(cin, marca);
            cout<<"Ingrese el kilometraje: "; cin>>kilometraje;
            cout<<"VEHICULOS DE LA MARCA "<<marca<<" CON KILOMETRAJE MENOR O IGUAL A "<<kilometraje<<endl;
            concesionario.imprime_vehiculos(marca, kilometraje); // Imprime vehiculos segun una marca y kilometraje especifico
        }
        else if (opcion == 7){
            system("cls");
            float precio;
            cout<<"Ingrese el precio (USD): "; cin>>precio;
            cout<<"VEHICULOS CON PRECIO MENOR O IGUAL A "<<precio<<endl;
            concesionario.imprime_vehiculos(precio); // Imprime vehiculos segun un precio específico
        }
        else if (opcion == 8){
            system("cls");
            cout<<"FIN DEL PROGRAMA"<<endl;
            concesionario.liberar_espacio(); // Aplicamos un destructor
            continua = 0;
        }
        else {
            system("cls");
            cout<<"OPCION NO VALIDA, INTENTE DE NUEVO"<<endl;
        }
    }
    return 0;
}
