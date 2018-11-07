/*
8. Se llama expresión en postfijo a una expresión matemática en la que cada operación aparece con sus
dos operandos seguidos por el operador. Hay un espacio entre cada dos elementos. Por ejemplo: 2 3
+ 5 * Escribe un programa que evalue una expresión en postfijo.
		a b ˆ c * d / e + donde a = 5, b = 3, c = d = 2, e = 9
		a b c d e + * +
		donde a = 12, b = 4, c = 7, d = 5, e = 2
		a b + c d * + e * donde a = 2, b = 6, c = 3, d = 5, e = 9
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
//g++ -o ejercicio8 ejercicio08.cpp
//No uso un vector de punteros a variables porque si no no compila
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


template <typename T>
T sustituir(char variable, pair<char, T> variables[], int num_variables){
	for(int i=0;i<num_variables;i++){
		if(variables[i].first==variable)
			return variables[i].second;
	}
}


template <typename T>
T evaluar(string expresion, pair<char, T> variables[], int num_variables){
	stack<T> pila;
	for(int i=0;i<expresion.size();i++){
		if(expresion[i]=='+' ||expresion[i]=='-'||expresion[i]=='*'||expresion[i]=='/'||expresion[i]=='^' ){
			if(expresion[i]=='+'){
				T x=pila.top();
				pila.pop();
				T y=pila.top();
				pila.pop();
				pila.push(x+y);
			}

			if(expresion[i]=='-'){
				T y=pila.top();
				pila.pop();
				T x=pila.top();
				pila.pop();
				pila.push(y-x);
			}

			if(expresion[i]=='*'){
				T y=pila.top();
				pila.pop();
				T x=pila.top();
				pila.pop();
				pila.push(x*y);	
			}

			if(expresion[i]=='/'){
				T y=pila.top();
				pila.pop();
				T x=pila.top();
				pila.pop();
				pila.push(x/y);	
			}
			if(expresion[i]=='^'){
				T y=pila.top();
				pila.pop();
				T x=pila.top();
				pila.pop();
				pila.push(pow(x,y));	
			}	

		}

		else 
			if(expresion[i]!=' ')
			pila.push(sustituir(expresion[i],variables,num_variables));
	}
	return pila.top();		
}


int main(){
	int num_variables=5,num_variables2=5,num_variables3=5;
	pair<char, int> variables[num_variables],variables2[num_variables2], variables3[num_variables3];
	string expresion="a b ^ c * d / e +";
	string expresion2="a b c d e + * + -";
	string expresion3="a b + c d * + e * ";
//Asigno las variables de la primera expresion

	variables[0].first='a';
	variables[0].second=5;

	variables[1].first='b';
	variables[1].second=3;
	
	variables[2].first='c';
	variables[2].second=2;

	variables[3].first='d';
	variables[3].second=2;

	variables[4].first='e';
	variables[4].second=9;
//Asigno las variables de la segunda expresion


	variables2[0].first='a';
	variables2[0].second=12;

	variables2[1].first='b';
	variables2[1].second=4;
	
	variables2[2].first='c';
	variables2[2].second=7;

	variables2[3].first='d';
	variables2[3].second=5;

	variables2[4].first='e';
	variables2[4].second=2;
//Asigno las variables de la tercera expresion
	
	

	variables3[0].first='a';
	variables3[0].second=2;

	variables3[1].first='b';
	variables3[1].second=6;
	
	variables3[2].first='c';
	variables3[2].second=3;

	variables3[3].first='d';
	variables3[3].second=5;

	variables3[4].first='e';
	variables3[4].second=9;

	cout<<"El resultado de la primera expresion es: "<<evaluar(expresion,variables,num_variables)<<endl;
	cout<<"El resultado de la segunda expresion es: "<<evaluar(expresion2,variables2,num_variables2)<<endl;
	cout<<"El resultado de la tercera expresion es: "<<evaluar(expresion3,variables3,num_variables3)<<endl;

}