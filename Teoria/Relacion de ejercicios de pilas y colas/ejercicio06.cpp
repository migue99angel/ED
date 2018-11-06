/*
6. Implementa un TDA cola usando como representación dos pilas.
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
//g++ -o ejercicio6 ejercicio06.cpp


#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class cola{

private:
	stack<T> pila1, pila2;

public:
	cola(){
		pila1=stack<T>();
		pila2=stack<T>();
	}
	cola(stack<T> primera,stack<T> segunda){
		pila1=primera;
		pila2=segunda;
	}
	cola(const cola<T> &cola){
		this->operator=(cola);
	}
	void push(T elemento){
		while(!pila1.empty()){
			pila2.push(pila1.top());
			pila1.pop();
		}
		pila2.push(elemento);

		while(!pila2.empty()){
			pila1.push(pila2.top());
			pila2.pop();
		}
	}
	void pop(){
		while(!pila1.empty()){
			pila2.push(pila1.top());
			pila1.pop();
		}
		pila2.pop();
		while(!pila2.empty()){
			pila1.push(pila2.top());
			pila2.pop();
		}
	}
	T& front(){
		return pila1.top();
	}
	T& back(){
		while(!pila1.empty()){
			pila2.push(pila1.top());
			pila1.pop();
		}

		T& devolver=pila2.top();

		while(!pila2.empty()){
			pila1.push(pila2.top());
			pila2.pop();
		}
		return devolver;
	}
	bool empty(){
		return pila1.empty();
	}
	int size(){
		return pila1.size();
	}

	bool operator ==( cola<T> comparar){
		bool iguales=true;
		if(pila1.size()==comparar.size()){
			//Comparamos la primera pila de cada objeto cola que estemos comparando
			while(!comparar.empty()){
				comparar.pila2.push(comparar.pila1.top());
				this->pila2.push(this->pila1.top());
				if(this->pila1.top()!=comparar.pila1.top())
					iguales=false;
				comparar.pila1.pop();
				this->pila1.pop();
			}
			//Dejamos las pilas en su estado inicial
			while(!comparar.pila2.empty()){
				comparar.pila1.push(comparar.pila2.top());
				comparar.pila2.pop();
				this->pila1.push(this->pila2.top());
				this->pila2.pop();
			}
		}
		else
			iguales=false;
		return iguales;
	}

	cola& operator =(const cola<T> &original){
		if(this != &original){
		this->pila1 = original.pila1;
		this->pila2 = original.pila2;
		}
		return *this;
	}
};


int main(){
	cola<int> cola, cola2;

	cola.push(0);
	cola.push(1);
	cola.push(2);


	while(!cola.empty()){
		cout<<"El elemento en la posicion: "<<cola.size()<<" es "<<cola.back()<<endl;
		cola.pop();

	}

	cola.push(0);
	cola.push(1);
	cola.push(2);

	cola2.push(1);
	cola2.push(1);
	cola2.push(2);

	cout<<"El primer elemento en entrar en la primera cola es: "<<cola.front()<<endl;
	cout<<"El ultimo elemento en entrar en la cola es: "<<cola.back()<<endl;

	if(cola==cola2)
		cout<<"Las dos colas son iguales"<<endl;
	else
		cout<<"Las colas NO son iguales"<<endl;



}