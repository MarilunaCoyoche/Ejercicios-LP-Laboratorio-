//tiendita.cpp
//PROGRAMA QUE USA PUNTEROS

//Librerías
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

//Clase Producto , implementación de get y set


class Producto {
    private:
        string nombre;
        string descripcion;
        float precio;
        int cantidad;

    public:
        Producto(string nombre, string descripcion, float precio, int cantidad) {
            this->nombre = nombre;
            this->descripcion = descripcion;
            this->precio = precio;
            this->cantidad = cantidad;
        }

        string getNombre() {
            return nombre;
        }

        void setNombre(string nombre) {
            this->nombre = nombre;
        }

        string getDescripcion() {
            return descripcion;
        }

        void setDescripcion(string descripcion) {
            this->descripcion = descripcion;
        }

        float getPrecio() {
            return precio;
        }

        void setPrecio(float precio) {
            this->precio = precio;
        }

        int getCantidad() {
            return cantidad;
        }

        void setCantidad(int cantidad) {
            this->cantidad = cantidad;
        }
};


//clase secundaria tienda, contiene las funciones 
class Tienda {
    private:
        Producto** productos;
        int cantidadProductos;
        int maxProductos;
        int op;

    public:
        Tienda(int maxProductos) {
            this->maxProductos = maxProductos;
            cantidadProductos = 0;
            productos = new Producto*[maxProductos];
        }

        ~Tienda() {
            for(int i = 0; i < cantidadProductos; i++) {
                delete productos[i];
            }
            delete[] productos;
        }

        void agregarProducto(string nombre, string descripcion, float precio, int cantidad) {
            if(cantidadProductos < maxProductos) {
                productos[cantidadProductos] = new Producto(nombre, descripcion, precio, cantidad);
                cantidadProductos++;
            }
            else {
                cout << "No se pueden agregar mas productos, la tienda esta llena" << endl;
            }
        }

        void imprimirProductos() {
            if(cantidadProductos > 0) {
                for(int i = 0; i < cantidadProductos; i++) {
                    cout <<"El producto " << i+1 << ": " << productos[i]->getNombre() <<endl;
                    cout <<"Su escripcion es: " << productos[i]->getDescripcion() <<endl;
                    cout <<"El precio es: S/." << productos[i]->getPrecio() <<endl;
                    cout <<"La cantidad en inventario es : " << productos[i]->getCantidad()<<" "<< productos[i]->getNombre()<<"(s/es)" << endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;

                }
            }
            else {
                cout << "No hay productos en la tienda" << endl;
            }
        }

        void Menu() {
            op=0;
                while (op != 1 && op != 2) {             
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Desea comprar los productos agregados? "<<endl;
                cout<<"1. SI "<<endl;
                cout<<"2. NO"<<endl;
                cout<<"Ingresar opcion: ";
                cin>>op;
                switch(op)
                {
                case 1:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Compra ralizada "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"HORA Y FECHA DE LA COMPRA - GRACIAS POR SU PREFERENCIA!!!"<<endl;
                    break;
                case 2:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Compra NO ralizada "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"HORA Y FECHA"<<endl;
                    break;
        
                }
            }
                    
        }
            
};


//Main
int main() {  
    
    Tienda tienda(5);

    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"BIENVENIDO A LA TIENDA VIRTUAL GAMER"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    
    cout<<"Se agregaron los siguiente productos a su carrito: "<<endl;
    tienda.agregarProducto("Playstation", "Consola de videojuegos edicion 5 modelo spiderman", 5000.0, 20);
    tienda.agregarProducto("Monitor", "Pantalla curva marca Teros de 49 pulgadas", 4560.0, 16);
    tienda.agregarProducto("Teclado", "Teclado mecanico rgb Redragon", 250.0, 25);
    tienda.agregarProducto("Microfono", "Microfono profesional 10 niveles turbo pro max ultra delta alfa sonido", 195.0, 22);
    tienda.imprimirProductos();
    tienda.Menu();
 
  
    //hora
    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);    
    


return 0;
}


