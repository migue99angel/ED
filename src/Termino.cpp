/*
@file Termino.cpp
@brief fichero de implementación del TDA termino
*/
#include "Diccionario.h"
#include "Vector_Dinamico.h"
#include "Termino.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

	
	Termino::Termino(){
		
	}

	Termino::Termino(string palabra,Vector_Dinamico<string> definiciones ){
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

	void Termino::setDefiniciones (Vector_Dinamico<string> definiciones){
		this->definiciones = definiciones;
	}

	void Termino::setDefinicion(string definicion){
		this->definiciones.resize(this->definiciones.size()+1);
		this->definiciones[this->definiciones.size()]=definicion;
	}

	Termino& Termino::operator =(const Termino& original){
		if(this != &original){
		this->palabra = original.getPalabra();
		this->definiciones = original.getDefiniciones();
		}
		return *this;
	}

	ostream& operator << (ostream &os, const Termino &p){
		for(int i=0;i<p.getDefiniciones().size();i++){
			os<<p.getPalabra()<<";";
			os<<p.getDefinicion(i)<<endl;
		}
		    return os;	
	}

	istream& operator >> (istream &is, Termino &p){
		string palabra_aux, definicion_aux;
		getline(is,palabra_aux,';');
		getline(is,definicion_aux);
		p.setPalabra(palabra_aux);
		p.setDefinicion(definicion_aux);
		getline(is,palabra_aux,';');
		while(strcmp(p.getPalabra().c_str(),palabra_aux.c_str())==0){
			getline(is,definicion_aux);
			p.setDefinicion(definicion_aux);
			getline(is,palabra_aux,';');
		}
		return is;
	}