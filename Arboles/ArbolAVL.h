#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include "NodoBinario.h"

template< class T >
class ArbolAVL {
protected:
    NodoBinario<T>* raiz;
public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool insert(T val);
    bool erase(T val);
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();

    NodoBinario<T>* rotarIzquierda(NodoBinario<T>* nodo);
    NodoBinario<T>* rotarDerecha(NodoBinario<T>* nodo);
    NodoBinario<T>* rotarIzqDer(NodoBinario<T>* nodo);
    NodoBinario<T>* rotarDerIzq(NodoBinario<T>* nodo);

    NodoBinario<T>* balancear(NodoBinario<T>* nodo);
    int obtenerBalance(NodoBinario<T>* nodo);

    NodoBinario<T>* insertarAVL(NodoBinario<T>* nodo, T val, bool& insertado);
    NodoBinario<T>* eliminarAVL(NodoBinario<T>* nodo, T val, bool& eliminado);
};

#include "ArbolAVL.hxx"

#endif