#include <iostream>
#include <string>

using namespace std;

// Clase base "Móvil"
class Movil {
public:
    // Constructor de la clase base
    Movil(const string& marca, const string& modelo, const string& sistemaOperativo)
        : marca_(marca), modelo_(modelo), sistemaOperativo_(sistemaOperativo) {
        cout << "Constructor de Móvil: " << marca_ << " " << modelo_ << endl;
    }

    // Destructor de la clase base
    ~Movil() {
        cout << "Destructor de Móvil: " << marca_ << " " << modelo_ << endl;
    }

protected:
    string marca_;
    string modelo_;
    string sistemaOperativo_;
};

// Clase derivada "Teléfono"
class Telefono : public Movil {
public:
    // Constructor de la clase "Teléfono"
    Telefono(const string& marca, const string& modelo, const string& sistemaOperativo, const string& numeroTelefono)
        : Movil(marca, modelo, sistemaOperativo), numeroTelefono_(numeroTelefono) {
        cout << "Constructor de Teléfono: " << marca_ << " " << modelo_ << endl;
    }

    // Destructor de la clase "Teléfono"
    ~Telefono() {
        cout << "Destructor de Teléfono: " << marca_ << " " << modelo_ << endl;
    }

    void mostrarInformacion() {
        cout << "Teléfono: " << marca_ << " " << modelo_ << endl;
        cout << "Sistema Operativo: " << sistemaOperativo_ << endl;
        cout << "Número de teléfono: " << numeroTelefono_ << endl;
    }

private:
    string numeroTelefono_;
};

// Clase derivada "Tablet"
class Tablet : public Movil {
public:
    // Constructor de la clase "Tablet"
    Tablet(const string& marca, const string& modelo, const string& sistemaOperativo, const string& tamanoPantalla)
        : Movil(marca, modelo, sistemaOperativo), tamanoPantalla_(tamanoPantalla) {
        cout << "Constructor de Tablet: " << marca_ << " " << modelo_ << endl;
    }

    // Destructor de la clase "Tablet"
    ~Tablet() {
        cout << "Destructor de Tablet: " << marca_ << " " << modelo_ << endl;
    }

    void mostrarInformacion() {
        cout << "Tablet: " << marca_ << " " << modelo_ << endl;
        cout << "Sistema Operativo: " << sistemaOperativo_ << endl;
        cout << "Tamaño de pantalla: " << tamanoPantalla_ << endl;
    }

private:
    string tamanoPantalla_;
};

int main() {
    // Crear objetos de la clase "Teléfono" y "Tablet"
    Telefono telefono("Snasbung", "Telem S10", "Android", "89889");
    Tablet tablet("Applesss", "iPad ", "iOS", "14.9 pl");

    // Menú para mostrar información
    int opcion;
    do {
        cout << "***** MENÚ PRINCIPAL *****" << endl;
        cout << "1. Mostrar información del teléfono" << endl;
        cout << "2. Mostrar información de la tablet" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                telefono.mostrarInformacion();
                break;
            case 2:
                tablet.mostrarInformacion();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
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
