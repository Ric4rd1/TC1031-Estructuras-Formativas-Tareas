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
    T busqSecuencial(vector<T>&, const int);
    T busqBinaria(vector<T>&, const int);

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
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(vector<T>&A, vector<T>&B, int low, int mid, int high){
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        } else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for(;j <= high; j++){
            B[k++] = A[j];
        } 
    } else{
            for(; i <= mid; i++){
                B[k++] = A[i];
            }
        }
    }

template <class T>
void Sorts<T>::mergeSplit(vector<T>&A, vector<T>&B, int low, int high){
    int mid;

    if((high - low) < 1 ){
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T>&prueba){
    vector<T> tmp(prueba.size());
    
    mergeSplit(prueba, tmp, 0, prueba.size() - 1);
}

template <class T>
T Sorts<T>::busqSecuencial(vector<T>&prueba, const int target){
    for(int i = 0; i <= prueba.size() - 1; i++){
        if(prueba[i] == target){
            return i;
        }
    }
    return -1;
}

template <class T>
T Sorts<T>::busqBinaria(vector<T>&prueba, const int target){
    int low = 0;
    int high = prueba.size() - 1;
    int mid;

    while(low <= high){
        mid = (low + high) / 2;
        if(prueba[mid] == target){
            return mid;
        } else if(prueba[mid] < target){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}


#endif