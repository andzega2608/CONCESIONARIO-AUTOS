/*
 * Proyecto Concesionario de Autos
 * Andrés Ignacio Zegales Taborga
 * A01711365
 * 10/06/2024
 * Version: 4
 *
 * Esta clase definida como Vehiculo es la clase Padre de las clases Auto, Bus y Motocicleta
 * Esta clase brindara tantos sus atributos como metodos a las clases mencionadas anteriormente
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Declaracion de la clase Vehiculo
class Vehiculo {
    protected: // Variables de instancia
        string tipo;
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
        /*
        * get_tipo()
        * @param
        * return el tipo de vehículo
        */
        string get_tipo() {return tipo;};
        /*
        * get_marca()
        * @param
        * return la marca de vehículo
        */
        string get_marca() {return marca;};
        /*
        * get_energia()
        * @param
        * return el tipo de energia electrico, gasolina, diesel
        */
        string get_energia(){return tipo_energia;};
        /*
        * get_kilometraje()
        * @param
        * return el kilometraje del vehiculo
        */
        float get_km(){return kilometraje;};
        virtual float calcular_precio() = 0; // Sobreescritura y polimorfismo
        virtual string mostrar_caracteristicas() = 0; // Sobreescritura y polimorfismo
};

Vehiculo::Vehiculo(){ // Constructor por default
}

/*
* Vehiculo(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje)
*
* Constructor que recibe todos los atributos de la clase
*
* param marca, modelo, color, tipo de energia, kilometraje
* @return
*/

Vehiculo::Vehiculo(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje){
    tipo = "";
    marca = _marca;
    modelo = _modelo;
    color = _color;
    tipo_energia = _tipo_energia;
    kilometraje = _kilometraje;
    precio = 0.0;
}

/*
* Vehiculo(string _marca, string _modelo, string _color)
*
* Constructor que recibe algunos atributos de la clase, dicho constructor toma que
* el vahículo es nuevo, es decir, cero kilometros y donde el tipo de energia es gasolina
*
* param marca, modelo, color, tipo de energia, kilometraje
* @return
*/

Vehiculo::Vehiculo(string _marca, string _modelo, string _color){
    tipo = "";
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
        /*
        * set_nro_puerta()
        * Establece el numero de puertas del auto
        * param el número de las puertas
        * @return
        */
        void set_nro_puerta(int _nro_puerta){nro_puerta = _nro_puerta;};
        /*
        * set_techo()
        * Establece si el auto posee techo panoramico o no
        * param true o false dependiendo la situacion
        * @return
        */
        void set_techo(bool _techo){techo = _techo;};
        /*
        * set_tipo_caja()
        * Establece el tipo de caja, caja manual o caja automatica
        * param tipo de caja
        * @return
        */
        void set_tipo_caja(string _tipo_caja){tipo_caja = _tipo_caja;};
        /*
        * get_nro_puerta()
        * @param
        * return el numero de puertas del auto
        */
        int get_nro_puerta(){return nro_puerta;};
        /*
        * get_techo()
        * @param
        * return true o false si el auto posee techo panoramico
        */
        bool get_techo(){return techo;};
        /*
        * get_tipo_caja()
        * @param
        * return si es caja manual o automatica
        */
        string get_tipo_caja(){return tipo_caja;};
        float calcular_precio(); // Sobreescritura
        string mostrar_caracteristicas(); // Sobreescritura
};

Auto::Auto(){ // Constructor por default
}

/*
* Auto (marca, modelo, color, tipo_energia, kilometraje, nro_puerta, techo, tipo_caja)
*
* Constructor que recibe todos los atributos de la clase auto, hereda el constructor de la
* clase padre Vehiculo
*
* param marca, modelo, color, tipo de energia, kilometraje, numero de puertas, techo, tipo de caja
* @return
*/

Auto::Auto(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, int _nro_puerta, bool _techo, string _tipo_caja):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    tipo = "Auto";
    nro_puerta = _nro_puerta;
    techo = _techo;
    tipo_caja = _tipo_caja;
}

/*
* Auto (marca, modelo, color, nro_puerta, techo, tipo_caja)
*
* Constructor que recibe algunos atributos de la clase auto, hereda el constructor de la
* clase padre Vehiculo. Este constructor toma que el auto es nuevo (0 km)
*
* param marca, modelo, color, numero de puertas, techo, tipo de caja
* @return
*/

