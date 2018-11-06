/*
10. Un tipo ventana es un tipo de dato que permite insertar un elemento, mover derecha, mover
izquierda, borrar elemento y que se implementa usando dos pilas. Implementa ese tipo de
dato con las operaciones comentadas.
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
//g++ -o ejercicio10 ejercicio10.cpp

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class ventana{


public:
	stack<T> pila_izq, pila_der;
	ventana(stack<T> pila_izq,stack<T> pila_der){
		this->pila_izq=pila_izq;
		this->pila_der=pila_der;
	}
//Como no se especifica si hay que insertarlo en una posicion determinada o al final yo lo insetare al final	
	void insertar(T elemento){
		
		while(!pila_der.empty()){
			mover_izquierda();
		}
		pila_der.push(elemento);
		mover_izquierda();
		
	}
	void mover_izquierda(){
		stack<T> aux;
		while(!pila_izq.empty()){
			aux.push(pila_izq.top());
			pila_izq.pop();
		}
		aux.push(pila_der.top());
		pila_der.pop();

		while(!aux.empty()){
			pila_izq.push(aux.top());
			aux.pop();
		}
	}

	void mover_derecha(){
		stack<T> aux;
		while(!pila_izq.empty()){
			aux.push(pila_izq.top());
			pila_izq.pop();
		}
		pila_der.push(aux.top());
		aux.pop();

		while(!aux.empty()){
			pila_izq.push(aux.top());
			aux.pop();
		}
	}
	//Como no se especifica que hay que eliminar yo interpreto que hay que eliminar el ultimo elemento
	void eliminar_elemento(){
		while(!pila_izq.empty()){
			pila_der.push(pila_izq.top());
			pila_izq.pop();
		}
		pila_der.pop();
		while(!pila_der.empty()){
			pila_izq.push(pila_der.top());
			pila_der.pop();
		}
	}
};

int main(){

	stack<char> izq, der;
	izq.push('o');
	izq.push('h');
	der.push('a');
	der.push('l');
	ventana<char> v(izq,der);
	ventana<char> v2(izq,der);
	ventana<char> v3(izq,der);
	ventana<char> v4(izq,der);
	ventana<char> v5(izq,der);
	while(!v.pila_izq.empty()){
		cout<<v.pila_izq.top();
		v.pila_izq.pop();
	}
	cout<<"  ";
	while(!v.pila_der.empty()){
		cout<<v.pila_der.top();
		v.pila_der.pop();
	}
	cout<<endl;

	cout<<"Movemos a la izquierda"<<endl;
	v2.mover_izquierda();
	while(!v2.pila_izq.empty()){
		cout<<v2.pila_izq.top();
		v2.pila_izq.pop();
	}
	cout<<"  ";
	while(!v2.pila_der.empty()){
		cout<<v2.pila_der.top();
		v2.pila_der.pop();
	}
	cout<<endl;

	cout<<"Movemos a la derecha"<<endl;
	v3.mover_derecha();
	while(!v3.pila_izq.empty()){
		cout<<v3.pila_izq.top();
		v3.pila_izq.pop();
	}
	cout<<"  ";
	while(!v3.pila_der.empty()){
		cout<<v3.pila_der.top();
		v3.pila_der.pop();
	}
	cout<<endl;
	cout<<"Insertamos la palabra mundo"<<endl;
	v4.insertar('m');
	v4.insertar('u');
	v4.insertar('n');
	v4.insertar('n');
	v4.insertar('d');
	v4.insertar('o');

	v4.mover_derecha();
	v4.mover_derecha();
	v4.mover_derecha();
	v4.mover_derecha();
	v4.mover_derecha();
	v4.mover_derecha();
	
	while(!v4.pila_izq.empty()){
		cout<<v4.pila_izq.top();
		v4.pila_izq.pop();
	}
	cout<<"  ";
	while(!v4.pila_der.empty()){
		cout<<v4.pila_der.top();
		v4.pila_der.pop();
	}
	cout<<endl;
	cout<<"Eliminamos la palabra mundo"<<endl;
	v5.insertar('m');
	v5.insertar('u');
	v5.insertar('n');
	v5.insertar('n');
	v5.insertar('d');
	v5.insertar('o');

	v5.eliminar_elemento();
	v5.eliminar_elemento();
	v5.eliminar_elemento();
	v5.eliminar_elemento();
	v5.eliminar_elemento();
	v5.eliminar_elemento();
	while(!v5.pila_izq.empty()){
		cout<<v5.pila_izq.top();
		v5.pila_izq.pop();
	}
	cout<<"  ";
	while(!v5.pila_der.empty()){
		cout<<v5.pila_der.top();
		v5.pila_der.pop();
	}
	cout<<endl;
}