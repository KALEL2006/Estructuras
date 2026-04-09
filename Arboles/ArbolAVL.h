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
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolAVL.hxx"

#endif