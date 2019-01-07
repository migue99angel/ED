#ifndef __lista_palabras_h__
#define __lista_palabras_h__
#include <vector>
#include <set>
#include <string.h>
#include "bolsa_letras.h"
#include "conjunto_letras.h"
using namespace std;

/**
 * @class lista_palabras
 * @brief T.D.A lista_palabras
 * 
 * @brief Práctica final para la asignatura de Estructura de Datos
 * @author Miguel Ángel Posadas Arráez
 * @date Diciembre 2018 - Enero 2019
 * 
 * Una instancia de este tipo de datos abstracto  
 * almacena ficheros en los que vienen ordenados alfabéticamente
 * un conjunto de palabras que son las que se considerarán soluciones
 * en el juego letras
 * 
 * Esta clase es utilizada en:
 * @include testlista_palabras.cpp
 * @include letras.cpp
 * 
 * 
 */

class lista_palabras{
    public:
    /**
    @brief Construye un lista_palabras vacío.
    **/
    lista_palabras();
    /**
    @brief Devuelve el numero de palabras en el lista_palabras
    **/
    inline int size() const {return datos.size();}
    /**
    @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
    @param longitud la longitud de las palabras de salida
    @return un vector con las palabras de longitud especificada en el parámetro de entrada
    **/
    vector<string> palabras_longitud(unsigned longitud);
    /**
    @brief Indica si una palabra está en el lista_palabras o no
    @param palabra la palabra que se quiere buscar
    @return true si la palabra esta en el lista_palabras. false en caso contrario
    **/
    bool Esta(string palabra);
    /**
    @brief genera las posibles soluciones con la bolsa dada
    @param la bolsa de letras generada
    @return Soluciones posibles
    **/
    lista_palabras generarSoluciones(const BolsaLetras &bolsa);
    /**
    @brief genera una lista_palabras con las mejores soluciones
    @param Modo de juego
    @return lista_palabra con soluciones
    **/
    lista_palabras mejoresSoluciones(char modo, Conjunto_letras &c);
    /**
    @brief Lee de un flujo de entrada un lista_palabras
    @param is flujo de entrada
    @param D el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is, lista_palabras &D);
    /**
    @brief Escribe en un flujo de salida un lista_palabras
    @param os flujo de salida
    @param D el objeto lista_palabras que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const lista_palabras &D);
    /**
    @brief Iterador para recorrer la lista_palabras, puede modificarlo
	**/
	typedef set<string>::iterator iterator;
	/**
    @brief Iterador para recorrer la lista_palabras
	**/
	typedef set<string>::const_iterator const_iterator;
    /**
	@brief Devuelve el valor del iterador correspondiente al principio del set, puede modificar el set
	@return Valor del iterador al comienzo del set 
	**/
	inline lista_palabras::iterator begin(){return this->datos.begin();}
	/**
	@brief Devuelve el valor del iterador correspondiente al final del set, puede modificar el set
	@return Valor del iterador al final del set 
	**/
	inline lista_palabras::iterator end() {return this->datos.end();}
	/**
	@brief Devuelve el valor del iterador correspondiente al principio del set
	@return Valor del iterador al comienzo del set 
	**/
	inline lista_palabras::const_iterator begin() const{return this->datos.cbegin();};
	/**
	@brief Devuelve el valor del iterador correspondiente al final del set
	@return Valor del iterador al final del set 
	**/
	inline lista_palabras::const_iterator end() const{return this->datos.cend();};

    private:
    set<string> datos;
};
    #endif