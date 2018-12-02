/*
2. Implementa una función desencripta que haga el proceso inverso al del ejercicio anterior.
string desencripta(string cad, const map<char, char> &codigo)

COMANDO PARA COMPILAR: g++ -o ejercicio1 ejercicio01.cpp

Obsevarciones: El ejercicio es igual al anterior, cambiando el first de la función
por second y viceversa.

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

string desencripta(string cad, const map<char, char> &codigo){
    typedef map<char,char> CharCharMap;
    string cad_encrp=cad;
    CharCharMap::const_iterator pos;
    for(int i=0;i<cad.size();i++){
        for(pos=codigo.begin();pos!=codigo.end();pos++){
            if(cad[i]==pos->second){
                cad_encrp[i]=pos->first;
            }
        }
    }
    
    return cad_encrp;
}



int main(){
    string cad_1="ipmb";
    string cad_2="ftusvduvsbefebupt";
    string cad_3="ftup ft vo fkfnqmp ef vo nfotbkf fodsjqubep";
    string cad_encrp;
    typedef map<char,char> CharCharMap;
    CharCharMap codigo;
    codigo.insert(pair<char,char>('a','b'));
    codigo.insert(pair<char,char>('b','c'));
    codigo.insert(pair<char,char>('c','d'));
    codigo.insert(pair<char,char>('d','e'));
    codigo.insert(pair<char,char>('e','f'));
    codigo.insert(pair<char,char>('f','g'));
    codigo.insert(pair<char,char>('g','h'));
    codigo.insert(pair<char,char>('h','i'));
    codigo.insert(pair<char,char>('i','j'));
    codigo.insert(pair<char,char>('j','k'));
    codigo.insert(pair<char,char>('k','l'));
    codigo.insert(pair<char,char>('l','m'));
    codigo.insert(pair<char,char>('m','n'));
    codigo.insert(pair<char,char>('n','o'));
    codigo.insert(pair<char,char>('o','p'));
    codigo.insert(pair<char,char>('p','q'));
    codigo.insert(pair<char,char>('q','r'));
    codigo.insert(pair<char,char>('r','s'));
    codigo.insert(pair<char,char>('s','t'));
    codigo.insert(pair<char,char>('t','u'));
    codigo.insert(pair<char,char>('u','v'));
    codigo.insert(pair<char,char>('v','w'));
    codigo.insert(pair<char,char>('w','x'));
    codigo.insert(pair<char,char>('x','y'));
    codigo.insert(pair<char,char>('y','z'));
    codigo.insert(pair<char,char>('z','a'));
    cout<<"La cadena a desencriptar es: "<<cad_1<<endl;
    cad_encrp=desencripta(cad_1,codigo);
    cout<<"Desencriptando..."<<endl;
    cout<<"La cadena desencriptada es: "<<cad_encrp<<endl<<endl;

    cout<<"La cadena a desencriptar es: "<<cad_1<<endl;
    cad_encrp=desencripta(cad_2,codigo);
    cout<<"Desencriptando..."<<endl;
    cout<<"La cadena desenencriptada es: "<<cad_encrp<<endl<<endl;

    cout<<"La cadena a desencriptar es: "<<cad_3<<endl;
    cad_encrp=desencripta(cad_3,codigo);
    cout<<"Desencriptando..."<<endl;
    cout<<"La cadena desencriptada es: "<<cad_encrp<<endl<<endl;
}