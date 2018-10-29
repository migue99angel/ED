/*
@file Termino.h
@brief fichero cabecera del TDA termino
*/
#ifndef termino_h
#define termino_h
#include <string>
#include "Vector_Dinamico.h"

using namespace std;

class Termino{
private:
	string palabra;
	Vector_Dinamico<string> definiciones; 

public:
	/*
	@brief constructor sin parametros
	*/
 	Termino(); 
 	/*
	@brief constructor con parametros
	@param palabra
	@param definiciones
	*/	
 	Termino(string palabra, Vector_Dinamico<string> v);
	/*
	@brief constructor copia
	@param termino a copiar
	*/
	Termino(const Termino& termino);
	/*
	@brief consultor de palabra
	@return palabra
	*/
	inline string getPalabra() const {return this->palabra;}
	/*
	@brief consultor de definiciones
	@return definiciones
	*/
	inline Vector_Dinamico<string> getDefiniciones() const {return definiciones;}
	/*
	@brief consultor de una definicion en concreto
	@param numero de la definicion
	@return definicion
	*/
	inline string getDefinicion(int i) const {return definiciones[i];}
	/*
	@brief consultor de definiciones
	@return numero de definiciones
	*/
	inline int getNumDefiniciones() const {return definiciones.size();}
	/*
	@brief operador de modificacion de palabra
	@param palabra
	*/
	void setPalabra (string palabra);
	/*
	@brief asigna definiciones
	@param definiciones
	*/
	void setDefiniciones (Vector_Dinamico<string> definiciones);
	/*
	@brief añade una definicion a definiciones
	@param definicion
	*/
	void setDefinicion(string definicion);
        /*
	@brief añade una definicion a definiciones
	@param definicion
	*/
        void addDefinicion(string definicion);
	/*
	@brief sobrecarga del operador igual
	@param Termino a asignar
	*/	
	Termino& operator=(const Termino& original);


};

#endif