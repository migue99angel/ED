#include "bolsa_letras.h"
#include "lista_palabras.h"
#include "conjunto_letras.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    if(argc != 5){
        cerr<<"Error en la llamada al programa"<<endl;
        cout<<"Formato correcto: ./letras 1-fichero con lista_palabras 2-fichero con letras 3-número de letras 4-Modalidad (L si palabra más larga, P si palabra con más puntos) "<<endl;
    }
    else{
            
        ifstream f(argv[1]);
        
        if (!f){
            cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
            return 0;
        }

        lista_palabras lista;
        cout<<"Cargando lista_palabras..."<<endl;
        f>>lista;
        cout<<"Se ha cargado con éxito la lista de palabras"<<endl<<endl;

        ifstream fletras(argv[2]);
        if (!fletras){
            cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
            return 0;
        }

        Conjunto_letras conjunto;
        cout<<"Cargando el conjunto de letras..."<<endl;
        fletras>>conjunto;
        cout<<"Se ha cargado con éxito el conjunto de letras."<<endl<<endl;
        cout<<"¡Juego preparado, vamos a jugar!"<<endl;
        

        BolsaLetras bolsa;
        int cantidad = strtol(argv[3], NULL, 10);
        
        bolsa = conjunto.generarLetrasJuego(cantidad);
        string sol;
        bool stop=false;
        char continuar;
        while(!stop){
            cout<<"__________________________________________________________________________________________________\n"<<endl;

            if(argv[4][0] == 'P'){
                cout<<"Las puntuaciones de cada letra son las siguientes: "<<endl;
                cout<<conjunto;
            }

            cout<<"Generando las letras para la partida..."<<endl;
            cout<<"Las letras son: ";
            
            bolsa.mostrarLetras(  );

            cout<<"¿Sabes alguna solución?: "; 
            cin>>sol;

            cout<<sol<<"\t Puntuación:  "<<conjunto.obtenerRanking(sol,(char) argv[4][0])<<endl<<endl;
            cout<<"Mis soluciones son: "<<endl;

            lista_palabras soluciones = lista.generarSoluciones(bolsa);
            lista_palabras::const_iterator itr;

            for(itr = soluciones.begin(); itr != soluciones.end(); ++itr)
                cout<<*itr<<"\t Puntuación:  "<<conjunto.obtenerRanking(*itr,(char) argv[4][0])<<endl;


            cout<<"¿Te apetece otra ronda?"<<endl;
            cout<<"Introduce S o s para seguir jugando, en caso contrario introduce cualquier otra letra para salir: ";
            cin>>continuar;

            if(!(continuar == 'S' || continuar == 's'))
                stop=true;
            else
                cout<<"¡Vamos a por otra ronda!"<<endl;    

        }

    }

    cout<<"¡Bien jugado!"<<endl;
}
