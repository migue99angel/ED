/*
4. Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la posición pos.
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/
// g++ -o ejercicio4 ejercicio4.cpp

/*Puesto que se pide una funcion igual al ejercicio anterior he copiado y pegado la función
y la he adaptado a las colas*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void insertar(queue<T> &P, int pos, const T &x){
	queue<T> aux;
	if(pos>=0 && pos<P.size()){	
	while(!P.empty()){
		if(pos!=P.size()){
			aux.push(P.front());
			P.pop();
		}
		else{
			aux.push(P.front());
			aux.push(x);
			P.pop();
		}
		
	}

	while(!aux.empty()){
		P.push(aux.front());
		aux.pop();
		}		
	}
}

int main(){
	queue<int> cola;
	cola.push(1);
	cola.push(2);
	cola.push(3);
	cola.push(4);
	cola.push(5);
	cola.push(7);
	cola.push(8);

	insertar(cola,3,6);

	while(!cola.empty()){
		cout<<cola.front()<<endl;
		cola.pop();
	}

}