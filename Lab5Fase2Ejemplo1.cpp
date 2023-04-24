// Codigo 3.02: practica3_02.cpp
// demostración del uso de las autoreferencias.

#include <iostream> 
using namespace std;
class Clase
{
    int variableEntera; 
    float variableFlotante;

public:
    Clase()
    {
        variableEntera = 0;
        variableFlotante = 0;
    }
    int getVariableEntera()
    {
        return this -> variableEntera;
    }
    float getVariableFlotante()
    {
        return this -> variableFlotante;
    }
    Clase& sumaEntero(int n)
    {
        variableEntera += n; 
        return *this;
    }
    Clase& sumaFlotante(float n)
    {
    variableFlotante += n; 
    return *this;
    }
};

int main()
{
    Clase objeto;
    cout << objeto.getVariableEntera() << endl; 
    cout << objeto.getVariableFlotante() << endl; 
    objeto.sumaEntero(5).sumaFlotante(3.5);
    cout << objeto.getVariableEntera() << endl; 
    cout << objeto.getVariableFlotante() << endl; 
    system("pause");
    return 0;
}
