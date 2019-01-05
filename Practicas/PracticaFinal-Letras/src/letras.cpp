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
        
        
        string sol;
        bool stop=false;
        bool imposible=false;
        char continuar;
        while(!stop){
            cout<<"__________________________________________________________________________________________________\n"<<endl;

            if(argv[4][0] == 'P'){
                cout<<"Las puntuaciones de cada letra son las siguientes: "<<endl;
                cout<<conjunto;
            }

            cout<<"Generando las letras para la partida..."<<endl;
            bolsa = conjunto.generarLetrasJuego(cantidad);
            cout<<"Las letras son: ";
            
            bolsa.mostrarLetras(  );
            lista_palabras soluciones = lista.generarSoluciones(bolsa);

            if(soluciones.size()!=0){

            cout<<"¿Sabes alguna solución?: "; 
            cin>>sol;

            if(!soluciones.Esta(sol)){
                char seguir;
                cout<<"La solución introducida no es válida\n";
                cout<<"¿Quieres seguir intentandolo? en caso afirmativo introduce S o s, cualquier otra letra para ver las soluciones: ";
                cin>>seguir;
                bool posible=false;

                if (seguir=='S' || seguir =='s'){

                while(posible == false){
                    cout<<"¿Sabes alguna solución?: "; 
                    cin>>sol;

                    if(soluciones.Esta(sol))
                        posible=true;
                    else{
                        cout<<"La solución introducida no es válida\n";
                        cout<<"¿Quieres seguir intentandolo? en caso afirmativo introduce S o s, cualquier otra letra para ver las soluciones: ";
                        cin>>seguir;
                        if(seguir != 'S' && seguir != 's'){
                            posible=true;
                            }
                        }    

                    }
                }
            }


            if(soluciones.Esta(sol)){
                cout<<"¡La solución introducida es correcta!\n";
                cout<<sol<<"\t Puntuación:  "<<conjunto.obtenerRanking(sol,(char) argv[4][0])<<endl<<endl;
            }

            
            cout<<"Mis soluciones son: "<<endl;
            /*AQUI SOLO MUESTRO LAS SOLUCIONES MÁS LARGAS O CON MAYOR PUNTUACIÓN PERO BASTARIA CON QUITAR LA SIGUIENTE LINEA PARA MOSTRAR TODAS LAS SOLUCIONES QUE SE PUEDEN FORMAR CON LAS LETRAS GENERADAS*/
            soluciones = soluciones.mejoresSoluciones(argv[4][0],conjunto);
            
            lista_palabras::const_iterator itr;

            for(itr = soluciones.begin(); itr != soluciones.end(); ++itr)
                cout<<*itr<<"\t Puntuación:  "<<conjunto.obtenerRanking(*itr,(char) argv[4][0])<<endl;

            }
            else{    
                cout<<"Es imposible formar palabras con la bolsa de letras generada\n";
                cout<<"Generando una nueva bolsa de letras...\n";
                imposible=true;
            }

            if(!imposible){
            cout<<"¿Te apetece otra ronda?"<<endl;
            cout<<"Introduce S o s para seguir jugando, en caso contrario introduce cualquier otra letra para salir: ";
            cin>>continuar;

            if(!(continuar == 'S' || continuar == 's'))
                stop=true;
            else
                cout<<"¡Vamos a por otra ronda!"<<endl;    
            }
            imposible=false;
        }

    }

    cout<<"¡Bien jugado!"<<endl;
}
