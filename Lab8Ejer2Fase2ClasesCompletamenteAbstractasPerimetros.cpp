#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Clase abstracta "Forma"
class Forma {
public:
    virtual ~Forma() {}

    // Método abstracto para calcular el perímetro
    virtual double calcularPerimetro() const = 0;
};

// Clase derivada "Círculo"
class Circulo : public Forma {
private:
    double radio;

public:
    // Constructor
    Circulo(double radio) : radio(radio) {}

    // Implementación del método calcularPerimetro para el círculo
    double calcularPerimetro() const override {
        return 2 * 3.14159 * radio;
    }
};

// Clase derivada "Rectángulo"
class Rectangulo : public Forma {
private:
    double lado1;
    double lado2;

public:
    // Constructor
    Rectangulo(double lado1, double lado2) : lado1(lado1), lado2(lado2) {}

    // Implementación del método calcularPerimetro para el rectángulo
    double calcularPerimetro() const override {
        return 2 * (lado1 + lado2);
    }
};

// Clase derivada "Triángulo"
class Triangulo : public Forma {
private:
    double lado1;
    double lado2;
    double lado3;

public:
    // Constructor
    Triangulo(double lado1, double lado2, double lado3) : lado1(lado1), lado2(lado2), lado3(lado3) {}

    // Implementación del método calcularPerimetro para el triángulo
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
};

// Clase abstracta "FabricaForma"
class FabricaForma {
public:
    virtual ~FabricaForma() {}

    // Método abstracto para crear una forma
    virtual unique_ptr<Forma> crearForma() const = 0;
};

// Clase derivada "FabricaCirculo"
class FabricaCirculo : public FabricaForma {
public:
    unique_ptr<Forma> crearForma() const override {
        double radio;
        cout << "Ingrese el radio del círculo: ";
        cin >> radio;
        return make_unique<Circulo>(radio);
    }
};

// Clase derivada "FabricaRectangulo"
class FabricaRectangulo : public FabricaForma {
public:
    unique_ptr<Forma> crearForma() const override {
        double lado1, lado2;
        cout << "Ingrese el lado 1 del rectángulo: ";
        cin >> lado1;
        cout << "Ingrese el lado 2 del rectángulo: ";
        cin >> lado2;
        return make_unique<Rectangulo>(lado1, lado2);
    }
};

// Clase derivada "FabricaTriangulo"
class FabricaTriangulo : public FabricaForma {
public:
    unique_ptr<Forma> crearForma() const override {
        double lado1, lado2, lado3;
        cout << "Ingrese el lado 1 del triángulo: ";
        cin >> lado1;
        cout << "Ingrese el lado 2 del triángulo: ";
        cin >> lado2;
        cout << "Ingrese el lado 3 del triángulo: ";
        cin >> lado3;
        return make_unique<Triangulo>(lado1, lado2, lado3);
    }
};

int main() {
    // Vector de fábricas de formas
    vector<unique_ptr<FabricaForma>> fabricasFormas;
    fabricasFormas.push_back(make_unique<FabricaCirculo>());
    fabricasFormas.push_back(make_unique<FabricaRectangulo>());
    fabricasFormas.push_back(make_unique<FabricaTriangulo>());

    // Selección
    cout << "BIENVENIDO--- CARGANDO FIGURAS OWO"<< endl;
    cout << "---------------------------------------------------------"<< endl;
    for (size_t i = 0; i < fabricasFormas.size(); i++) {
        cout << i + 1 << ". ";
        unique_ptr<Forma> forma = fabricasFormas[i]->crearForma();
        cout << "Perímetro de la forma: " << forma->calcularPerimetro() << endl;
    }

    // Selección de opción
    size_t opcion;
    cout << "Ingrese la opción: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= fabricasFormas.size()) {
        unique_ptr<Forma> forma = fabricasFormas[opcion - 1]->crearForma();
        cout << "El perímetro es: " << forma->calcularPerimetro() << endl;
    } else {
        cout << "Opción inválida.\n";
    }
    
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
