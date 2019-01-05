#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "conjunto_letras.h"

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
    Conjunto_letras D;
    cout<<"Cargando el conjunto de letras..."<<endl;

    f>>D;

    cout<<"Leido el conjunto de letras..."<<endl;
    cout<<"El tamaño del conjunto de letras es de: "<<D.size()<<endl;
    cout<<D;
}
