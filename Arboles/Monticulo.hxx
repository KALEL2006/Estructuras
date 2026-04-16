#ifndef MONTICULO_HXX
#define MONTICULO_HXX

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<class T>
Monticulo<T>::Monticulo() {}

template <class T>
Monticulo<T>::~Monticulo() {
  data.clear();
}

template<class T>
Monticulo<T>::Monticulo(T val) {
  data.push_back(val);
  make_heap(data.begin(), data.end());
}

template<class T>
void Monticulo<T>::insert(T val) {
  //para duplicados
  if(find(data.begin(), data.end(), val) != data.end()){
    return;
  }
  data.push_back(val);
  push_heap(data.begin(), data.end());
}

template<class T>
void Monticulo<T>::erase(T val) {
  if (data.empty()) return;
  typename vector<T>::iterator it = find(data.begin(), data.end(), val);
  if (it != data.end()) {
    swap(*it, data.back());
    data.pop_back();
    make_heap(data.begin(), data.end());
  }
}

template <class T>
void Monticulo<T>::inordenEnLista(list<T>& lista) {
  vector<T> copia = data;          // copia para no dañar el heap original
  sort(copia.begin(), copia.end()); // ordena de menor a mayor pq es MaxHeap
  lista.insert(lista.end(), copia.begin(), copia.end());
}

#endif