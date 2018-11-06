/*11. Implementa una cola con prioridad de un tipo struct con (apellidos, nombre, prioridad) de
forma que los datos salgan de acuerdo a ese tercer campo prioridad.*/
/*
	@author Miguel Ángel Posadas Arráez
*/
//g++ -o ejercicio11 ejercicio11.cpp

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Persona{
	string apellidos;
	string nombre;
	int prioridad;
};

struct comparacion{
 	bool operator()(Persona p1 , Persona p2) {
 			if(p1.prioridad < p2.prioridad)
 				return true;
 			else
 				return false;
 		}
 };


 int main(){

	priority_queue<Persona,vector<Persona>,comparacion> cola_con_prioridad;
	cola_con_prioridad.push({"Rodriguez Jimenez","María del Pilar",1});
	cola_con_prioridad.push({"Morales Martín","Carmen",3});
	cola_con_prioridad.push({"Gonzalez Tabernero","Ángeles",2});
	cola_con_prioridad.push({"Posadas Arráez", "Miguel Ángel",0});
	cola_con_prioridad.push({"Jackson Smith","Samuel",5});
	cola_con_prioridad.push({"Specter Zane","Eusebio",7});

	while(!cola_con_prioridad.empty()){
		cout<<cola_con_prioridad.top().apellidos<<", "<<cola_con_prioridad.top().nombre<<"  Prioridad: "<<cola_con_prioridad.top().prioridad<<endl;
		cola_con_prioridad.pop();
	}







 }