#include "Diccionario.h"
#include "Termino.h"
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario

   
   //Obtener las definiciones asociadas a una palabra  
   string definiciones_obtener = "a";
   cout<<"Las definiciones de la palabra "<<definiciones_obtener<<endl;
   for(unsigned i=0;i<mi_diccionario.getSignificados(definiciones_obtener).size();i++){
      cout<<mi_diccionario.getSignificados(definiciones_obtener)[i]<<endl;
   }
   
   
  //Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
   char inicial ='a',final = 'b';
   cout<<"El (sub)diccionario de termino comprendido entre  " <<inicial<< "  y  " <<final <<"  es: "<<endl;
   cout<<mi_diccionario.filtroIntervalo(inicial,final)<<endl<<endl<<endl<<endl;
  //Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"
   string clave ="farm";
   cout<<"El (sub)diccionario aociado a la palabra clave, "<<clave<<" es: "<<endl;
   cout<<mi_diccionario.filtroPalabraClave(clave)<<endl;
   //Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
   int num_defs, max_defs;
   float media;
   mi_diccionario.recuento(num_defs,max_defs,media);
   cout<<"El numero total de definiciones es: "<<num_defs<<endl;
   cout<<"El maximo de definiciones asociadas a un termino es: "<<max_defs<<endl;
   cout<<"El promedio de definiciones por palabra es: "<<media<<endl<<endl<<endl<<endl<<endl;
   //el siguiente método nos dice si una palabra se encuentra en el diccionario
   /*string buscar="horn";
   if(mi_diccionario.contenido(buscar))
    cout<<"La palabra "<<buscar<<" se encuentra en el diccionario"<<endl;
  else
    cout<<"La palabra "<<buscar<<" NO se encuentra en el diccionario"<<endl;
*/
}
