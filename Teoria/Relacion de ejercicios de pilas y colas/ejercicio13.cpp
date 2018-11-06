/*
13. Implementa una cola con prioridad que contenga strings y de la que salgan primero las
cadenas de caracteres que tengan más vocales y que en caso de igualdad salgan por orden
alfabético.
*/
/*
	@pre las letras deben ser minusculas
	@author Miguel Ángel Posadas Arráez
*/
/*
En la función cuentavocales compara los string con el codigo ASCII por tanto todas las letras deben estar
en minúsculas porque si no puede ocurrir que una letra que este antes que otra en el abecedario
salga mayor que otra si esta primera esta en mayuscula.
Ejemplo:
Con los ejemplos puestos la salida es :
	abecedario
	abuelito
	escualido
	Java
	a
	ruby
Si cambiamos escualido por Escualido la salida es: 
	abecedario
	Escualido
	abuelito
	Java
	a
	ruby
Además para que se contabilicen las vocales con tilde bastaría con añadirlas al string vocales	
*/
//g++ -o ejercicio13 ejercicio13.cpp


#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct comparacion{
	string vocales={"aeiouAEIOU"};
 	bool operator()(string p1 , string p2) {
 		int vocales1=cuentavocales(p1);
 		int vocales2=cuentavocales(p2);

 			if(vocales1 == vocales2){
 				if(p1>p2)
 					return true;
 				else
 					return false;
 			}
 			else
 				return vocales1<vocales2;
 		}

 	int cuentavocales(string p1){ 		
 		int contador=0;
 		for(int i=0;i<p1.size();i++){
 			for(int j=0;j<vocales.size();j++){
 				if(p1[i]==vocales[j])
 					contador++;
 			}
 		}
 		return contador;
 	}	
 };

 int main(){

	priority_queue<string,vector<string>,comparacion> cola_con_prioridad;
	cola_con_prioridad.push({"a"});
	cola_con_prioridad.push({"abecedario"});
	cola_con_prioridad.push({"abuelito"});
	cola_con_prioridad.push({"Escualido"});
	cola_con_prioridad.push({"ruby"});
	cola_con_prioridad.push({"Java"});

	while(!cola_con_prioridad.empty()){
		cout<<cola_con_prioridad.top()<<endl;
		cola_con_prioridad.pop();
	}
}

