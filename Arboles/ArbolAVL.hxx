#ifndef ARBOLAVL_HXX
#define ARBOLAVL_HXX

#include "ArbolAVL.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>
ArbolAVL<T>::ArbolAVL() {
    this->raiz=NULL;
}

template <class T>
ArbolAVL<T>::~ArbolAVL() {
    if(this->raiz != NULL){
        delete this->raiz;
        this->raiz=NULL;
    }
}

template <class T>
bool ArbolAVL<T>::esVacio() {
    return this->raiz==NULL;
}

template <class T>
T ArbolAVL<T>::datoRaiz() {
    return this->raiz->obtenerDato();
}

template <class T>
int ArbolAVL<T>::altura() {
    if(this->esVacio()){
        return -1;
    } else {
        return this->raiz->altura();
    }
}

template <class T>
int ArbolAVL<T>::tamano() {
    if(this->esVacio()){
        return 0;
    } else {
        return this->raiz->tamano();
    }
}

template <class T>
bool ArbolAVL<T>::insertar(T val) {
    bool insertado = false;
    this->raiz = insertarAVL(this->raiz, val, insertado);
    return insertado;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::insertarAVL(NodoBinario<T>* nodo, T val, bool& insertado){

    if(nodo == NULL){
        insertado = true;
        return new NodoBinario<T>(val);
    }

    if(val < nodo->obtenerDato()){
        nodo->fijarHijoIzq(insertarAVL(nodo->obtenerHijoIzq(), val, insertado));
    }
    else if(val > nodo->obtenerDato()){
        nodo->fijarHijoDer(insertarAVL(nodo->obtenerHijoDer(), val, insertado));
    }
    else{
        insertado = false; // duplicado
        return nodo;
    }
    //de abajo para arriba
    return balancear(nodo);
}

template <class T>
bool ArbolAVL<T>::eliminar(T val){
    bool eliminado = false;
    this->raiz = eliminarAVL(this->raiz, val, eliminado);
    return eliminado;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::eliminarAVL(NodoBinario<T>* nodo, T val, bool& eliminado){

    if(nodo == NULL){
        eliminado = false;
        return NULL;
    }

    if(val < nodo->obtenerDato()){
        nodo->fijarHijoIzq(eliminarAVL(nodo->obtenerHijoIzq(), val, eliminado));
    }
    else if(val > nodo->obtenerDato()){
        nodo->fijarHijoDer(eliminarAVL(nodo->obtenerHijoDer(), val, eliminado));
    }
    else{
        eliminado = true;

        // Caso 1: hoja
        if(nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() == NULL){
            delete nodo;
            return NULL;
        }

        // Caso 2: un hijo
        if(nodo->obtenerHijoIzq() == NULL){
            NodoBinario<T>* temp = nodo->obtenerHijoDer();
            nodo->fijarHijoDer(NULL);
            delete nodo;
            return temp;
        }

        if(nodo->obtenerHijoDer() == NULL){
            NodoBinario<T>* temp = nodo->obtenerHijoIzq();
            nodo->fijarHijoIzq(NULL);
            delete nodo;
            return temp;
        }

        // Caso 3: dos hijos
        NodoBinario<T>* reemplazo = nodo->obtenerHijoIzq();

        while(reemplazo->obtenerHijoDer() != NULL){
            reemplazo = reemplazo->obtenerHijoDer();
        }

        nodo->fijarDato(reemplazo->obtenerDato());

        nodo->fijarHijoIzq(
            eliminarAVL(nodo->obtenerHijoIzq(), reemplazo->obtenerDato(), eliminado)
        );
    }

    return balancear(nodo);
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarDerecha(NodoBinario<T>* nodo){

    NodoBinario<T>* n_padre = nodo->obtenerHijoIzq();
    nodo->fijarHijoIzq(n_padre->obtenerHijoDer());
    n_padre->fijarHijoDer(nodo);
    
    return n_padre;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarIzquierda(NodoBinario<T>* nodo){

    NodoBinario<T>* n_padre = nodo->obtenerHijoDer();
    nodo->fijarHijoDer(n_padre->obtenerHijoIzq());
    n_padre->fijarHijoIzq(nodo);
    
    return n_padre;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarIzqDer(NodoBinario<T>* nodo) {
    nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
    return rotarDerecha(nodo);
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarDerIzq(NodoBinario<T>* nodo) {
    nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
    return rotarIzquierda(nodo);
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::balancear(NodoBinario<T>* nodo){

    int diferencia = obtenerBalance(nodo);

    if(diferencia == 2){
        NodoBinario<T>* hijoIzq = nodo->obtenerHijoIzq();
        int dif_hijo = obtenerBalance(hijoIzq);

        if(dif_hijo >= 0){
            return rotarDerecha(nodo);
        } else {
            return rotarIzqDer(nodo);
        }
    }

    if(diferencia == -2){
        NodoBinario<T>* hijoDer = nodo->obtenerHijoDer();
        int dif_hijo = obtenerBalance(hijoDer);

        if(dif_hijo <= 0){
            return rotarIzquierda(nodo);
        } else {
            return rotarDerIzq(nodo);
        }
    }

    return nodo;
}

template <class T>
int ArbolAVL<T>::obtenerBalance(NodoBinario<T>* nodo){
    
    int h_hijoIzq, h_hijoDer, diferencia;

    if(nodo == NULL) return 0;

    if(nodo->obtenerHijoIzq()==NULL){
        h_hijoIzq=-1;
    } else {
        h_hijoIzq = nodo->obtenerHijoIzq()->altura();
    }

    if(nodo->obtenerHijoDer()==NULL){
        h_hijoDer=-1;
    } else {
        h_hijoDer = nodo->obtenerHijoDer()->altura();
    }

    diferencia = h_hijoIzq - h_hijoDer;

    return diferencia;

}


template <class T>
bool ArbolAVL<T>::buscar(T val) {

    if(this->esVacio()){
        return false;
    }

    NodoBinario<T>* nodo = this->raiz;

    bool encontrado=false;

    while(!encontrado && nodo!=NULL){

        if(val > nodo->obtenerDato()){
            nodo=nodo->obtenerHijoDer();
        } else if (val < nodo->obtenerDato()){
            nodo=nodo->obtenerHijoIzq();
        } else {
            encontrado = true;
        }

    }
        
     return encontrado;

}

template <class T>
void ArbolAVL<T>::preOrden() {
    if(!this->esVacio()){
        this->raiz->preOrden();
    }
}

template <class T>
void ArbolAVL<T>::inOrden() {
    if(!this->esVacio()){
        this->raiz->inOrden();
    }
}

template <class T>
void ArbolAVL<T>::posOrden() {
    if(!this->esVacio()){
        this->raiz->posOrden();
    }
}

template <class T>
void ArbolAVL<T>::nivelOrden(){

    if(!this->esVacio()){
        queue<NodoBinario<T>*> cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while(!cola.empty()){
            nodo=cola.front();
            cola.pop();
            cout<<nodo->obtenerDato()<<" ";
            if(nodo->obtenerHijoIzq()!=NULL){
                cola.push(nodo->obtenerHijoIzq());
            }
            if(nodo->obtenerHijoDer()!=NULL){
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}

#endif