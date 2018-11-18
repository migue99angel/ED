#ifndef pila_max_h
#define pila_max_h

/*
* @file Cola_max_pila.h
* @brief Fichero de cabecera de Cola_max_pila
* @author Miguel Ángel Posadas Arráez
*/

#include <iostream>
#include <stack>
 

using namespace std;



template <class T> 
class Cola{
private:
	/*
	* TDA Cola_max_pila
	*/
	stack<T> elementos;
	stack<T> mayores;
        int pos;

public:
	/*
	* @brief Constructor por defecto
	*/
	Cola();

	/*
	* @brief Constructor por parámetros
	*/
	Cola(stack<T> elementos, stack<T> mayores);

	/*
	* @brief Constructor por copia
	* @param La cola de la que se hace la copia. No se modifica
	*/
	Cola(const Cola& c);

	/*
	* @brief Insertar un elemento en la cola
	* @param El elemento a insertar
	*/
	void poner(const T& elemento);

	/*
	* @brief Eliminar elemento de la cola. Elimina el elemento que acaba de entrar
	*/
	void quitar();

	/*
	* @brief Devuelve el elemento del frente, el primero en entrar
	* @return El elemento
	*/
	T& frente();

	/*
	* @brief Devuelve el máximo actual en la cola
	* @return El máximo de la cola
	*/
	T& maximo();
 
	/*
	* @brief Comprueba si la cola 
	* @return Devuelve true si está vacía, false si no lo está
	*/
	bool vacia();

	/*
	* @brief Devuelve el número de elementos que contiene la cola
	* @return Número de elementos de la cola
	*/
	int num_elementos();
};

#include "Cola_max_pila.cpp"
#endif
