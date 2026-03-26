#ifndef ARBOLBINARIOORD_HXX
#define ARBOLBINARIOORD_HXX

#include "ArbolBinarioOrd.h"
#include <iterator>
#include <iostream>

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd() {
    this->raiz=NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd() {
    if(this->raiz != NULL){
        delete this->raiz;
        this->raiz=NULL;
    }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio() {
    return this->raiz=NULL;
}

template <class T>
T ArbolBinarioOrd<T>::datoRaiz() {
    return this->raiz->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::altura() {
    if(this->esVacio()){
        return -1;
    } else {
        return this->raiz->altura();
    }
}

template <class T>
int ArbolBinarioOrd<T>::tamano() {
    
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(T val) {
    
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val) {
    
}

template <class T>
bool ArbolBinarioOrd<T>::buscar(T val) {
    
}

template <class T>
void ArbolBinarioOrd<T>::preOrden() {
    
}

template <class T>
void ArbolBinarioOrd<T>::inOrden() {
    if(!this->esVacio()){
        this->raiz->inOrden();
    }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden() {
    
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden() {
    
}

#endif