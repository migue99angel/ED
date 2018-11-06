/*
7. Implementa el TDA cola usando dos pilas. ¿Qué orden de eficiencia tienen las operaciones push y
pop?
*/
//g++ -o ejercicio7 ejercicio07.cpp


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class pila{

private:
	queue<T> cola1, cola2;

public:
	pila(){
		cola1=queue<T>();
		cola2=queue<T>();
	}
	pila(queue<T> primera,queue<T> segunda){
		cola1=primera;
		cola2=segunda;
	}
	pila(const pila<T> &pila){
		this->operator=(pila);
	}
	void push(T elemento){
		while(!cola1.empty()){
			cola2.push(cola1.front());
			cola1.pop();
		}
		cola2.push(elemento);

		while(!cola2.empty()){
			cola1.push(cola2.front());
			cola2.pop();
		}
	}
	void pop(){
		while(!cola1.empty()){
			cola2.push(cola1.front());
			cola1.pop();
		}
		cola2.pop();
		while(!cola2.empty()){
			cola1.push(cola2.front());
			cola2.pop();
		}
	}
	T& top(){
		while(!cola1.empty()){
			cola2.push(cola1.front());
			cola1.pop();
		}

		T& devolver=cola2.front();

		while(!cola2.empty()){
			cola1.push(cola2.front());
			cola2.pop();
		}
		return devolver;
	}
	bool empty(){
		return cola1.empty();
	}
	int size(){
		return cola1.size();
	}

	bool operator ==( pila<T> comparar){
		bool iguales=true;
		if(cola1.size()==comparar.size()){
			//Comparamos la primera cola de cada objeto cola que estemos comparando
			while(!comparar.empty()){
				comparar.cola2.push(comparar.cola1.front());
				this->cola2.push(this->cola1.front());
				if(this->cola1.front()!=comparar.cola1.front())
					iguales=false;
				comparar.cola1.pop();
				this->cola1.pop();
			}
			//Dejamos las colas en su estado inicial
			while(!comparar.cola2.empty()){
				comparar.cola1.push(comparar.cola2.front());
				comparar.cola2.pop();
				this->cola1.push(this->cola2.front());
				this->cola2.pop();
			}
		}
		else
			iguales=false;
		return iguales;
	}

	pila& operator =(const pila<T> &original){
		if(this != &original){
		this->cola1 = original.cola1;
		this->cola2 = original.cola2;
		}
		return *this;
	}
};


int main(){
	pila<int> pila, pila2;

	pila.push(0);
	pila.push(1);
	pila.push(2);


	while(!pila.empty()){
		cout<<"El elemento en la posicion: "<<pila.size()<<" es "<<pila.top()<<endl;
		pila.pop();

	}

	pila.push(0);
	pila.push(1);
	pila.push(2);

	pila2.push(0);
	pila2.push(1);
	pila2.push(2);

	cout<<"El ultimo elemento en entrar en la primera pila es: "<<pila.top()<<endl;

	if(pila==pila2)
		cout<<"Las dos pilas son iguales"<<endl;
	else
		cout<<"Las pilas NO son iguales"<<endl;



}