/*
18. Implementa la función intercalar(vector<T> &v, vector<pair<int, T> > pos)
que inserta el segundo elemento de cada par de pos en v en los lugares indicados por el primer
elemento de cada par de pos

COMANDO PARA COMPILAR: g++ -o ejercicio18 ejercicio18.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;


template <typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){
    typename vector<pair<int, T>>::iterator i=pos.begin();
    typename vector<T>::iterator j;
    for(i;i!=pos.end();i++){
        j=i->first;
        v.insert(j,i->second);
    }
}
int main(){
    vector<pair<int,int>> pos;
    vector<int> v;
    pos.push_back(make_pair(1,2));
    pos.push_back(make_pair(2,5));
    pos.push_back(make_pair(3,7));
    pos.push_back(make_pair(5,3));
    pos.push_back(make_pair(6,8));

    cout<<"El vector de pares es : "<<endl;
    for(typename vector<pair<int,int>>::const_iterator i=pos.begin();i!=pos.end();i++){
        cout<<" ("<<i->first<<" , "<<i->second<<")  ";
    }
    cout<<"El vector intercalado es:"<<endl;
    intercalar(v,pos);
    for(int j;j< v.size();j++){
        cout<<"  "<<v[j]<<"  ";
    }
}