/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 22/05/2024
 * Version: 1
 * Esta clase definida como Vehiculo es la clase Padre de las clases Auto, Bus y Motocicleta
 * Esta clase brindara tantos sus atributos como metodos a las clases mencionadas anteriormente
 */
#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

// Declaracion de la clase Vehiculo
class Vehiculo {
    protected: // Variables de instancia
        string marca;
        string modelo;
        string color;
        string tipo_energia;
        float kilometraje;
        float precio;
    public: // Metodos que tendra el objeto de la clase
        Vehiculo();
        Vehiculo(string, string, string, string, float); // Metodo donde se aplica sobrecarga
        Vehiculo(string, string, string); // Metodo donde se aplica sobrecarga
        string get_energia(){return tipo_energia;};
        float get_km(){return kilometraje;};
        float calcular_precio(); // Metodo donde se aplica sobreescritura
        string mostrar_caracteristicas(); // Metodo donde se aplica sobreescritura
};

Vehiculo::Vehiculo(){
}

Vehiculo::Vehiculo(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje){
    marca = _marca;
    modelo = _modelo;
    color = _color;
    tipo_energia = _tipo_energia;
    kilometraje = _kilometraje;
    precio = 0.0;
}

Vehiculo::Vehiculo(string _marca, string _modelo, string _color){
    marca = _marca;
    modelo = _modelo;
    color = _color;
    tipo_energia = "Gasolina";
    kilometraje = 0.0;
    precio = 0.0;
}

// Declaracion de la clase Auto que hereda de la clase padre Vehiculo
class Auto : public Vehiculo{
    private: // Variables de instancia
        int nro_puerta;
        bool techo;
        string tipo_caja;
    public: // Metodos de la clase Auto
        Auto();
        Auto(string, string, string, string, float, int, bool, string); // Sobrecarga
        Auto(string, string, string, int, bool, string); // Sobrecarga
        Auto(string, string, string, bool); // Sobrecarga
        void set_nro_puerta(int _nro_puerta){nro_puerta = _nro_puerta;};
        void set_techo(bool _techo){techo = _techo;};
        void set_tipo_caja(string _tipo_caja){tipo_caja = _tipo_caja;};
        int get_nro_puerta(){return nro_puerta;};
        bool get_techo(){return techo;};
        string get_tipo_caja(){return tipo_caja;};
        float calcular_precio(); // Sobreescritura
        string mostrar_caracteristicas(); // Sobreescritura
};

Auto::Auto(){
}

Auto::Auto(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, int _nro_puerta, bool _techo, string _tipo_caja):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    nro_puerta = _nro_puerta;
    techo = _techo;
    tipo_caja = _tipo_caja;
}

Auto::Auto(string _marca, string _modelo, string _color, int _nro_puerta, bool _techo, string _tipo_caja):Vehiculo(_marca, _modelo, _color){
    nro_puerta = _nro_puerta;
    techo = _techo;
    tipo_caja = _tipo_caja;
}

Auto::Auto(string _marca, string _modelo, string _color, bool _techo):Vehiculo(_marca, _modelo, _color){
    nro_puerta = 4;
    techo = _techo;
    tipo_caja = "Automatico";
}