Auto::Auto(string _marca, string _modelo, string _color, int _nro_puerta, bool _techo, string _tipo_caja):Vehiculo(_marca, _modelo, _color){
    tipo = "Auto";
    nro_puerta = _nro_puerta;
    techo = _techo;
    tipo_caja = _tipo_caja;
}

/*
* Auto (marca, modelo, color, techo)
*
* Constructor que recibe algunos atributos de la clase auto, hereda el constructor de la
* clase padre Vehiculo. Este constructor toma que el auto es nuevo (0 km) y posee 4 puertas
* y posee una caja de tipo automática
*
* param marca, modelo, color, techo, tipo de caja
* @return
*/

Auto::Auto(string _marca, string _modelo, string _color, bool _techo):Vehiculo(_marca, _modelo, _color){
    tipo = "Auto";
    nro_puerta = 4;
    techo = _techo;
    tipo_caja = "Automatico";
}

/*
* calcular_precio()
*
* Esta función establece el precio de cada auto respecto al vehiculo y las caracteristicas del mismo
* Por ejemplo, si el vehiculo es de una marca deluxe como ser Audi, Mercedes Benz o BMW, el precio aumenta
* Del mismo modo, si el auto posee un tipo de caja automatico, el precio aumenta a diferencia que sea manual
* Igual el tema del kilometraje es muy importante ya que al tener un kilometraje menor, el auto tiene mas valor
* Adicionalmente, el hecho que el auto posea techo panoramico influye en el precio.
*
* @param
* return precio del auto segun las caracteristicas definidas
*/

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

/*
* mostrar_caracteristicas()
*
* La funcion concatena todas las caracteristicas del auto y la introduce dentro de una variable
*
* @param
* return string con los valores y texto concatenado.
*/

string Auto::mostrar_caracteristicas() { // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    stringstream aux;
    aux<<"Marca: "<<marca<<"\n"<<"Modelo: "<<modelo<<"\n"<<"Color: "<<color<<"\n"<<"Tipo de energia: "<<tipo_energia<<"\n";
    aux<<"Kilometraje: "<<kilometraje<<" km\n"<<"Numero de puertas: "<<nro_puerta<<"\n"<<"Techo: "<<techo<<"\n"<<"Tipo de caja: ";
    aux<<tipo_caja<<"\n"<<"Precio: "<<calcular_precio()<<"USD\n";
    return aux.str();
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
        /*
        * set_capacidad(_capacidad)
        * param capacidad de pasajeros que posee le bus
        * @return
        */
        void set_capacidad(int _capacidad){capacidad = _capacidad;};
        /*
        * set_caja(_tipo_caja)
        * param tipo de caja del bus, automatico o manual
        * @return
        */
        void set_caja(string _tipo_caja){tipo_caja = _tipo_caja;};
        /*
        * get_capacidad()
        * @param
        * return capacidad de pasajeros que tiene el bus
        */
        int get_capacidad(){return capacidad;};
        /*
        * get_caja()
        * @param
        * return tipo de caja del bus
        */
        string get_caja(){return tipo_caja;};
        string mostrar_caracteristicas(); // Sobreescritura
        float calcular_precio(); // Sobreescritura
};

Bus::Bus(){ // Constructor por default
}

/*
* Bus(marca, modelo, color, tipo_energia, kilometraje, capacidad, tipo_caja)
*
* Constructor que recibe todos los atributos de la clase Bus, asimismo hereda el constructor
* de la clase padre Vehiculo
*
* param marca, modelo, color, tipo_energia, kilometraje, capacidad, tipo_caja
* @return
*/

Bus::Bus(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, int _capacidad, string _tipo_caja):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    tipo = "Bus";
    capacidad = _capacidad;
    tipo_caja = _tipo_caja;
}

/*
* Bus(marca, modelo, color, capacidad)
*
* Constructor que recibe todos los atributos de la clase Bus, asimismo hereda el constructor
* de la clase padre Vehiculo. Este constrcutor establece que el bus es nuevo y que el tipo de caja
* es manual por default
*
* param marca, modelo, color, capacidad
* @return
*/

Bus::Bus(string _marca, string _modelo, string _color, int _capacidad):Vehiculo(_marca, _modelo, _color){
    tipo = "Bus";
    capacidad = _capacidad;
    tipo_caja = "Manual";
}

