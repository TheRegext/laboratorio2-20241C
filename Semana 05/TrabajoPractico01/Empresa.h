#pragma once
#include <string>

class Empresa
{
    public:
        Empresa();
        Empresa(int numero, std::string nombre, int cantidadEmpleados, int categoria, int numeroMunicipio, bool estado);
        
        /// getter y setter
        int getNumero();
        void setNumero(int numero);
        
        std::string getNombre();
        void setNombre(std::string nombre);
        
        int getCantidadEmpleados();
        void setCantidadEmpleados(int cantidadEmpleados);
        
        int getCategoria();
        void setCategoria(int categoria);
        
        int getNumeroMunicipio();
        void setNumeroMunicipio(int numeroMunicipio);
        
        /// estaEliminado isDeleted
        bool getEstado();
        void setEstado(bool estado);
        
    private:
        int _numeroEmpresa;
        char _nombre[30];
        int _cantidadEmpleados;
        int _categoria;
        int _numeroMunicipio;
        bool _estado;
};
