#include "bolsa_letras.h"
#include <string>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

BolsaLetras::BolsaLetras(){

}

char BolsaLetras::getLetra(){
    BolsaLetras::const_iterator i =BolsaLetras::begin();
    char aux = *i;
    this->bolsa.erase(i);
    return aux;
}

void BolsaLetras::insertar(const letra &l){
    this->bolsa.push_back(l.getCaracter());
}

void BolsaLetras::mostrarLetras(){

    cout<<"Mostrando bolsa de "<<bolsa.size()<<" letras ..."<<endl;
    for(unsigned i=0;i<this->bolsa.size();i++){
        cout<<this->bolsa[i]<<"\t";
    }
    cout<<endl;
}

bool BolsaLetras::solucionValida(string palabra)const{
    bool valida=true;
    BolsaLetras bolsa_aux = (*this);

    //Transformamos en mayúsculas porque en el fichero letras.txt los caracteres están en mayusculas
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);

    for (unsigned i=0;i<palabra.size() && valida;i++){
        //Utilizamos esta función que devuelve true si la letra se puede elegir y en ese caso la elimina de la bolsa para que no este disponible de nuevo para elegirla
        valida = bolsa_aux.letraElegida(palabra[i]);
    }

    return valida;

}

bool BolsaLetras::letraElegida(char letra){
    BolsaLetras::iterator itr;
    bool valida=false;

    for (itr = BolsaLetras::begin() ;itr != BolsaLetras::end() && !valida; ++itr){
        if(letra == *itr){
            valida=true;
            this->bolsa.erase(itr);
        }
    }
    return valida;
}