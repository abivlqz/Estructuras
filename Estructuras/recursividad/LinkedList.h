//

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
    
    Node<T>* getHead(){
        return Head;
    }
    /// Método addFirst
    /// Parámetro: recibe un valor de tipo T
    /// Descripción: crea un nodo con el valor recibido como parámetro y lo coloca al inicio de la lista

    void addFirst(T data){
        Node <T> *pNew = new Node <T>(data);
        pNew->pNext = Head;
        Head = pNew;
    }

    
    /// Método deleteFirst
    /// Parámetro: no recibe nada
    /// Descripción: borra el primer nodo de la lista si hay

    void deleteFirst(){
        
        if (Head!=NULL) {
            Node<T> *paux=Head;
            Head = Head->pNext;
            delete paux;
        }
    }
    
    
   /// Método addLast
    /// Checar si se comporta diferente con o sin nodas
    /// Parámetro: recibe un valor de tipo T
    /// Descripción: crea un nodo con el valor recibido como parámetro y lo coloca al final de la lista
    void addLast(T data){
        
        Node <T> *pNew = new Node <T> (data);
        Node<T>*aux= Head;
        if (Head==NULL)
            Head = pNew;
        else{
            while (aux->pNext!=NULL)
                aux= aux->pNext;
            
            aux->pNext=pNew;
        }
    }

    /// Método deleteLast
    /// Parámetro: no recibe nada
    /// Descripción: borra el primer nodo de la lista si hay

//    void deleteLast(){
//        Node<T> * paux= Head;
//        Node<T> * paux2= NULL;
//        if (paux!=NULL) {
//            while (paux->pNext!=NULL) {
//                paux2 =paux;
//                paux=paux->pNext;
//            }
//            delete paux;
//            if (paux2!=NULL) {
//                paux2->pNext=NULL;
//            }else
//                Head=NULL;
//
//        }
//
//    }
    
    void deleteLast(){
        Node<T> * paux= Head;
        Node<T>*paux2= NULL;
        int contador = 0;
        while (contador<(getSize()-1)) {
                paux2 = paux;
                paux = paux->pNext;
                contador++;
            }
            delete paux;
            if (paux2!=NULL)
              paux2->pNext=NULL;
            else
              Head=NULL;
    }
    
    /// Método addN
    /// Checar si se comporta diferente con o sin nodas
    /// Parámetro: recibe un valor de tipo T y una posicion en la lista P para guardar el elemento
    /// Descripción: crea un nodo con el valor recibido como parámetro y lo coloca en la posicion P
    void addN(T data, int P){

        Node <T> *pNew = new Node <T> (data);
        Node<T>*aux= Head;
        if (P==1) {
            addFirst(data);
        }else{

        if (P<=getSize() && P>0) {
            for (int i =1; i<P-1; i++) {
                aux=aux->pNext;
            }
            pNew->pNext=aux->pNext;
            aux->pNext=pNew;
            
        }

        }

    }

    
    
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




    /// Método getSize
    /// Parámetro: ninguno
    /// Descripción: calcula y regresa la cantidad de nodos.

    int getSize(){
        int contador = 0;
        Node<T> *pP = Head;
        
        while (pP!=NULL) {
            contador++;
            pP= pP->pNext;
        }
        return contador;
    }
    
   // Realiza el métodos eliminaNodo el cual recibe un número entero y borra todos los nodos que contienen dicho número
    
    void eliminaNodo(int x){
        
        if (Head!=NULL) {
            Node<T>* pp = Head;
            
            if (pp->data==x) {
                if (pp->pNext!=NULL) {
                    Head=Head->pNext;
                    delete pp;
                    pp=Head;
                }else{
                    delete pp;
                    Head = NULL;
                }
               
            }
            while (pp->pNext!=NULL) {
                if (pp->data==x) {
                    
                }
            }
        }
        
        
        
    }
    
    
    int sumaCuadrados(){
        Node<T>* Inicio= Head;
       return sumCuadrados(Inicio);
        
    }
    
    
    int sumCuadrados(Node<T>* pP){
        if (pP==NULL)
            return 0;
        else
        return ((pP->data)*(pP->data)+sumCuadrados(pP->pNext));
    }
    int min (int a, int b){
        if (a<b)
            return a;
        else
            return b;
        
    }
    
    int minValor(Node<T>*pP){
       if (pP!=NULL) {
           return min(pP->data, minValor(pP->pNext));
        }
       
       return 10000;
     
        
    }

};

#endif // LINKEDLIST_H_INCLUDED




