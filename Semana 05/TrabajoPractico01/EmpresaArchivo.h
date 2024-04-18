#pragma once 
#include <string>
#include "Empresa.h"

class EmpresaArchivo{
public:
    EmpresaArchivo();
    EmpresaArchivo(std::string fileName);
    
    bool guardar(Empresa empresa);
    Empresa leer(int index);
    int buscar(int numeroEmpresa);
    int getCantidadRegistros();
    bool isExist(int numeroEmpresa);
private:
    bool abrir(std::string modo="rb");
    void cerrar();

    FILE* _pFile;
    std::string _fileName;
};

