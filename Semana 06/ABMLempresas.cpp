#include <iostream>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

///CLASE EMPRESA
class Empresa{
    private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        int categoria;
        int numeroMunicipio;
        bool estado;
    public:
        Empresa(){estado=false;}
        void setNumero(int n){numero = n;}
        void setCategoria(int c){categoria = c;}
        void setEstado(bool e){estado = e;}
        int getNumero(){return numero;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        bool getEstado(){return estado;}
        int getCategoria(){return categoria;}
        int getMunicipio(){return numeroMunicipio;}
        void Cargar();
        void Mostrar();
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1){
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"NUMERO DE MUNICIPIO: ";
    cin>>numeroMunicipio;
    estado=true;
}

void Empresa::Mostrar(){
    if(estado==true){
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio<<endl;
    }
}

///CLASE PARA MANIPULAR EL ARCHIVO DE EMPRESAS
class ArchivoEmpresas{
    private:
        char nombre[30];
    public:
        ArchivoEmpresas(const char *n="empresas.dat"){strcpy(nombre,n);}
        void grabarRegistro(Empresa obj);
        Empresa leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool listarRegistros();
        void modificarRegistro(Empresa obj, int pos);
        bool copiaSeguridad(const char *nombreAr="empresas.bak");
        void listarCopiaSeguridad(const char *nombreAr="empresas.bak");
        bool restaurarArchivo();
};

bool ArchivoEmpresas::listarRegistros(){
    Empresa reg;
    int cantReg=contarRegistros();
    if(cantReg==0) return false;
    for(int i=0;i<cantReg;i++){
            reg=leerRegistro(i);
            reg.Mostrar();
            cout<<endl;
    }
    return true;
}

bool ArchivoEmpresas::restaurarArchivo(){
    FILE *p;
    Empresa reg;

    ArchivoEmpresas archiBak("empresas.bak");

    int cantReg = archiBak.contarRegistros();

    p = fopen(nombre,"wb");
    if(p== NULL){
        return false;
    }

    for(int i=0;i<cantReg;i++){
            reg=archiBak.leerRegistro(i);
            fwrite(&reg, sizeof reg, 1, p);
    }
    fclose(p);
    return true;
}

void ArchivoEmpresas::listarCopiaSeguridad(const char *nombreAr){
    FILE *p=fopen(nombreAr, "rb");
    if(p==NULL){
        return;
    }
    Empresa reg;
    while(fread(&reg, sizeof reg,1, p)==1){
            reg.Mostrar();
            cout<<endl;
    }
    fclose(p);
}

bool ArchivoEmpresas::copiaSeguridad(const char *nombreAr){
    FILE *pBak;
    Empresa reg;

    pBak = fopen(nombreAr,"wb");
    if(pBak == NULL){
        return false;
    }
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
            reg=leerRegistro(i);
            fwrite(&reg, sizeof reg, 1, pBak);
    }
    fclose(pBak);
    return true;
}


void ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof (Empresa), 1, p);
    fclose(p);
}

Empresa ArchivoEmpresas::leerRegistro(int pos){
    Empresa obj;
    obj.setNumero(-1);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof(Empresa), 0);
    fread(&obj, sizeof (Empresa), 1, p);
    fclose(p);
    return obj;
}

int ArchivoEmpresas::buscarRegistro(int num){
    Empresa obj;
    int cant=contarRegistros();
    for(int i=0; i<cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero()==num){
            return i;
        }
    }
    return -1;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *pEmp;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pEmp, 0, 2);
    int cantBytes = ftell(pEmp);
    fclose(pEmp);
    return cantBytes/sizeof(Empresa);
}

void ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *pEmp;
    pEmp=fopen(nombre, "rb+");///+ le agrega al modo lo que le falta.
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    fseek(pEmp, pos * sizeof (Empresa) , 0);
    fwrite(&obj, sizeof (Empresa), 1, pEmp);
    fclose(pEmp);
}

///FUNCIONES GLOBALES
void altaEmpresa(){
    ArchivoEmpresas arcEmp("empresas.dat");
    Empresa obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistro(obj.getNumero());
    if(pos != -1){
        cout<<"YA EXISTE UNA EMPRESA CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        arcEmp.grabarRegistro(obj);
    }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
    }
}

void modificarRegistro(){
    ArchivoEmpresas arcEmp("empresas.dat");
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A MODIFICAR: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj = arcEmp.leerRegistro(pos);
    int cat;
    cout<<"INGRESE LA NUEVA CATEGORIA: ";
    cin>>cat;
    obj.setCategoria(cat);
    arcEmp.modificarRegistro(obj, pos);
}

void bajaLogica(){
    ArchivoEmpresas arcEmp;
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A DAR DE BAJA: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Empresa obj;
    obj = arcEmp.leerRegistro(pos);
    obj.setEstado(false);
    arcEmp.modificarRegistro(obj, pos);
}

