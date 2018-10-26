/*
@file Diccionario.cpp
@brief fichero de implementación del TDA diccionario
*/
#include "Diccionario.h"
#include <string.h>
#include "Vector_Dinamico.h"
#include <iostream>

using namespace std;

	Diccionario::Diccionario(){
		diccionario=0;
	}

	Diccionario::Diccionario(Vector_Dinamico<Termino> terminos){
		this->diccionario=terminos;
	}

	Diccionario::Diccionario(const Diccionario& diccionario){
		this->diccionario=diccionario.getDiccionario();
	}

	Vector_Dinamico<string> Diccionario::getSignificados(string buscar){
		int indice=buscarTermino(buscar);
		return this->diccionario[indice].getDefiniciones();
	}

	void Diccionario::addTermino(Termino nuevo){
		Termino aux;
		this->diccionario.resize(diccionario.size()+1);
		for(int i=0; i<diccionario.size();i++ ){
			if(strcmp(diccionario[i].getPalabra().c_str(),nuevo.getPalabra().c_str()) > 0){
				for(int j=diccionario[i].getNumDefiniciones()-1;j>i;j--){
					this->diccionario[j]=this->diccionario[j+1];
				}
			this->diccionario[i]=nuevo;
			}
		}
	}

	void Diccionario::delTermino(Termino eliminar){
		Termino aux;
		int indice=buscarTermino(eliminar.getPalabra());
		for(int i=indice;i<diccionario.size();i++){
			diccionario[i+1]=diccionario[i];
		}
		diccionario.resize(diccionario.size()-1);
	}

	int Diccionario::buscarTermino(string buscar){
		int indice=-1;
		bool encontrado=false;
		for (int i=0;i<diccionario.size() && !encontrado ;i++){
			if(strcmp(this->diccionario[i].getPalabra().c_str(),buscar.c_str())==0){
				indice=i;
				encontrado=true;
			}
		}
		return indice;
	}
	bool Diccionario::contenido(string palabra){
		bool contenido=false;
		int entero=this->buscarTermino(palabra);
		if(entero != -1)
			contenido=true;
		return contenido;
	}

	Diccionario Diccionario::filtroIntervalo (char a, char b){
		int comienzo,final;
		Diccionario filtrado;
		bool encontrado=false;
		for(int i=0; i < this->getNumTerminos() && !encontrado ;i++){
			if(diccionario[i].getPalabra()[0]==a){
				comienzo=i;
				encontrado=true;
			}
		}
		encontrado=false;
		for(int i=comienzo; i < this->getNumTerminos() && !encontrado ;i++){
			if(diccionario[i].getPalabra()[0]==b){
				final=i;
				encontrado=true;
			}
		}
		for(int i=comienzo;i<final;i++){
			for(int j=0;j<(final-comienzo);j++){
				filtrado.addTermino(diccionario[i]);
			}
		}
		return filtrado;
	}
	
	Diccionario Diccionario::filtroPalabraClave (string clave){
		unsigned pos,contador=0;
		Diccionario aux;
		bool incluido=false;
		for(int i=0;i<this->getNumTerminos();i++){
			for (int j=0;j<this->diccionario[i].getNumDefiniciones();i++){
				pos=diccionario[i].getDefinicion(j).find(clave);
				if( pos != string::npos && !incluido ){
					aux.diccionario[contador]=this->diccionario[i];
					incluido=true;
				}
				if(pos != string::npos){
					aux.diccionario[contador].setDefinicion(this->diccionario[i].getDefinicion(j));
				}

			}
		contador++;
		incluido=false;
		}
		return aux;
	}	

	void Diccionario::recuento(int& num_defs, int& max_defs, float& media){
		num_defs=max_defs=media=0;
		for(int i=0;i<diccionario.size();i++){
			num_defs += diccionario[i].getNumDefiniciones();
			if(diccionario[i].getNumDefiniciones() > max_defs)
				max_defs=diccionario[i].getNumDefiniciones();
		}
		media=(num_defs/this->getNumTerminos());		
	}	

	Diccionario& Diccionario::operator=(const Diccionario& original){
		if(this != &original){
			this->diccionario=original.diccionario;
		}
		return *this;
	}



ostream& operator << (ostream &os, const Diccionario &p){
	for(int i=0;i <p.getNumTerminos(); i++){
		for(int j=0;j<p.getTermino(i).getNumDefiniciones();j++){
			os << p.getTermino(i); 
		}
	}
	return os;
}

istream& operator >> (istream &is, Diccionario &p){
	Termino aux;
	while(!is.eof()){
		is >> aux;
		p.addTermino(aux);
	}
	return is;
}