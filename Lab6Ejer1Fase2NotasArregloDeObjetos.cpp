#include <iostream>
#include <string>

using namespace std;

//Cantidadd maxima de estudiantes
const int MAX_ESTUDIANTES = 100;

//clase estudiante
class Estudiante {
public:
    string nombre;
    int edad;
    int codigo;
    float notas[5];

    Estudiante() {}

//constructoe de estudiante 
    Estudiante(string nombre, int edad, int codigo) {
        this->nombre = nombre;
        this->edad = edad;
        this->codigo = codigo;
    }

//Añadir 5 notas por estudante
    void setNotas(float nota1, float nota2, float nota3, float nota4, float nota5) {
        notas[0] = nota1;
        notas[1] = nota2;
        notas[2] = nota3;
        notas[3] = nota4;
        notas[4] = nota5;
    }

//prommm
    float promedio() {
        float suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += notas[i];
        }
        return suma / 5;
    }
};

//main
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes;
    
//Presentación

    cout << "-----------------------------------------------" << endl;
    cout << "Bienvenido al registro de notas 0w0: " << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Ingrese el número de estudiantes a agregar: ";
    cin >> numEstudiantes;

    for (int i = 0; i < numEstudiantes; i++) {
        string nombre;
        int edad, codigo;
        float nota1, nota2, nota3, nota4, nota5;

        cout << "\nEstudiante " << i+1 << endl;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        cout << "Código: ";
        cin >> codigo;

        cout << "Notas (separadas por espacios, agregue 5 notas por estudiante): ";
        cin >> nota1 >> nota2 >> nota3 >> nota4 >> nota5;
        cout << "-----------------------------------------------" << endl;

        estudiantes[i] = Estudiante(nombre, edad, codigo);
        estudiantes[i].setNotas(nota1, nota2, nota3, nota4, nota5);
    }

    float notaConsulta;
    cout << "\nIngrese una nota para hacer la consulta: ";
    cin >> notaConsulta;

    cout << "\nEstudiantes con notas iguales/mayores a " << notaConsulta << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].promedio() >= notaConsulta) {
            cout << estudiantes[i].nombre << " (" << estudiantes[i].codigo << "): ";
            for (int j = 0; j < 5; j++) {
                cout << estudiantes[i].notas[j] << " ";
            }
            cout << endl;
        }
    }


    //hora de registro
    cout << "-----------------------------------------------" << endl;
    cout << "Fin de registro" << endl;

    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);    
    

    return 0;
}
