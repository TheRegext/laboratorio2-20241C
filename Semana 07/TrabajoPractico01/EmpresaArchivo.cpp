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

bool EmpresaArchivo::guardar(int index, Empresa empresa){
    int grabo;
    
    if(abrir("rb+") == false){
        return false;
    }
    
    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);
    
    grabo = fwrite(&empresa, sizeof (Empresa), 1, _pFile);
    
    cerrar();
    
    return grabo;

}


int EmpresaArchivo::buscar(int numeroEmpresa){
    int index = 0;
    Empresa empresa;
    
    if(abrir("rb+") == false){
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


bool EmpresaArchivo::copiaSeguridad(string fileName){
    FILE *pFileBkp;
    Empresa reg;
    
    pFileBkp = fopen(fileName.c_str(), "wb");
    
    if(pFileBkp == nullptr){
        return false;
    }

    int cantReg = getCantidadRegistros();
    
    for(int i=0;i<cantReg;i++){
        reg=leer(i);
        fwrite(&reg, sizeof reg, 1, pFileBkp);
    }
    
    fclose(pFileBkp);
    
    return true;
}


bool EmpresaArchivo::restaurarCopiaSeguridad(string fileName){
    Empresa reg;

    EmpresaArchivo archiBak(fileName);

    if(!abrir("wb")){
        return false;
    }

    int cantReg = archiBak.getCantidadRegistros();
    
    for(int i=0;i<cantReg;i++){
        reg=archiBak.leer(i);
        fwrite(&reg, sizeof (Empresa), 1, _pFile);
    }
    
    cerrar();
    return true;
}


bool EmpresaArchivo::eliminar(int numeroEmpresa){
    int indice;
    Empresa empresa;
    
    indice = buscar(numeroEmpresa);
    empresa = leer(indice);
    empresa.setEstado(0);
    
    return guardar(indice, empresa);
}















