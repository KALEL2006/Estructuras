#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__

#include <list>

using namespace std;

template <class T>
class NodoGeneral {
    protected:
        T dato;
        list<NodoGeneral<T>*> desc;
    public:
        NodoGeneral();
        ~NodoGeneral();
        T& obtenerDato();
        void fijarDato(T& val);
        void limpiarLista();
        void adicionarDesc(T& val);
        bool eliminarDesc(T& val);
        bool esHoja();
        int altura();
        void preOrden();
        void posOrden();
        void nivelOrden();
        bool insertarNodo(T padre, T n);
        bool eliminarNodo(T n);
        bool buscarNodo(T n);
};

#include "NodoGeneral.hxx"

#endif