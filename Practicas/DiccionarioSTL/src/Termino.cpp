/*
@file Termino.cpp
@brief fichero de implementación del TDA termino
*/
#include "Termino.h"
#include <iostream>

using namespace std;

	
	Termino::Termino(){
            
	}

	Termino::Termino(string palabra,vector<string> definiciones ){
		this->definiciones.first = palabra;
		this->definiciones.second = definiciones;
	}

	Termino::Termino(const Termino& termino){
		this->definiciones.first = termino.definiciones.first;
		this->definiciones.second = termino.definiciones.second;
	}

	void Termino::setPalabra (string palabra){
		this->definiciones.first = palabra;
	}

	void Termino::setDefiniciones (vector<string> definiciones){
		this->definiciones.second = definiciones;
	}

	void Termino::setDefinicion(string definicion){
        this->definiciones.second.push_back(definicion);
	}

	Termino& Termino::operator =(const Termino& original){
		if(this != &original){
            this->definiciones.first = original.getPalabra();
            this->definiciones.second = original.getDefiniciones();
		}
		return *this;
	}
    ostream& operator<< (ostream & os, const Termino & t){
            Termino::const_iterator i_c;

            for(i_c = t.begin(); i_c != t.end(); ++i_c){
                os << t.definiciones.first << "-->" << (*i_c) << endl;
            }

            return os;
    }
