#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "lista_palabras.h"

using namespace std;

int main(int argc, char const *argv[]){
    if(argc != 2){
        cout<<"Los parámetros son: "<<endl;
        cout<<"1.- El fichero con las palabras ";

        return 0;
    }
    ifstream f(argv[1]);
    if (!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }
    lista_palabras D;
    cout<<"Cargando lista_palabras..."<<endl;

    f>>D;

    cout<<"Leida la lista_palabras..."<<endl;
    cout<<D;

    unsigned longitud;
    cout<<"Dime la longitud de las palabras que quieres ver: ";
    cin>> longitud;
    vector<string> v=D.palabras_longitud(longitud);

    cout<<"Palabras de Longitud "<<longitud<<endl;
    for(unsigned int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    string p;
    cout<<"Dime una palabra  : ";
    cin>>p;

    if(D.Esta(p))
        cout<<"Sí, esa palabra existe"<<endl;
    else
        cout<<"No, esa palabra no existe "<<endl;        
}
