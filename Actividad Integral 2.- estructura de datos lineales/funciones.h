#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <list>

using namespace std;

template <class T> class List;

template <class T>
class Link { //La clase link es la padre y amiga de la list
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);
	T value;
	Link<T>* next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T>& source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&);
	~List();

	void addFirst(T,T,T);
  void addFirst(T);
	void meterPersonaje(T,T,T);
  void meterPersonaje(T);
	T buscarPersonaje(T) const;
	void verlista();
	void escribir(string);

	std::string toString() const;
	bool empty() const;
	void operator= (const List&);

private:
	Link<T>* head;
	int size;

};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T>* p;

	p = head;
	aux << "[";

	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void List<T>::meterPersonaje(T nom, T ed, T ele) {
	Link<T>* newLink, * p;
  T val= nom + " " + ed + " " + ele;
	newLink = new Link<T>(val);
	if (empty()) {
		addFirst(nom, ed, ele);
		return;
	}
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
bool verArchivo(List<T>& lista, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo de personajes: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) {
		if (linea.size() > 0) {
			lista.meterPersonaje(linea);
		}
	}
	arch.close();
	return true;
}

template <class T>
void List<T>::escribir(string archi) {
	ofstream arch;
	arch.open(archi);
	Link<T>* p;
	p = head;
	while (p != 0) {
		arch << p->value << endl;
		p = p->next;
	}
	arch.close();
}

template <class T>
void List<T>::verlista() {
	Link<T>* p;
	p = head;
	while (p != 0) {
		cout << p->value << endl;
		p = p->next;
	}
}

template <class T>
void List<T>::addFirst(T val) {
	Link<T>* newLink;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::addFirst(T nom, T ed, T ele) {
	Link<T>* newLink;
  T val= nom + " " + ed + " " + ele;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::meterPersonaje(T val) {
	Link<T>* newLink, * p;
	newLink = new Link<T>(val);
	if (empty()) {
		addFirst(val);
		return;
	}
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}

void buscarPersonaje(ifstream& archivo, string personajeBuscado) {
	archivo.open("personajesAvatar.txt", ios::in);
	string personaje, edad, elemento;
	int aux = 0;
	archivo >> personaje;
	while (!archivo.eof() && aux == 0) {
		archivo >> edad;
		archivo >> elemento;
		if (personaje == personajeBuscado) {
			cout << "El personaje es: " << endl;
			cout << personaje << " " << edad << " " << elemento << endl;
			aux = 1;
		}
		archivo >> personaje;
	}
	archivo.close();
	if (aux == 0) {
		cout << "La edad no existe" << endl;
	}
}

#endif
