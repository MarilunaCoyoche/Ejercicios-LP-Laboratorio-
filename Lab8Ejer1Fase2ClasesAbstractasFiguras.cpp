#include <iostream>
#include <cmath>

using namespace std;

class Figura {
public:
    virtual float calcularArea() = 0;
};

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(float radio) : radio(radio) {}

    float calcularArea() override {
        return M_PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    float base;
    float altura;

public:
    Rectangulo(float base, float altura) : base(base), altura(altura) {}

    float calcularArea() override {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    float base;
    float altura;

public:
    Triangulo(float base, float altura) : base(base), altura(altura) {}

    float calcularArea() override {
        return (base * altura) / 2;
    }
};

class Cuadrado : public Figura {
private:
    float lado;

public:
    Cuadrado(float lado) : lado(lado) {}

    float calcularArea() override {
        return lado * lado;
    }
};

class Pentagono : public Figura {
private:
    float lado;

public:
    Pentagono(float lado) : lado(lado) {}

    float calcularArea() override {
        float apotema = lado / (2 * tan(M_PI / 5));
        float perimetro = 5 * lado;
        return (perimetro * apotema) / 2;
    }
};

int main() {
    int opcion;
    float medida1, medida2;

    cout << "BIENVENIDO AL MENÚ PRINCIPAL:" << endl;        
    cout << "Elige una opción::" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1. Círculo" << endl;
    cout << "2. Rectángulo" << endl;
    cout << "3. Triángulo" << endl;
    cout << "4. Cuadrado" << endl;
    cout << "5. Pentágono" << endl;
    cout << "Ingrese el número de la opción: ";
    cin >> opcion;
    cout << "---------------------------------------------" << endl;

    Figura* figura;

    switch (opcion) {
        case 1:
            // Solicitar el radio del círculo
            cout << "Ingrese el radio del círculo: ";
            cin >> medida1;
            figura = new Circulo(medida1);
            break;
        case 2:
            // Solicitar la base y altura del rectángulo
            cout << "Ingrese la base del rectángulo: ";
            cin >> medida1;
            cout << "Ingrese la altura del rectángulo: ";
            cin >> medida2;
            figura = new Rectangulo(medida1, medida2);
            break;
        case 3:
            // Solicitar la base y altura del triángulo
            cout << "Ingrese la base del triángulo: ";
            cin >> medida1;
            cout << "Ingrese la altura del triángulo: ";
            cin >> medida2;
            figura = new Triangulo(medida1, medida2);
            break;
        case 4:
            // Solicitar el lado del cuadrado
            cout << "Ingrese el lado del cuadrado: ";
            cin >> medida1;
            figura = new Cuadrado(medida1);
            break;
        case 5:
            // Solicitar el lado del pentágono
            cout << "Ingrese el lado del pentágono: ";
            cin >> medida1;
            figura = new Pentagono(medida1);
            break;
        default:
            cout << "Opción inválida." << endl;
            return 0;
    }

    // Calcular el área de la figura seleccionada
    float area = figura->calcularArea();
    cout << "El área de la figura seleccionada es: " << area << endl;
    cout << "---------------------------------------------" << endl;
    
    // Liberar la memoria
    delete figura;
    
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
