/*14. Un vector disperso es un vector en el que la inmensa mayorı́a de sus elementos son nulos. Para
representar ese tipo de vectores se suele utilizar como representación una lista:
template <typename T>
class vdisperso {
public:
    vdisperso(const vector<T> &v);
    void asignar_coeficiente(int i, const T &x);
    vector<T> convertir() const;
    ...
private:
    list< pair<int, T> > coefs;
    int n;
}
De esa forma se ahorra una gran cantidad de espacio. Implementa los dos métodos indicados en la
parte pública.

COMANDO PARA COMPILAR: g++ -o ejercicio14 ejercicio14.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)

*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class vdisperso {
public:
    vdisperso(const vector<T> &v){
        int contador=0;
        typename vector<T>::const_iterator i=v.begin();
        for(i;i!=v.end();i++){
            if(*i!=0)
                asignar_coeficiente(n,*i);           
            n++;
        }
    }
    void asignar_coeficiente(int i, const T &x){
        coefs.push_back(make_pair(i,x));
    }
    void MostrarVectorDisperso(){
        typename list<pair<int,T>>::const_iterator i=coefs.begin();
        for(i;i!=coefs.end();i++){
            cout<<"( "<<i->first<<" , "<<i->second<<") ";
        }
        cout<<endl;
    }
    vector<T> convertir() const{
        vector<T> v;
        int k=0;
        typename list<pair<int,T>>::const_iterator i=coefs.begin();
            while(k<n){
                if(!(i->first==k)){
                    v.push_back(0);
                }
                else{
                    v.push_back(i->second);
                    i++;
                }
                k++;
            }
        return v;
    }
private:
    list< pair<int, T> > coefs;
    int n=0;
};

int main(){
    vector<int> v {0,0,0,0,0,10,0,0,0,0,3,0,0,0,0,50,0,0,0,6},vaux;
    vdisperso<int> vdis(v);
    cout<<"El vector original es: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
    cout<<"El vector disperso es: "<<endl;
    vdis.MostrarVectorDisperso();

    cout<<"Probamos a convertir a un vector tradicional de nuevo: "<<endl;
    vaux=vdis.convertir();

    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
}