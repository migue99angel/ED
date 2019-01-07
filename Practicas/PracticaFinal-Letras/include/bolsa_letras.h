#ifndef __bolsa_letras_h__
#define __bolsa_letras_h__
#include <iostream>
#include "letra.h"
#include <vector>
using namespace std;


/**
 * @class BolsaLetras
 * @brief T.D.A BolsaLetras
 * 
 * @brief Práctica final para la asignatura de Estructura de Datos
 * @author Miguel Ángel Posadas Arráez
 * @date Diciembre 2018 - Enero 2019
 * 
 * Una instancia de este tipo de dato abstracto utiliza una
 * instancia de Conjunto_letras para generar un vector con n caracteres
 * aleatorios teniendo en cuenta las repeticiones de cada letra.
 * 
 * Un ejemplo de utilización de esta clase lo podemos ver en:
 * @include testconjunto_letras.cpp
 * 
 * 
 * 
 */
class BolsaLetras{
    private:
        vector<char> bolsa;
    public:
        /**
        @brief Constructor por defecto
        **/
        BolsaLetras();
        /**
        @brief Inserta un objeto de tipo letra en la bolsa
        @param Letra a insertar
        **/
        void insertar(const letra &l);
        /**
        @brief Devuelve una letra
        @return la letra
        **/
        char getLetra();
        /**
        @brief Muestra por pantalla una cantidad de letras determinada 
        @param Cantidad de letras a mostrar
        **/
        void mostrarLetras();
        /**
        @brief Comprueba si la palabra pasada por parámetro es válida
        @param La solucion a comprobar
        @return booleano que indica si es válida o no 
        **/
        bool solucionValida(string sol)const;
        /**
        @brief Comprueba si la letra pasada por parametro esta en la bolsa, en ese caso la elimina para que no se use de nuevo
        @param Letra a comprobar
        @return true si es valida o false en caso contrario
        **/
        bool letraElegida(char letra);
        /**
        @brief Devuelve el tamaño del vector
        @return tamaño
        **/
        inline int size() {return bolsa.size();};
        /**
        @brief Iterador para recorrer la Bolsaletras, puede modificarla
        **/
        typedef vector<char>::iterator iterator;
        /**
        @brief Iterador para recorrer la Bolsaletras
        **/
        typedef vector<char>::const_iterator const_iterator;
        /**
        * @brief Devuelve el valor del iterador correspondiente al principio del vector, puede modificar el vector
        * @return Valor del iterador al comienzo del vector 
        **/
        inline BolsaLetras::iterator begin(){return bolsa.begin();}
        /**
        * @brief Devuelve el valor del iterador correspondiente al final del vector, puede modificar el vector
        * @return Valor del iterador al final del vector 
        **/
        inline BolsaLetras::iterator end() {return this->bolsa.end();}
        /**
        * @brief Devuelve el valor del iterador correspondiente al principio del vector
        * @return Valor del iterador al comienzo del vector 
        **/
        inline BolsaLetras::const_iterator begin() const{return this->bolsa.cbegin();};
        /**
        * @brief Devuelve el valor del iterador correspondiente al final del vector
        * @return Valor del iterador al final del vector 
        **/
        inline BolsaLetras::const_iterator end() const{return this->bolsa.cend();};    
};


#endif