#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
///Arbol heap implementado como arreglo
#include <iostream>
using namespace std;

class Heap{
private:
    int capacidad; //capacidad máximo del heap
    int *arr; //pointer a un arreglo de enteros donde
    int heapTam; // va tomando el tamaño actual del heap
public:
    Heap(int capacidad){
        this->capacidad = capacidad;
        arr=new int[capacidad];
        heapTam=0;
    }

    ///método que regresa el padre de un nodo
    int padre(int nodo){
        return nodo/2;
    }
 ///método para regresar el hijo izquierdo de un nodo
 ///Parametro un entero del nodo del cual se desea el hijo izquierdo
 int hijoIzq(int nodo){
    return 2 * nodo;
 }

 ///método para regresar el hijo derecho de un nodo
 ///Parametro el valor entero del nodo del cual se desea el hijo derecho
    int hijoDer(int nodo){
        return (2*nodo) +1;
    }


 ///Método para insertar un valor
 ///Parametro un entero que representa el valor a insertar
    void insertaValor(int valor){
        
        arr[heapTam+1]=valor;
        //cout<<arr[0]<<endl;
        heapTam+=1;
        int i =heapTam;
        while( (arr[padre(i)]) < (arr[i]) ){
         int aux= arr[padre(i)];
            
            arr[padre(i)]=arr[i];
            arr[i]=aux;
            i=padre(i);
            
        }
        
      
       
    }
    
    


 /// Metodo ImprimirHeap
 /// Imprime los valores de los nodos del Heap usando el arreglo
 void imprimirHeap(){
    if (heapTam > 0){
         for (int i=0;i<=heapTam-1;i++)
            cout<<arr[i]<<" ";
         cout<<endl;
    }

     
 }

};



#endif // HEAP_H_INCLUDED
