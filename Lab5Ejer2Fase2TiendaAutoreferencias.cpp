//Programa que usa AUTOREFERENCIA (algunos punteros)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto {
public:
    string nombre;
    double precio;

//punteros 
    Producto(string nombre, double precio) {
        this->nombre = nombre;
        this->precio = precio;
    }
};

class CarritoDeCompras {
private:
    vector<Producto*> productos;
    double total;

public:
    CarritoDeCompras() {
        this->total = 0;
    }

//AUTOREFERENCIA EN ESTE METODOOO agregarProducto   REFRENCIA AL PRODUCTO DEL CARRITO AGRGA PUNTERO COMO REFERENCIA
    void agregarProducto(Producto& producto) {
        this->productos.push_back(&producto);
        this->total += producto.precio;
    }

    void quitarProducto(Producto& producto) {
        for (auto it = productos.begin(); it != productos.end(); it++) {
            if (*it == &producto) {
                productos.erase(it);
                this->total -= producto.precio;
                break;
            }
        }
    }

    double getTotal() {
        return this->total;
    }
};


//main
int main() {
    Producto p1("Laptop", 1000.00);
    Producto p2("Celular", 500.00);
    Producto p3("Tablet", 250.00);

    CarritoDeCompras carrito;
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.agregarProducto(p3);
    carrito.quitarProducto(p2);

    cout << "Total: S/." << carrito.getTotal() << endl;

    return 0;
}
