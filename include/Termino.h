/*
@file Termino.h
@brief fichero cabecera del TDA termino
*/
#ifndef termino_h
#define termino_h
#include "vector_dinamico.h"

class Termino{
private:
	string palabra;
	vector_dinamico<string> definiciones; //¿?

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
 	Termino(string palabra, vector_dinamico v);
	/*
	@brief constructor copia
	@param termino a copiar
	*/
	Termino(const Termino& termino);
	/*
	@brief consultor de palabra
	@return palabra
	*/
	inline string getPalabra() const {return palabra};
	/*
	@brief consultor de definiciones
	@return definiciones
	*/
	inline vector_dinamico getDefiniciones() const {return definiciones};
	/*
	@brief consultor de una definicion en concreto
	@param numero de la definicion
	@return definicion
	*/
	inline vector_dinamico getDefinicion(i) const {return definiciones[i]};
	/*
	@brief consultor de definiciones
	@return numero de definiciones
	*/
	inline vector_dinamico getNumDefiniciones() const {return definiciones.size()};
	/*
	@brief operador de modificacion de palabra
	@param palabra
	*/
	void setPalabra (string palabra);
	/*
	@brief asigna definiciones
	@param definiciones
	*/
	void setDefiniciones (vector_dinamico definiciones);
	/*
	@brief añade una definicion a definiciones
	@param definicion
	*/
	void setDefinicion(string definicion);
	/*
	@brief sobrecarga del operador igual
	@param Termino a asignar
	*/	
	Termino& operator=(const Termino& original);
};
	/*
	@brief Sobrecarga de operadores de entrada y salida
	*/

friend ostream& operator << (ostream &os, const Termino $p);
friend istream& operator >> (istream &is, const Termino $p);

#endif