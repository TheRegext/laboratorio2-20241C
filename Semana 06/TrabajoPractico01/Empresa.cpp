#include <string>
#include <cstring>
#include "Empresa.h"

using namespace std;

Empresa::Empresa()
{
    _numeroEmpresa = 0;
    strcpy(_nombre, "");
    _cantidadEmpleados = 0;
    _categoria = 0;
    _numeroMunicipio = 0;
    _estado = false;
}

Empresa::Empresa(int numero, string nombre, int cantidadEmpleados, int categoria, int numeroMunicipio, bool estado)
{
    setNumero(numero);
    setNombre(nombre);
    setCantidadEmpleados(cantidadEmpleados);
    setCategoria(categoria);
    setNumeroMunicipio(numeroMunicipio);
    setEstado(estado);
}

int Empresa::getNumero()
{
    return _numeroEmpresa;
}

void Empresa::setNumero(int numero)
{
    _numeroEmpresa = numero;
}

string Empresa::getNombre()
{
    return _nombre;
}

void Empresa::setNombre(string nombre)
{
    if(nombre.size() <= 29)
    {
        strcpy(_nombre, nombre.c_str());
    }
    else
    {
        strcpy(_nombre, "SIN DATOS");
    }
}

int  Empresa::getCantidadEmpleados()
{
    return _cantidadEmpleados;
}

void Empresa::setCantidadEmpleados(int cantidadEmpleados)
{
    _cantidadEmpleados  = cantidadEmpleados;
}

int  Empresa::getCategoria()
{
    return _categoria;
}

void Empresa::setCategoria(int categoria)
{
    _categoria = categoria;
}
                  
int  Empresa::getNumeroMunicipio()
{
    return _numeroMunicipio;
}

void Empresa::setNumeroMunicipio(int numeroMunicipio)
{
    _numeroMunicipio = numeroMunicipio;
}

bool Empresa::getEstado()
{
    return _estado;
}
void Empresa::setEstado(bool estado)
{
    _estado = estado;
}
