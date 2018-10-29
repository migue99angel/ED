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
        this->definiciones.resize(definiciones.size()+1);
        this->definiciones[definiciones.size()-1]=definicion;
	}

	Termino& Termino::operator =(const Termino& original){
		if(this != &original){
		this->palabra = original.getPalabra();
		this->definiciones = original.getDefiniciones();
		}
		return *this;
	}
