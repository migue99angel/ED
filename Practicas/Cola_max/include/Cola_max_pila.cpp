/*
* @file Cola_max_elementos.cpp
* @author Miguel Ángel Posadas Arráez
*/

#ifndef PILAMAX_H
#define PILAMAX_H

#include <iostream>
#include <stack>
#include "Cola_max.h"

using namespace std;

template<class T> 
Cola<T>::Cola(){
    this->elementos = stack<T>();
    this->mayores = stack<T>();
    this->pos = 0;
}

template<class T> 
Cola<T>::Cola(stack<T> elementos, stack<T> mayores){
    this->elementos = elementos;
    this->mayores = mayores;
}

template<class T> 
Cola<T>::Cola(const Cola& c){
    this->elementos = c.elementos;
    this->mayores = c.mayores;
}

template<class T> 
void Cola<T>::poner(const T& elemento){
    T max;
    this->elementos.push(elemento);
    
    if(mayores.empty())
        max = (int) 0;
    
    else
        max = (T) maximo();
    
    
    if(elemento < (T) max){
        mayores.push(elemento);
        pos = mayores.size() - 1;
    }
    
    else{

        while(mayores.size() != pos){
            mayores.pop();
        }
        
        for(int i=mayores.size(); i<elementos.size(); i++){
            mayores.push(elemento);
        }
    }
}

template<class T> 
void Cola<T>::quitar(){
    stack<T> elementos_aux;

    while(!elementos.empty()){
        elementos_aux.push(elementos.top());
        elementos.pop();
    }
    
    elementos_aux.pop();
    
    while(!elementos_aux.empty()){
        elementos.push(elementos_aux.top());
        elementos_aux.pop();
    }
   
    mayores.pop();    
}

template<class T> 
T& Cola<T>::frente(){
	stack<T> elementos_aux;
        
	while(!elementos.empty()){
		elementos_aux.push(elementos.top());
		elementos.pop();
	}

	T& frente = elementos_aux.top();

	while(!elementos_aux.empty()){
		elementos.push(elementos_aux.top());
		elementos_aux.pop();
	}

	return frente;
}

template<class T> 
T& Cola<T>::maximo(){
	return mayores.top();
}

template<class T> 
bool Cola<T>::vacia(){
	bool vacia = false;

	if(elementos.empty())
            vacia = true;

	return vacia;
}

template<class T> 
int Cola<T>::num_elementos(){
	return this->elementos.size();
}

#endif