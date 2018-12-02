/*
21. En un servicio de urgencias de un hospital quieren tener la posibilidad de poder gestionar el orden
en que los pacientes se irán atendiendo. Para ello, de cada paciente se guarda nombre, apellidos,
dni, gravedad. Al mismo tiempo se quiere poder acceder por dni. Construye una clase adecuada e
implementa las operaciones de inserción y borrado.

COMANDO PARA COMPILAR: g++ -o ejercicio21 ejercicio21.cpp

Observacion:El paciente con el indice mas pequeño será el más grave 

Autor:Miguel Ángel Posadas Arráez
Grupo:2ºB(1)
*/


#include <iostream>
#include <list>
#include <queue>
#include <map>

using namespace std;


struct Paciente{
    string nombre;
    string apellidos;
    string dni;
    int gravedad;
};

struct Comparacion{
    bool operator()(Paciente p1, Paciente p2){
        return p1.gravedad > p2.gravedad;         
    }
};


class ListaPacientes{
    private:
        priority_queue<Paciente,vector<Paciente>,Comparacion> hospital;
        typedef map<string,Paciente> StringPacienteMap;
        StringPacienteMap DNI_paciente;

    public:   
        ListaPacientes(){
        
        }
        ListaPacientes(const ListaPacientes &c){
            this->hospital =c.hospital;
            this->DNI_paciente= c.DNI_paciente;
        }
        void insercion(Paciente p){
            hospital.push(p);
            DNI_paciente.insert(pair<string,Paciente>(p.dni,p));
        }
        void borrado(){
            hospital.pop();
        }

        Paciente SiguientePaciente(){
           return hospital.top();
        }
        /*
        Cuidado, al mostrar la lista esta queda vacia
        */
        void MostrarLista(){
	    while(!hospital.empty()){
		    cout<<"Paciente: "<<this->SiguientePaciente().nombre<<" "<<this->SiguientePaciente().apellidos<<" "<<this->SiguientePaciente().dni<<" "<<"gravedad: "<<this->SiguientePaciente().gravedad<<endl;
		    hospital.pop();
	        }
        }
        Paciente BuscarPorDNI(string dni){
            StringPacienteMap::iterator i;
            i=DNI_paciente.find(dni);
            return i->second;
        }
};

int main(){

    Paciente p1, p2 ,p3, p4, paux;

    p1.nombre="Francisco";
    p1.apellidos="Gomez Hernandez";
    p1.dni="12345678E";
    p1.gravedad=1;

    p2.nombre="David";
    p1.apellidos="Dominguez Lorente";
    p2.dni="66666666W";
    p2.gravedad=10;

    p3.nombre="Maria";
    p3.apellidos="Itafti Rivas";
    p3.dni="21345325R";
    p3.gravedad=3;

    p4.nombre="Nora";
    p4.apellidos="Alcazar Marcos";
    p4.dni="66565658P";
    p4.gravedad=4;

    ListaPacientes l;
    l.insercion(p1);
    l.insercion(p2);
    l.insercion(p3);
    l.insercion(p4);

    l.MostrarLista();

    cout<<"El paciente mas grave ha sido atendido "<<endl;
    l.insercion(p1);
    l.insercion(p2);
    l.insercion(p3);
    l.insercion(p4);
    l.borrado();
    l.MostrarLista();

    cout<<"El paciente con DNI 66565658P es : "<<endl;
    paux=l.BuscarPorDNI("66565658P");
    cout<<"Paciente: "<<paux.nombre<<" "<<paux.apellidos<<" "<<paux.dni<<" "<<"gravedad: "<<paux.gravedad<<endl;


}