/*
3. Construye una función a la que se le pase el nombre de un fichero que contiene un texto y devuelva
un map que contenga las palabras que aparecen y el número de veces que aparece cada una.
map<string,int> contar(string nom_fich)

COMANDO PARA COMPILAR: g++ -o ejercicio3 ejercicio03.cpp

Observaciones:La última palabra del fichero siempre la cuenta una vez de más,en la línea 38 he puesto 
una solución que se me ha ocurrido para ello, aunque no es lo mas elegante.

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

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

int main(int argc, char * argv[]){
    typedef map<string, int> StringIntMap;
    StringIntMap cuenta_fichero;
    if (argc!=2){
        cout<<"Para la ejecucion del programa se debe pasar el nombre de un fichero al ejecutarlo."<<endl;
        return 0;
    }

   cuenta_fichero=contar(argv[1]);
   for(StringIntMap::const_iterator i=cuenta_fichero.begin();i!=cuenta_fichero.end();i++){
       cout<<i->first<<",   "<<i->second<<endl;
   }

   

}