void buscarEmpresa(){
    ArchivoEmpresas arcEmp;
    int num;
    cout<<"INGRESE EL NUMERO DE EMPRESA A BUSCAR: ";
    cin>>num;
    int pos=arcEmp.buscarRegistro(num);
    if(pos<0){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    else{
        Empresa obj;
        obj = arcEmp.leerRegistro(pos);
        obj.Mostrar();
    }
}

///SUBMENU REPORTES
void empresasCategoria();
void muncipiosSinEmpresas();
    int contarRepetidos(int *v, int tam,int numeroBuscado);/// devuelve la cantidad de veces que se repite numeroBuscado en el vector

void submenuReportes(){
    while(true){
        int opc;
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - EMPRESAS POR CATEGORIA"<<endl;
        cout<<"2 - "<<endl;
        cout<<"3 - MUNICIPIOS SIN EMPRESAS "<<endl;
        cout<<"4 - "<<endl;
        cout<<"5 - "<<endl;
        cout<<"0 - VOLVER AL MENU ANTERIOR "<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                empresasCategoria();
                break;
            case 2:

                break;
            case 3:
                muncipiosSinEmpresas();
                break;
            case 4:

                break;
            case 5:

                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        system("pause");
    }
    return;
}



///


int main(){
    ArchivoEmpresas archiEmp;
    while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - ALTA EMPRESA"<<endl;
        cout<<"2 - BAJA LOGICA EMPRESA"<<endl;
        cout<<"3 - MODIFICAR CATEGORIA EMPRESA"<<endl;
        cout<<"4 - LISTAR EMPRESAS"<<endl;
        cout<<"5 - BUSCAR EMPRESA POR NUMERO"<<endl;
        cout<<"6 - SUBMENU REPORTES "<<endl;
        cout<<"7 - BACKUP EMPRESA.DAT "<<endl;
        cout<<"8 - MOSTRAR BACKUP EMPRESA.DAT "<<endl;
        cout<<"9 - RESTAURAR EMPRESA.DAT "<<endl;

        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaEmpresa();
                break;
            case 2:
                bajaLogica();
                break;
            case 3:
                modificarRegistro();
                break;
            case 4:
                archiEmp.listarRegistros();
                break;
            case 5:
                buscarEmpresa();
                break;
            case 6: submenuReportes();
                    break;
            case 7: if(archiEmp.copiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    }
                    else{
                        cout<<"ERROR EN BACKUP"<<endl;
                    }
                    break;
            case 8: cout<<"REGISTROS EN COPIA DE SEGURIDAD "<<endl;
                    archiEmp.listarCopiaSeguridad();
                    break;
            case 9: cout<<"ESTA SEGURO DE RESTAURAR EL ARCHIVO EMPRESAS.DAT ? "<<endl;
                    archiEmp.restaurarArchivo();
                    break;
            case 0:
                return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        system("pause");
    }
    return 0;
}

/*
A partir del archivo de Empresas de la clase pasada, (hacer un proyecto) agregar al menú una opción de nombre REPORTES, que llame a un submenú con las siguientes opciones/puntos a resolver:

1. Listar los registros de las empresas que pertenezcan a una categoría que se ingresa por teclado

2. Listar los registros de las empresas con más de 10 empleados

3. Calcular e informar la cantidad de municipios sin empresas.

4. Listar los municipios con más de 5 empresas.

5. Informar la categoría con más empresas.

6. Informar el municipio con más empresas

7. Informar para cada municipio la cantidad de empleados de las empresas pertenecientes a ese municipio

8. Informar el municipio con mayor cantidad de empleados en las empresas pertenecientes a ese municipio

9. Informar la cantidad de empleados (entre todas las empresas) de cada categoría

10. Informar la categoría con más empleados (entre todas las empresas)
*/
///DESARROLLO DE LAS FUNCIONES DE REPORTES

void empresasCategoria(){
    int categoria;
    Empresa reg;
    ArchivoEmpresas archiEmp;
    int cantReg=archiEmp.contarRegistros();
    int i;
    cout<<"INGRESE CATEGORIA DE EMPRESA A LISTAR ";
    cin>>categoria;
    for(i=0;i<cantReg;i++){
            reg=archiEmp.leerRegistro(i);
            if(reg.getCategoria()==categoria) {
                reg.Mostrar();
                cout<<endl;
            }
    }
}

void muncipiosSinEmpresas(){
    int vMuniEmpresas[135]={0};/// cuando declaro le tengo que poner cuántos elementos quiero
    Empresa reg;
    ArchivoEmpresas archiEmp;
    int cantReg=archiEmp.contarRegistros();
    int i;
    for(i=0;i<cantReg;i++){
       reg=archiEmp.leerRegistro(i);
       vMuniEmpresas[reg.getMunicipio()-1]++;
    }
    ///el vector va a contener en cada posición la cantidad de empresas por municipio -1 (0 está el 1, en la 1 está el 2...)
    int sinEmpresas=contarRepetidos(vMuniEmpresas,135,0);
    cout<<"CANTIDAD DE MUNICIPIOS SIN EMPRESAS "<<sinEmpresas<<endl;
}

int contarRepetidos(int *v, int tam,int numeroBuscado){
    int i, cont=0;
    for(i=0;i<tam;i++){
            if(v[i]==numeroBuscado) cont++;
    }
    return cont;
}
