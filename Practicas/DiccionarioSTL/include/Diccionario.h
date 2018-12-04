/*
@file Termino.h
@brief fichero cabecera del TDA termino
*/
#ifndef diccionario_h
#define diccionario_h
#include "Termino.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <utility>
#include <set>
#include <vector>
using namespace std;
class Orden{
public:
	bool operator () (const Termino & t1, const Termino & t2){
		return t1.getPalabra() < t2.getPalabra();
	}
};
/*
 * @class Diccionario
 * @brief Representacion del TDA Diccionario
*/
class Diccionario{
private:
	set<Termino,Orden> diccionario;

public:
	/*
	@brief constructor sin parametros
	*/
 	Diccionario(); 
 	/*
 	@brief constructor con parametros
	@param vector de terminos
	*/	
 	Diccionario(set<Termino,Orden> terminos);
	/*
	@brief constructor copia
	@param Diccionario a copiar
	*/
	Diccionario(const Diccionario& diccionario);
	/*
	@brief consultor de diccionario
	@return diccionario
	*/	
	inline set<Termino,Orden> getDiccionario() const {return diccionario;}
	/*
	@brief devuelve las definiciones de un termino
	@return definiciones
	*/	
	vector<string> getSignificados(string buscar);
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
	@brief Devuelve true si la palabra introducida esta contenida en el diccionario
	@param palabra a buscar
	@return true si esta contenida ,en caso contrario devuelve false
	*/
	bool contenido(Termino palabra);
	/*
		*@brief Iterador para recorrer el diccionario, puede modificarlo
	*/
	typedef set<Termino>::iterator iterator;
	/*
		*@brief Iterador para recorrer el diccionario
	*/
	typedef set<Termino>::const_iterator const_iterator;       
	/*
	@brief Sobrecarga de operadores de entrada y salida
	*/
	friend ostream& operator << (ostream &os, const Diccionario &p);
	friend istream& operator >> (istream &is, Diccionario &p);
	/*
	* @brief Devuelve un iterador al comienzo del diccionario, puede modificarlo
	*/
	inline Diccionario::iterator begin() {return this->diccionario.begin();}
	/*
	*@brief Devuelve un iterador al final del diccionario, puede modificarlo
	*/
	inline Diccionario::iterator end() {return this->diccionario.end();}
	/*
	* @brief Devuelve un iterador al comienzo del diccionario
	*/
	inline Diccionario::const_iterator begin() const {return this->diccionario.cbegin();}
	/*
	*@brief Devuelve un iterador al final del diccionario
	*/
	inline Diccionario::const_iterator end() const {return this->diccionario.cend();}
	};
        


#endif