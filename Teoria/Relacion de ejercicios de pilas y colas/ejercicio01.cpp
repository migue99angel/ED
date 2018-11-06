/*1. Construye una función a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo T y que
modifique la pila de forma que todas las veces que aparezca x se substituya por y (quedando la pila en
el mismo estado en el que estaba anteriormente). Para este ejercicio no se podrán utilizar iteradores.*/
/*
	@author Miguel Ángel Posadas Arráez
*/

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void substituye(stack<T> &P, const T &x, const T &y){
	stack<T> aux;
	do{
		if(P.top()==x)
			aux.push(y);
		else
			aux.push(P.top());
		P.pop();
	}while(!P.empty());

	do{
		P.push(aux.top());
		aux.pop();
	}while(!aux.empty());
}

int main(){
	stack<int> pila;
	int x=1, y=4;

	pila.push(1);
	pila.push(2);
	pila.push(1);
	pila.push(5);
	pila.push(3);
	substituye(pila, x,y);

	for(int i=0;i<5;i++){
		cout<<pila.top()<<endl;
		pila.pop();
	}
}