float Auto::calcular_precio(){ // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    float precio1, precio2;
    precio1 = 0.0;
    precio2 = 0.0;
    if (nro_puerta == 4){
        precio1 = 7200;
        if (techo == true){
            precio1 = precio1 + 2200;
            if (tipo_caja == "Automatico"){
                precio1 = precio1 + 2500;
            }
            else {
                precio1 = precio1 + 1500;
            }
        }
        else {
            if (tipo_caja == "Automatico"){
                precio1 = precio1 + 1000;
            }
            else {
                precio1 = precio1 + 1500;
            }
        }
    }
    else {
        precio1 = 6500;
        if (techo == true){
            precio1 = precio1 + 2200;
            if (tipo_caja == "Automatico"){
                precio1 = precio1 + 2500;
            }
            else {
                precio1 = precio1 + 1500;
            }
        }
        else {
            if (tipo_caja == "Automatico"){
                precio1 = precio1 + 1000;
            }
            else {
                precio1 = precio1 + 1500;
            }
        }
    }
    if (marca == "Audi" || marca == "Mercedes Benz" || marca == "BMW"){
        precio2 = 7000;
        if (tipo_energia != "Electrico"){
            precio2 = precio2 + 1500;
            if (kilometraje < 15000){
                precio2 = precio2 + 800;
            }
            else {
                precio2 = precio2 + 400;
            }
        }
        else {
            precio2 = precio2 + 2500;
            if (kilometraje < 15000){
                precio2 = precio2 + 800;
            }
            else {
                precio2 = precio2 + 400;
            }
        }
    }
    else{
        precio2 = 5000;
        if (tipo_energia != "Electrico"){
            precio2 = precio2 + 1500;
            if (kilometraje < 15000){
                precio2 = precio2 + 800;
            }
            else {
                precio2 = precio2 + 400;
            }
        }
        else {
            precio2 = precio2 + 2500;
            if (kilometraje < 15000){
                precio2 = precio2 + 800;
            }
            else {
                precio2 = precio2 + 400;
            }
        }
    }
    precio = precio1 + precio2;
    return precio;
}

string Auto::mostrar_caracteristicas() { // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    string info;
    info = "Marca: " + marca + "\n";
    info = info + "Modelo: " + modelo + "\n";
    info = info + "Color: " + color + "\n";
    info = info + "Tipo de energia: " + tipo_energia + "\n";
    info = info + "Kilometraje: " + to_string(kilometraje) + " km\n";
    info = info + "Numero de puertas: " + to_string(nro_puerta) + "\n";
    info = info + "Techo: " + to_string(techo) + "\n";
    info = info + "Tipo de caja: " + tipo_caja + "\n";
    info = info + "Precio: " + to_string(calcular_precio()) + "USD\n";
    return info;
}

// Declaracion de la clase Bus que hereda de la clase padre Vehiculo
class Bus: public Vehiculo{
    private: // Variables de instancia
        int capacidad;
        string tipo_caja;
    public: // Metodos de la clase Bus
        Bus();
        Bus(string, string, string, string, float, int, string); // Sobrecarga
        Bus(string, string, string, int); // Sobrecarga
        void set_capacidad(int _capacidad){capacidad = _capacidad;};
        void set_caja(string _tipo_caja){tipo_caja = _tipo_caja;};
        int get_capacidad(){return capacidad;};
        string get_caja(){return tipo_caja;};
        string mostrar_caracteristicas(); // Sobreescritura
        float calcular_precio(); // Sobreescritura
};

Bus::Bus(){
}

Bus::Bus(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, int _capacidad, string _tipo_caja):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    capacidad = _capacidad;
    tipo_caja = _tipo_caja;
}

Bus::Bus(string _marca, string _modelo, string _color, int _capacidad):Vehiculo(_marca, _modelo, _color){
    capacidad = _capacidad;
    tipo_caja = "Manual";
}

