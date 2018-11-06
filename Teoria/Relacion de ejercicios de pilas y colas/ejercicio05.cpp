/*
5. Usando una pila y una cola, implementa una función que compruebe si un string es un palı́ndromo.
*/

//g++ -o ejercicio5 ejercicio5.cpp

//Si pongo como prueba una frase que sea un palindromo como lo es "a cavar a caravaca"
//no devuelve true
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool palindromo(string cad){
	stack<char> pila;
	queue<char> cola;
	bool palindromo=true;

	for(int i=0;i<cad.size();i++){
		pila.push(cad[i]);
		cola.push(cad[i]);
	}
	while(!pila.empty()){
		if(pila.top()!= cola.front())
			palindromo=false;
		pila.pop();
		cola.pop();
	}

	return palindromo;
}

int main(){

string prueba1="oro";
string prueba2="palindromo";
string prueba3="dad";

if(palindromo(prueba1))
	cout<<"La cadena de la prueba1 es un palindromo"<<endl;
else
	cout<<"La cadena de la prueba1 NO es un palindromo"<<endl;
if(palindromo(prueba2))
	cout<<"La cadena de la prueba2 es un palindromo"<<endl;
else
	cout<<"La cadena de la prueba2 NO es un palindromo"<<endl;
if(palindromo(prueba3))
	cout<<"La cadena de la prueba3 es un palindromo"<<endl;
else
	cout<<"La cadena de la prueba3 NO es un palindromo"<<endl;


}