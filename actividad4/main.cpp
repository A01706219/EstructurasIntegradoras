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
		cout << "-Ver archivo de personajes (1)" << endl << "-Buscar elemento (2)" << endl << "-Meter personaje (3)" << endl << "-Casos de prueba(4)" << endl <<"-Salir (5)" << endl;
		cin >> opc;

		if (opc == 1) {
			lista.verlista(); //La función ver lista despliega los datos del archivo en la lista buscada
		}
		else if (opc == 2) { //Actualmente la función buscar esta en proceso y no la he terminado ya que al buscar por rango y por el atributo deseado necesito dividir cada elemento y categorizarlo
			string personajebuscado;
			cout << "Escribe el personaje que quieres buscar: ";
			cin >> personajebuscado;
			BuscarPersonaje(archivo, personajebuscado);
		}
		else if (opc == 3) { //La función nueva edad inserta un nuevo elemento en la lista y lo guarda en el archivo ejemplo.
			string nuevopersonaje;
			cout << "Escribe el personake que quieres agregar: ";
			cin >> nuevopersonaje;
			lista.meterpersonaje(nuevopersonaje);
			lista.escribir("personajesAvatar.txt");
		}
    else if (opc == 4) {
      cout << "Mostramos la lista con los personajes" << endl;
      lista.verlista();
      cin.ignore();
      cout << "Ahora buscaremos al personaje aang" << endl;
      BuscarPersonaje(archivo, "aang");
      cin.ignore();
      cout << "Meteremos un nuevo personaje que se llame Xin" << endl;
      lista.meterpersonaje("Xin");
      cin.ignore();
      cout << "Ahora checaremos por ultimo el archivo con el nuevo personaje" << endl;
      lista.verlista();
      cin.ignore();
    }
		else if (opc == 5) { //Salimos del programa
			exit(1);
		}
	}

	return 0;
}

