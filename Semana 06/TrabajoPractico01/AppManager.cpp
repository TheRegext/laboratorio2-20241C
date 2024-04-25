#include <iostream>
#include "AppManager.h"

using namespace std;

void AppManager::menu(){
    int opcion;
    
    do{
            system("cls");
            cout << "--------- MENU PRINCIPAL -------" << endl;
            cout << "-------------------------------" << endl;
            cout << "1- EMPRESAS  " << endl;
            cout << "2- MUNICIPIO " << endl;
            cout << "3- CONFIGURACION " << endl;
            cout << "4- REPORTES" << endl;
            cout << "-------------------------------" << endl;
            cout << "0- SALIR " << endl;
            cout << "-------------------------------" << endl;
            cout << "Opcion: " << endl;
            cin >> opcion;
            
            switch(opcion){
            case 1: 
                system("cls");
                empresaManager.menu();
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 0:
                system("cls");
                cout << "Gracias por utilizar mi aplicacion, pagame un cafecito :) " << endl;
                system("pause");
            }
        
    }while(opcion != 0);
    
}
