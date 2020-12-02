#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funciones.h"

using namespace std;

int main(int argc, char const* argv[]) { //Empezamos el main
	List<string> lista;
	ifstream archivo;
	ofstream write;
	int opc = 0;
	verArchivo(lista, "personajesAvatar.txt"); //Con la funcion guardamos el contenido del archivo en la lista

	while (opc != 5) { //Menu
		cout << "-Ver archivo de personajes (1)" << endl << "-Buscar elemento (2)" << endl << "-Meter personaje (3)" << endl << "-Salir (4)" << endl;
		cin >> opc;

		if (opc == 1) {
			lista.verlista(); //La función ver lista despliega los datos del archivo en la lista buscada
		}
    //Casos de prueba primera funcion:
    //Caso 1: Solo hay una opcion que despliega la lista
		else if (opc == 2) { //Actualmente la función buscar esta en proceso y no la he terminado ya que al buscar por rango y por el atributo deseado necesito dividir cada elemento y categorizarlo
			string nombreBuscado;
			cout << "Escribe el personaje que quieres buscar: ";
			cin >> nombreBuscado;
			buscarPersonaje(archivo, nombreBuscado);
      //Casos de prueba segunda funcion:
      //Caso 1: si nombreBuscado se pone como aang te dira que es aang 14 avatar. buscarPersonaje(archivo, aang)
      //Caso 2: si nombreBuscado se pone como katara te dira que es katara 14 agua. buscarPersonaje(archivo, katara)
		}
		else if (opc == 3) { //La funcion nueva edad inserta un nuevo elemento en la lista y lo guarda en el archivo ejemplo.
			string nuevoNombre, nuevaEdad, nuevoElemento;
			cout << "Escribe el personaje que quieres agregar: " << endl;
			cin >> nuevoNombre;
      cout << "Escribe la edad del personaje" << endl;
      cin >> nuevaEdad;
      cout << "Escribe el elemento del personaje" << endl;
      cin >> nuevoElemento;
			lista.meterPersonaje(nuevoNombre, nuevaEdad, nuevoElemento);
			lista.escribir("ejemplo.txt");
      //Casos de prueba tercera funcion:
      //Caso 1: Meteremos al personaje xin de 52 anios de edad y elemento de fuego.
      //nuevoNombre seria xin
      //nuevaEdad seria 52
      //nuevoElemento seria fuego
      //La funcion quedaria como lista.meterPersonaje(xin, 52, fuego);
      //Caso 2: Meteremos al personaje azula de 14 anios de edad y elemento de fuego.
      //nuevoNombre seria azula
      //nuevaEdad seria 14
      //nuevoElemento seria fuego
      //La funcion quedaria como lista.meterPersonaje(azula, 14, fuego);
		}
		else if (opc == 4) { //Salimos del programa
			exit(1);
		}
	}
	return 0;
}
