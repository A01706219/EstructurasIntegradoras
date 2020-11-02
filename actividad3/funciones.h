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
template <class T> class Personaje;
template <class T> class Edad;
template <class T> class Elemento;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);
	T value;
	Link<T>* next;

	friend class List<T>;
	friend class Edad<T>;
	friend class Personaje<T>;
	friend class Elemento<T>;
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

	void addFirst(T);
	void meteredad(T);
	T buscaredad(T) const;
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
class Edad {
public:
	Edad();
	Edad(const Edad<T>&);
	~Edad();

	void addFirst(T);
	void meteredad(T);
	T buscaredad(T) const;
	bool empty() const;
	void operator= (const Edad&);

private:
	Link<T>* head;
	int size;
};

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
void List<T>::addFirst(T val) {
	Link<T>* newLink;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::meteredad(T val) {
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

template <class T>
T List<T>::buscaredad(T val) const {
	Link<T>* p;

	p = head;
	int index = 0;
	while (p != 0) {
		if (p->value == val) {
			cout << "La edad se encuentra en la: " << """ << p->value << """ << endl;
			return "";
		}
		p = p->next;
		index++;
	}
	cout << "La edad no existe." << endl;
	return "";
}

template <class T>
bool verArchivo(List<T>& lista, string nombrearch) {
	ifstream arch(nombrearch);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombrearch << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) {
		if (linea.size() > 0) {
			lista.meteredad(linea);
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
void Edad<T>::addFirst(T val) {
	Link<T>* newLink;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void Edad<T>::meteredad(T val) {
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

void buscaredad(ifstream& archivo, string edadbuscada) {
	archivo.open("personajesAvatar.txt", ios::in);
	string personaje, edad, elemento;
	int aux = 0;
	archivo >> personaje;
	while (!archivo.eof() && aux == 0) {
		archivo >> personaje;
		archivo >> edad;
		if (edad == edadbuscada) {
			cout << "La edad es: " << endl;
			cout << edad << " " << personaje << " " << elemento << endl;
			aux = 1;
		}
		archivo >> edad;
	}
	archivo.close();
	if (aux == 0) {
		cout << "La edad no existe" << endl;
	}
}

#endif
