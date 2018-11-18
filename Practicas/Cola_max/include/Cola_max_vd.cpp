/*
@file Cola_max_vd.cpp
@author Miguel Ángel Posadas Arráez
*/
#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

#include<iostream>
#include<vector>
#include "Cola_max.h"

using namespace std;

template <class T>
Cola<T>::Cola(){
	this->elementos=vector<T>();
	this->mayor=vector<T>();
    this->pos=0;
}

template <class T>
Cola<T>::Cola(const Cola &c){
	this->elementos=c.getElementos();
	this->mayor=c.getMayores();
    this->pos=c.pos;
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
    T max;
    this->elementos.push_back(elemento);  
    if(mayor.empty()){
        max =(int) 0;
    }
    
    else{
        max = (T) maximo();
    } 
    if(elemento < max){
        mayor.push_back(elemento);
        pos = mayor.size() - 1;
    }
    else{

        for(unsigned i=mayor.size(); i>pos; i--){
            mayor.pop_back();
        }        
        for(unsigned i=mayor.size(); i<elementos.size(); i++){
            mayor.push_back(elemento);
        }
    }
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
#endif