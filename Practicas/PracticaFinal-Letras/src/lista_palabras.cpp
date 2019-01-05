#include <vector>
#include <set>
#include <string.h>
#include <iostream>
#include "lista_palabras.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"

using namespace std;

lista_palabras::lista_palabras(){
    datos.clear();
}

vector<string> lista_palabras::palabras_longitud(unsigned palabras_longitud){
    vector<string> resultado;
    lista_palabras::iterator i;
    for (i=this->datos.begin();i!=this->datos.end();i++){
        string aux=*i;
        if(aux.size()==palabras_longitud)
            resultado.push_back(*i);
    }
    return resultado;
}

bool lista_palabras::Esta(string palabra){
    bool esta=false;
    lista_palabras::const_iterator i;

    i = this->datos.find(palabra);

    if(i != this->lista_palabras::end())
        esta=true;

    return esta;
}

lista_palabras lista_palabras::mejoresSoluciones(char modo, Conjunto_letras &c){
    lista_palabras soluciones;
    int mayor=0,puntos;
    vector<pair<string,int>> aux;
    lista_palabras::iterator itr;

        for(itr=this->begin();itr != this->end();++itr){
            puntos=c.obtenerRanking(*itr,modo);
            aux.push_back(pair<string,int>(*itr,puntos));
            if(puntos>mayor)
                mayor=puntos;
        }

        vector<pair<string,int>>::iterator vi;
        for(vi=aux.begin();vi != aux.end() ; ++vi){
            if(vi->second == mayor)
                soluciones.datos.insert(vi->first);
        }


    return soluciones;
}

lista_palabras lista_palabras::generarSoluciones(const BolsaLetras &bolsa){
    lista_palabras soluciones;
    bool valido;

    for(lista_palabras::const_iterator itr = lista_palabras::begin();itr != lista_palabras::end();++itr){
        valido = false;
        valido = bolsa.solucionValida(*itr);
        if(valido)
            soluciones.datos.insert(*itr);
    }
    return soluciones;
}
ostream& operator << (ostream &os, const lista_palabras &l){
    lista_palabras::const_iterator i;
    for(i=l.begin();i!=l.end();i++)
        os<<*i<<endl;

    return os;
}

istream& operator >> (istream &is, lista_palabras &l){
    string aux;
    do{
        getline(is, aux, '\n');
        if(aux.size() > 0)
            l.datos.insert(aux);

    }while(!is.eof());

    return is;
}