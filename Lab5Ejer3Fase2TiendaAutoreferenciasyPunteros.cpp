//PROGRAMA QUE USA PUNTEROS Y AUTOREFERENCIA

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {
public:
    string nombre;
    string direccion;
    int telefono;

    Cliente(string nombre, string direccion, int telefono) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telefono;
    }
};

class Producto {
public:
    string nombre;
    double precio;
    int cantidad;

    Producto(string nombre, double precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }
};

class CarritoDeCompras {
private:
    vector<Producto*> productos;
    double total;
    Cliente* cliente;
    string fecha;

public:

/*En el constructor CarritoDeCompras, AUTOREF para asignar los valores de los nuevos atributosSS*/
    CarritoDeCompras(Cliente& cliente, string fecha) {
        this->total = 0;
        this->cliente = &cliente;
        this->fecha = fecha;
    }

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

    Cliente* getCliente() {
        return this->cliente;
    }
 /*getFecha,  autoreferencia "this" para devolver la cadena de 
 caracteres que representa la fecha de la compra.*/
    string getFecha() {
        return this->fecha;
    }
};

//MAIN

int main() {
    Cliente cliente("Juan", "Calle 123", 1234567);
    Producto p1("Laptop", 1000.00, 1);
    Producto p2("Celular", 500.00, 2);
    Producto p3("Tablet", 250.00, 3);

    CarritoDeCompras carrito(cliente, "24/04/2023");
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.agregarProducto(p3);
    carrito.quitarProducto(p2);

    cout << "Total: S/." << carrito.getTotal() << endl;
    cout << "Cliente: " << carrito.getCliente()->nombre << endl;
    cout << "Fecha: " << carrito.getFecha() << endl;

    return 0;
}
