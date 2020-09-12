//
//  LinkedList.h
//  Estructuras
//
//  Created by Aby Velazquez on 09/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
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
    
    void addFirst(T data){
        Node<T> * newNode= new Node<T>(data);
        newNode->pNext=Head;
        Head=newNode;
        
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
    
    /// Método intercambiarDatos
    /// Parámetro: dos apuntadores de tipo nodo.
    /// Descripción: Intercambia los datos entre nodos.
    void intercambiarDatos(Node<T> *a, Node<T> *b){
        if (a !=NULL && b!=NULL) {
            T aux= a->data;
            a->data = b->data;
            b->data= aux;
        }
    }
    
    
    
    /// Método reverse
    /// Parámetro: ninguno
    /// Descripción: Invierte el contenido de la lista encadenada, no tiene retornos.
    void reverse(){
        if (Head!=NULL) {
            Node<T> *y = Head;
            Node<T> * x= Head;
            int contador = 0;
            int start = 0;
            int end =getSize()-1;
            while (start<end) {
                while (contador < end) {
                    y= y->pNext;
                    contador++;
                }
                intercambiarDatos(x, y);
                x=x->pNext;
                y=Head;
                start++;
                end--;
                contador =0;
            }
        }
    }
    
    /// Método shift
    /// Parámetro: un numero entero.
    /// Descripción: hace un corrimiento de x casillas en la lista encadenada. Si int es 2, la cero pasa a ser la 2 , la 1 la 3 y así en forma circular. Si int es -1 la cero pasa a ser la última, la 1 la cero y así sucesivamente, no tiene retornos.
    void shift(int x){
        int cont1=0;
        int cont2=0;
        if (Head!=NULL) {
            Node<T> * pAux= Head;
            Node<T> *nodeAux = new Node<T>(Head->data);
            int numNodos = getSize();
            if (x<0)
                x=getSize()+x;
            while (cont1<numNodos) {
               while (cont2<x) {
                    if (pAux->pNext!=NULL) {
                        pAux=pAux->pNext;
                        cont2++;
                    }else{
                        pAux=Head;
                        cont2++;
                    }
                }
                intercambiarDatos(pAux, nodeAux);
                cont2=0;
                cont1++;
            }
            delete nodeAux;
            }
    }
    
    /// Operator ==
    /// Parámetro: la lista L con la que se compara la otra lista (que se pasa por referencia).
    /// Descripción: Revisa si dos listas encadenadas tienen el mismo contenido y en el mismo orden.
    bool operator ==(LinkedList &L){
        int aux=0;
        int cont = 0;
        if (this->getSize() == L.getSize()) {
            if (this->Head!=NULL &&  L.Head!=NULL) {
                 Node<T> * pL1 = this->Head;
                 Node<T> * pL2 = L.Head;
                // el auxiliar ayuda a que deje de comparar nodos al momento
                // en que encuentra uno diferente y así, no llega hasta el final
                 while (cont<getSize() && aux==0) {
                     if (pL1->data != pL2->data) {
                         aux ++;
                        
                     }
                      pL1 = pL1->pNext;
                      pL2 = pL2->pNext;
                      cont++;
                 }
                if (aux==0) {
                    return true;
                }else{
                    return false;
                }
            }else if (this->Head==NULL &&  L.Head==NULL){
                return true;
            }
            else{
                return false;
            }
        }else{
            return false;
        }
   }
    
    
    void operator+=(const LinkedList<T>& L2){
       Node<T> *pp= Head;
        Node<T> *pp2= L2.Head;

        if (L2.Head==NULL) {
            return;
        }
        else {
            if (Head==NULL) {
                Head = new Node<T>(pp2->data);
                pp=Head;
            }else{
                while (pp->pNext!=NULL) {
                    pp=pp->pNext;
                }
                pp->pNext=new Node<T>(pp2->data);
                pp=pp->pNext;
            }
            while (pp2->pNext!=NULL) {
            pp2=pp2->pNext;
            pp->pNext=new Node<T>(pp2->data);
            pp=pp->pNext;
            }
        }
    }
    
    
    
    
    
    /// Método remove
    /// Parámetro: dos numeros : x & y de tipo entero.
    /// Descripción: Borra x nodos a partir de la posición y( o sea el elemento y también se borra). Se valida que haya
    /// suficientes nodos para borra a partir de la posición y, en caso de que x sea mayor a la cantidad de nodos que
    /// quedan a partir de la posición, se borran todos los que quedan.
    void remove(int x, int y){
        Node<T>*pp = Head;
        Node<T>*pp2 = Head;
        Node<T> *aux = NULL;
        int cont=0;
        int sizeInic=getSize();
        if (Head!=NULL) {
            //si el numero de nodos que se requiere borrar es mayor a los nodos que quedan
            // se redefine x para que sea igual a los que quedan
            if ((y+x)>sizeInic) {
                x=sizeInic-y;
            }
            while (cont<x) {
                // resetea los apuntadores al inicio despues de que se elimina un nodo
                pp=Head;
                pp2=Head;
                // Proceso de borrado si se requiere borrar nodos desde nodo Head
                if (y==0) {
                    if (Head->pNext!=NULL) {
                        Head= Head->pNext;
                        delete pp;
                        cont++;
                    } else {
                        delete pp;
                        Head=NULL;
                        cont++;
                    }
                   
                }
                // Proceso de borrado si se requiere borrar nodos intermedios
                else if((y+x)<sizeInic&&y>0) {
                    for (int i = 0; i<(y-1); i++) {
                        pp=pp->pNext;
                    }
                    pp2=pp->pNext;
                    pp->pNext = pp2->pNext;
                    delete pp2;
                    cont++;
                    
                }
                // Proceso de borrado si se requiere borrar desde un nodo hasta el final
                // de la lista, es decir, si se borra desde el último
                else if ((y+x)>=sizeInic){
                   // x=sizeInic-y;
                    while (pp->pNext!=NULL) {
                        aux=pp;
                        pp=pp->pNext;
                    }
                    delete pp;
                    if (aux!=NULL) {
                        aux->pNext=NULL;
                    } else {
                        Head=NULL;
                    }
                    cont++;
                }
            }
        }
    }
        
        
        
        
    
    
    
    
    
    

};


#endif /* LinkedList_h */
