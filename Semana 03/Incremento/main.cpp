#include <iostream>
#include "Incrementador.h"

using namespace std;

int main(){
    
    // Incrementador vInc[5]; // se crean 5 objetos y se les llama al constructor por defecto
    Incrementador vInc[5]{
        Incrementador(), 
        Incrementador(0,15), 
        Incrementador(0,10),
        Incrementador(0,1),
        Incrementador(0,2)
    };
    
    for(int i=0; i<5; i++){
        vInc[i].incrementar();
    }
    
    for(int i=0; i<5; i++){
        vInc[i].incrementar();
    }
    
    for(int i=0; i<5; i++){
        vInc[i].incrementar();
    }
    
    for(int i=0; i<5; i++){
        cout << "Valor final: " << vInc[i].getValor() << endl;
    }
    
    
    return 0;
}



/*
int main(){
    bool incrementar = true;
    Incrementador inc(0, 50);
        
    cout << "Quiere incrementar?" << endl;
    cin >> incrementar;
    
    while(incrementar){
        inc.incrementar();
        
        cout << "Valor actual: " << inc.getValor()<< endl;
        
        cout << "Quiere incrementar?" << endl;
        cin >> incrementar;    
    }
    
 
    cout << "Valor final: " << inc.getValor() << endl;
    cout << "Cantidad de incrementos: " << inc.getCantidad() << endl;
   
    return 0;
}
*/
