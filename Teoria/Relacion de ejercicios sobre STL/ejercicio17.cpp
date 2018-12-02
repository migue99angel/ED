/*
17. Implementa la clase vector dinámico usando como representación el tipo list. ¿Qué orden de eficiencia
tiene cada operación?

COMANDO PARA COMPILAR: g++ -o ejercicio17 ejercicio17.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <list>
#include <vector>
#include <cassert>

using namespace std;

template <class T>
class vector_dinamico{
    private:
        list<T> v;

    public:
    vector_dinamico(){

    }   

    vector_dinamico(const vector_dinamico &vd){
        this->v=vd.v;
    }
    void insert (T elemento){
        v.push_back(elemento);
    }
    T getElemento(int indice){
        int cont=0;
        typename list<T>::const_iterator i=v.begin();
        for(i;cont!=indice;i++){
            cont++;
        }
        return *i;
    }
    int size(){
        v.size();
    }
    bool empty(){
        return v.empty();
    }
    T operator[]( int i){
        assert(i>=0 && i<v.size());
        return getElemento(i);
    }
    T front(){
        return *(v.begin());
    }
    T back(){
        return getElemento(size()-1);
    }
    

};

int main(){
    vector_dinamico<int> v;
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(6);
    cout<<"El elemento en la posicion 2 es: "<<v[2]<<endl;
    cout<<"El tamanio del vector es : "<<v.size()<<endl;
    if(v.empty())
        cout<<"El vector esta vacio"<<endl;
    else 
        cout<<"El vector NO esta vacio"<<endl;
    cout<<"El primer elemento del vector es: "<<v.front()<<endl;        
    cout<<"El ultimo elemento del vector es: "<<v.back()<<endl;    


}