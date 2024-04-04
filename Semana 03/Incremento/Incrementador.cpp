#include "Incrementador.h"

Incrementador::Incrementador(){ // constructor por defecto
    _valor = 0;
    _cantidadIncrementos = 0;
    setValorIncremento(1);
}   

Incrementador::Incrementador(int incial, int incremento){
    _valor = incial;
    _cantidadIncrementos = 0;
    
    setValorIncremento(incremento);
}

void Incrementador::incrementar(){
    _valor += _valorIncremento;
    _cantidadIncrementos++;
}

/// getter y setter
int Incrementador::getValor(){
    return _valor;
}

int Incrementador::getCantidad(){
    return _cantidadIncrementos;
}

int Incrementador::setValorIncremento(int valorIncremento){
    _valorIncremento = valorIncremento;
    if(_valorIncremento < 0){
        _valorIncremento = 0;
    }
}
