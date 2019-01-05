#include <iostream>
#include "letra.h"

using namespace std;

letra::letra(){
    this->caracter='-';
    this->puntuacion=-1;
    this->repeticiones=-1;
}

letra::letra(char caracter, int puntuacion, int repeticiones){
    this->caracter=caracter;
    this->puntuacion=puntuacion;
    this->repeticiones=repeticiones;
}

void letra::setCaracter (char caracter){
    this->caracter=caracter;
}
bool letra::operator<(letra l){
    return this->caracter < l.caracter;
}
void letra::setPuntuacion(int puntuacion){
    this->puntuacion=puntuacion;
}

void letra::setRepeticiones(int repeticiones){
    this->repeticiones=repeticiones;
}

ostream& operator << (ostream &os, const letra &L){
    os<<L.getCaracter()<<"      "<<L.getRepeticiones()<<"      "<<L.getPuntuacion()<<endl;
    return os;
}

istream& operator >> (istream &is, letra &L){
    char carac_aux;
    int punt_aux, rep_aux;
    if(!is.eof()){
        is>>carac_aux>>rep_aux>>punt_aux;
        L.setCaracter(carac_aux);
        L.setPuntuacion(punt_aux);
        L.setRepeticiones(rep_aux);
    }
    return is;
}