#include "EmpresaArchivo.h"
using namespace std;

EmpresaArchivo::EmpresaArchivo(){
    _fileName = "empresas.dat";
}

EmpresaArchivo::EmpresaArchivo(string filename)
{
   _fileName = filename;
}

int EmpresaArchivo::getCantidadRegistros(){
    
    if(abrir("rb") == false){
        return 0;
    }
    
    fseek(_pFile, 0, SEEK_END);
    int tam = ftell(_pFile);
    
    cerrar();
    
    return tam / sizeof(Empresa);

}

bool EmpresaArchivo::guardar(Empresa empresa){
    
    int grabo;
    
    if(abrir("ab") == false){
        return false;
    }
    
    grabo = fwrite(&empresa, sizeof (Empresa), 1, _pFile);
    
    cerrar();
    
    return grabo;
}


int EmpresaArchivo::buscar(int numeroEmpresa){
    int index = 0;
    Empresa empresa;
    
    if(abrir("rb") == false){
        return -1;
    }
    
    while(fread(&empresa, sizeof (Empresa), 1, _pFile)){
        if(empresa.getNumero() == numeroEmpresa){
            break;
        }
        
        index++;
    }
    
    cerrar();
    
    if(empresa.getNumero() == numeroEmpresa){
        // si encontre la empresa
        return index;
    }   
    else{
        /// si no encontre la empresa
        return -1;
    }
    
}              

Empresa EmpresaArchivo::leer(int index){
    Empresa empresa;
    
    if(abrir("rb") == false){
        return empresa;
    }
   
    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);
    
    fread(&empresa, sizeof(Empresa), 1, _pFile);
    
    cerrar();
    
    return empresa;
}


bool EmpresaArchivo::isExist(int numeroEmpresa){
    return buscar(numeroEmpresa) != -1;
}
