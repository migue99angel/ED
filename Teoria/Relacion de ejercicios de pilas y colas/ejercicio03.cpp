/*3. Implementa una función insertar(P, pos, x) que inserte un elemento en una pila P en la posición pos.
La pila debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)*/

//g++ -o ejercicio3 ejercicio3.cpp 


#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void insertar(stack<T> &P, int pos, const T &x){
	stack<T> aux;
	if(pos>=0 && pos<P.size()){	
	//Copio en la pila auxiliar la pila P, si pos es igual al tamaño de P
	//meto el elemento siguiente e inserto el elemento x	
	while(!P.empty()){
		if(pos!=P.size()){
			aux.push(P.top());
			P.pop();
		}
		else{
			aux.push(P.top());
			aux.push(x);
			P.pop();
		}
		
	}
	//Copio el contenido de la pila auxiliar en P que viene pasada por referencia
	//para devolver el resultado y darle la vuelta ya que se encuentra al reves 
	//tras el paso anterior
	while(!aux.empty()){
		P.push(aux.top());
		aux.pop();
		}		
	}
}

int main(){
	stack<int> prueba;

	prueba.push(10);
	prueba.push(9);
	prueba.push(7);
	prueba.push(6);
	prueba.push(5);
	prueba.push(4);
	prueba.push(3);
	prueba.push(2);
	prueba.push(1);

	insertar(prueba,3,8);
	insertar(prueba,1,11);

	while(!prueba.empty()){
		cout<<prueba.top()<<endl;
		prueba.pop();
	}
}