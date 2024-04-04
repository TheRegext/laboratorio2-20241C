#include<iostream>

using namespace  std;
/*  a  Todos
void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}*/
class Fecha{

public:

    ///metodo 1: Constructor por defecto, doy valores fijos
    /*Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 1800;
    }*/

    ///Metodo2: Fecha(int dia=1, int mes=1, int anio=1800)
    Fecha(int dia=1, int mes=1, int anio=1800){ ///constructor por envio de parametros
    _dia = dia;
    _mes = mes;
    _anio = anio;
    }/// me ejecuto en mi nacimiento

    ~Fecha(){ ///destructor

    } ///me ejecuto cuando muero

    void Mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
    }

private:
    int _dia;
    int _mes;
    int _anio;

};

/*Crear una clase alumno con las siguientes propiedades:
LEGAJO,NOMBRE, APELLIDO,FECHA DE NACIMIENTO,DIRECCION, TELEFONO.
Crear los repectivos metodos (set, get) de cada propiedad.
crear un constructor por defecto y un constructor por envio de parametros
Crear un mostrar y un cargar*/

int main(){


return 0;
}
