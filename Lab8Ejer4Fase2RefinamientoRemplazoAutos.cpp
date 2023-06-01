#include <iostream>

using namespace std;

// Clase base Vehículo
class Vehiculo {
public:
    // Método acelerar
    void acelerar() {
        cout << "Acelerando el VEHICULO" << endl;
        cout<<"-----------------------------------------------------"<<endl;

    }
};

// Clase derivada Coche
class Coche : public Vehiculo {
public:
    // Método acelerar (redefinido)
    void acelerar() {
        cout << "Acelerando el COCHE" << endl;
        cout<<"-----------------------------------------------------"<<endl;
    }

    // Nuevo método encenderLuces
    void encenderLuces() {
        cout << "Luces del COCHE estan encendidas" << endl;
        cout<<"-----------------------------------------------------"<<endl;

    }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
public:
    // Método acelerar (redefinido)
    void acelerar() {
        cout << "Acelerando la MOTO" << endl;
        cout<<"-----------------------------------------------------"<<endl;

    }
};

int main() {
    // Crear instancia de Coche
    Coche miCoche;

    // Llamar al método acelerar de Coche
    miCoche.acelerar();

    // Crear instancia de Motocicleta
    Motocicleta miMotocicleta;

    // Llamar al método acelerar de Motocicleta
    miMotocicleta.acelerar();

    // Llamar al método encenderLuces de Coche
    miCoche.encenderLuces();
     
    //hora
    
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Hora y fecha "<<endl;
    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);
    

    return 0;
}
