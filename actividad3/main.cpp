#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funciones.h"

using namespace std;

int main(int argc, char const* argv[]) {
	List<string> lista;
	ifstream archivo;
	ofstream write;
	int opc = 0;
	verArchivo(lista, "personajesAvatar.txt");

	while (opc != 5) {
		cout << "-Ver archivo de personajes (1)" << endl << "-Buscar elemento (2)" << endl << "-Meter personaje (3)" << endl << "-Salir (4)" << endl;
		cin >> opc;

		if (opc == 1) {
			lista.verlista(); //La función ver lista despliega los datos del archivo en la lista buscada
		}
		else if (opc == 2) { //Actualmente la función buscar esta en proceso y no la he terminado ya que al buscar por rango y por el atributo deseado necesito dividir cada elemento y categorizarlo 
			string edadbuscada;
			cout << "Escribe la edad que quieres buscar: ";
			cin >> edadbuscada;
			buscaredad(archivo, edadbuscada);
		}
		else if (opc == 3) { //La función nueva edad inserta un nuevo elemento en la lista y lo guarda en el archivo ejemplo.
			string nuevaedad;
			cout << "Escribe la edad que quieres agregar: ";
			cin >> nuevaedad;
			lista.meteredad(nuevaedad);
			lista.escribir("ejemplo.txt");
		}
		else if (opc == 4) { //Salimos del programa
			exit(1);
		}
	}

	return 0;

	return 0;
}
