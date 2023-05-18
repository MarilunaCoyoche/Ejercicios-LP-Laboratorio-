/*
Crear una clase que represente un vector en 2D con sus componentes x e y.2.
Sobrecargar los operadores + y - para que permitan sumar y restar vectores.
3. Crear instancias de la clase vector y utilizar los operadores sobrecargados para realizar operaciones 
entreellos, como sumar y restar vectores
*/


#include <iostream>
// clase vector2d
class Vector2D {
public:
    int x;
    int y;

    Vector2D(int x, int y) : x(x), y(y) {}

    // Sobrecarga del operador + para sumar vectores
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Sobrecarga del operador - para restar vectores
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
};

// Función para imprimir un vector
void printVector(const Vector2D& vector) {
    std::cout << "Vector: (" << vector.x << ", " << vector.y << ")" << std::endl;
}

int main() {
    // Ejemplo de uso

    // Crear dos instancias de Vector2D
    Vector2D vector1(2, 3);
    Vector2D vector2(1, 4);

    // Suma de vectores
    Vector2D suma = vector1 + vector2;
    printVector(suma);  // Imprimir la suma de los vectores

    // Resta de vectores
    Vector2D resta = vector1 - vector2;
    printVector(resta); // Imprimir la resta de los vectores


// La función printVector toma un objeto Vector2D como parámetro y muestra las coordenadas x e y del vector.
    return 0;
}

/*definir cómo se comportarán los operadores en el contexto de tu propia clase, 
lo que brinda flexibilidad y expresividad al trabajar con objetos.

Al sobrecargar un operador, puedes definir cómo se realizarán las 
operaciones utilizando objetos de tu clase en lugar de los tipos de datos básicos. 

*/

