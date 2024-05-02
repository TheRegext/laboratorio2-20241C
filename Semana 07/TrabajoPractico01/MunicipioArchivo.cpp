#include <iostream>
#include "MunicipioArchivo.h"

using namespace std;

MunicipioArchivo::MunicipioArchivo() {
        _fileName = "municipios.dat";
}

MunicipioArchivo::MunicipioArchivo(string fileName) {
    _fileName = fileName;
}

bool MunicipioArchivo::guardar(Municipio municipio) {
    int guardo;

    if(!abrir("ab")) {
        return false;
    }

    guardo = fwrite(&municipio, sizeof(Municipio), 1, _pFile);

    cerrar();

    return guardo;
}

int MunicipioArchivo::buscar(int numMunicipio) {
    Municipio municipio;
    int index = 0;

    if(!abrir()) {
        return false;
    }

    while(fread(&municipio, sizeof(Municipio), 1, _pFile)) {
        if(municipio.getNumeroMunicipio() == numMunicipio) {
            break;
        }
        index++;
    }

    cerrar();

    if(municipio.getNumeroMunicipio() == numMunicipio) {
        return index;
    }
    else {
        return -1;
    }
}

Municipio MunicipioArchivo::leer(int index) {
    Municipio municipio;

    if(!abrir()) {
        return municipio;
    }

    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);

    fread(&municipio, sizeof(Municipio), 1, _pFile);

    cerrar();

    return municipio;
}

bool MunicipioArchivo::modificar(Municipio municipio, int index) {
    int modifico;

    if(!abrir("rb+")) {
        return false;
    }

    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);

    modifico = fwrite(&municipio, sizeof(Municipio), 1, _pFile);

    cerrar();

    return modifico;
}

bool MunicipioArchivo::eliminar(int numMunicipio) {
    Municipio municipio;
    int index;

    index = buscar(numMunicipio);
    municipio = leer(index);

    municipio.setEstado(0);


    return modificar(municipio, index);
}

int MunicipioArchivo::getCantidadMunicipios() {
    if(!abrir("rb")) {
        return 0;
    }

    fseek(_pFile, 0, SEEK_END);
    int bytesTotales = ftell(_pFile);

    cerrar();

    return bytesTotales / sizeof(Municipio);
}

bool MunicipioArchivo::copiaSeguridad(string fileName){
    FILE *pFileBkp;
    Municipio municipio;

    pFileBkp = fopen(fileName.c_str(), "wb");

    if(pFileBkp == nullptr){
        return false;
    }

    int cantReg = getCantidadMunicipios();

    for(int i=0;i<cantReg;i++){
        municipio = leer(i);
        fwrite(&municipio, sizeof (Municipio), 1, pFileBkp);
    }

    fclose(pFileBkp);

    return true;
}

bool MunicipioArchivo::restaurarCopiaSeguridad(string fileName){
    Municipio municipio;
    MunicipioArchivo archiBak(fileName);

    if(!abrir("wb")) {
        return false;
    }


    int cantReg = archiBak.getCantidadMunicipios();

    for(int i=0;i<cantReg;i++){
        municipio= archiBak.leer(i);
        fwrite(&municipio, sizeof (Municipio), 1, _pFile);
    }

    cerrar();

    return true;
}
