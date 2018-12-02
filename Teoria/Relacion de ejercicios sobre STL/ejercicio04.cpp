/*
4. Construye una función que dado el map del ejercicio anterior devuelva un multimap que nos permita
consultar las palabras que aparecen un número determinado de veces.
vector<string> veces(const map<string,int> &palabras, int num)

COMANDO PARA COMPILAR: g++ -o ejercicio4 ejercicio04.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
vector<string> veces(const map<string,int> &palabras, int num){
    typedef map<string, int> StringIntMap;
    vector<string> devolver;
    for(StringIntMap::const_iterator pos=palabras.begin();pos!=palabras.end();pos++){
        if(pos->second==num)
            devolver.push_back(pos->first);
    }
    return devolver;
}

//Esta es la funcion del ejercicio 4 que la he puesto de nuevo para cargar el map de un fichero
map<string,int> contar(string nom_fich){
    typedef map<string, int> StringIntMap;
    StringIntMap devolver;
    string aux;
    ifstream f (nom_fich);
    if (!f){
        cout<<"No puedo abrir el fichero "<<nom_fich<<endl;
        return devolver;
   }
   else{
       cout<<"Cargando los datos del fichero"<<endl;
       do{
           f>>aux;
            devolver[aux]+=1;
       }while(!f.eof());
   }
       devolver[aux]--;
       f.close();
       return devolver;

}
int main(int argc, char const *argv[])
{
    typedef map<string, int> StringIntMap;
    StringIntMap cuenta_fichero;
    vector<string> n_veces;
    string aux;
    int n=2;

    if (argc!=2){
        cout<<"Para la ejecucion del programa se debe pasar el nombre de un fichero al ejecutarlo."<<endl;
        return 0;
    }

   cuenta_fichero=contar(argv[1]);
   n_veces=veces(cuenta_fichero,n);
   cout<<"Las palabras que aparecen "<<n<<" veces son: "<<endl;

   for(int i=0;i<n_veces.size();i++){
       cout<<n_veces[i]<<endl;
   }
}

