/*
12. Implementa una cola con prioridad que contenga strings y de la que salgan primero las
cadenas de caracteres más largas y que en caso de igualdad salgan por orden alfabético.
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
//g++ -o ejercicio12 ejercicio12.cpp


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct comparacion{
 	bool operator()(string p1 , string p2) {
 			if(p1.size() == p2.size()){
 				if(p1>p2)
 					return true;
 				else
 					return false;
 			}
 			else
 				return p1.size()<p2.size();
 		}
 };
 int main(){

	priority_queue<string,vector<string>,comparacion> cola_con_prioridad;
	cola_con_prioridad.push({"holamundo"});
	cola_con_prioridad.push({"Estructuradedatos"});
	cola_con_prioridad.push({"SistemasConcurrentesyDistribuidos"});
	cola_con_prioridad.push({"ProgramacionydiseñoOrientadoaObjetos"});
	cola_con_prioridad.push({"Ruby"});
	cola_con_prioridad.push({"Java"});

	while(!cola_con_prioridad.empty()){
		cout<<cola_con_prioridad.top()<<endl;
		cola_con_prioridad.pop();
	}
}

