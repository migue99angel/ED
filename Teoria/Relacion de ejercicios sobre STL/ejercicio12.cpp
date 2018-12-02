/*
12. Implementa una función bool contenida(const list<T> &l1, const list<T> &l2)
a la que se le pasen dos listas y compruebe si la lista l1 está contenida en l2 (si los elementos apa-
recen en la otra y en el mismo orden).

COMANDO PARA COMPILAR: g++ -o ejercicio12 ejercicio12.cpp

Observaciones: Para la resolución del ejercicio voy a suponer que l1 siempre será una lista de menor tamaño que l2 

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)

*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T>
bool contenida(const list<T> &l1, const list<T> &l2){
    int contador=0;
    int tope=l1.size();
    bool contenido=false;
    typename list<T>::const_iterator i=l2.begin(), j=l1.begin();
    for(j;j!=l1.end() && !contenido ;j++){
        for(i;i!=l2.end() && !contenido;i++){
            if(*i==*j){
                contador++;
                j++;
                if(contador==tope)
                    contenido=true;
            }
            else
                contador=0;    
        }
    }
    return contenido;
}


template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}

int main(){

    list<int> l2 {1,2,3,4,5,6,7,8,9};
    list<int> l1 {5,6,7};
    cout<<"La primera lista es: "<<endl;
    mostrar(l1);
    cout<<"La segunda lista es: "<<endl;
    mostrar(l2);
    if(contenida(l1,l2))
        cout<<"La lista 1 esta contenida en la lista 2"<<endl;
    else
        cout<<"La lista 1 NO esta contenida en la lista 2"<<endl;    

}