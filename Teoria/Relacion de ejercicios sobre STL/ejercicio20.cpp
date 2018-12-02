/*
20. Escribe un programa que permita leer de la entrada estándar una serie de coordenadas (como un par
de float) y que contabilice de forma eficiente el número de veces que aparece cada uno de los pares.

COMANDO PARA COMPILAR: g++ -o ejercicio20 ejercicio20.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <list>

using namespace std;

struct Coordenada{
    pair<float,float> c;
};

struct CoordenadaCompleta{
    pair<Coordenada,int> c_completa;
};

class ListaCoordenadas{
    private:
        list<CoordenadaCompleta> serie;
    public:
        ListaCoordenadas(){

        }

        ListaCoordenadas(const ListaCoordenadas &s){
            this->serie=s.serie;
        }

        void insertar_coordenada(Coordenada coordenada){
            bool contenida=false;
            list<CoordenadaCompleta>::iterator i=this->serie.begin();
            for(i;i!=serie.end() && !contenida ;i++){
                if(coordenada.c==i->c_completa.first.c){
                    i->c_completa.second++;
                    contenida=true;
                }
            }
            if(!contenida){
                CoordenadaCompleta c;
                c.c_completa.first=coordenada;
                c.c_completa.second=1;
                serie.push_back(c);
            }
        }
        void MostrarLista(){
            list<CoordenadaCompleta>::iterator i=this->serie.begin();
            for(i;i!=serie.end();i++){
                cout<<"Coordenada ( "<<i->c_completa.first.c.first<<" , "<<i->c_completa.first.c.second<<" )  aparece "<<i->c_completa.second<<" veces "<<endl; 
            }

        }


};

int main(){
    ListaCoordenadas l;
    Coordenada c1, c2, c3, c4, c5, c6;
    c1.c.first=1.7;
    c1.c.second=2.3;

    c2.c.first=1.0;
    c2.c.second=2.0;

    c3.c.first=1.7;
    c3.c.second=2.3;

    c4.c.first=1.7;
    c4.c.second=2.3;

    c5.c.first=9.8;
    c5.c.second=1.0;

    c6.c.first=1.0;
    c6.c.second=2.0;


    l.insertar_coordenada(c1);
    l.insertar_coordenada(c2);
    l.insertar_coordenada(c3);
    l.insertar_coordenada(c4);
    l.insertar_coordenada(c5);
    l.insertar_coordenada(c6);

    l.MostrarLista();

}