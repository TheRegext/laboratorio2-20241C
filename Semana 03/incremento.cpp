/**
    En las clases definimos caracteristicas (propiedades)  pero el objeto tiene el estado de dicha caracteristica
    Se definen las acciones (metodos) pero el objeto tiene un comportamiento
    
    Defne un objeto en programcion
    
    Estado
    Comportamiento
    Identidad
*/


/**
   Incrementador
    Caracteristicas:
        int valor
        int valorIncremento
        int cantidadIncrementos
        
    Acciones:
        Incrementar()
*/


#include <iostream>

using namespace std;

void incremenarIncrementador(int &, int &);

int main(){
    int incrementador;
    bool incrementar = true;
    int cantidad = 0;
    
    
    cout << "Quiere incrementar?" << endl;
    cin >> incrementar;
    
    while(incrementar){
        incremenarIncrementador(incrementador, cantidad);
        
        cout << "Valor actual: " << incrementador << endl;
        
        cout << "Quiere incrementar?" << endl;
        cin >> incrementar;    
    }
    
    incremenarIncrementador(incrementador, cantidad);
    
    cout << "Valor final: " << incrementador << endl;
    cout << "Cantidad de incrementos: " << cantidad << endl;
    
    
    return 0;
}


void incremenarIncrementador(int &incrementador, int &contador){
    incrementador += 50;
    contador++;
        
}

