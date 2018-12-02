/*
6. Implementa una función que, dada una lista l de tipo T y un elemento x de tipo T, elimine el elemento
x de todas las posiciones en las que aparezca en l. Por ejemplo: si x = 1 y l = (2, 1, 1, 1, 1, 5, 3) el
resultado deberı́a ser (2, 5, 3)
void elimina(list<T> &l, const T &x)

COMANDO PARA COMPILAR: g++ -o ejercicio6 ejercicio06.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
void elimina(list<T> &l, const T &x){
    typename list<T>::iterator i=l.begin();
    while(i!=l.end()){
        if(*i==x)
            i=l.erase(i);
        else
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
int x=1;

cout<<"La lista original es:"<<endl;
mostrar(l);
cout<<"Eliminando elemento "<<x<<" ..."<<endl;
elimina(l,x);
cout<<"La lista modificada es: "<<endl;
mostrar(l);
}


