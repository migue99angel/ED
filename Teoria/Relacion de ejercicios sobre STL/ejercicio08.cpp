/*
8. Implementa una función que dada una lista l devuelva una lista que tenga los elementos de l pero en
orden inverso.
list<T> inversa(const list<T> &l)

COMANDO PARA COMPILAR: g++ -o ejercicio8 ejercicio08.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
list<T> inversa(const list<T> &l){
    list<T> aux;
    typename list<T>::const_iterator i=l.begin();
    while(i!=l.end()){
        aux.push_front(*i);
        i++;
    }
    return aux;
}

template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}
int main(){
    list<int> l {2,1,1,1,1,5,3};
    cout<<"La lista original es: "<<endl;
    mostrar(l);
    cout<<"La lista invertida es: "<<endl;
    mostrar(inversa(l));

}