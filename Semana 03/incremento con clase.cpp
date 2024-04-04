#include <iostream>

using namespace std;

/**
   Incrementador
    Caracteristicas:
        int valor
        int valorIncremento
        int cantidadIncrementos
        
    Acciones:
        Incrementar()
        
        
        

*/

/// PascalCase -- Upper camelcase

/**
    PascalCase --- clases
    camelCase --- variables y funciones
    UPPERCASE 
    lowercase 
    snake_case -- variables y funciones
    UPPER_SNAKE_CASE --- constantes
    kebab-case -- no se usa en C++ == web
*/


/**
 private: es modificador que se uiliza para definir una propiedad o metodos privado
    algo privado es solo accedido desde dentro de la clase.
    
 protected: es modificador que se utiliza para definir una propiedad o pedoco como protegido
    algo protegido es solo accedido desde dentro de la clase y por sus hijos (herencia)
    
 public: se utiliza para deficinir la interface publica
    la interface publica es accedida desde fuera de la clase
*/

class Incrementador {
/// propiedades
private:
    int _valor;
    int _valorIncremento;
    int _cantidadIncrementos;
/// metodos
public:
    /// constructor
    Incrementador(){ // constructor por defecto
        _valor = 0;
        _cantidadIncrementos = 0;
        setValorIncremento(1);
    }   
    
    Incrementador(int incial, int incremento){
        _valor = incial;
        _cantidadIncrementos = 0;
        
        setValorIncremento(incremento);
    }
    
    void incrementar(){
        _valor += _valorIncremento;
        _cantidadIncrementos++;
    }
    
    /// getter y setter
    int getValor(){
        return _valor;
    }
    
    int getCantidad(){
        return _cantidadIncrementos;
    }
    
    
private:
    int setValorIncremento(int valorIncremento){
        _valorIncremento = valorIncremento;
        if(_valorIncremento < 0){
            _valorIncremento = 0;
        }
    }
};


int main(){
    Incrementador inc, inc2(0, 10);
    Incrementador inc3;
    Incrementador inc4(0, 15);
    
    inc3 = inc4; // guardando el valor del inc4 en los valores del inc3
    
    inc3.incrementar();
    cout << "Incrementar 3: " << inc3.getValor() << endl;
    cout << "Incrementar 4: " << inc4.getValor() << endl;
    
    cout << "----------------------" << endl;
    
    
    for(int i=0; i<10; i++){
    
        inc.incrementar();
        inc2.incrementar();
        
        cout << "Incrementar 1: " << inc.getValor() << endl;
        cout << "Incrementar 2: " << inc2.getValor() << endl;
    }
    
    
    return 0;
}














