/*
10. Implementa una función list<T> mezclar(const list<T> &l1, const list<T> &l2)
que dadas dos listas ordenadas l1 y l2 devuelva una lista ordenada mezclando las dos listas.

COMANDO PARA COMPILAR: g++ -o ejercicio10 ejercicio10.cpp

Observacion:Para la resolucion de este ejercicio he supuesto que las dos listas originales estan ordenadas

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
    list<T> l_final;
    bool primera_acabada=false, segunda_acabada=false;
    int tope=l1.size()+l2.size();
    typename list<T>::const_iterator i=l1.begin(), j=l2.begin();
    while(l_final.size()<tope){
        if((*i<*j && !primera_acabada) || segunda_acabada ){
            l_final.push_back(*i);
            i++;
            if(i==l1.end())
                primera_acabada=true;
        }
        else{
            if(!segunda_acabada){
            l_final.push_back(*j);
            j++;
            if(j==l2.end())
                segunda_acabada=true;
            }
        }
    }
    return l_final;
    
}

template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l1 {1,3,5,7,9,13,15};
    list<int> l2 {2,4,6,8,10,11,12};
    list<int> l_final;
    cout<<"La lista 1 es:"<<endl;
    mostrar(l1);
    cout<<"La lista 2 es:"<<endl;
    mostrar(l2);
    l_final=mezclar(l1,l2);
    cout<<"La lista mezclada es:"<<endl;
    mostrar(l_final);
}