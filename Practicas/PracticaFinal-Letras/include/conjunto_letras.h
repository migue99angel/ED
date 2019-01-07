#ifndef __conjunto_letras_h__
#define __conjunto_letras_h__
#include <set>
#include "letra.h"
#include "bolsa_letras.h"

using namespace std;

/**
 * @class Orden
 * 
 * @brief Práctica final para la asignatura de Estructura de Datos
 * @author Miguel Ángel Posadas Arráez
 * @date Diciembre 2018 - Enero 2019
 * 
 * Esta clase establece el orden con el que se ordenará el set
 * de la clase Conjunto_letras
 * 
 * Un ejemplo de utilización de esta clase lo podemos ver en:
 * @include testconjunto_letras.cpp
 * 
 * 
 * 
 */
class Orden{
public:
	bool operator () (const letra &l1, const letra &l2){
		return l1.getCaracter() < l2.getCaracter();
	}
};
/**
 * @class Conjunto_letras
 * @brief T.D.A Conjunto_letras
 * 
 * @brief Práctica final para la asignatura de Estructura de Datos
 * @author Miguel Ángel Posadas Arráez
 * @date Diciembre 2018 - Enero 2019
 * 
 * Una instancia de este tipo de dato abstracto utiliza la clase
 * letra para formar un contenedor que almacenará objetos de la clase letra
 * 
 * Un ejemplo de utilización de esta clase lo podemos ver en:
 * @include testconjunto_letras.cpp
 * 
 * 
 * 
 */
class Conjunto_letras{
    private:
    set<letra,Orden> conjunto;
    public:
    /**
    *@brief Constructor por defecto
    **/
    Conjunto_letras();
    /**
    *@brief Inserta una letra
    **/
    void insertar(letra l);
    /**
    @brief Devuelve el tamaño del contenedor
    @return numero de letras en el conjunto
    **/
    inline int size() const{return this->conjunto.size();}
    /**
    @brief Calcula los puntos de cada solución
    @param solución
    @param modo de juego
    **/
    int obtenerRanking(string solucion,char modo);
    /**
    @brief A partir de un conjunto genera una bolsa de letras para jugar
    @param Cantidad de letras
    @return Bolsa_letras
    **/
    BolsaLetras  generarLetrasJuego(int cantidad);
    /**
    @brief Lee de un flujo de entrada un fichero letras
    @param is flujo de entrada
    @param D el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is, Conjunto_letras &L);
    /**
    @brief Escribe en un flujo de salida un letras
    @param os flujo de salida
    @param D el objeto Conjunto_letras que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const Conjunto_letras &L);
    /**
    @brief Iterador para recorrer la lista_palabras, puede modificarlo
	**/
	typedef set<letra,Orden>::iterator iterator;
	/**
    @brief Iterador para recorrer la lista_palabras
	**/
	typedef set<letra,Orden>::const_iterator const_iterator;
    /**
	* @brief Devuelve el valor del iterador correspondiente al principio del set, puede modificar el set
	* @return Valor del iterador al comienzo del set 
	**/
	inline Conjunto_letras::iterator begin(){return this->conjunto.begin();}
	/**
	* @brief Devuelve el valor del iterador correspondiente al final del set, puede modificar el set
	* @return Valor del iterador al final del set 
	**/
	inline Conjunto_letras::iterator end() {return this->conjunto.end();}
	/**
	* @brief Devuelve el valor del iterador correspondiente al principio del set
	* @return Valor del iterador al comienzo del set 
	**/
	inline Conjunto_letras::const_iterator begin() const{return this->conjunto.cbegin();};
	/**
	* @brief Devuelve el valor del iterador correspondiente al final del set
	* @return Valor del iterador al final del set 
	**/
	inline Conjunto_letras::const_iterator end() const{return this->conjunto.cend();};

};


#endif