#include <string>
#include <iostream>
#include "EmpresaManager.h"

using namespace std;

Empresa EmpresaManager::crearEmpresa(){
    int numeroEmpresa, cantidadEmpleados, categoria, numeroMunicipio;
    string nombre;

    /*
    do{
        cout << "Ingrese numero de empresa: ";
        cin >> numeroEmpresa;    
    } while(empresaArchivo.isExist(numeroEmpresa)) ;
   */ 
   
   while(true){
        cout << "Ingrese numero de empresa: ";
        cin >> numeroEmpresa;    
        
        if(empresaArchivo.isExist(numeroEmpresa)){
            cout << "La empresa existe, intente con otra..." << endl;
        }
        else{
            break;
        }
   }
   
    
    
    cin.ignore();
    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    
    cout << "Ingrese cantidad de empleados: ";
    cin >> cantidadEmpleados;
    
    cout << "Ingrese categoria: ";
    cin >> categoria;
    
    cout << "Ingrese numero municipio: ";
    cin >> numeroMunicipio;
    
    return Empresa(numeroEmpresa, nombre, cantidadEmpleados, categoria, numeroMunicipio, true);    
}

void EmpresaManager::mostrar(Empresa empresa){
    cout << "Numero: " << empresa.getNumero() << endl;
    cout << "Nombre: " << empresa.getNombre() << endl;
    cout << "Cantidad de Empleados: " << empresa.getCantidadEmpleados() << endl;
    cout << "Categoria: " << empresa.getCategoria() << endl;
    cout << "Numero de Municipio: " << empresa.getNumeroMunicipio() << endl;
    cout << "Disponibilidad: " << (empresa.getEstado() ? "Disponible" : "No disponible") << endl;
}


void EmpresaManager::cargarEmpresa(){
     Empresa empresa;
     empresa = crearEmpresa();
     
     if(empresaArchivo.guardar(empresa)){
        cout << "Empresa guardada con exito!" << endl;
     }
     else{
        cout << "No se pudo guardar la empresa :(" << endl;        
     }
     
}

void EmpresaManager::buscarEmpresa(){
    int index, numero;
    Empresa empresa;
    
    cout << "Ingrese numero de empresa a buscar: "<< endl;
    cin >> numero;
    
    index = empresaArchivo.buscar(numero);
    
    if(index >= 0){
        empresa = empresaArchivo.leer(index);
        mostrar(empresa);
    }
    else{
        cout << "La empresa no se encuentra :(" << endl;
    }
    
}

void EmpresaManager::listarEmpresas(){
    int cantidad = empresaArchivo.getCantidadRegistros();
    
    for(int i=0; i < cantidad ; i++){
        Empresa empresa = empresaArchivo.leer(i);
        cout << "---------------" << endl;
        mostrar(empresa);
        cout << "---------------" << endl;
    }
}

void EmpresaManager::menu(){
    int opcion;
    
    do{
            system("cls");
            cout << "--------- MENU EMPRESAS -------" << endl;
            cout << "-------------------------------" << endl;
            cout << "1- CARGAR EMPRESA  " << endl;
            cout << "2- BUSCAR EMPRESA POR NUMERO  " << endl;
            cout << "3- LISTAR TODAS LAS EMPRESAS" << endl;
            cout << "-------------------------------" << endl;
            cout << "0- SALIR " << endl;
            cout << "-------------------------------" << endl;
            cout << "Opcion: " << endl;
            cin >> opcion;
            
            switch(opcion){
            case 1: 
                system("cls");
                cargarEmpresa();
                break;
            case 2:
                system("cls");
                buscarEmpresa();
                break;
            case 3:
                system("cls");
                listarEmpresas();
                break;
            case 0:
                system("cls");
                cout << "Gracias por utilizar mi aplicacin, pagame un cafecito :) " << endl;
            }
            system("pause");
        
    }while(opcion != 0);
    

}



