#ifndef NODOBINARIO_HXX
#define NODOBINARIO_HXX

#include "NodoBinario.h"
#include <iterator>
#include <iostream>

template <class T>
NodoBinario<T>::NodoBinario() {
    
}

template <class T>
NodoBinario<T>::NodoBinario(T val) {
    
}

template <class T>
NodoBinario<T>::~NodoBinario() {
    
}

template <class T>
T NodoBinario<T>::obtenerDato() {
    
}

template <class T>
void NodoBinario<T>::fijarDato(T val) {
    
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq) {
    
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der) {
    
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
void NodoBinario<T>::inOrden(){

    if(this->hijoIzq != NULL){
        this->hijoIzq->inOrden();
    }

    cout << this->dato << " ";

    if(this->hijoDer != NULL){
        this->hijoDer->inOrden();
    }
}

#endif