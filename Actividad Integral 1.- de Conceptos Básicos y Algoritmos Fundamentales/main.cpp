#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funciones.h"

using namespace std;

int main(int argc, char const* argv[]) {
	Sorts<string> sorts;
	vector<string> vr;
	ifstream arch;
	ofstream archout;
	int opc = 0;

	verArchivo(vr, "personajesAvatar.txt");

	sorts.mergeSort(vr);

	ofstream ejemplo("ejemplo.txt");
	if (ejemplo.is_open()) {
		for (string& linea : vr) {
			ejemplo << linea << endl;
		}
	}

	while (opc != 5) {
		cout << "-Ver archivo de personajes (1)" << endl << "-Ordenar lista (2)" << endl << "-Buscar (3)" << endl << "-Meter Personaje (4)" << endl << "-Salir (5)" << endl;
		cin >> opc;

		if (opc == 1) {
			verPersonaje(arch);
      //Casos de prueba primera funcion:
      //Caso 1: La primera funcion unicamente imprime el archivo y solo hay una opcion
		}
		else if (opc == 2) {
			for (string& line : vr) {
				cout << line << endl;
			}
      //Casos de prueba segunda funcion:
      //Caso 1: La segunda funcion igualmente solo hay una opcion de ordenar el archivo por orden alfabetico.
		}
		else if (opc == 3) {
			buscarPersonaje(arch);
      //Casos de prueba tercera funcion:
      //Caso 1: Vamos a buscar al personaje zuko y la funcion unicamente recibe el nombre del personaje ya que asi los categoriza
      //La funcion nos regresará Nombre: zuko, Edad: 16, Elemento: fire
      //Caso 2: Vamos a buscar al personaje yue
      //La funcion nos regresará Nombre: yue, Edad: 16, Elemento: water
		}
		else if (opc == 4) {
			meterPersonaje(archout); //La funcion recibe el nombre del archivo donde se va a añadir que en este caso es ejemplo.txt
      //Casos de prueba cuarta funcion:
      //Caso 1: vamos a añadir al personaje korra con 18 anios de edad y elemento avatar
      //La funcion regresaria el txt con el archivo original y al final korra 18 avatar
		}
	}

	exit(1);

	return 0;
}
