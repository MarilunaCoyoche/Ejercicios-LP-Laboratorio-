//Librerías
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Clase Alumno
class Alumno {
//Atributos
private:
    std::string nombre;
    int edad;
    float promedio;
//Metodos
public:
    // Constructor de la clase Alumno
    Alumno(std::string nombre, int edad, float promedio) {
        this->nombre = nombre;
        this->edad = edad;
        this->promedio = promedio;
    }
    
    //Getters
    // Método para obtener el nombre del alumno
    std::string get_nombre() const {
        return nombre;
    }
    
    // Método para obtener la edad del alumno
    int get_edad() const {
        return edad;
    }
    
    // Método para obtener el promedio del alumno
    float get_promedio() const {
        return promedio;
    }
    
    // Operador < sobrecargado para comparar alumnos por su promedio
    bool operator<(const Alumno& otro) const {
        return promedio < otro.promedio;
    }
    
    // Método para convertir los datos del alumno a string
    std::string to_string() const {
        return nombre + " (Tiene " + std::to_string(edad) + " años) -Su promedio es: " + std::to_string(promedio);
    }
    

};

// Clase Grupo
class Grupo {
//Atributos    
private:
    std::vector<Alumno> alumnos;
    int cantidad;
    
//Métodos
public:
    // Constructor de la clase Grupo
    Grupo(int cantidad) {
        this->cantidad = cantidad;
        // Reserva espacio en memoria para la cantidad de alumnos especificada
        alumnos.reserve(cantidad);
    }
    
    // Método para agregar un alumno al grupo
    void agregar_alumno(std::string nombre, int edad, float promedio) {
        Alumno alumno(nombre, edad, promedio);
        alumnos.push_back(alumno);
    }
    
    // Método para ordenar a los alumnos del grupo por su promedio
    void ordenar_por_promedio() {
        std::sort(alumnos.begin(), alumnos.end());
    }
    
    // Método para obtener el promedio de promedios del grupo
    float promedio_grupo() const {
        float sum = 0;
        for (const auto& alumno : alumnos) {
            sum += alumno.get_promedio();
        }
        return sum / alumnos.size();
    }
    
    // Método para obtener al alumno con el peor promedio del grupo
    const Alumno& peor_promedio() const {
        const Alumno* mejor = &alumnos[0];
        for (const auto& alumno : alumnos) {
            if (alumno < *mejor) {
                mejor = &alumno;
            }
        }
        return *mejor;
    }
    
    // Método para convertir los datos del grupo a string
    string to_string() const {
        std::string result = "";
        for (const auto& alumno : alumnos) {
            result += alumno.to_string() + "\n";
        }
        return result;
    }
    
};

// Función principal main owo
int main() {
    // Crea un objeto de la clase Grupo con una cantidad de 5 alumnos
    Grupo grupo(5);
    // Agrega 5 alumnos al grupo con sus respectivos datos
    grupo.agregar_alumno("Mariluna", 18, 17.5);
    grupo.agregar_alumno("Diego", 21, 12.0);
    grupo.agregar_alumno("Adriana", 19, 19.5);
    grupo.agregar_alumno("Danna", 20, 15.5);
    grupo.agregar_alumno("Stephano", 23, 18.0);
    grupo.ordenar_por_promedio();

    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "BIENVENIDO" << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;

    cout << "El Grupo:\n" << grupo.to_string() << endl;
    cout << "--------------------------------------" << endl;

    cout << "El Promedio de promedios del grupo es: " << grupo.promedio_grupo() << endl;
    cout << "--------------------------------------" << endl;
    
    cout << "El Peor promedio es: " << grupo.peor_promedio().to_string() << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}
