/*

19. Define una clase que permita guardar los datos de los pilotos de F1. Por ejemplo, nombre, apellido
(sólo uno), posición en la clasificación, nombre de la escuderı́a. Además debe permitir que se pueda
buscar a un piloto por su apellido. ¿Qué podrı́amos añadir a esa clase para que se pueda buscar
también por cualquiera de los restantes campos?.

COMANDO PARA COMPILAR: g++ -o ejercicio19 ejercicio19.cpp

Observacion: He intentado que en el metodo BuscarPorCualquierCampo tambien busque por la posicion pero al ser de un tipo diferente que el resto 
de datos no compilaba, por eso he implementado la funcion BuscarPorPosicion

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <cstring>
#include <list>


using namespace std;


struct Piloto {
    string nombre;
    string apellido;
    int posicion;
    string escuderia;
};

class Clasificacion{
    private:
    list<Piloto> l;

    public:
    Clasificacion(){

    }

    Clasificacion(const Clasificacion &c){
        this->l=c.l;
    }

    void nuevoPiloto(Piloto nuevo){
        l.push_back(nuevo);
    }

    Piloto BuscarPorApellido(string apellido){
        Piloto aux;
        bool encontrado=false;
        list<Piloto>::iterator i;
        for(i=l.begin();i!=l.end() && !encontrado;i++){
            if(i->apellido == apellido){
                aux=*i;
                encontrado=true;
            }
        }
        return aux;
    }

    Piloto BuscarPorPosicion(int pos){
        Piloto aux;
        bool encontrado=false;
        list<Piloto>::iterator i;
        for(i=l.begin();i!=l.end() && !encontrado;i++){
            if(i->posicion == pos){
                aux=*i;
                encontrado=true;
            }
        }
        return aux;
    }

    template <typename T>
    Piloto BuscarPorCualquierCampo(T campo){
        Piloto aux;
        bool encontrado=false;
        list<Piloto>::iterator i;
        for(i=l.begin();i!=l.end() && !encontrado;i++){
            if(i->apellido==campo || i->nombre==campo || i->escuderia==campo){
                aux=*i;
                encontrado=true;
            }
        }
        return aux;
    }

    void MostrarPilotos(){
        for(list<Piloto>::iterator i=l.begin();i!=l.end();i++){
            cout<<"Piloto: "<<i->nombre<<" "<<i->apellido<<endl;
            cout<<"Escuderia: "<< i->escuderia<<endl;
            cout<<"Posicion: "<<i->posicion<<endl<<endl;
        }

    }

};

int main(){
    Piloto p1, p2, p3, p4;
    Clasificacion c;
    p1.nombre="Fernando";
    p1.apellido="Alonso";
    p1.posicion=1;
    p1.escuderia="McClaren";

    c.nuevoPiloto(p1);

    p2.nombre="Pastor";
    p2.apellido="Maldonado";
    p2.posicion=12;
    p2.escuderia="Lotus-Renault";

    c.nuevoPiloto(p2);

    p3.nombre="Sebastia";
    p3.apellido="Vettel";
    p3.posicion=3;
    p3.escuderia="Ferrari";

    c.nuevoPiloto(p3);

    p4.nombre="Lewis";
    p4.apellido="Hamilton";
    p4.posicion=2;
    p4.escuderia="Mercedes";

    c.nuevoPiloto(p4);

    c.MostrarPilotos();
    string cad="Lewis";

    p1=c.BuscarPorCualquierCampo(cad);
    cout<<"Piloto: "<<p1.nombre<<" "<<p1.apellido<<endl;
    cout<<"Escuderia: "<< p1.escuderia<<endl;
    cout<<"Posicion: "<<p1.posicion<<endl<<endl;

    cad="Lotus-Renault";
    p1=c.BuscarPorCualquierCampo(cad);
    cout<<"Piloto: "<<p1.nombre<<" "<<p1.apellido<<endl;
    cout<<"Escuderia: "<< p1.escuderia<<endl;
    cout<<"Posicion: "<<p1.posicion<<endl<<endl;



}