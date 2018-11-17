/*
@file Cola_max_vd.cpp
@author Miguel Ángel Posadas Arráez
*/
#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

#include<iostream>
#include<vector>
#include "Cola_max_vd.h"

using namespace std;

template <class T>
Cola<T>::Cola(){

}

template <class T>
Cola<T>::Cola(const Cola &c){
	this->elementos=c.getElementos();
	this->mayor=c.getMayores();
        this->anterior=c.anterior;
}
template <class T>
T Cola<T>::maximo() const {
	return this->mayor.back();
}
template <class T>
T Cola<T>::frente() const{
	return this->elementos.front();
}

template <class T>
void Cola<T>::poner(T elemento){
    if(elementos.size()>=1){
        if(elementos[elementos.size()-1]>elemento)
            anterior=elementos[elementos.size()-1];
    }
	this->elementos.push_back(elemento);
        this->mayor.push_back(elemento);
        actualizaMayores();
}



template <class T>
void Cola<T>::quitar(){
	vector<T> aux;
        elementos[0]=-1;
	for(unsigned i=0;i<this->elementos.size();i++){
            if(elementos[i]!=-1)
		aux.push_back(this->elementos[i]);
	}
	
	this->elementos=aux;
	aux.clear();
        mayor[mayor.size()-1]=-1;
	for(unsigned i=0;i<this->mayor.size();i++){
            if(mayor[i]!=-1)
		aux.push_back(this->mayor[i]);
	}
	this->mayor=aux;
}
template <class T>
bool Cola<T>::vacia(){
	return elementos.empty();
}

template <class T>
void Cola<T>::actualizaMayores(){
    bool encontrado=false;
    unsigned tope=0;
    if(this->mayor.size()>=1){
    for(unsigned j= elementos.size();j>0 && !encontrado;j--){
        if(elementos[j]==anterior){
            tope=j;
            encontrado=true;
        }
    }
    int i=mayor.size();
    while(i!=0){
        
        if( mayor[i]>mayor[i-1] ){
            mayor[i-1]=mayor[i];
            }
        i--;
        }
    cout<<"hola";
    }
}

#endif