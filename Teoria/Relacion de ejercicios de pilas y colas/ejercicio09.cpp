/*
9. Dada una matriz que representa un laberinto, construye una función que determine si se puede llegar
desde la entrada hasta la salida. Esta matriz tendrá una ’E’ en la entrada, una ’S’ en la salida, un ’0’
en las casillas por las que se pueda pasar y un ’1’ en las que no. No se puede ir en diagonal.
*/
/*
	@author Miguel Ángel Posadas Arráez
*/
/*
Para la resolucion del problema he asumido que la salida siempre estará en la
posicion 0,0 de la matriz y la salida siempre estará al final de la diagonal principal de la matriz
es decir en el último elemento de la última fila y de la última columna.
*/

//g++ -o ejercicio9 ejercicio09.cpp
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

const int n_filas=5;
const int n_cols=5;
//Puesto que en el ejercicio anterior he aprendido a usar pair, he visto una buena ocasión para usarlo utilizando una pila de pairs
bool salida_laberinto(char laberinto[n_filas][n_cols], int n_filas, int n_cols){
	bool salida=true;
	stack<pair<int, int> > solucion;
//Aquí inserto las posiciones de la matriz cuyo elemento es 0	
	for(int i=0;i<n_filas;i++){
		for(int j=0;j<n_cols;j++){
			if(laberinto[i][j]=='0'){
				solucion.push(make_pair(i,j));
			}
		}
	}
//Hago el bucle while hasta que la pila tenga tamaño uno para comprobar que todos los ceros están conectados y para comprobar el último punto posteriormente	
	while(salida && solucion.size()>1){
		if(laberinto[solucion.top().first][solucion.top().second+1]!='0'&& laberinto[solucion.top().first][solucion.top().second-1]!='0'&& 
			laberinto[solucion.top().first-1][solucion.top().second]!='0'){
			salida=false;
		}
		solucion.pop();
	}
//Como hemos considerado que la entrada debe estar en la posicion 0,0(y que no se puede desplazar en diagonal) las únicas soluciones 
//posibles al laberinto son aquellas en las que los ceros están conectados y cuyo último cero se encuentra en la posición 0,1 o 1,0	
	if(solucion.size()==1 && solucion.top() != make_pair(0,1) && solucion.top() != make_pair(1,0))
		salida=false;

	return salida;
}


int main(){



	char laberinto1[n_filas][n_cols] = 	{	{'E','0','1','0','0'},
											{'1','1','0','1','0'},
											{'1','1','1','1','0'},
											{'1','0','0','1','0'},
											{'1','1','1','1','S'}};

	char laberinto2[n_filas][n_cols] = 	{	{'E','0','0','0','0'},
											{'0','1','0','1','0'},
											{'0','1','1','1','0'},
											{'0','0','0','1','0'},
											{'0','0','0','0','S'}};										


	if(salida_laberinto(laberinto1,n_filas,n_cols))
		cout<<"El laberinto tiene salida"<<endl;
	else
		cout<<"El laberinto NO tiene salida"<<endl;

	if(salida_laberinto(laberinto2,n_filas,n_cols))
		cout<<"El laberinto2 tiene salida"<<endl;
	else
		cout<<"El laberinto2 NO tiene salida"<<endl;


	}