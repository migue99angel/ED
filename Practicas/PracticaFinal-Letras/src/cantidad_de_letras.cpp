#include "conjunto_letras.h"
#include "lista_palabras.h"
#include "letra.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class CantidadLetras{
    private:
        char caracter;
        int frec_abs;
        double frec_relv;
    public:
        CantidadLetras(){
            caracter='-';
            frec_abs=0;
            frec_relv=0;
        } 
        char getLetra(){return this->caracter;}
        int getFrecuenciaAbsoluta(){return this->frec_abs;}
        double getFrecuenciaRelativa(long total){return (this->frec_abs*1.0/total)*100;}
        void setLetra(char letra){this->caracter=letra;}
        void incrementar(){this->frec_abs++;}
};

int main(int argc, char const *argv[])
{
    if(argc != 4){
        cout<<"Los parámetros son: "<<endl;
        cout<<"1.-El fichero con las palabras\n ";
        cout<<"2.-El fichero con las letras\n";
        cout<<"3.-El fichero donde escribir las frecuencias\n ";

        return 0;
    }
    ifstream f(argv[1]);
    if (!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }
    ifstream fletras(argv[2]);
    if (!fletras){
        cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return 0;
    }
    ofstream salida(argv[3]);
    cout<<"Este programa carga en memoria una lista de palabras y un conjunto de letras y a partir de los datos cargados calcula la frecuencia con la que aparece cada letra\n ";
   
    cout<<"Cargando lista de palabras...\n";
    lista_palabras lista;
    f>>lista;
    cout<<"Lista de palabras cargada correctamente\n";

    cout<<"Cargando el conjunto de letras...\n";
    Conjunto_letras conjunto;
    fletras>>conjunto;
    cout<<"El conjunto de letras se ha leido correctamente\n";

    vector<CantidadLetras> solucion;
    vector<CantidadLetras>::iterator vi;
    Conjunto_letras::iterator iconj;
    CantidadLetras aux;

    //Añado todas las letras del conjunto al vector
    for(iconj=conjunto.begin();iconj != conjunto.end();++iconj){
        aux.setLetra(iconj->getCaracter());
        solucion.push_back(aux);
    }

    //incrementamos el valor de cada letra segun aparezca
    long nletras=0;
    lista_palabras::const_iterator itr;
    for(itr = lista.begin();itr != lista.end();++itr){
        string palabra = *itr;
        for(unsigned i = 0; i < palabra.size(); ++i){
            transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
            bool incrementado=false;
            for(vi=solucion.begin();vi != solucion.end() && !incrementado;++vi){
                if(vi->getLetra() == palabra[i]){
                    vi->incrementar();
                    incrementado=true;
                    nletras++;
                }
            }
        }
    }


    salida<<"#Letra Cantidad"<<endl;
    for(vi=solucion.begin();vi != solucion.end(); ++vi){
        salida<<vi->getLetra()<<"\t"<<vi->getFrecuenciaRelativa(nletras)<<endl;
    }



}
