/*
15. Una variante del vector disperso es aquella en la que se puede definir cual es el valor nulo. Modifica
la clase anterior de forma que se pueda definir cual es el valor nulo al crear un objeto. Implementa
también cambiar_nulo(const T &n)

COMANDO PARA COMPILAR: g++ -o ejercicio15 ejercicio15.cpp


Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)

*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;
template<typename T>
class vdisperso {
public:
    vdisperso(const vector<T> &v,T nulo){
        int contador=0;
        this->nulo=nulo;
        typename vector<T>::const_iterator i=v.begin();
        for(i;i!=v.end();i++){
            if(*i!=this->nulo)
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
                    v.push_back(this->nulo);
                }
                else{
                    v.push_back(i->second);
                    i++;
                }
                k++;
            }
        return v;
    }
    void cambiar_nulo(const T &n){
        vector<T> aux=this->convertir();
        this->nulo=n;
        vdisperso<T> l_aux(aux,n);
        this->coefs=l_aux.coefs;
        this->n=l_aux.n;
    }

private:
    list< pair<int, T> > coefs;
    int n=0;
    T nulo;
};

int main(){
    vector<int> v {0,0,0,0,0,10,0,0,0,0,3,0,0,0,0,50,0,0,0,6},vaux;
    int nulo=1;
    vdisperso<int> vdis(v,nulo);  
    cout<<"El vector original es: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    
    cout<<endl;
    cout<<"El vector disperso siendo el valor nulo "<<nulo<<" es : "<<endl;
    vdis.MostrarVectorDisperso();
    

    cout<<"Probamos a convertir a un vector tradicional de nuevo: "<<endl;
    vaux=vdis.convertir();

    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    
    cout<<endl;
    cout<<"Cambiamos el valor nulo por 0"<<endl;
    vdis.cambiar_nulo(0);
    vdis.MostrarVectorDisperso();
}