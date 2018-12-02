/*
11. Implementa una función a la que se le pase una lista de enteros y un entero x de manera que cada vez
que aparezca en una posición ese valor, se inserte x-1 en la posición siguiente.
void inserta_antes(list<int> &l, int x)

COMANDO PARA COMPILAR: g++ -o ejercicio11 ejercicio11.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

void inserta_antes(list<int> &l, int x){
    for(list<int>::iterator i=l.begin();i!=l.end();i++){
        if(*i==x)
            l.insert(i,x-1);
    }
}

template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l {1,3,3,2,5,3,4,6,3};
    int x=3;
    cout<<"La lista original es: "<<endl;
    mostrar(l);
    cout<<"Vamos a poner el elemento "<<x-1<<" antes de cada "<<x<<endl;
    inserta_antes(l,x);
    cout<<"El resultado es: "<<endl;
    mostrar(l);
}