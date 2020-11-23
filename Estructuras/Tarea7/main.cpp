//  Tarea7
//  main.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 13/10/2020
//  Este programa incluye use cases de los siguientes metodos añadidos al Header
//  LinkedList: reverse, shift, operator ==, operator +=, remove.
//

#include <stdio.h>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    
    
    LinkedList<int>L1;
    LinkedList<int>L2;
    L1.addFirst(12);
    L1.addFirst(10);
    L1.addFirst(7);
    L1.addFirst(3);
    L1.addFirst(1);
//    cout<<"Lista original :"<<endl;
//    L1.printList();
//    cout<<endl;
//    cout<<"--------------------------"<<endl;
//    cout<<"Lista invertida(despues del metodo reverse):"<<endl;
//    L1.reverse();
//    L1.printList();
//    cout<<endl;
//    cout<<"--------------------------"<<endl;
//    cout<<"Lista recorrida(metodo shift) con int=3:"<<endl;
//    L1.shift(3);
//    L1.printList();
//    cout<<endl;
//    cout<<"Lista recorrida(metodo shift) con int=-2:"<<endl;
//    L1.shift(-2);
//    L1.printList();
//    cout<<endl;
//    cout<<"--------------------------"<<endl;
//    cout<<"Lista con nodos eliminados(metodo remove)"<<endl;
//    cout<<" borra x nodos a partir de la posicion y (borra desde y)"<<endl;
//    cout<<"con int x = 2, int y = 1   :"<<endl;
//    L1.remove(2, 1);
//    L1.printList();
//    cout<<endl;
//    cout<<"Lista con nodos eliminados(metodo remove)"<<endl;
//    cout<<" borra x nodos a partir de la posicion y (borra desde y)"<<endl;
//    cout<<"con int x = 5, int y = 2   :"<<endl;
//    L1.remove(5, 2);
//    L1.printList();
//    L2.addFirst(7);
//    L2.addFirst(1);
//    cout<<endl;
//    cout<<"--------------------------"<<endl;
//    cout<<"Comprueba que dos listas son iguales(operator ==): "<<endl;
//    cout<<"Lista 1 :";
//    L1.printList();
//    cout<<endl;
//    cout<<"Lista 2 :";
//    L2.printList();
//    cout<<endl;
//    if (L1==L2) {
//        cout<<"Las listas son iguales "<<endl;
//    }else{
//          cout<<"Las listas No son iguales "<<endl;
//    }
//    L1.addFirst(5);
//    cout<<"Lista 1 :";
//    L1.printList();
//    cout<<endl;
//    cout<<"Lista 2 :";
//    L2.printList();
//    cout<<endl;
//    if (L1==L2) {
//        cout<<"Las listas son iguales "<<endl;
//    }else{
//          cout<<"Las listas No son iguales "<<endl;
//    }
//    cout<<"--------------------------"<<endl;
//    cout<<"Concatena Lista 2 al final de Lista 1(operator +=):"<<endl;
//    L1+=L2;
//    L1.printList();
//    cout<<endl;
    
    cout<<L1.Acumula(20)<<endl;
    
    return 0;
}
