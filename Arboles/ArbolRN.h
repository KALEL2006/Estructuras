#ifndef __ARBOLRN_H__
#define __ARBOLRN_H__

#include <iostream>
#include <set>
#include <list>

using namespace std;

template< class T >
class ArbolRN {
protected:
    set<T> datos;
public:
    ArbolRN();
    ~ArbolRN();
    bool esVacio();
    int tamano();
    void insert(T val);
    void erase(T val);
    bool buscar(T val);
    void inordenEnLista(list<T>& lista);
};

#include "ArbolRN.hxx"
#endif