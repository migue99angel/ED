/*
@file Diccionario.cpp
@brief fichero de implementación del TDA diccionario
*/
#include "Diccionario.h"
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

	Diccionario::Diccionario(){
            
	}

	Diccionario::Diccionario(set<Termino,Orden> terminos){
		this->diccionario=terminos;
	}

	Diccionario::Diccionario(const Diccionario& diccionario){
		this->diccionario=diccionario.getDiccionario();
	}

	vector<string> Diccionario::getSignificados(string buscar){
        Termino aux;
        Diccionario::iterator i;
        for(i= this->diccionario.begin();i!=this->end();i++){
            if(i->getPalabra() == buscar)
                aux =*i;
        }

        return aux.getDefiniciones();
	}

	void Diccionario::addTermino(Termino nuevo){
        this->diccionario.insert(nuevo);
	}

	void Diccionario::delTermino(Termino eliminar){
        this->diccionario.erase(eliminar);
	}

	bool Diccionario::contenido(Termino palabra){
		Diccionario::const_iterator i= this->diccionario.find(palabra);
        if (i != this->end())
            return true;
        else 
            return false;
	}

	Diccionario Diccionario::filtroIntervalo (char a, char b){
        string comparacion;
		Diccionario filtrado;
        Diccionario::const_iterator i_c;
        Termino aux;
        for(i_c=this->begin(); i_c != this->end() ; i_c++){
            aux = *i_c;
            comparacion=aux.getPalabra();
            if( comparacion[0]>=a && comparacion[0]<=b )
                filtrado.addTermino(aux);
        }
        return filtrado;
 }
	
	Diccionario Diccionario::filtroPalabraClave (string clave){
		Diccionario aux;
		Diccionario::iterator i;
		for(i=this->begin();i != this->end();i++){
            Termino taux;
            bool incluido=true;
			for (int j=0 ;j< (*i).getNumDefiniciones();j++){         
                if( (*i).getDefiniciones()[j].find(clave) != string::npos ){
                    taux.setPalabra((*i).getPalabra());
                    incluido=false;
                    taux.setDefinicion((*i).getDefiniciones()[j]);
                }                                
            }
			if(!incluido){
                aux.addTermino(taux);
			}			
		}
		return aux;
	}	

	void Diccionario::recuento(int& num_defs, int& max_defs, float& media){
        Diccionario::const_iterator i;
		num_defs=max_defs=media=0;
		for(i=this->begin() ;i !=this->diccionario.end() ;i++){
			num_defs += (*i).getNumDefiniciones();
			if((*i).getNumDefiniciones() > max_defs)
				max_defs=(*i).getNumDefiniciones();
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
    Diccionario::const_iterator i;
	for(i=p.begin() ;i != p.end() ; i++){
            os<<*i;
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
