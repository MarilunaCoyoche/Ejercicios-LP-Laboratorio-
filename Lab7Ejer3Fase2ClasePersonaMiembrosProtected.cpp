#include <iostream>
#include <string>

using namespace std;

// Definición de la clase Persona
class Persona {
    //MIEMBRO PROTECTED
protected:
    string correoElectronico;

public:
    string nombre;
    int edad;
    float salario;

    void setCorreoElectronico(string correo) {
        correoElectronico = correo;
    }

    string getCorreoElectronico() {
        return correoElectronico;
    }
};

// Definición de la clase Empleado que hereda de Persona
class Empleado : public Persona {
public:
    void mostrarDatos() {
        cout << "Datos del empleado:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: " << salario << endl;
        cout << "Correo electrónico: " << correoElectronico << endl;
    }
};

// Definición de la clase Cliente que hereda de Persona
class Cliente : public Persona {
public:
    void mostrarDatos() {
        cout << "Datos del cliente:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: " << salario << endl;
        cout << "Correo electrónico: " << correoElectronico << endl;
        cout << "----------------------------------------------"  << endl;

    }
};

int main() {
    Empleado empleado;
    empleado.nombre = "Mariluna";
    empleado.edad = 18;
    empleado.salario = 2500.0;
    empleado.setCorreoElectronico("moon@gamil.com");

    Cliente cliente;
    cliente.nombre = "Adriana";
    cliente.edad = 19;
    cliente.salario = 0.0;
    cliente.setCorreoElectronico("adriana@gmail.com");

    int opcion;

    do {
        // Mostrar menú
        cout << "----------------------------------------------"  << endl;
        cout << "BIENVENIDO AL MENU PRINCIPAL:" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Mostrar datos del empleado" << endl;
        cout << "2. Mostrar datos del cliente" << endl;
        cout << "3. Salir" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;

        switch (opcion) {
            case 1:
                empleado.mostrarDatos();
                break;
            case 2:
                cliente.mostrarDatos();
                break;
            case 3:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 3);


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

