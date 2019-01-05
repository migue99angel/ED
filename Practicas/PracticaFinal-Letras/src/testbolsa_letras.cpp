#include <iostream>
#include "bolsa_letras.h"
#include "conjunto_letras.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"Este es un pequeño programa para comprobar el funcionamiento de la clase Bolsa_letras"<<endl<<endl;
    cout<<"Para comprobar el correcto funcionamiento de la clase cargaremos el fichero letras.txt"<<endl;

    Conjunto_letras conjunto;
    cout<<"\nAbriendo el fichero letras.txt...\n";
        
    ifstream fletras(argv[1]);

    cout<<"Cargando el fichero...\n";
    fletras>>conjunto;
    cout<<"Tamaño del conjunto: "<<conjunto.size()<<endl;
    cout<<"Fichero cargado con éxito.\n";

    cout<<"\nAhora comprobaremos el funcionamiento de la bolsa de letras"<<endl;
    BolsaLetras bolsa;
    bolsa = conjunto.generarLetrasJuego(8);
    cout<<"Generando una bolsa de 8 letras aleatorias....\n";
    cout<<"Generada con éxito. "<<endl;
    bolsa.mostrarLetras();

    cout<<"Generando una bolsa de 5 letras aleatorias....\n";
    bolsa=conjunto.generarLetrasJuego(5);;
    cout<<"Generada con éxito. "<<endl;
    bolsa.mostrarLetras();

    cout<<"Generando otra bolsa de 8 letras aleatorias....\n";
    bolsa=conjunto.generarLetrasJuego(8);
    cout<<"Generada con éxito. "<<endl;
    bolsa.mostrarLetras();


    cout<<"\nFIN DEL TEST"<<endl;


}
