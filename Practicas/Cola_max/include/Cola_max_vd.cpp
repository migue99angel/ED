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
}
template <class T>
T Cola<T>::maximo() const {
	return this->mayor.back();
}
template <class T>
T Cola<T>::frente() const{
	return this->mayor.front();
}

template <class T>
void Cola<T>::poner(T elemento){
        bool esmayor=true;
	this->elementos.push_back(elemento);
	if(this->elementos[this->elementos.back()]<elemento){
		this->mayor.push_back(elemento);
                for(unsigned i=mayor.back()-1;i>0 && esmayor;i--){
                    if(mayor[i]<elemento)
                        mayor[i]=elemento;
                    else
                        esmayor=false;
                    
                }
        }
	else
		this->mayor.push_back(mayor.back());
	}
template <class T>
void Cola<T>::quitar(){
	vector<T> aux;
	for(unsigned i=1;i<this->elementos.size();i++){
		aux.push_back(this->elementos[i]);
	}
	
	this->elementos=aux;
	aux.clear();

	for(unsigned i=1;i<this->mayor.size();i++){
		aux.push_back(this->mayor[i]);
	}

	this->mayor=aux;
}
template <class T>
bool Cola<T>::vacia(){
	return elementos.empty();
}
#endif