/*
2. Implementa un función para determinar si una expresión contenida en un string tiene una configura-
ción de paréntesis correcta. Debe tener un orden lineal.
*/
/*g++ -o ejercicio2 ejercicio2.cpp*/

//Si ponemos como prueba ()prueba)( la función la reconoce como correcta y no es asi
//Lo he intentado arreglar volviendo a poner abre y cierra a false pero entonces me lo 
//reconoce todo como incorrecto


#include <iostream>
#include <stack>
using namespace std;


bool parentesis_correctos(string expresion){
	stack<char> parentesis;
	bool correctos=false ,abre=false, cierra=false;
	int abiertos=0, cerrados=0;
	for(int i=0;i<expresion.size();i++){
		if(expresion[i]=='('){
			parentesis.push(expresion[i]);
			abre=true;
		}
		else{
			if(expresion[i]==')'){
				parentesis.push(expresion[i]);
				cierra=true;
			}
		}
		if(cierra && !abre)
			return false;
	}

	while(!parentesis.empty()){
		if(parentesis.top()!=')')
			cerrados++;
		parentesis.pop();
		if(parentesis.top()!='(')
			abiertos++;
		parentesis.pop();
	}
	if(abiertos==cerrados)
		correctos=true;
	return correctos;

}

int main(){
string prueba="(Esto es una prueba del ejercicio 2)";
string prueba2 = ")(Esto no es correcto()";
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