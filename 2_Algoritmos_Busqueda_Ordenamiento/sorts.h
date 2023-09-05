#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <list>

using namespace std;

template <class T>
class Sorts{
 private:
    void swap(vector<T>&, int, int);
    void copyArray(vector<T>&, std::vector<T>&, int, int);
	void mergeArray(vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(vector<T>&, std::vector<T>&, int, int);
 public:
    void ordenaSeleccion(vector<T>&);
    void ordenaBurbuja(vector<T>&);
    void ordenaMerge(vector<T>&);
    T busqSecuencial(vector<T>&, T);
    T busqBinaria(vector<T>&, T);

};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T>&prueba){
    for(int i = 0; i < prueba.size(); i++){
        int min = i;
        for (int j = i; j < prueba.size(); j++){
            if (prueba[min] > prueba[j]){
                min = j;
            }
        }
    swap(prueba, min, i);
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(vector<T>&prueba){
    for(int i = prueba.size() - 1; i > 0;i--){
        for(int j = 0; j < i; j++){
            if(prueba[j] > prueba[j+1]){
                swap(prueba, j + 1, j);
            }
        }
    }
    
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T>&prueba){
    
}

template <class T>
T Sorts<T>::busqSecuencial(vector<T>&prueba, T){
    
    return T();
}

template <class T>
T Sorts<T>::busqBinaria(vector<T>&prueba, T){
    
    return T();
}


#endif