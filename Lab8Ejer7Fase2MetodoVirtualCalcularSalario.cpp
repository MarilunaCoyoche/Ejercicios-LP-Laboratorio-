#include <iostream>

using namespace std;

// Clase base Empleado
class Empleado {
public:
    // Método virtual para calcular el salario
    virtual float calcularSalario() {
        return 0.0f; // El salario por defecto es 0.0
    }
};

// Clase derivada EmpleadoTiempoCompleto
class EmpleadoTiempoCompleto : public Empleado {
public:
    // Redefinición del método calcularSalario
    float calcularSalario() override {
        // Cálculo del salario para un empleado a tiempo completo
        float salarioBase = 2000.0f;
        float bono = 500.0f;
        return salarioBase + bono;
    }
};

// Clase derivada EmpleadoMedioTiempo
class EmpleadoMedioTiempo : public Empleado {
public:
    // Redefinición del método calcularSalario
    float calcularSalario() override {
        // Cálculo del salario para un empleado a medio tiempo
        float salarioBase = 1000.0f;
        float bono = 250.0f;
        return salarioBase + bono;
    }
};

int main() {
    int opcion;
    
    do {
        // Mostrar el menú
        cout << "----------------------------------------------"  << endl;
        cout << "MENU PRINCIPAL:"  << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "1. Empleado a tiempo completo" << endl;
        cout << "2. Empleado a medio tiempo" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;

        
        switch (opcion) {
            case 1: {
                // Crear instancia de EmpleadoTiempoCompleto
                EmpleadoTiempoCompleto empleadoTiempoCompleto;
                float salario = empleadoTiempoCompleto.calcularSalario();
                cout << "Salario del empleado a tiempo completo: S/. " << salario << endl;
                break;
            }
            case 2: {
                // Crear instancia de EmpleadoMedioTiempo
                EmpleadoMedioTiempo empleadoMedioTiempo;
                float salario = empleadoMedioTiempo.calcularSalario();
                cout << "Salario del empleado a medio tiempo: S/. " << salario << endl;
                break;
            }
            case 3:
                cout << "Saliendo del programa OWO" << endl;
                break;
            default:
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
