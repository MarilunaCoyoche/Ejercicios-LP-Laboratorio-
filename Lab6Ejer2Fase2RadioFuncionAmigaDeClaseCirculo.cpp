
/*
Crear una clase que represente un círculo con su radio y diámetro, a este 
agrégale una función que calcule el área de un círculo dado su radio. 
Hacer que la función sea amiga de la clase círculo, de forma que pueda acceder a su radio. 
Crear instancias de la clase círculo y utilizar la función para calcular sus áreas. 
Permitir ingresar datos por teclado, que tenga setters y getters para los atributos. 
*/
#include <iostream>
#include <cmath> 
// Necesario para usar M_PI (valor de pi)

using namespace std;

//clase circulo
class Circulo {
    //atributos
private:
    float radio;
    float diametro;

public:
//constructor
    Circulo(float r) {
        radio = r;
        diametro = r * 2.0;
    }

    // Getter y setter para el radio
    float getRadio() const {
        return radio;
    }

    void setRadio(float r) {
        radio = r;
        diametro = r * 2.0;
    }

    // Getter para el diámetro
    float getDiametro() const {
        return diametro;
    }

//funcion amiga de la clase Circulo 
    // Función para calcular el área de un círculo
    friend float calcularArea(const Circulo& c) {
        //acceder al radio del círculo para calcular su área
        float radio = c.radio;
        return M_PI * pow(radio, 2);
    }
};

int main() {
    // Pedimos al usuario que ingrese el radio del círculo
    
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"BIENVENIDO USUARIO"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    float radio;
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    // objeto de la clase Circulo con el radio ingresado
    Circulo c(radio);

    // Mostramos el radio y el diámetro del círculo
    cout << "Radio: " << c.getRadio() << endl;
    cout << "Diametro: " << c.getDiametro() << endl;

    // area del círculo utilizando la función amiga
    float area = calcularArea(c);
    cout << "Area: " << area << endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
      
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
