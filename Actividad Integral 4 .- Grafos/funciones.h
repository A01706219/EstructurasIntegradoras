#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class Graph{
private:
    bool dir;
	  vector<T> listaNodos;
	  vector<vector<int>> listaAdyacencia;
    vector<T> informacionPersonaje;
public:
    Graph(){}
    Graph(bool d);
    void meterNodo(T);
    void meterNodo(T,T,T); //meter el nuevo personaje con los 3 atributos de nombre, edad y elemento
	  void meterArista(T nodoInicial, T nodoFinal);
    bool find(string);
    void transcribir(string);
    string imprimirListaNodos();
};

template<class T>
string Graph<T>::imprimirListaNodos(){
	string resultadoFinal = "";
	for (int i = 0; i < listaNodos.size(); i++){
		resultadoFinal += to_string(i) + " " + listaNodos[i] + " " + informacionPersonaje[i] + "\n";
	}
	return resultadoFinal;
}

template<class T>
bool Graph<T>::find(string cancion){
    for (int i=0; i<listaNodos.size(); i++){
        if(listaNodos[i] == cancion){
          cout << "El personaje es: " << listaNodos[i] + " tiene " + informacionPersonaje[i] << endl;
          return true;
        }
    }
    cout << "El personaje no existe."; //Si no existe retorna lo siguiente
    return false;
}

template<class T> //Con esta funcion checamos si el valor ya esta dentro
void Graph<T>::meterNodo(T personaje){
	for (int i=0; i<listaNodos.size(); i++){
		if (listaNodos[i] == personaje) {
            return;
        }
	}
	listaNodos.push_back(personaje);
	vector<int> nuevaFila;
	listaAdyacencia.push_back(nuevaFila);
}

template<class T>
void Graph<T>::meterNodo(T personaje, T edad, T elemento){
    T val = edad+" "+elemento;
	for (int i = 0; i < listaNodos.size(); i++){
		if (listaNodos[i] == personaje) {
            return;
        }
	}
	listaNodos.push_back(personaje);
  informacionPersonaje.push_back(val);
	vector<int> nuevaFila;
	listaAdyacencia.push_back(nuevaFila); //Aqui se encuentra la lista de adyacencia
}

template<class T>
void Graph<T>::meterArista(T valorInicial, T valorFinal){
    int nodoInicial = -1;
	int nodoFinal = -1;

	for (int i=0; i<listaNodos.size(); i++){
		if (listaNodos[i] == valorInicial) {
            nodoInicial = i;
        } if (listaNodos[i] == valorFinal){
            nodoFinal = i;
        }
	} if (nodoInicial == -1 || nodoFinal == -1){
        cout << "No existe." << endl;
		return;
	}
	listaAdyacencia[nodoInicial].push_back(nodoFinal);
	if (!dir)
		listaAdyacencia[nodoFinal].push_back(nodoInicial);
}

void verArchivo(Graph<string> &graph){
	ifstream archivo;
	archivo.open("personajesAvatar.txt");
	while(archivo.good()){
		string personaje;
		string edad;
		string elemento;
		getline(archivo, personaje, ' ');
		getline(archivo, edad, ' ');
		getline(archivo, elemento, '\n');
		graph.meterNodo(personaje, edad, elemento);
	}
	archivo.close();
}

void verConexiones(Graph<string> &graph){
	ifstream archivo;
	archivo.open("relaciones.csv");
	while(archivo.good()){
		string personaje1;
		string personaje2;
		string amistad;
		getline(archivo, personaje1, ',');
		getline(archivo, personaje2, ',');
		getline(archivo, amistad, '\n');
		graph.meterArista(personaje1, personaje2);
	}
	archivo.close();
}

template <class T>
void Graph<T>::transcribir(string myFile){
	ofstream arch;
  arch.open (myFile);
  for(int i = 0; i < listaNodos.size(); i++){
    arch << listaNodos[i] + " " + informacionPersonaje[i] <<endl;
  }
  arch.close();
}

void buscarPersonaje(ifstream &archivo, string personajeBuscado){
    archivo.open("personajesAvatar.txt", ios::in);
    string personaje, edad, elemento;
    int aux = 0;
    archivo >> personaje;
    while(!archivo.eof() && aux == 0){
        archivo >> edad;
        archivo >> elemento;
        if(personaje == personajeBuscado){
            cout << "El personaje es: " << endl;
            cout << personaje << " " << edad << " " << elemento << endl;
            aux = 1;
        }
        archivo >> personaje;
    }
    archivo.close();
    if (aux == 0){
        cout << "El personaje no existe en el arbol" << endl;
    }
}

#endif
