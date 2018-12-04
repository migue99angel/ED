/*
@file Termino.h
@brief fichero cabecera del TDA termino
*/

#ifndef termino_h
#define termino_h
#include <utility>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 * @class Termino
 * @brief Representacion del TDA Termino
*/
class Termino{
private:
	pair<string, vector<string>> definiciones; 
        
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
 	Termino(string palabra, vector<string> v);
	/*
	@brief constructor copia
	@param termino a copiar
	*/
	Termino(const Termino& termino);
	/*
	@brief consultor de palabra
	@return palabra
	*/
	inline string getPalabra() const {return this->definiciones.first;}
	/*
	@brief consultor de definiciones
	@return definiciones
	*/
	inline vector<string> getDefiniciones() const {return this->definiciones.second;}
	/*
	@brief consultor de definiciones
	@return numero de definiciones
	*/
	inline int getNumDefiniciones() const {return definiciones.second.size();}
	/*
	@brief operador de modificacion de palabra
	@param palabra
	*/
	void setPalabra (string palabra);
	/*
	@brief asigna definiciones
	@param definiciones
	*/
	void setDefiniciones (vector<string> definiciones);
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
	/*
	*@brief iterador que permitirá la modificación del vector de definiciones
	*/
	typedef vector<string>::iterator iterator;
	/*
	*@brief iterador constante que no permitirá modificar el vector
	*/
	typedef vector<string>::const_iterator const_iterator;
	/*
	* @brief Devuelve el valor del iterador correspondiente al principio del vector, puede modificar el vector
	* @return Valor del iterador al comienzo del vector 
	*/
	inline Termino::iterator begin(){return this->definiciones.second.begin();}
	/*
	* @brief Devuelve el valor del iterador correspondiente al final del vector, puede modificar el vector
	* @return Valor del iterador al final del vector 
	*/
	inline Termino::iterator end() {return this->definiciones.second.end();}
	/*
	* @brief Devuelve el valor del iterador correspondiente al principio del vector
	* @return Valor del iterador al comienzo del vector 
	*/
	inline Termino::const_iterator begin() const{return this->definiciones.second.cbegin();};
	/*
	* @brief Devuelve el valor del iterador correspondiente al final del vector
	* @return Valor del iterador al final del vector 
	*/
	inline Termino::const_iterator end() const{return this->definiciones.second.cend();};
	/*
	* @brief Sobrecarga del operador de salida
	*/
	friend ostream& operator << (ostream& os, const Termino &t);
};

#endif