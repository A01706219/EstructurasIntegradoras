#include<iostream>
#include<vector>
#include<algorithm>
#include "funciones.h"

using namespace std;

int main() {
    cout << "Rodrigo Marquina Magana - A01706210" << endl;
    cout << "Bienvenido a la actividad integral extra: " << endl;
    cout << "Caso 1 de prueba: " << endl;
    cout << "Los valores 0.3, 0.2, 0.7, 0.9, 0.1 y 0.9 seran arreglados de menor a mayor por el metodo bucket sort." << endl;
    float lista[] = {0.3, 0.2, 0.7, 0.9, 0.1, 0.9}; //Inicializamos la lista con los valores del caso de prueba

    int longitud = sizeof(lista)/sizeof(lista[0]); //La longitud se pasa de bits a entero

    cout << "Lista sin ordenar: " << endl;
    for(int i = 0; i < longitud; i++){ //Tomamos los valores de la lista y los imprimimos para que los vea el usuario
       cout << lista[i] << ", ";
    }
    cout << '\n';
    bucketSort(lista, longitud); //Con la funcion ordenamos la lista

    cout << "Lista ordenada: " << endl; //Se la enviamos al usuario par que la vea
    for (int i = 0; i < longitud; i++){
       cout << lista[i] << ", ";
    }

    cout << '\n' << "Enter para continuar." << endl; //Caso de prueba 2
    cin.ignore();

    cout << "Caso 2 de prueba: " << endl;
    cout << "Los valores 0.32, 0.51, 0.95, 0.29, 0.01, 0.23 y 0.43 seran arreglados de menor a mayor por el metodo bucket sort." << endl;

    float lista2[] = {0.32, 0.51, 0.95, 0.29, 0.01, 0.23, 0.43};

    int longitud2 = sizeof(lista)/sizeof(lista[0]);

    cout << "Lista sin ordenar: " << endl;
    for(int i = 0; i < longitud2; i++){
       cout << lista2[i] << ", ";
    }
    cout << '\n';
    bucketSort(lista2, longitud2);

    cout << "Lista ordenada: " << endl;
    for (int i = 0; i < longitud2; i++){
       cout << lista2[i] << ", ";
    }

    return 0;
}
