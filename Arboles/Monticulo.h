#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <class T>
class Monticulo {
    private:
    vector<T> data;

    public:
    Monticulo();
    ~Monticulo();
    Monticulo(T val);
    void insert(T val);
    void erase(T val);
    list<T> inOrder();
    void inordenEnLista(list<T>& lista);;

};

#include "Monticulo.hxx"
#endif
