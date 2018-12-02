/*
16. Una forma eficiente de guardar secuencias de valores iguales consiste en guardar cada uno de los
valores seguido del número de veces que aparece en la secuencia. Por ejemplo,
<1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5>
< (1,3), (2,6), (7,5), (12,1), (1,2), (5,2) >
Implementa las funciones:
list<pair<T, int> > comprimir(const list<T> &l)+
list<T> descomprimir(const list<pair<T, int> > &lc)
que permitan convertir entre ambas representaciones.

COMANDO PARA COMPILAR: g++ -o ejercicio16 ejercicio16.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <list>

using namespace std;

template <typename T>
list<pair<T, int> > comprimir(const list<T> &l){
    int contador=1;
    list<pair<T,int>> l_comprimida;
    typename list<T>::const_iterator i=l.begin();
    typename list<T>::const_iterator j=l.begin();
    for(i;j!=l.end();i++){
        j++;
        if(*i==*j)
            contador++;
        else{
            l_comprimida.push_back(make_pair(*i,contador));
            contador=1;
        }
    }
    return l_comprimida;
}

template <typename T>
list<T> descomprimir(const list<pair<T, int> > &lc){
    list<T> l_descomprimida;
    int tope=0;
    typename list<pair<T,int>>::const_iterator i=lc.begin(),j;
    for(i;i!=lc.end();i++){
        for(j=i;tope < i->second;j++){
            l_descomprimida.push_back(i->first);
            tope++;
        }
        tope=0;
    }
    return l_descomprimida;

}
template<typename T>
void mostrar(const list<T> &l){

    for(typename list<T>::const_iterator i=l.begin();i!=l.end();i++){
        cout<<" "<<*i<<" ";
    }
    cout<<endl;
}


int main(){
    list<int> l {1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5}, l_descomprimida;
    list<pair<int,int>> l_comprimida;
    cout<<"La lista original es: "<<endl;
    mostrar(l);
    cout<<"Comprimiendo..."<<endl;
    l_comprimida=comprimir(l);
    cout<<"La lista comprimida es : "<<endl;
    for(typename list<pair<int,int>>::const_iterator i=l_comprimida.begin();i!=l_comprimida.end();i++){
        cout<<" ("<<i->first<<" , "<<i->second<<")  ";
    }
    cout<<endl;
    cout<<"Descomprimiendo..."<<endl;
    l_descomprimida=descomprimir(l_comprimida);
    cout<<"La lista descomprimida es: "<<endl;
    mostrar(l_descomprimida);
}