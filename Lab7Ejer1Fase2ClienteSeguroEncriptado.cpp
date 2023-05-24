#include <iostream>
#include <string>

using namespace std;

// Clase base "Cliente"
class Cliente {
//protected------------
protected:
    string nombre;
    string direccion;
    int edad;
    double saldo;

public:
    // Constructor de la clase base
    Cliente(const string& nombre, const string& direccion, int edad, double saldo)
        : nombre(nombre), direccion(direccion), edad(edad), saldo(saldo) {}

    // Destructor virtual para permitir la destrucción adecuada de objetos polimórficos
    virtual ~Cliente() {}
    
//metodo principal para mostrra la información

    void mostrarInformacion() {
        cout << "El nombre ingresado es: " << nombre << endl;
        cout << "La ciudad ingresada es: " << direccion << endl;
        cout << "La edad ingresada es: " << edad << endl;
        cout << "El saldo ingresado es: S/. " << saldo << endl;
        cout << "----------------------------------------------"  << endl;
    }
};

// Clase derivada "ClienteSeguro"
class ClienteSeguro : protected Cliente {
private:
    string claveAcceso;

public:
    // Constructor de la clase derivada que llama al constructor de la clase base 
    // inicializa el atributo adicional "claveAcceso"
    ClienteSeguro(const string& nombre, const string& direccion, int edad, double saldo, const string& claveAcceso)
        : Cliente(nombre, direccion, edad, saldo), claveAcceso(claveAcceso) {}

    // Destructor de la clase derivada
    ~ClienteSeguro() {}

    // Utilización de herencia pública para heredar el método "mostrarInformacion" de forma pública
    using Cliente::mostrarInformacion;

    void encriptarInformacion() {
        // Implementación para encriptar la información del cliente
        // Aquí se puede agregar la lógica de encriptación deseada
        // Por simplicidad, este método no realiza ninguna encriptación en este ejemplo
        // OJOOO No usar hasta los siguietes puntos de la práctica
    
    }
    
    void verificarAutenticidad() {
        // Implementación para verificar la autenticidad del cliente
        // Aquí se puede agregar la lógica de verificación deseada
        // Por simplicidad, este método no realiza ninguna verificación en este ejemplo
        // OJOOO No usar hasta los siguietes puntos de la práctica

    }
};
//funcion principal

int main() {
    string nombre, direccion, claveAcceso;
    int edad;
    double saldo;

    int opcion;
    bool salir = false;

    ClienteSeguro* clienteSeguro = nullptr;

    while (!salir) {
        // Mostrar menú
        cout << "----------------------------------------------"  << endl;
        cout << "----- Menú de Ingreso -----" << endl;
        cout << "1. Crear nuevo cliente" << endl;
        cout << "2. Mostrar información del cliente" << endl;
        cout << "3. Salir" << endl;
        cout << "----------------------------------------------"  << endl;
        cout << "Ingrese el número de opción: " << endl;
        cin >> opcion;
        cout << "----------------------------------------------"  << endl;


        switch (opcion) {
            case 1:
                // Crear nuevo cliente
                cout << "Ingrese el nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese la ciudad del cliente: ";
                cin >> direccion;
                cout << "Ingrese la edad del cliente: ";
                cin >> edad;
                cout << "Ingrese el saldo del cliente: ";
                cin >> saldo;
                cout << "Ingrese la clave de acceso del cliente: ";
                cin >> claveAcceso;

                // Eliminar el cliente anterior (si existe)
                delete clienteSeguro;

                // Crear instancia de ClienteSeguro
                clienteSeguro = new ClienteSeguro(nombre, direccion, edad, saldo, claveAcceso);
                clienteSeguro->encriptarInformacion();
                clienteSeguro->verificarAutenticidad();

                cout << "Cliente creado exitosamente." << endl;
                break;

            case 2:
                // Mostrar información del cliente
                cout << "----- Información del Cliente -----" << endl;
                if (clienteSeguro != nullptr) {
                    clienteSeguro->mostrarInformacion();
                } else {
                    cout << "No hay cliente creado." << endl;
                }
                cout << "-----------------------------------" << endl;
                break;

            case 3:
                // Salir del programa
                salir = true;
                break;

            default:
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
                break;
        }

        cout << endl;
    }

    // Eliminar el cliente creado antes de salir
    delete clienteSeguro;
    clienteSeguro = nullptr;

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

/*
destructor virtual en la clase base "Cliente" para permitir la destrucción adecuada de objetos polimórficos.

constructor en la clase derivada "ClienteSeguro" que llama al constructor de la clase base y 
también inicializa el atributo adicional "claveAcceso".

destructor en la clase derivada "ClienteSeguro" para liberar los 
recursos utilizados por la clase derivada y la clase base.

herencia protegida para heredar los atributos protegidos de la clase base en la clase derivada.

herencia pública para heredar el método "mostrarInformacion()" de forma pública, 
permitiendo su acceso desde el objeto de la clase derivada.

herencia privada al definir la clase derivada "ClienteSeguro" para ocultar los atributos y 
métodos de la clase base, haciendo que solo sean accesibles dentro de la clase derivada.

*/
