/*
7. Implementa una función elimina_duplicados(list<T> &l) que elimine los elementos du-
plicados (sin ordenar previamente la lista).

COMANDO PARA COMPILAR: g++ -o ejercicio7 ejercicio07.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
void elimina_duplicados(list<T> &l){
    typename list<T>::const_iterator i=l.begin();
    while(i!=l.end()){
        typename list<T>::const_iterator j=i;
        j++;
        while(j!=l.end()){            
            if(*j==*i)
                j=l.erase(j);
            else
                j++;    
        }
        i++;
    }
}

template<typename T>
void mostrar(list<T> &l){
    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l {2,1,1,1,1,5,3};
    cout<<"La lista original es: "<<endl;
    mostrar(l);
    cout<<"Eliminando repetidos..."<<endl;
    elimina_duplicados(l);
    cout<<"La lista modificada es: "<<endl;
    mostrar(l);
}