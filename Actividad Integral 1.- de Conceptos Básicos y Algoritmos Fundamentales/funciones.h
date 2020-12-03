#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

template <class T>
bool verArchivo(vector<T>& vr, string nombreArchivo) {
	ifstream arch(nombreArchivo);
	if (!arch) {
		cout << "No se encuentra el archivo: " << nombreArchivo << endl;
		return false;
	}
	string linea;
	while (getline(arch, linea)) {
		if (linea.size() > 0) {
			vr.push_back(linea);
		}
	}
	arch.close();
	return true;
}

void verPersonaje(ifstream& arch) {
	string nombre;
	string edad;
	string elemento;
	arch.open("personajesAvatar.txt", ios::in);
	if (arch.is_open()) {
		arch >> nombre;
		while (!arch.eof()) {
			arch >> edad;
			arch >> elemento;
			cout << nombre << edad << elemento << endl;
			arch >> nombre;
		}
		arch.close();
	}
	else {
		cout << "Error" << endl;
	}
}

void buscarPersonaje(ifstream& arch) {
	arch.open("personajesAvatar.txt", ios::in);
  string nombre;
	string edad;
	string elemento;
	string auxnombre;
	bool band = false;
	cout << "Buscar personaje de Avatar" << endl;
	cin >> auxnombre;
	arch >> nombre;
	while (!arch.eof() && band == 0) {
		arch >> edad;
		arch >> elemento;
		if (nombre == auxnombre) {
			cout << "Nombre: " << nombre << endl;
			cout << "Edad: " << edad << endl;
			cout << "Elemento: " << elemento << endl;
			band = 1;
		}
		arch >> nombre;
	}
	arch.close();
	if (band == 0) {
		cout << "No se ha encontrado al personaje buscado." << endl;
	}
}

void meterPersonaje(ofstream& archout) {
	string nombre;
	string edad;
	string elemento;
	archout.open("ejemplo.txt", ios::out | ios::app);
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Edad: ";
	cin >> edad;
	cout << "Elemento: ";
	cin >> elemento;
	archout << nombre << edad << elemento << endl;
	archout.close();
}

	template <class T>
	class Sorts {
	private:
		void swap(vector<T>&, int, int);
		void copyArray(vector<T>&, vector<T>&, int, int);
		void mergeArray(vector<T>&, vector<T>&, int, int, int);
		void mergeSplit(vector<T>&, vector<T>&, int, int);
	public:
		vector<T> mergeSort(vector<T>&);
	};

	template <class T>
	void Sorts<T>::swap(vector<T> & vr, int i, int j) {
		T aux = vr[i];
		vr[i] = vr[j];
		vr[j] = aux;
	}

	template <class T> 	//copyarray aux1
	void Sorts<T>::copyArray(vector<T> & A, vector<T> & B, int low, int high) {

		for (int i = low; i <= high; i++) {
			A[i] = B[i];
		}
	}

	template <class T> 	//mergearray aux2
	void Sorts<T>::mergeArray(vector<T> & A, vector<T> & B, int low, int mid, int high) {
		int i, j, k;

		i = low;
		j = mid + 1;
		k = low;

		while (i <= mid && j <= high) {
			if (A[i] < A[j]) {
				B[k] = A[i];
				i++;
			}
			else {
				B[k] = A[j];
				j++;
			}
			k++;
		}
		if (i > mid) {
			for (; j <= high; j++) {
				B[k++] = A[j];
			}
		}
		else {
			for (; i <= mid; i++) {
				B[k++] = A[i];
			}
		}
	}

	template <class T> 	//mergesplit aux3
	void Sorts<T>::mergeSplit(vector<T> & A, vector<T> & B, int low, int high) {
		int mid;

		if ((high - low) < 1) {
			return;
		}
		mid = (high + low) / 2;
		mergeSplit(A, B, low, mid);
		mergeSplit(A, B, mid + 1, high);
		mergeArray(A, B, low, mid, high);
		copyArray(A, B, low, high);
	}

	template <class T>	//ordenaMerge
	vector<T> Sorts<T>::mergeSort(vector<T> & vr) {
		vector<T> tmp(vr.size());
		mergeSplit(vr, tmp, 0, vr.size() - 1);
		return vr;
	}

#endif
