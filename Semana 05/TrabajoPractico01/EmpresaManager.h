#pragma once
#include "Empresa.h"   
#include "EmpresaArchivo.h"

class EmpresaManager{
public:
    Empresa crearEmpresa();
    void mostrar(Empresa empresa);
    void menu();
    
private:
    void buscarEmpresa();
    void cargarEmpresa();
    void listarEmpresas();
    EmpresaArchivo empresaArchivo;
    
};
