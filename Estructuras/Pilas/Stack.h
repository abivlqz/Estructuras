#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;
//Creamos la clase nodo
template <class T>
class Nodo{
public:
    T dato;
    Nodo <T> *pSig;
    Nodo <T> (){pSig=NULL;}
    Nodo <T>(T dato){
        this->dato=dato;
        pSig=NULL;}
};
template <class T>
class Stack{
public:
    //Constructor
    Stack(){
        pTope=NULL;
    }
    // Destructor
    ~Stack(){
        while (pTope!=NULL)
            pop();
    }
    //Agrega nodos al inicio
    void push(T valor){
        Nodo <T> *pP= new Nodo <T>(valor);
        pP->pSig=pTope;
        pTope=pP;
    }

    //Mostrar lista
    void mostrar(){
        Nodo <T> *pQ=pTope;
        while (pQ != NULL){
            cout<<pQ->dato<<" ";
            pQ=pQ->pSig;
        }
        cout<<endl;
    }
    //Borrar el primer nodo de la lista
    void pop(){
        if (pTope != NULL){
            Nodo <T> *pP = pTope;
            pTope=pTope->pSig;
            delete pP;
        }
    }

    T peek(){
        if (pTope!=NULL)
            return pTope->dato;
        else
            return 0;
    }
    bool isEmpty(){
        return pTope==NULL;
    }

private:
    Nodo <T> *pTope;
};


#endif // STACK_H_INCLUDED

