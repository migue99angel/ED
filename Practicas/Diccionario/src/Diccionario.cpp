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
        bool encontrado=false;
        int pos;
		this->diccionario.resize(diccionario.size()+1);
		for(int i=0; i<diccionario.size() && !encontrado ;i++ ){
			if(nuevo.getPalabra() < diccionario[i].getPalabra()){
                            pos=i;
                            encontrado = true;
			}
		}
        if(!encontrado)
            pos=this->getNumTerminos()-1;
                
        for(int i=this->getNumTerminos()-1;i>pos;i--)
            diccionario[i]=diccionario[i-1];
		
        diccionario[pos] = nuevo;
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
		for (int i=0;i<this->getNumTerminos() && !encontrado ;i++){
                    Termino aux = this->diccionario[i];
                    string palabra=this->diccionario[i].getPalabra();
			if((this->diccionario[i].getPalabra().compare(buscar) )==0){
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
        string comparacion;
		Diccionario filtrado;
                for(int i=0; i<this->diccionario.size() ; i++){
                    comparacion = this->diccionario[i].getPalabra();

                    if( comparacion[0]>=a && comparacion[0]<=b )
                        filtrado.addTermino(this->diccionario[i]);
    }

                return filtrado;
 }
	
	Diccionario Diccionario::filtroPalabraClave (string clave){
		Diccionario aux;
		
		for(int i=0;i<this->getNumTerminos();i++){
                    Termino t;
                    bool incluido=true;
                    
			for (int j=0;j<this->diccionario[i].getNumDefiniciones();j++){                        
				if( diccionario[i].getDefinicion(j).find(clave) != string::npos ){
                    t.setPalabra(this->diccionario[i].getPalabra());
					incluido=false;
                    t.setDefinicion(diccionario[i].getDefinicion(j));
				}                                
            }

			if(!incluido){
               aux.addTermino(t);
			}			
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
		media=(1.0*num_defs/this->getNumTerminos());		
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
			os << p.diccionario[i].getPalabra()<<";";
                        os << p.diccionario[i].getDefinicion(j)<<endl;
		}
	}
	return os;
}

istream& operator >> (istream &is, Diccionario &p){
    string aux;
    string anterior = "\0";
    
    
    getline(is, aux, ';');
    do{
        Termino taux;
        do{
            if(anterior == "\0" || aux != anterior){
                taux.setPalabra(aux);
                anterior = aux;
                getline(is, aux, '\n');
                taux.setDefinicion(aux);
            }
            else{
                getline(is, aux, '\n');
                taux.setDefinicion(aux);
            }

            if(!is.eof())
                getline(is, aux, ';');
        }while(aux == anterior);

        p.addTermino( taux );
        
    }while(!is.eof());

    return is;
}


