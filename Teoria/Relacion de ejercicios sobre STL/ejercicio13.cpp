/*
13. Tenemos dos listas: l, que contiene n elementos y otra li que contiene una serie de posiciones de la
lista anterior (valores de la clase iterador). Construye una función a la que se le pasen esas dos listas
y devuelva otra que contenga los elementos de l indicados por las posiciones de la lista li.
list<T> lista_posiciones(const list<T> &l, const list<list<T>::iterator>

COMANDO PARA COMPILAR: g++ -o ejercicio13 ejercicio13.cpp

Observacion:Voy a suponer que todos las posiciones de la lista de iteradores se encuentran en la lista de elementos

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)

*/

#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<T> lista_posiciones(const list<T> &l, const list<typename list<T>::const_iterator> li){
    list<T> solucion;
    typename list<T>::const_iterator i=l.begin();
    typename list< typename list<T>::const_iterator>::const_iterator j=li.begin();
    for(j;j!=li.end();j++){
        i=*j;
        solucion.push_back(*i);
    }
    return solucion;
}

template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l {1,2,3,4,5,6}, solucion;
    list<int>::const_iterator i=l.begin(),j,k;
    list<list<int>::const_iterator> li;
    li.push_back(i);
    j=++i;
    li.push_back(j);
    k=++j;
    li.push_back(k);

    cout<<"La lista de elementos es: "<<endl;
    mostrar(l);

    cout<<"La lista de los elementos a los que corresponden los iteradores es :"<<endl;
    solucion=lista_posiciones(l,li);
    cout<<"La lista que contiene la solucione es: "<<endl;
    mostrar(solucion);
}