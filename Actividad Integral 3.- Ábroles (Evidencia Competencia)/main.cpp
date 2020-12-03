#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"

using namespace std;

int main(){

    SplayTree<string> myTree;

    ifstream archivo;
    verArchivo(myTree, "personajesAvatar.txt");
    myTree.transcribir("ejemplo.txt");
    int opc;

    while (opc != 3) { //Menu
      cout << "-Desplegar arbol (1)" << endl << "-Buscar personaje (2)" << endl << "-Salir (3)" << endl;
      cin >> opc;

      if (opc == 1) {
        cout << myTree.verArbol();
        //Casos de prueba primera funcion:
        //Caso 1: Esta funcion unicamente puedes correrla y te despliega todo el arbol
      }
      else if (opc == 2) {
        string personajeBuscado;
        cout << "Escribe el personaje que quieras buscar: ";
        cin >> personajeBuscado;
        buscarPersonaje(archivo, personajeBuscado);
        //Casos de prueba segunda funcion:
        //Caso 1: buscarPersonaje(archivo, aang);
        //esta funcion te retornará aang 14 avatar
        //Caso 2: buscarPersonaje(archivo, katara);
        //esta funcion te retornará katara 14 agua
      }
    }
  exit(1);
  return 0;
}
