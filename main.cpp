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
		}
		else if (opc == 2) {
			for (string& line : vr) {
				cout << line << endl;
			}
		}
		else if (opc == 3) {
			buscarPersonaje(arch);
		}
		else if (opc == 4) {
			meterPersonaje(archout);
		}
	}

	exit(1);

	return 0;
}
