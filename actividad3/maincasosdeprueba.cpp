#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funciones.h"

using namespace std;

int main(int argc, char const* argv[]) {
	List<string> arbol;
	ifstream archivo;
	ofstream write;
	int opc = 0;
	verArchivo(arbol, "personajesAvatar.txt");
	cout << "-Escribimos 1 para mostrar el archivo con los personajes" << endl;
	arbol.verarbol(); //La función ver arbol despliega los datos del archivo en el arbol buscado
	//Actualmente la función buscar esta en proceso y no la he terminado ya que al buscar por rango y por el atributo deseado necesito dividir cada elemento y categorizarlo 
	string edadbuscada;
	cout << "Escribe el personaje que quieres buscar: " << endl;
	cout << "-Escriba el personaje que quiera como por ejemplo aang" << endl;
	cin >> edadbuscada;
	buscar(archivo, edadbuscada);
	//La función nueva edad inserta un nuevo elemento en el arbol y lo guarda en el archivo ejemplo.
	string nuevaedad;
	cout << "Escribe el personaje que quieres agregar: " << endl;
	cout << "-Ahora podemos meter lo que queramos como por ejemplo blam" << endl;
	cin >> nuevaedad;
	arbol.insertar(nuevaedad);
	arbol.escribir("ejemplo.txt");
	//Salimos del programa
	arbol.verarbol();
	cout << "-Finalmente la volvemos a imprimir para ver el elemento aniadido" << endl;
	exit(1);

	return 0;
}
