#ifndef Cola_max_vd_h
#define Cola_max_vd_h

/*
@file Cola_max_pila.h
@author Miguel Ángel Posadas Arráez
*/
#include<iostream>
#include<vector>


using namespace std;
template <class T>
class Cola{
private:
	/*
	* TDA Cola_max_vd
	*/
	vector<T> elementos;
	vector<T> mayor;
        int pos;
	/*
	@brief Devuelve el vector de elementos
	@return el elemento
	*/
	inline vector<T> getElementos() const {return this->elementos;} 
	/*
	@brief Devuelve el vector de mayor
	@return mayor
	*/
	inline vector<T> getMayores()const {return this->mayor;}


public:
	/*
	@brief Cosntructor sin parámetros
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
	T  maximo()const;
	/*
	@brief devuelve el numero de elementos
	@return numero elementos
	*/
	inline int num_elementos()const {return elementos.size();}
	/*
	@brief devuelve el elemento al frente de la cola
	@return elemento al frente de la cola
	*/
	T frente()const;
	/*
	@brief inserta un elemento en la cola
	*/
	void poner(T elemento);
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
#include "Cola_max_vd.cpp"
#endif
