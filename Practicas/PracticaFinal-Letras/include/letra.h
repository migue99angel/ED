#ifndef __letra_h__
#define __letra_h__
#include <iostream>
using namespace std;

/**
 * @class letra
 * @brief T.D.A letra
 * 
 * @brief Práctica final para la asignatura de Estructura de Datos
 * @author Miguel Ángel Posadas Arráez
 * @date Diciembre 2018 - Enero 2019
 * 
 * Una instancia de este tipo de dato almacena la información que necesita
 * el programa letras para cada tipo de caracter, el propio caracter, su puntuación y el
 * número de veces que este caracter podrá estar repetido.
 * 
 * 
 * Un ejemplo de utilización de esta clase lo podemos ver en:
 * @include testconjunto_letras.cpp
 * 
 * 
 * 
 */

class letra{
    private:
    char caracter;
    int puntuacion;
    int repeticiones;
    public:
    /**
    *@brief Constructor por defecto
    **/
    letra();
    /**
    *@brief Constructor con parámetros
    **/
    letra(char caracter,int puntuacion,int repeticiones);
    /**
    *@brief Modificador básico del caracter
    **/
    void setCaracter (char caracter); 
    /**
    *@brief Modificador básico de puntuacion
    **/
    void setPuntuacion (int puntuacion); 
    /**
    *@brief Modificador básico de repeticiones
    **/
    void setRepeticiones (int repeticiones); 
    /**
    *@brief Consultor básico del caracter
    *@return caracter
    **/
    inline char getCaracter() const {return this->caracter;}
    /**
    *@brief Consultor básico de la puntucacion
    *@return puntuacion
    **/
    inline int getPuntuacion() const {return this->puntuacion;}
    /**
    *@brief Consultor básico de las repeteciones
    *@return repeticiones
    **/
    inline int getRepeticiones() const {return this->repeticiones;}
    /**
    @brief Sobrecarga del operador <
    @param Letra con la que comparar
    @return true o false
    **/
    bool operator < (letra l);
    /**
    @brief Lee de un flujo de entrada un fichero letras
    @param is flujo de entrada
    @param D el objeto donde se realiza la lectura.
    @return el flujo de entrada
    **/
    friend istream & operator>>(istream & is, letra &L);
    /**
    @brief Escribe en un flujo de salida un letras
    @param os flujo de salida
    @param D el objeto Conjunto_letras que se escribe
    @return el flujo de salida
    **/
    friend ostream & operator<<(ostream & os, const letra &L);

};


#endif