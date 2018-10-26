/*
@file Termino.h
@brief fichero cabecera del TDA termino
*/
#ifndef diccionario_h
#define diccionario_h
#include "Termino.h"
#include "Vector_Dinamico.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class Diccionario{
private:
	Vector_Dinamico<Termino> diccionario;

public:
	/*
	@brief constructor sin parametros
	*/
 	Diccionario(); 
 	/*
 	@brief constructor con parametros
	@param vector de terminos
	*/	
 	Diccionario(Vector_Dinamico<Termino> terminos);
	/*
	@brief constructor copia
	@param Diccionario a copiar
	*/
	Diccionario(const Diccionario& diccionario);
	/*
	@brief consultor de diccionario
	@return diccionario
	*/	
	inline Vector_Dinamico<Termino> getDiccionario() const {return diccionario;}
	/*
	@brief devuelve las definiciones de un termino
	@return definiciones
	*/	
	Vector_Dinamico<string> getSignificados (string palabra);
	/*
	@brief devuelve el termino que ocupa la posicion que se le pasa por parametro
	@param posicion en el diccionario del elemento a devolver
	@return termino
	*/	
	inline Termino getTermino (int i) const {return diccionario[i];}
	/*
	@brief consultor de diccionario
	@return diccionario
	*/	
	inline int getNumTerminos() const {return diccionario.size();}
	/*
	@brief añade un nuevo termino al diccionario
	*/	
	void addTermino(Termino nuevo);
	/*
	@brief elimina un termino del diccionario
	*/	
	void delTermino(Termino eliminar);
	/*
	@brief Devuelve un diccionario con los terminos que se encuentran entre los límites
	@param a extremo inferior del intervalo
	@param b extremo superior del intervalo
	*/
	Diccionario filtroIntervalo (char a, char b);	
	/*
	@brief Devuelve un diccionario con los terminos en cuyas definiciones se encuentra la palabra clave
	@param palabra clave
	*/
	Diccionario filtroPalabraClave (string clave);
	/*
	@brief esta funcion hace el recuento de definiciones, el numero máximo de definiciones de un termino y la media de definiciones
	@param num_defs variable en la que guardaremos el numero de definiciones
	@param max_defs variable donde guardaremos el numero maximo de definiciones 
	@param media variable en la que guardaremos la media de las definiciones
	*/
	void recuento(int& num_defs, int& max_defs, float& media);
	/*
	@brief sobrecarga del operador igual
	@param Diccionario a asignar
	*/	
	Diccionario& operator=(const Diccionario& original);
	/*
	@brief Busca un Termino en el diccionario (lo hace usando la palabra)
	@return Devuelve la posicion en la que se encuentra el termino a buscar, -1 si no lo encuentra
	*/
	int buscarTermino(string buscar);
	/*
	@brief Devuelve true si la palabra introducida esta contenida en el diccionario
	@param palabra a buscar
	@return true si esta contenida ,en caso contrario devuelve false
	*/
	bool contenido(string palabra);
	/*
	@brief Sobrecarga de operadores de entrada y salida
	*/
	friend ostream& operator << (ostream &os, const Diccionario &p);
	friend istream& operator >> (istream &is, Diccionario &p);
	};


#endif