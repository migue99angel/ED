/*
5. Construye una función a la que se le pasen los parámetros con los que se ha ejecutado un programa
y determine qué opciones se han seleccionado y, en su caso, el valor que se le ha asignado. Por
ejemplo: tar -z -x -f fichero deberı́a indicar que se han activado z,x y también f que tiene un parámetro fichero.
map<string, string> params(string cad)

COMANDO PARA COMPILAR: g++ -o ejercicio5 ejercicio05.cpp

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/


#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;


map<char, string> params(string cad){
    typedef map<char, string> StringStringMap;
    StringStringMap parametros;
    for(int i=0;i<cad.size();i++){
        if(cad[i]=='-'){
            switch(cad[i+1]){
                case 'a': parametros.insert(make_pair('a',"Opcion a"));break;
                case 'b': parametros.insert(make_pair('b',"Opcion b"));break;
                case 'c': parametros.insert(make_pair('c',"Opcion c"));break;
                case 'd': parametros.insert(make_pair('d',"Opcion d"));break;
                case 'e': parametros.insert(make_pair('e',"Opcion e"));break;
                case 'f': parametros.insert(make_pair('f',"Opcion f , que tiene como parametro un fichero"));break;
                case 'g': parametros.insert(make_pair('g',"Opcion g"));break;
                case 'h': parametros.insert(make_pair('h',"Opcion h"));break;
                case 'i': parametros.insert(make_pair('i',"Opcion i"));break;
                case 'j': parametros.insert(make_pair('j',"Opcion j"));break;
                case 'k': parametros.insert(make_pair('k',"Opcion k"));break;
                case 'l': parametros.insert(make_pair('l',"Opcion l"));break;
                case 'm': parametros.insert(make_pair('m',"Opcion m"));break;
                case 'n': parametros.insert(make_pair('n',"Opcion n"));break;
                case 'o': parametros.insert(make_pair('o',"Opcion o"));break;
                case 'p': parametros.insert(make_pair('p',"Opcion p"));break;
                case 'q': parametros.insert(make_pair('r',"Opcion r"));break;
                case 's': parametros.insert(make_pair('s',"Opcion s"));break;
                case 't': parametros.insert(make_pair('t',"Opcion t"));break;
                case 'u': parametros.insert(make_pair('u',"Opcion u"));break;
                case 'v': parametros.insert(make_pair('v',"Opcion v"));break;
                case 'w': parametros.insert(make_pair('w',"Opcion w"));break;
                case 'x': parametros.insert(make_pair('x',"Opcion x"));break;
                case 'y': parametros.insert(make_pair('y',"Opcion y"));break;
                case 'z': parametros.insert(make_pair('z',"Opcion z"));break;
            }
        }
    }
    return parametros;
}

int main(){

    string cad="tar -z -x -f fichero";
    string cad2="ejemplo -d -g -w -f fichero -k ";
    typedef map<char, string> StringStringMap;
    StringStringMap parametros;
    parametros=params(cad);
    cout<<"La cadena que se ha pasado ha sido :"<<cad<<endl;
    cout<<"Las opciones que se han reconocido son las siguientes: "<<endl;
    for(StringStringMap::const_iterator i=parametros.begin();i!=parametros.end();i++){
       cout<<i->first<<",   "<<i->second<<endl;
   }
    parametros=params(cad2);
    cout<<"La cadena que se ha pasado ha sido :"<<cad2<<endl;
    cout<<"Las opciones que se han reconocido son las siguientes: "<<endl;
    for(StringStringMap::const_iterator i=parametros.begin();i!=parametros.end();i++){
       cout<<i->first<<",   "<<i->second<<endl;
   }

}
