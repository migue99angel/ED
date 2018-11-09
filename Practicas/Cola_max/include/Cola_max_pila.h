/*
@file Cola_max_vd.h
@author Miguel Ángel Posadas Arráez
*/
#include<iostream>
#include<stack>

using namespace std;
template <class T>
class Cola{
private:

public:
	/*
	@brief Constructor sin parámetros
	*/
	Cola();
	/*
	@brief Constructor de copia
	*/
	Cola(const Cola &c);
	/*
	@brief devuelve el máximo introducido hasta el momento
	@return maximo
	*/	
	T  maximo();
	/*
	@brief devuelve el numero de elementos
	@return numero elementos
	*/
	int num_elementos();
	/*
	@brief devuelve el elemento al frente de la cola
	@return elemento al frente de la cola
	*/
	T frente();
	/*
	@brief inserta un elemento en la cola
	*/
	void poner();
	/*.
	@brief elimina un elemento de la cola
	*/
	void quitar();
	/*
	@brief devuelve un booleano que indica si la cola está vacía
	@return true si esta vacía y false en caso contrario
	*/
	bool vacia();

};
