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

    NodoBinario<T>* nuevo = new NodoBinario<T>;
    nuevo->fijarDato(val);

    if(this->esVacio()){
        this->raiz=nuevo;
        return true;
    }

    NodoBinario<T>* nodo = this->raiz;

    while(!insertado && nodo!=NULL){

        if(val > nodo->obtenerDato()){

            if(nodo->obtenerHijoDer()!=NULL){
                nodo=nodo->obtenerHijoDer();
            } else {
                nodo->fijarHijoDer(nuevo);
                insertado=true;
            }

        } else if (val < nodo->obtenerDato()){
            
            if(nodo->obtenerHijoIzq()!=NULL){
                nodo=nodo->obtenerHijoIzq();
            } else {
                nodo->fijarHijoIzq(nuevo);
                insertado=true;
            }
        } else {
            delete nuevo;
            insertado = false;
            break;
        }

    }
        
     return insertado;
}

template <class T>
bool ArbolAVL<T>::eliminar(T val) {

    if(this->esVacio()){
        return false;
    }

    NodoBinario<T>* padre = NULL;
    NodoBinario<T>* nodo = this->raiz;

    // Buscar
    while(nodo != NULL && nodo->obtenerDato() != val){
        padre = nodo;

        if(val < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        } else {
            nodo = nodo->obtenerHijoDer();
        }
    }

    if(nodo == NULL){
        return false;
    }

    // Caso 3: dos hijos (máximo del subárbol izquierdo)
    if(nodo->obtenerHijoIzq() != NULL && nodo->obtenerHijoDer() != NULL){

        NodoBinario<T>* padreReemp = nodo;
        NodoBinario<T>* reemplazo = nodo->obtenerHijoIzq();

        while(reemplazo->obtenerHijoDer() != NULL){
            padreReemp = reemplazo;
            reemplazo = reemplazo->obtenerHijoDer();
        }

        nodo->fijarDato(reemplazo->obtenerDato());

        padre = padreReemp;
        nodo = reemplazo;
    }

    // Caso 1: hoja
    if(nodo->esHoja()){
        if(padre == NULL){
            this->raiz = NULL;
        }
        else if(padre->obtenerHijoIzq() == nodo){
            padre->fijarHijoIzq(NULL);
        }
        else{
            padre->fijarHijoDer(NULL);
        }

        delete nodo;
        return true;
    }

    // Caso 2: un hijo
    NodoBinario<T>* hijo;

    if(nodo->obtenerHijoIzq() != NULL){
        hijo = nodo->obtenerHijoIzq();
    } else {
        hijo = nodo->obtenerHijoDer();
    }

    if(padre == NULL){
        this->raiz = hijo;
    }
    else if(padre->obtenerHijoIzq() == nodo){
        padre->fijarHijoIzq(hijo);
    }
    else{
        padre->fijarHijoDer(hijo);
    }

    nodo->fijarHijoIzq(NULL);
    nodo->fijarHijoDer(NULL);
    delete nodo;
    return true;
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