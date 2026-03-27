#ifndef ARBOLGENERAL_HXX
#define ARBOLGENERAL_HXX

#include "ArbolGeneral.h"
#include <iostream>

template <class T>
ArbolGeneral<T>::ArbolGeneral() {
    this->raiz=NULL;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val) {
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);

    this->raiz = nodo;

}

template <class T>
ArbolGeneral<T>::~ArbolGeneral() {

    delete this->raiz;
    this->raiz=NULL;

}

template <class T>
bool ArbolGeneral<T>::esVacio() {
    return this->raiz==NULL;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz() {
    return this->raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz) {
    this->raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n) {

    if(this->esVacio()){
        NodoGeneral<T>* nodo = new NodoGeneral<T>;
        nodo->fijarDato(n);
        this->raiz = nodo;
        return true;
    }

    return this->raiz->insertarNodo(padre, n);

}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n) {
    if(this->esVacio()){
        return false;
    }

    if(this->raiz->obtenerDato() == n) {
        delete this->raiz;
        this->raiz = NULL;
        return true;
    }

    return this->raiz->eliminarNodo(n);

}

template <class T>
bool ArbolGeneral<T>::buscar(T n) {
    if(this->esVacio()) {
        return false;
    }
    return this->raiz->buscarNodo(n);
}

template <class T>
int ArbolGeneral<T>::altura() {

    if(this->esVacio()){
        return -1;
    } else {
        return this->raiz->altura();
    }
}

template <class T>
unsigned int ArbolGeneral<T>::tamano() {
    unsigned int tam=0;
    if(this->esVacio()){
        tam=0;
    } else {
        tam=1;
        typename list<NodoGeneral<T>*>::iterator it = this->raiz->desc.begin();

        for(; it!=this->raiz->desc.end();it++){
            tam+=(*it)->tamano();
        }
    }
    return tam;
}

template <class T>
void ArbolGeneral<T>::preOrden() {
    if(!this->esVacio()){
        this->raiz->preOrden();
    }
}

template <class T>
void ArbolGeneral<T>::posOrden() {
    if(!this->esVacio()){
        this->raiz->posOrden();
    }
}

template <class T>
void ArbolGeneral<T>::nivelOrden() {
    if(!this->esVacio()){
        this->raiz->nivelOrden();
    }
}

#endif