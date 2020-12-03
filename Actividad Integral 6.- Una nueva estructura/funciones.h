#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Empezamos las funcion con los parametros de una lista llamada lista y su tamanio en la variable elementos
void bucketSort(float lista[], int elementos) {
    vector<float> buckets[elementos]; //Creamos muchos buckets pequeños
    int indice = 0;

    for(int i = 0; i < elementos; i++){ //Vamos llenando cada valor en su respectivo bucket pequeño
       int bucketInicial = elementos*lista[i];
       buckets[bucketInicial].push_back(lista[i]);
    }
    for (int i = 0; i < elementos; i++){ //Usamos la funcion sort para ordenar los buckets que contienen todos los numeros
       sort(buckets[i].begin(), buckets[i].end());
    }
    for(int i = 0; i < elementos; i++){ //Ahora que todos los buckets pequeños estan arreglados los metemos a la lista
        for(int j = 0; j < (signed)buckets[i].size(); j++){
          lista[indice++] = buckets[i][j];
        }
    }
}

#endif
