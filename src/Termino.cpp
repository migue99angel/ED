/*
@file Termino.cpp
@brief fichero de implementación del TDA termino
*/
#include "Diccionario.h"
#include "vector_dinamico.h"
#include "Termino.h"
#include <fstream>
#include <iostream>

using namespace std;

class Termino{
private:	
	Termino::Termino(){
		palabra=null;
		definiciones=null;
	}

	Termino::Termino(string palabra,vector_dinamico definiciones ){
		this->palabra = palabra;
		this->definiciones = definiciones;
	}

	Termino::Termino(const Termino& termino){
		this->palabra = termino.palabra;
		this->definiciones = termino.definiciones;
	}
	void Termino::setPalabra (string palabra){
		this->palabra = palabra;
	}
	void Termino::setDefiniciones (vector_dinamico definiciones){
		this->definiciones = definiciones;
	}
	void setDefinicion(string definicion){
		this->definiciones.resize(definiciones.size()+1);
		this->definiciones[definiciones.size()]=definicion;
	}

	Termino& operator =(const Termino& original){
		if(this != &original){
		this->palabra = original.getPalabra;
		this->definiciones = original.getDefiniciones;
		}
		return *this;
	}
}
ostream& operator << (ostream &os, const Termino $p){
	for(int i=0;i<p.getDefiniciones().size();i++){
		os<<p.getPalabra()<<";";
		os<<getDefiniciones(i)<<endl;
	}
	    return os;	
}

istream& operator >> (istream &is, Termino $p){
	string palabra_aux, definicion_aux;
	getline(is,palabra_aux,';');
	getline(is,definicion_aux);
	p.setPalabra(palabra_aux);
	p.setDefinicion(definicion_aux);
	getline(is,palabra_aux,';');
	while(strcmp(palabra_aux,p.getPalabra()==0)){
		getline(is,definicion_aux);
		p.setDefinicion(definicion_aux);
		getline(is,palabra_aux,';');
	}
	return is;
}