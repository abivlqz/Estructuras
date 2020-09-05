/// 2 Septiembre 2020
/// Created by : Ing. Delia Castro


#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>

/// clase Nodo, el cual guarda un atributo de cualquier tipo y un apuntador a otra estructura igual del mismo tipo
class Node{
public://Todo publico para poder acceder desde la clase LinkedList
   ///atributos
    T data;
    Node <T> *pNext;
    ///constructores
    Node (){
        pNext=NULL;
    }
    Node ( T data){
        this->data = data;
        pNext=NULL;
    }
};

///clase Linkedlisy cuyo atributo es un apuntador al inicio de la estructura, la cual estara formada por cero, uno o varios nodos
template <class T>
class LinkedList{
private:
    Node <T> *Head;
public:
    /// Constructor que inicializa el apuntador (atributo a NULL)
    LinkedList(){
        Head=NULL;
    }
    /// Desctructor, libera la memoria de todos los nodos que tenga
    ~LinkedList(){
        Node <T> *pAux = Head;
        while (pAux != NULL){
                Head = Head->pNext;
                delete pAux;
                pAux = Head;
        }
    }
    /// Método addFirst
    /// Parámetro: recibe un valor de tipo T
    /// Descripción: crea un nodo con el valor recibido como parámetro y lo coloca al inicio de la lista

    void addFirst(T data){
        Node <T> *pNew = new Node <T>(data);
        pNew->pNext = Head;
        Head = pNew;
    }

   /// Método addLast
    /// Parámetro: recibe un valor de tipo T
    /// Descripción: crea un nodo con el valor recibido como parámetro y lo coloca al final de la lista
//    void addLast(T data){
//        //Node <T> *pNew = new Node <T> (data);
//
//
//    }

    /// Método printList
    /// Parámetro: ninguno
    /// Descripción: Muestra el contenido de los nodos de la lista
    void printList(){
        Node<T> * pP = Head;
        while (pP!=NULL) {
            cout<<pP->data<<"--->";
            pP= pP->pNext;
        }
    }

};

#endif // LINKEDLIST_H_INCLUDED

