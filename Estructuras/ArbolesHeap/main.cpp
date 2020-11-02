
#include <iostream>

using namespace std;
#include "Heap.h"
int main()
{
    int cantidad;
    cout<<"Dame el tamaño del heap "<<endl;
    cin>>cantidad;
    Heap h(cantidad);
    h.insertaValor(2);
    h.insertaValor(4);
    h.insertaValor(1);
    h.insertaValor(5);
    h.imprimirHeap();
    return 0;
}

