#include <iostream>
#include <vector>

using namespace std;

// Clase base Animal
class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido desconocido." << endl;
    }
};

// Clase derivada Perro
class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "---------------------------------------------" << endl;
        cout << "PERRO EMPIEZA A DECIR:" << endl;
        cout << "El perro hace: gufgufgufgufgufgfufhfuf / le muerde*" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// Clase derivada Gato
class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "GATO EMPIEZA A DECIR:" << endl;
        cout << "El gato hace: miaumiaumiaumoiau" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// Clase derivada Vaca
class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "VACA EMPIEZA A DECIR:" << endl;
        cout << "muuuuuuuuuuuuuuuuu" << endl;
        cout << "---------------------------------------------" << endl;

    }
};

// Clase derivada Caballo
class Caballo : public Animal {
public:
    void hacerSonido() override {
        cout << "CABALLO EMPIEZA A DECIR:" << endl;
        cout << "GSDGSDJSDSDDSDSDKSDJSHJDS" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

int main() {
    // Crear un vector de punteros a Animal
    vector<Animal*> animales;

    // Agregar objetos de diferentes animales al vector
    animales.push_back(new Perro());
    animales.push_back(new Gato());
    animales.push_back(new Vaca());
    animales.push_back(new Caballo());

    // Iterar sobre el vector y llamar al método hacerSonido() para cada objeto POLIMORFISMO
    for (Animal* animal : animales) {
        animal->hacerSonido();
    }

    // Liberar la memoria asignada dinámicamente
    for (Animal* animal : animales) {
        delete animal;
    }

    return 0;
}
