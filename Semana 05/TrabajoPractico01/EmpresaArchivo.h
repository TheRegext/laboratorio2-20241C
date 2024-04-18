#pragma once 
#include <string>
#include "Empresa.h"
#include "Archivo.h"

class EmpresaArchivo: public Archivo{
public:
    EmpresaArchivo();
    EmpresaArchivo(std::string fileName);
    
    bool guardar(Empresa empresa);
    Empresa leer(int index);
    int buscar(int numeroEmpresa);
    int getCantidadRegistros();
    bool isExist(int numeroEmpresa);
private:
   

};

