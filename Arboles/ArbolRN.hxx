#ifndef ARBOLRN_HXX
#define ARBOLRN_HXX

#include "ArbolRN.h"

template <class T>
ArbolRN<T>::ArbolRN() {
}

template <class T>
ArbolRN<T>::~ArbolRN() {
    datos.clear();
}

template <class T>
bool ArbolRN<T>::esVacio() {
    return datos.empty();
}

template <class T>
int ArbolRN<T>::tamano() {
    return datos.size();
}

template <class T>
void ArbolRN<T>::insert(T val) {
    datos.insert(val);
}

template <class T>
void ArbolRN<T>::erase(T val) {
    datos.erase(val);
}

template <class T>
bool ArbolRN<T>::buscar(T val) {
    return datos.find(val) != datos.end();
}

template <class T>
void ArbolRN<T>::inordenEnLista(list<T>& lista) {

    typename set<T>::iterator it;

    for (it = datos.begin(); it != datos.end(); ++it) {
        lista.push_back(*it);
    }
}

#endif