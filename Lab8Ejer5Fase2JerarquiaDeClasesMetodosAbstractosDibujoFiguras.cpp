#include <iostream>
#include <cmath>

using namespace std;

// Clase abstracta Figura
class Figura {
public:
    virtual void dibujar() = 0; // Método abstracto para dibujar la figura
    virtual double calcularArea() = 0; // Método abstracto para calcular el área de la figura
};

// Clase Círculo, derivada de Figura
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    void dibujar() {
        cout << "Dibujando un círculo." << endl;
    }

    double calcularArea() {
        return M_PI * radio * radio;
    }
};

// Clase Rectángulo, derivada de Figura
class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    void dibujar() {
        cout << "Dibujando un rectángulo." << endl;
    }

    double calcularArea() {
        return base * altura;
    }
};

// Clase Triángulo, derivada de Figura
class Triangulo : public Figura {
private:
    double base;
    double altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    void dibujar() {
        cout << "Dibujando un triángulo." << endl;
    }

    double calcularArea() {
        return (base * altura) / 2.0;
    }
};

int main() {
    // Crear un arreglo de punteros a Figura
    Figura* figuras[3];

    // Crear instancias de cada figura y asignarlas al arreglo
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(3.0, 8.0);

    // Llamar a los métodos implementados usando polimorfismo
    for (int i = 0; i < 3; i++) {
        figuras[i]->dibujar();
        cout << "Área: " << figuras[i]->calcularArea() << endl;        
        cout << "---------------------------------------------------------"<< endl;
    }

    // Liberar la memoria de las instancias creadas
    for (int i = 0; i < 3; i++) {
        delete figuras[i];
    }

    return 0;
}