/*
* calcular_precio()
*
* La funcion establece el precio de cada bus respecto a las caracteristicas que posee el mismo
* Por ejemplo, si el vehiculo es de una marca deluxe como ser Volvo, Mercedes Benz, el precio aumenta
* Del mismo modo, si el bus posee un tipo de caja automatico, el precio aumenta a diferencia que sea manual
* Igual el tema del kilometraje es muy importante ya que al tener un kilometraje menor, el bus tiene mas valor
* Adicionalmente, la capacidad de pasajeros que el bus posea influye en el precio.
*
* @param
* return precio del bus segun las caracteristicas que posee.
*/

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

/*
* mostrar_caracteristicas()
*
* La funcion concatena todas las caracteristicas del bus y la introduce dentro de una variable
*
* @param
* return string con los valores y texto concatenado.
*/

string Bus::mostrar_caracteristicas() { // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    stringstream aux;
    aux<<"Marca: "<<marca<<"\n"<<"Modelo: "<<modelo<<"\n"<<"Color: "<<color<<"\n"<<"Tipo de energia: "<<tipo_energia<<"\n";
    aux<<"Kilometraje: "<<kilometraje<<" km\n"<<"Capacidad de pasajeros: "<<capacidad<<"\n"<<"Tipo de caja: "<<tipo_caja<<"\n";
    aux<<"Precio: "<<calcular_precio()<<"USD\n";
    return aux.str();
}

// Declaracion de la clase Bus que hereda de la clase padre Vehiculo
class Motocicleta : public Vehiculo{
    private: // Variables de instancia
        bool deportiva;
    public: // Metodos de la clase Motocicleta
        Motocicleta();
        Motocicleta(string, string, string, string, float, bool);
        /*
        * set_sport(_deportiva)
        * param si la motocicleta es deportivo o no (true / false)
        * @return
        */
        void set_sport(bool _deportiva){deportiva = _deportiva;};
        /*
        * get_sport()
        * @param
        * return true si es deportiva o false no lo es
        */
        bool get_sport(){return deportiva;};
        float calcular_precio(); // Sobreescritura
        string mostrar_caracteristicas(); // Sobreescritura
};

Motocicleta::Motocicleta(){ // Constructor por default
}

/*
* Motocicleta(marca, modelo, color, tipo_energia, kilometraje, deportiva)
*
* Constructor que recibe todos los atributos de la clase y que tambien hereda un constructor
* de la clase padre Vehículo
*
* @param marca, modelo, color, tipo_energia, kilometraje, deportiva
* @return
*/

Motocicleta::Motocicleta(string _marca, string _modelo, string _color, string _tipo_energia, float _kilometraje, bool _deportiva):Vehiculo(_marca, _modelo, _color, _tipo_energia, _kilometraje){
    tipo = "Motocicleta";
    deportiva = _deportiva;
}

/*
* calcular_precio()
*
* La funcion establece el precio de cada motocicleta respecto a las caracteristicas que posee el mismo
* Por ejemplo, si el vehiculo es de una marca deluxe como ser Yamaha, Honda o Harley-Davidson, el precio aumenta
* Del mismo modo, el tema del kilometraje es muy importante ya que al tener un kilometraje menor, la motocicleta tiene mas valor
* Adicionalmente, si la motocicleta es deportiva o no, igual influye en el precio.
*
* @param
* return precio de la motocicleta segun las caracteristicas que posee.
*/

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

/*
* mostrar_caracteristicas()
*
* La funcion concatena todas las caracteristicas de la motocicleta y la introduce dentro de una variable
*
* @param
* return string con los valores y el texto concatenado.
*/

string Motocicleta::mostrar_caracteristicas(){ // Este método aplica el concepto de sobreescritura con relacion a la clase padre Vehiculo
    stringstream aux;
    aux<<"Marca: "<<marca<<"\n"<<"Modelo: "<<modelo<<"\n"<<"Color: "<<color<<"\n"<<"Tipo de energia: "<<tipo_energia<<"\n";
    aux<<"Kilometraje: "<<kilometraje<<" km\n"<<"Deportiva: "<<deportiva<<"\n"<<"Precio: "<<calcular_precio()<<"USD\n";
    return aux.str();
}

#endif // VEHICULO_H
