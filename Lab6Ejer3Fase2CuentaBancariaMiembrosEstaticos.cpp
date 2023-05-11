#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//clase banco con tasa de interés
class Banco {
public:

//miembros estaticos
    static float tasaDeInteres;
    static void cambiarTasaDeInteres(float nuevaTasa) {
        tasaDeInteres = nuevaTasa;
    }
};

float Banco::tasaDeInteres = 0.05; // <-------- tasa de interés inicial del banco

//clase cuentabancaria, nombre, saldo y codigo 
class CuentaBancaria {
public:
    string nombre;
    string apellido;
    float saldo;
    int codigoDeCuenta;
    CuentaBancaria(string nombre, string apellido, float saldoInicial, int codigoDeCuenta) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->saldo = saldoInicial;
        this->codigoDeCuenta = codigoDeCuenta;
    }
    //Metodos para depositar y retirar
    void depositar(float cantidad) {
        saldo += cantidad;
    }
    void retirar(float cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
        } else {
            cout << "No tiene suficiente saldo para realizar el retiro." << endl;
        }
    }
    void mostrarInformacion() {
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout << "Cuenta Nº" << codigoDeCuenta << endl;
        cout << "Titular de la cuenta: " << nombre << " " << apellido << endl;
        cout << "Saldo actual: S/." << saldo << endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        
    }
    float calcularInteres() {
        return saldo * Banco::tasaDeInteres;
    }
};

int main() {
    vector<CuentaBancaria> cuentas;
    
    // Crear algunas cuentas de ejemplo
    cuentas.push_back(CuentaBancaria("Mariluna", "Coyoche", 1000.0, 1));
    cuentas.push_back(CuentaBancaria("María", "Pareja", 5000.0, 2));
    cuentas.push_back(CuentaBancaria("Adriana", "Ticona", 2000.0, 3));
    
    // Cambiar la tasa de interés del banco
    Banco::cambiarTasaDeInteres(0.03);

    int opcion;
    do {
        // Mostrar opciones del menú
        cout << "Seleccione una opción:" << endl;
        cout << "1. Mostrar información de todas las cuentas" << endl;
        cout << "2. Realizar depósito en una cuenta" << endl;
        cout << "3. Realizar retiro en una cuenta" << endl;
        cout << "4. Salir" << endl;
        
        // Leer opción seleccionada por el usuario
        cin >> opcion;
        
        switch(opcion) {
            case 1: // Mostrar información de todas las cuentas
                for (int i = 0; i < cuentas.size(); i++) {
                    cuentas[i].mostrarInformacion();
                    cout << "Interés ganado: S/." << cuentas[i].calcularInteres() << endl;
                    cout << endl;
                }
                break;
            case 2: // Realizar depósito en una cuenta
                int codigoDeposito;
                float cantidadDeposito;
                cout << "Ingrese el código de cuenta en el que desea hacer el depósito: ";
                cin >> codigoDeposito;
                cout << "Ingrese la cantidad que desea depositar: ";
                cin >> cantidadDeposito;
                for (int i = 0; i < cuentas.size(); i++) {
                    if (cuentas[i].codigoDeCuenta == codigoDeposito) {
                        cuentas[i].depositar(cantidadDeposito);
                        cout << "Depósito exitoso." << endl;
                        break;
                    }
                    if (i == cuentas.size() - 1) {
                        cout << "Código de cuenta no encontrado." << endl;
                    }
                }
                break;
            case 3: // Realizar retiro en una cuenta
                int codigoRetiro;
                float cantidadRetiro;
                cout << "Ingrese el código de cuenta en el que desea hacer el retiro: ";
                cin >> codigoRetiro;
                cout << "Ingrese la cantidad que desea retirar: ";
                cin >> cantidadRetiro;
                for (int i = 0; i < cuentas.size(); i++) {
                    if (cuentas[i].codigoDeCuenta == codigoRetiro) {
                        cuentas[i].retirar(cantidadRetiro);
                        break;
                    }
                    if (i == cuentas.size() - 1) {
                        cout << "Código de cuenta no encontrado." << endl;
                    }
                }
                break;
            case 4: // Salir
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
        
        cout << endl;
    } while (opcion != 4);


    //hora
    cout<<"Hora registrada"<<endl;

    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);    
    
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    return 0;
}
