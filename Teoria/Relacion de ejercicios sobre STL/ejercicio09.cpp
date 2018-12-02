/*
9. Resuelve el problema anterior pero sobre la lista pasada por referencia.
void inversa(list<T> &l)
COMANDO PARA COMPILAR: g++ -o ejercicio9 ejercicio09.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
void inversa(list<T> &l){
    //Creamos dos iteradores uno que apunte al principio de la lista y otro que apute al final(debemos 
    //restarle una unidad porque si no apunta a la posición contigua al final) y vamos intercambiando su
    //contenido con ayuda de una variable auxiliar;
    typename list<T>::iterator i=l.begin(), j=l.end();
    j--;
    T aux;
    //Cuando ambos iteradores sean iguales será porque son el mismo elemento de la lista y no tiene sentido el intercambio
    while(i!=j){
        aux=*i;
        *i=*j;
        *j=aux;
        i++;
        j--;        
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
    list<int> l {2,1,1,1,1,5,3};
    cout<<"La lista original es: "<<endl;
    mostrar(l);
    cout<<"La lista invertida es: "<<endl;
    inversa(l);
    mostrar(l);

}