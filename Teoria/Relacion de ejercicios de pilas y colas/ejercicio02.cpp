/*
2. Implementa un función para determinar si una expresión contenida en un string tiene una configura-
ción de paréntesis correcta. Debe tener un orden lineal.
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
/*g++ -o ejercicio2 ejercicio02.cpp*/

#include <iostream>
#include <stack>
using namespace std;


bool parentesis_correctos(string expresion){
	stack<char> parentesis;
	for(int i=0;i<expresion.size();i++){
		if(expresion[i]=='('){
			parentesis.push(expresion[i]);
		}
		if(expresion[i]==')' && parentesis.empty()){
			return false;	
		}
		if(expresion[i]==')'){
			parentesis.pop();		
		}
	
	}
	return parentesis.empty();	
}

int main(){
string prueba="(Esto es una prueba del ejercicio 2)";
string prueba2 = "()Esto no es correcto)(";
string prueba3="((Esto es correcto))";
bool correctos=parentesis_correctos(prueba);
bool correctos2=parentesis_correctos(prueba2);
bool correctos3=parentesis_correctos(prueba3);
if(correctos)
	cout<<"La prueba 1 es correcta"<<endl;
else
	cout<<"La prueba 1 NO es correcta"<<endl;
if(correctos2)
	cout<<"La prueba 2 es correcta"<<endl;
else
	cout<<"La prueba 2 NO es correcta"<<endl;
if(correctos3)
	cout<<"La prueba 3 es correcta"<<endl;
else
	cout<<"La prueba 3 NO es correcta"<<endl;
}