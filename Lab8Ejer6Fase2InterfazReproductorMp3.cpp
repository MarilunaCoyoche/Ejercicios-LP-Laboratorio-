#include <iostream>
#include <string>

using namespace std;

// Definición de la interfaz Reproductor
class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
};

// Implementación de la clase ReproductorMP3
class ReproductorMP3 : public Reproductor {
public:
    void reproducir() override {
        cout << "Reproduciendo archivo de audio MP3" << endl;
        // Lógica para reproducir un archivo de audio MP3
    }

    void pausar() override {
        cout << "Pausando reproducción" << endl;
        // Lógica para pausar la reproducción
    }

    void detener() override {
        cout << "Deteniendo reproducción" << endl;
        // Lógica para detener la reproducción
    }
};

int main() {
    // Crear instancia de ReproductorMP3
    ReproductorMP3 reproductorMP3;

    // Probar los métodos de la interfaz
    reproductorMP3.reproducir();
    reproductorMP3.pausar();
    reproductorMP3.detener();

    // Obtener información del archivo MP3 desde el usuario
    string archivoMP3;
    cout << "Ingrese el nombre del archivo MP3: ";
    cin >> archivoMP3;
    cout << "Archivo MP3 ingresado: " << archivoMP3 << endl;

    // Realizar más operaciones con el archivo MP3 si es necesario...

    return 0;
}
