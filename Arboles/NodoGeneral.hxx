#ifndef NODOGENERAL_HXX
#define NODOGENERAL_HXX

#include "NodoGeneral.h"
#include <queue>

template <class T>
NodoGeneral<T>:: NodoGeneral(){
    this->desc.clear();
}

template <class T>
NodoGeneral<T>:: ~NodoGeneral(){
    list<NodoGeneral<T>*>::iterator it=this->desc.begin();

    for(; it != this->desc.end(); it++){
        delete *it;
    }

    this->desc.clear();
}

template<class T>
T& NodoGeneral<T>::obtenerDato(){
    return this->dato;
}

template<class T>
void NodoGeneral<T>::fijarDato(T& val){
    this->dato = val;
}

template<class T>
void NodoGeneral<T>::limpiarLista(){
    this->desc.clear();
}

template<class T>
void NodoGeneral<T>::adicionarDesc(T& val){
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->desc.push_back(nodo);
}

template<class T>
bool NodoGeneral<T>::insertarNodo(T padre, T n){
    if(this->obtenerDato()==padre){
        this->adicionarDesc(n);
        return true;
    } else {
        list<NodoGeneral<T>*>::iterator it=this->desc.begin();

        for(; it != this->desc.end(); it++){
            if((*it)->insertarNodo(padre, n)){
                return true;
            }
        }
    }
    return false;
}

template<class T>
bool NodoGeneral<T>::eliminarNodo(T n){

    list<NodoGeneral<T>*>::iterator it=this->desc.begin();

    for(; it != this->desc.end(); it++){

        if((*it)->obtenerDato()==n){
            return this->eliminarDesc(n);
        } else {
            if((*it)->eliminarNodo(n)){
                return true;
            }
            
        }

    }
    return false;
}

template<class T>
bool NodoGeneral<T>::eliminarDesc(T& val){

    list<NodoGeneral<T>*>::iterator it=this->desc.begin();
    NodoGeneral<T>* nodo;
    bool eliminado = false;

    for(; it != this->desc.end(); it++){
        nodo=*it;
        if(nodo->obtenerDato()==val){
            break;
        }
    }

    if(it != this->desc.end()){
        delete *it;
        this->desc.erase(it);
        eliminado=true;
    }
    
    return eliminado;

}

template<class T>
bool NodoGeneral<T>::buscarNodo(T n){
    if(this->obtenerDato()==n){
        return true;
    }

    list<NodoGeneral<T>*>::iterator it=this->desc.begin();

    for(; it != this->desc.end(); it++){
        if((*it)->buscarNodo(n)){
            return true;
        }
    }
    return false;
}

template<class T>
bool NodoGeneral<T>::esHoja(){
    return this->desc.empty();
}

template<class T>
int NodoGeneral<T>::altura(){

    int altura=-1;

    if(this->esHoja()){
        altura=0;
    } else {
        int alturaH;
        list<NodoGeneral<T>*>::iterator it = this->desc.begin();

        for(; it!=this->desc.end();it++){
            alturaH=(*it)->altura();
            if(alturaH > altura){
                altura = alturaH;
            }
        }
    }

    altura+=1;

    return altura;
}

template<class T>
void NodoGeneral<T>::preOrden(){

    cout<<this->obtenerDato()<<" ";

    list<NodoGeneral<T>*>::iterator it = this->desc.begin();

    for(; it!=this->desc.end(); it++){
        (*it)->preOrden();
    }

}

template<class T>
void NodoGeneral<T>::posOrden(){

    list<NodoGeneral<T>*>::iterator it = this->desc.begin();

    for(; it!=this->desc.end(); it++){
        (*it)->posOrden();
    }

    cout<<this->obtenerDato()<<" ";

}

template<class T>
void NodoGeneral<T>::nivelOrden(){

    queue<NodoGeneral<T>*> cola;

    cola.push(this);

    while(!cola.empty()){

        cout<<(cola.front())->obtenerDato()<<" ";

        for( list<NodoGeneral<T>*>::iterator it = (cola.front())->desc.begin(); it!=(cola.front())->desc.end(); it++){
            cola.push(*it);
        }

        cola.pop();

    }

}

#endif