float Bus::calcular_precio(){ // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    float precio1, precio2;
    precio1 = 0.0;
    precio2 = 0.0;
    if (capacidad > 60){
        precio1 = 22200;
        if (tipo_caja == "Manual"){
            precio1 = precio1 + 2500;
        }
        else {
            precio1 = precio1 + 4500;
        }
    }
    else {
        precio1 = 17200;
        if (tipo_caja == "Manual"){
            precio = precio + 2500;
        }
        else {
            precio1 = precio1 + 4500;
        }
    }
    if (marca == "Volvo" || marca == "Mercedes Benz" || marca == "MAN"){
        precio2 = 10000;
        if (tipo_energia == "Diesel"){
            precio2 = precio2 + 3500;
            if (kilometraje < 150000){
                precio2 = precio2 + 4500;
            }
            else {
                precio2 = precio2 + 2000;
            }
        }
        else {
            precio2 = precio2 + 3500;
            if (kilometraje < 150000){
                precio2 = precio2 + 4500;
            }
            else {
                precio2 = precio2 + 2000;
            }
        }
    }
    else {
        precio2 = 8000;
        if (tipo_energia == "Diesel"){
            precio2 = precio2 + 3500;
            if (kilometraje < 150000){
                precio2 = precio2 + 4500;
            }
            else {
                precio2 = precio2 + 2000;
            }
        }
        else {
            precio2 = precio2 + 3500;
            if (kilometraje < 150000){
                precio2 = precio2 + 4500;
            }
            else {
                precio2 = precio2 + 2000;
            }
        }
    }
    precio = precio1 + precio2;
    return precio;
}
string Bus::mostrar_caracteristicas() { // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    string info;
    info = "Marca: " + marca + "\n";
    info = info + "Modelo: " + modelo + "\n";
    info = info + "Color: " + color + "\n";
    info = info + "Tipo de energia: " + tipo_energia + "\n";
    info = info + "Kilometraje: " + to_string(kilometraje) + " km\n";
    info = info + "Capacidad de pasajeros: " + to_string(capacidad) + "\n";
    info = info + "Tipo de caja: " + tipo_caja + "\n";
    info = info + "Precio: " + to_string(calcular_precio()) + "USD\n";
    return info;
}

// Declaracion de la clase Bus que hereda de la clase padre Vehiculo
class Motocicleta : public Vehiculo{
    private: // Variables de instancia
        bool deportiva;
    public: // Metodos de la clase Motocicleta
        Motocicleta();
        Motocicleta(string, string, string, string, float, bool);
        void set_sport(bool _deportiva){deportiva = _deportiva;};
        bool get_sport(){return deportiva;};
        float calcular_precio(); // Sobreescritura
        string mostrar_caracteristicas(); // Sobreescritura
};

Motocicleta::Motocicleta(){
}

Motocicleta::Motocicleta(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, bool _deportiva):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    deportiva = _deportiva;
}

float Motocicleta::calcular_precio(){ // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    float precio1, precio2;
    if (deportiva == true){
        precio1 = 4500;
    }
    else {
        precio1 = 2500;
    }
    if (marca == "Harley-Davidson" || marca == "Honda" || marca == "Yamaha"){
        precio2 = 3000;
        if (tipo_energia == "Diesel" || tipo_energia == "Gasolina"){
            precio2 = precio2 + 3500;
            if (kilometraje < 5000){
                precio2 = precio2 + 2500;
            }
            else {
                precio2 = precio2 + 1000;
            }
        }
        else {
            precio2 = precio2 + 3500;
            if (kilometraje < 5000){
                precio2 = precio2 + 2500;
            }
            else {
                precio2 = precio2 + 1000;
            }
        }
    }
    else {
        precio2 = 1700;
        if (tipo_energia == "Diesel" || tipo_energia == "Gasolina"){
            precio2 = precio2 + 3500;
            if (kilometraje < 5000){
                precio2 = precio2 + 2500;
            }
            else {
                precio2 = precio2 + 1000;
            }
        }
        else {
            precio2 = precio2 + 3500;
            if (kilometraje < 5000){
                precio2 = precio2 + 2500;
            }
            else {
                precio2 = precio2 + 1000;
            }
        }
    }
    precio = precio1 + precio2;
    return precio;
}

string Motocicleta::mostrar_caracteristicas(){ // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    string info;
    info = "Marca: " + marca + "\n";
    info = info + "Modelo: " + modelo + "\n";
    info = info + "Color: " + color + "\n";
    info = info + "Tipo de energia: " + tipo_energia + "\n";
    info = info + "Kilometraje: " + to_string(kilometraje) + " km\n";
    info = info + "Deportiva: " + to_string(deportiva) + "\n";
    info = info + "Precio: " + to_string(calcular_precio()) + "USD\n";
    return info;
}

#endif // VEHICULO_H
