#include <iostream>
#include <cstring>
#include "funciones.h"

using namespace std;

int main(){
    Graph<string> vec;
    ifstream archivo;
    ofstream write;
    verArchivo(vec);
    verConexiones(vec);
    int opc;

    while (opc != 4) { //Menu
      cout << "-Desplegar grafo (1)" << endl << "-Buscar personaje (2)" << endl << "-Meter personaje (3)" << endl << "-Salir (4)" << endl;
      cin >> opc;
      if (opc == 1) {
        cout<<vec.imprimirListaNodos();
        //Casos de prueba primera funcion:
        //Caso 1: La primera funcion unicamente despliega el grafo y el unico caso de prueba es desplegarlo
      }
      else if (opc == 2) {
        string personajeBuscado;
        cout << "Escribe el nombre del personaje que buscas: ";
        cin >> personajeBuscado;
        vec.find(personajeBuscado);
        //Casos de prueba segunda funcion:
        //Caso 1: vec.find(aang) asi se vería la funcion y despues de buscar en el grafo encontraria el personaje
        //y lo regresaria como "El personaje es: aang tiene 112 avatar" que es el nombre, la edad y el elemento
        //Caso 2: vec.find(yue) asi se vería la funcion y despues de buscar en el grafo encontraria el personaje
        //y lo regresaria como "El personaje es: yue tiene 16 agua" que es el nombre, la edad y el elemento
      }
      else if (opc == 3) {
        string nuevoPersonaje;
        string nuevaEdad;
        string nuevoElemento;
        cout << "Escribe el nombre del personaje que quieras meter: " << endl;
        cin >> nuevoPersonaje;
        cout << "Escribe la edad del personaje: " << endl;
        cin >> nuevaEdad;
        cout << "Escribe el elemento del personaje: " << endl;
        cin >> nuevoElemento;
        vec.meterNodo(nuevoPersonaje, nuevaEdad, nuevoElemento);
        vec.transcribir("personajesAvatar.txt");
        //Casos de prueba tercera funcion:
        //Caso 1: vec.meterNodo(shue, 38, tierra); en este caso meteriamos los datos al archivo
        //y al grafo y se le da su numero propio.
        //Caso 2: vec.meterNodo(long, 32, aire); en este caso meteriamos los datos al archivo
        //y al grafo y se le da su numero propio.
      }
    }
  exit(1);
  return 0;
}
