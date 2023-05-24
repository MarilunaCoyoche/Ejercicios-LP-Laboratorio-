/*

Crea una clase base "Vehículo" con atributos como la marca, modelo, año de fabricación y precio.
Luego, crea dos clases derivadas, "Automóvil" y "Motocicleta" que hereden de la clase "Vehículo" 
y añade atributos específicos como número de puertas y tipo de combustible en el caso del automóvil
y cilindrada en el caso de la motocicleta.

*/


#include <iostream>
#include <string>
using namespace std;

// Definición de la clase base "Vehículo"
class Vehiculo {
public:
    string marca;
    string modelo;
    int anioFabricacion;
    float precio;
};

// Definición de la clase derivada "Automóvil"
class Automovil : public Vehiculo {
public:
    int numeroPuertas;
    string tipoCombustible;
};

// Definición de la clase derivada "Motocicleta"
class Motocicleta : public Vehiculo {
public:
    int cilindrada;
};

int main() {
    // Creación de objetos de las clases derivadas
    Automovil auto1;
    auto1.marca = "Alfa Romeo";
    auto1.modelo = "Alfetta";
    auto1.anioFabricacion = 2022;
    auto1.precio = 250000.0;
    auto1.numeroPuertas = 4;
    auto1.tipoCombustible = "Gasolina";

    Motocicleta moto1;
    moto1.marca = "Cholp";
    moto1.modelo = "AR393848";
    moto1.anioFabricacion = 2021;
    moto1.precio = 8000.0;
    moto1.cilindrada = 500;
    
    cout << "----------------------------------------------"  << endl;
    cout << "VEHICULOS REGISTRADOS:"  << endl;
    cout << "----------------------------------------------"  << endl;

    // Accediendo a los atributos de los objetos
    cout << "----------------------------------------------"  << endl;
    cout << "Automóvil 1: " << auto1.marca << " " << auto1.modelo << endl;
    cout << "Año de fabricación: " << auto1.anioFabricacion << endl;
    cout << "Precio: $" << auto1.precio << endl;
    cout << "Número de puertas: " << auto1.numeroPuertas << endl;
    cout << "Tipo de combustible: " << auto1.tipoCombustible << endl;
    cout << "----------------------------------------------"  << endl;


    cout << endl;
    cout << "----------------------------------------------"  << endl;
    cout << "Motocicleta 1: " << moto1.marca << " " << moto1.modelo << endl;
    cout << "Año de fabricación: " << moto1.anioFabricacion << endl;
    cout << "Precio: $" << moto1.precio << endl;
    cout << "Cilindrada: " << moto1.cilindrada << " cc" << endl;
    cout << "----------------------------------------------"  << endl;
    cout << " "  << endl;
    cout << "----------------------------------------------"  << endl;
    
    //hora
    cout<<"Hora registrada"<<endl;

    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);    
    
    cout << "----------------------------------------------"  << endl;
    return 0;
}

