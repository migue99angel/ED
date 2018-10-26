/*
@file Diccionario.cpp
@brief fichero de implementación del TDA diccionario
*/
#include "Diccionario.h"
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

class Diccionario{
public:
	Diccionario::Diccionario(){
		diccionario=NULL;
	}

	Diccionario::Diccionario(vector_dinamico terminos){
		this->diccionario=terminos;
	}

	Diccionario::Diccionario(const Diccionario& diccionario){
		this=diccionario;
	}friend ostream& operator << (ostream &os, const Diccionario $p);
friend istream& operator >> (istream &is, const Diccionario $p);

	vector_dinamico<string*> getSignificados(Termino buscar){
		int indice=buscarTermino(buscar);
		return diccionario[indice].getDefiniciones();
	}

	void Diccionario::addTermino(Termino nuevo){
		Termino aux;
		this->diccionario.resize(diccionario.size()+1);
		for(int i=0; i<diccionario.getNumTerminos();i++ ){
			if(strcmp(diccionario[i].getPalabra(),nuevo.getPalabra() > 0)){
				for(int j=diccionario.getNumDefiniciones()-1;j>i;j--){
					this->diccionario[j]=this->diccionario[j+1];
				}
			this->diccionario[i]=nuevo;
			}
		}
	}

	void Diccionario::delTermino(Termino eliminar){
		Termino aux;
		int indice=buscarTermino(eliminar);
		diccionario[indice]=NULL;
		for(int i=indice;i<diccionario.size();i++){
			diccionario[i+1]=diccionario[i];
		}
		diccionario.resize(diccionario.size()-1);
	}

	int Diccionario::buscarTermino(Termino buscar){
		int indice=0;
		bool encontrado=false;
		for (int i=0;i<diccionario.size() && !encontrado ;i++){
			if(cmp(this->diccionario[i].palabra,buscar.palabra)==0){
				indice=i;
				encontrado=true;
			}
		}
		return indice;
	}

	Diccionario filtroIntervalo (char a, char b){
		int comienzo,final;
		Diccionario filtrado;
		bool encontrado=false;
		for(int i=0; i < diccionario.size && !encontrado ;i++){
			if(strcmp(Diccionario[i].getPalabra[0],a)==0){
				comienzo=i;
				encontrado=true;
			}
		}
		encontrado=false;
		for(int i=0; i < diccionario.size && !encontrado ;i++){
			if(strcmp(Diccionario[i].getPalabra[0],a)==0){
				final=i;
				encontrado=true;
			}
		}
		for(int i=comienzo;i<final;i++){
			for(int j=0;j<(final-comienzo);j++){
				aux[j]=diccionario[i];
			}
		}
		return aux;
	}
	
	Diccionario filtroPalabraClave (string clave){
		int pos,contador=0;
		Diccionario aux;
		bool incluido=false;
		for(int i=0;i<this->diccionario.getNumDefiniciones();i++){
			for (int j=0;j<this->diccionario[i].getNumDefiniciones();i++){
				pos=diccionario[i].getDefinicion(j).find(clave);
				if( n != string::npos && !incluido ){
					aux[contador]=this->diccionario[i];
					incluido=true;
				}
				if(n != string::npos){
					aux[contador].setDefinicion(this->diccionario[i].getDefinicion(j));
				}

			}
		contador++;
		incluido=false;
		}
		return aux;
	}	

	void recuento(int& num_defs, int& max_defs, float& media){
		num_defs=max_defs=media=0;
		for(int i=0;i<diccionario.size();i++){
			num_defs += diccionario[i].getNumDefiniciones();
			if(diccionario[i].getNumDefiniciones() > mayor)
				mayor=diccionario[i].getNumDefiniciones();
		}
		media=num_defs/diccionario.getNumTerminos();		
	}	

	Diccionario& operator=(const Diccionario& original){
		if(this != &original){
			this->diccionario=original;
		}
		return *this;
	}
};


ostream& operator << (ostream &os, const Diccionario $p){
	for(int i=0;i <p.getNumTerminos(); i++){
		for(int j=0;j<p.getTermino(i).getNumDefiniciones();j++){
			os << p.getTermino(i); Valdria solo con esto?
		}
	}
	return os;
}

istream& operator >> (istream &is, Diccionario $p){
	Termino aux;
	while(!is.eof()){
		is >> aux
		p.addTermino(aux);
	}
	return is;
}