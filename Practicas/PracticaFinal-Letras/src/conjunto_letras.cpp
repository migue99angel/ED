#include <iostream>
#include <set>
#include "conjunto_letras.h"
#include <stdio.h>
#include <time.h>
#include <algorithm>



using namespace std;

Conjunto_letras::Conjunto_letras(){
    this->conjunto.clear();
}

void Conjunto_letras::insertar(letra l){
    this->conjunto.insert(l);
}

int Conjunto_letras::obtenerRanking(string sol, char modo){
    bool defecto=false;
    int puntuacion=0;
    if(!(modo == 'L' || modo =='P')){
        cout<<"La modalidad de juego introducida no es correcta, por defecto jugará siguiendo la modalidad por puntos. "<<endl;
        defecto=true;
    }

    if(modo == 'P' || defecto ){
        for(unsigned i=0;i<sol.size();i++){
            for(Conjunto_letras::const_iterator itr = Conjunto_letras::begin(); itr != Conjunto_letras::end(); itr++){
                if(toupper(sol[i]) == itr->getCaracter())
                    puntuacion += itr->getPuntuacion();
                
            }
        }

    }else if(modo == 'L'){
        puntuacion= (int) sol.size();
    }

    return puntuacion;

}



 BolsaLetras  Conjunto_letras::generarLetrasJuego(int cantidad){

    BolsaLetras generada;
    srand(time(NULL));
    int repeticiones[conjunto.size()] = {0};
    int aniadidos=0, aleatorio;

    while(aniadidos < cantidad){
        Conjunto_letras::iterator itr = conjunto.begin();
 
        
        aleatorio = rand() % (conjunto.size()-1);

        int x=0;
        while(x<aleatorio){
            ++itr;
            ++x;
        }

        repeticiones[aleatorio]++;
        if(repeticiones[aleatorio] <= itr->getRepeticiones()){
            generada.insertar(*itr);
            aniadidos++;
        }
    }
    
    return generada;
}


ostream& operator << (ostream &os, const Conjunto_letras &L){
    Conjunto_letras::const_iterator i;
    os<<"#Letra Cantidad Puntos"<<endl;
    for(i=L.begin();i!=L.end();i++){
        os<<*i;
    }
    
    return os;
}

istream& operator >> (istream &is, Conjunto_letras &L){
    string cabecera;
    letra aux;
    getline(is,cabecera,'\n');
    if(cabecera=="#Letra Cantidad Puntos"){   
        do{
            is>>aux;
            L.insertar(aux);
        }while(!is.eof());
    }
    else
        cerr<<"El fichero introducido no se corresponde con el formato especificado"<<endl;
    

    return is;
}
