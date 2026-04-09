#ifndef NODOBINARIO_HXX
#define NODOBINARIO_HXX

#include "NodoBinario.h"
#include <iostream>

using namespace std;

template <class T>
NodoBinario<T>::NodoBinario() {
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
}

template <class T>
NodoBinario<T>::NodoBinario(T val) {
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
    this->dato=val;
}

template <class T>
NodoBinario<T>::~NodoBinario() {
    if(this->hijoIzq!=NULL){
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }

    if(this->hijoDer!=NULL){
        delete this->hijoDer;
        this->hijoDer = NULL;
    }
    
}

template <class T>
T NodoBinario<T>::obtenerDato() {
    return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T val) {
    this->dato=val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    return this->hijoDer;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq) {
    this->hijoIzq=izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der) {
    this->hijoDer=der;
}

template <class T>
bool NodoBinario<T>::esHoja() {

    if(this->hijoIzq==NULL && this->hijoDer==NULL){
        return true;
    }

    return false;
}

template<class T>
int NodoBinario<T>::altura(){

    int altura;

    if(this->esHoja()){
        altura = 0;
        return altura;
    } else {

        int alturaHI;
        int alturaHD;

        if(this->hijoIzq==NULL){
            alturaHI=-1;
        } else {
             alturaHI= this->hijoIzq->altura();
        }

        if(this->hijoDer==NULL){
            alturaHD=-1;   
        } else {
            alturaHD= this->hijoDer->altura();
        }

        if(alturaHI > alturaHD){
            altura=alturaHI;
        } else {
            altura=alturaHD;
        }

    }
    altura+=1;
    return altura;
}

template<class T>
int NodoBinario<T>::tamano(){
    int tamano = 1;

    if(this->hijoIzq != NULL){
        tamano += this->hijoIzq->tamano();
    }

    if(this->hijoDer != NULL){
        tamano += this->hijoDer->tamano();
    }

    return tamano;

}


template<class T>
void NodoBinario<T>::inOrden(){

    if(this->hijoIzq != NULL){
        this->hijoIzq->inOrden();
    }

    cout << this->dato << " ";

    if(this->hijoDer != NULL){
        this->hijoDer->inOrden();
    }
}

template<class T>
void NodoBinario<T>::preOrden(){

    cout<<this->dato<<" ";

    if(this->hijoIzq != NULL){
        this->hijoIzq->preOrden();
    }

    if(this->hijoDer != NULL){
        this->hijoDer->preOrden();
    }

}

template<class T>
void NodoBinario<T>::posOrden(){

    if(this->hijoIzq != NULL){
        this->hijoIzq->posOrden();
    }

    if(this->hijoDer != NULL){
        this->hijoDer->posOrden();
    }

    cout<<this->dato<<" ";

}

#endif