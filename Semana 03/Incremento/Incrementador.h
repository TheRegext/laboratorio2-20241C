#pragma once
class Incrementador {
public:
     Incrementador();
     Incrementador(int incial, int incremento);
     void incrementar();
     int getValor();
     int getCantidad();

private:
    int _valor; // acumulador
    int _valorIncremento; // valor a acumular
    int _cantidadIncrementos; // contador
    
    int setValorIncremento(int valorIncremento);
};
