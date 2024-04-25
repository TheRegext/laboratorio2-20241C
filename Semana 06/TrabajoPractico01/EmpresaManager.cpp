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

void EmpresaManager::realizarCopiaSeguridad(){
    bool hacerCopia;
    
    cout << "Realmente quiere hacer una copia de seguridad? 1-Si 0-No: ";
    cin >> hacerCopia;
    
    if(hacerCopia){
        if(empresaArchivo.copiaSeguridad("empresa.bkp")){
            cout << "La copia de seguridad se realizo con exito!" << endl;
        }
        else{
            cout << "No se pudo realizar la copia de seguridad"<< endl;
        }
    }
    else{
        cout << "No se realizo la copia de seguridad." << endl;
    }
}

void EmpresaManager::restaurarCopiaSeguridad(){
     bool hacerCopia;
    
    cout << "Realmente quiere resturar la copia de seguridad? 1-Si 0-No: ";
    cin >> hacerCopia;
    
    if(hacerCopia){
        if(empresaArchivo.restaurarCopiaSeguridad("empresa.bkp")){
            cout << "La copia de seguridad se restauro con exito!" << endl;
        }
        else{
            cout << "No se pudo restaurar la copia de seguridad"<< endl;
        }
    }
    else{
        cout << "No se realizo la restauracion de la copia de seguridad." << endl;
    }
}

void EmpresaManager::eliminarEmpresas(){
    int numeroEmpresa, indice;
    
    cout << "Ingrese numero de empresa que quiere eliminar: ";
    cin >> numeroEmpresa;
    
    indice = empresaArchivo.buscar(numeroEmpresa);
    
    if(indice != -1){
        Empresa empresa = empresaArchivo.leer(indice);
        bool eliminar;
        
        mostrar(empresa);
        
        cout << "Esta seguro que quiere eliminar la empresa? 1-SI 0-NO: ";
        cin >> eliminar;
        
        if(eliminar){
            if(empresaArchivo.eliminar(numeroEmpresa)){
                cout << "La empresa se elimino correctamente!"<<endl;
            }
            else{
                cout << "La empresa no se pudo eliminar..." << endl;
            }    
        }
        else{
            cout << "La empresa no se elimino. " << endl;
        }
        
        
    }
    else{
        cout << "La empresa no existe..." << endl;
    }
    
}

void EmpresaManager::menu(){
    int opcion;
    
    do{
            system("cls"); /// borar la pantalla 
            cout << "--------- MENU EMPRESAS -------" << endl;
            cout << "-------------------------------" << endl;
            cout << "1- CARGAR EMPRESA  " << endl;
            cout << "2- BUSCAR EMPRESA POR NUMERO  " << endl;
            cout << "3- LISTAR TODAS LAS EMPRESAS" << endl;
            cout << "5- ELIMINAR EMPRESA LOGICA " << endl;
            cout << "6- REALIZAR COPIA DE SEGURIDAD" << endl;
            cout << "7- RESTAURAR COPIA DE SEGURIDAD" << endl;
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
            case 5:
                system("cls");
                eliminarEmpresas();
                break;
            case 6:
                system("cls");
                realizarCopiaSeguridad();
                break;
            case 7:
                system("cls");
                restaurarCopiaSeguridad();
                break;
            }
            system("pause");
        
    }while(opcion != 0);
    

}



