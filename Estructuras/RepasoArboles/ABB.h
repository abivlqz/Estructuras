//
//  ABB.h
//  Estructuras
//
//  Created by Aby Velazquez on 21/10/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#ifndef ABB_h
#define ABB_h

#include <cmath>
#include <iostream>
using namespace std;
class NodeTree{
    public:
    int Data;
    NodeTree *Left,*Right;
    NodeTree(){Left=Right=NULL;}
    NodeTree(int value)
    {Data=value; Left=Right=NULL;}
    
};

class ABB{
private:
    NodeTree* root;
public:
    //Constructor
    ABB(){root=NULL;}
    //Destructor
    ~ABB(){
        NodeTree* pP=root;
        libera(pP);
    }
    // Metodo para realizar el destructor
    void libera(NodeTree* r){
        if (r !=NULL) {
            libera(r->Left);
            libera(r->Right);
             delete r;
        }
    }
    
    NodeTree* encuentraPadre(int iValor){
       NodeTree *pPadre, *pHijo;
        pHijo = root;
        pPadre = NULL;
        while (pHijo != NULL && pHijo->Data != iValor)
        {
            pPadre = pHijo;
            pHijo = (pHijo->Data > iValor ? pHijo->Left : pHijo->Right);
        }
        return pPadre;
        
    }
    
    void meterABB (int iValor)
       {
           NodeTree *pPadre = encuentraPadre(iValor);
           NodeTree *pNuevo = new NodeTree (iValor);
           if( pPadre == NULL) //Agrega el primer nodo del árbol
               root = pNuevo;
           else
           { //Agrega un nodo hoja
               if ( pPadre->Data > iValor )
                   pPadre->Left = pNuevo;
               else
                   pPadre->Right = pNuevo;
           }
       }

    NodeTree* predecesor(NodeTree* pActual){
        NodeTree* pP=pActual->Left;
        while (pP->Right!=NULL)
            pP=pP->Right;
        return pP;
    }
    
    NodeTree * sucesor(NodeTree* pActual){
        NodeTree* pP= pActual->Right;
        while (pP->Left!=NULL) {
            pP=pP->Left;
        }
        return pP;
        
    }
    
    void sacarABB(int iValor)
    {
        NodeTree *pPadre = encuentraPadre(iValor);
        NodeTree *pNodoABorrar;
        if (pPadre == NULL)
            pNodoABorrar = root;
        else
            pNodoABorrar=(pPadre->Data > iValor? pPadre->Left : pPadre->Right);

        ///Encontrar substituto cuando el nodo a borrar tiene 2 hijos
        if (pNodoABorrar->Left != NULL && pNodoABorrar->Right != NULL)
        {
            NodeTree *pSubstituto = predecesor(pNodoABorrar);
            int iNuevovalor = pSubstituto->Data;
            sacarABB (pSubstituto->Data);
            pNodoABorrar->Data = iNuevovalor;
        }
        else if (pPadre == NULL)
        { ///Borra nodo raíz el cual solo tiene un hijo
            if (pNodoABorrar->Right == NULL)
                root = pNodoABorrar->Left;
            else
                root = pNodoABorrar->Right;
        }
        else if (pPadre->Data > iValor)
            ///Borra nodo con 0 o 1 hijo
            if (pNodoABorrar->Left == NULL)
                pPadre->Left = pNodoABorrar->Right;
            else
                pPadre->Left = pNodoABorrar->Left;
        else if (pNodoABorrar->Right == NULL)
            pPadre->Right =pNodoABorrar->Left;
        else
            pPadre->Right = pNodoABorrar->Right;

        delete pNodoABorrar;
    }
    
    //Imprime el arbol
    void Print(){
        NodeTree* pP=root;
        P_Print(pP);
    }
    
    void P_Print(NodeTree* pP){
        if(pP!=NULL){
            cout<<" "<<pP->Data<<endl;
            P_Print(pP->Left);
            P_Print(pP->Right);
        }else
            return;
        
    }
    
    //Metodo Height manda a calcular la altura de un árbol (sus niveles)
    int Height(){
        NodeTree* pP=root;
        return calcularAltura(pP);
    }
    
    int calcularAltura(NodeTree* pP){
        
        if(pP==NULL)
            return 0;
        else
            return(1+max(calcularAltura(pP->Left),calcularAltura(pP->Right)));
    }
    
    int addNodes(){
        NodeTree* pP=root;
        return sumaNodos(pP);
        
    }
    
    int sumaNodos(NodeTree* pP){
        if(pP==NULL)
            return 0;
        else
            return (pP->Data+sumaNodos(pP->Left)+sumaNodos(pP->Right));
        
    }
    
    //Metodo FindValue que regresa un valor booleano si el valor se encuentra en el arbol
    bool findValue(int valor){
        NodeTree * pP = root;
        while (pP!=NULL) {
            if(pP->Data==valor)
                return true;
            else
                pP=(pP->Data>valor?pP->Left:pP->Right);
        }
        return false;
        
    }
    
    //Metodos que cuentan el numero de nodos hoja de un arbol
    int contarNodosHoja(){
        NodeTree* pP= root;
        return nodosHoja(pP);
    }
    int nodosHoja(NodeTree* pP){
        if(pP==NULL)
            return 0;
        else if(pP->Left==NULL && pP->Right==NULL)
            return 1;
        else
            return nodosHoja(pP->Left)+nodosHoja(pP->Right);
    }

    //Metodos que cuentan el numero de nodos padre de un arbol
    int contarNodosPadre(){
        NodeTree* r=root;
        return nodosPadre(r);
    }
    
    int nodosPadre(NodeTree* pP){
        if (pP==NULL)
            return 0;
        else if (pP->Right!= NULL || pP->Left!=NULL)
            return 1+nodosPadre(pP->Right)+nodosPadre(pP->Left);
        else
            return 0;
        
    }
    
    //Metodos que cuentan el numero de nodos padre con un solo hijo
    int contarNodosPadreUnHijo(){
        NodeTree* r = root;
        return nodosPadreUnHijo(r);
    }
    
    int nodosPadreUnHijo(NodeTree *pP){
        if(pP==NULL)
            return 0;
        else if(pP->Left!=NULL && pP->Right==NULL)
            return 1+nodosPadreUnHijo(pP->Left);
        else if (pP->Left==NULL && pP->Right!=NULL)
            return 1+nodosPadreUnHijo(pP->Right);
        else
            return nodosPadreUnHijo(pP->Left)+nodosPadreUnHijo(pP->Right);
    }
    
    //Metodos que cuentan el numero de nodos padre con un solo hijo
       int contarNodosPadreUnHijoIzquierda(){
           NodeTree* r = root;
           return nodosPadreUnHijoIzquierda(r);
       }
       
       int nodosPadreUnHijoIzquierda(NodeTree *pP){
           if(pP==NULL)
               return 0;
           else if(pP->Left!=NULL && pP->Right==NULL)
               return 1+nodosPadreUnHijoIzquierda(pP->Left);
           else
               return nodosPadreUnHijoIzquierda(pP->Left)+nodosPadreUnHijoIzquierda(pP->Right);
       }
    //Metodos que cuentan el numero de nodos padre con un solo hijo
       int contarNodosPadreUnHijoDerecha(){
           NodeTree* r = root;
           return nodosPadreUnHijoDerecha(r);
       }
       
       int nodosPadreUnHijoDerecha(NodeTree *pP){
           if(pP==NULL)
               return 0;
           else if (pP->Left==NULL && pP->Right!=NULL)
               return 1+nodosPadreUnHijoDerecha(pP->Right);
           else
               return nodosPadreUnHijoDerecha(pP->Left)+nodosPadreUnHijoDerecha(pP->Right);
       }
    //Manda a llamar el numero de nodos
    int numeroNodos(){
        NodeTree * r = root;
        return numberNodes(r);
    }
    
//    // Calcula el numero de nodos
//    int numberNodes(NodeTree* pP){
//        if(pP==NULL)
//            return 0;
//        else
//            return (1+numberNodes(pP->Left)+numberNodes(pP->Right));
//
//    }
    
    NodeTree * findNodo(int value){
        NodeTree * pP=root;
        bool found=false;
        while (pP!=NULL && found ==false) {
            if(pP->Data==value)
                found = true;
            else
                pP=(pP->Data>value?pP->Left:pP->Right);
                
        }
        if(found)
            return pP;
        else
            return NULL;
        
    }
    
   
    int numberNodes(NodeTree* pP){
        if(pP==NULL)
            return 0;
        else
            return (1+numberNodes(pP->Left)+numberNodes(pP->Right));
    }
    
    int numNodosMenores(int value){
        NodeTree* pP=findNodo(value);
        if(pP!=NULL){
        pP=pP->Left;
        return numberNodes(pP);
        }
        else return 0;
    }
    
    int numNodosMayores(int value){
      NodeTree * pP=findNodo(value);
        if(pP!=NULL){
        pP=pP->Right;
        return numberNodes(pP);
        }
        else return 0;
    }
    
    int predecesorValor(int value){
        NodeTree* pP=findNodo(value);
        NodeTree* predecesor1=NULL;
        if(pP!=NULL){
            predecesor1= predecesor(pP);
            return predecesor1->Data;
        }
        else return 0;
        
    }
    
    void imprimirPre(){
        NodeTree * r = root;
        printPre(r);
    }
    
    void printPre(NodeTree* r){
        if(r!=NULL){
            cout<<" "<<r->Data;
            printPre(r->Left);
            printPre(r->Right);
        }
        return;
    }
    
    void imprimirIn(){
        NodeTree * r= root;
        printIn(r);
    }
    
    void printIn(NodeTree* r){
        if(r!=NULL){
            printIn(r->Left);
            cout<<" "<<r->Data;
            printIn(r->Right);
        }
        return;
        
    }
    
    void imprimirPost(){
        NodeTree * r= root;
        printPost(r);
    }
    
    void printPost(NodeTree* r){
        if(r!=NULL){
            printPost(r->Left);
            printPost(r->Right);
            cout<<" "<<r->Data;
        }
        return;
        
    }
    
    int nodosRange(int inferior, int superior){
        NodeTree* r = root;
        return calcularNodosRango(r, inferior, superior);
        
    }
    
    int calcularNodosRango(NodeTree* pP, int inf, int sup){
        if(pP==NULL)
            return 0;
        else if(pP->Data>inf && pP->Data<sup)
            return (1+calcularNodosRango(pP->Left, inf, sup)+calcularNodosRango(pP->Right, inf, sup));
        else
            return (calcularNodosRango(pP->Left, inf, sup)+calcularNodosRango(pP->Right, inf, sup));
        
        
    }
    
    int anchura (int nivel){
        NodeTree* pP=root;
        return numNodosNivel(pP, nivel);
    }
    
    int numNodosNivel(NodeTree* pP, int nivel){
        nivel--;
        if (pP==NULL )
            return 0;
        else if (nivel==0)
            return 1;
        else
            return (0+numNodosNivel(pP->Left, nivel)+numNodosNivel(pP->Right, nivel));
        
        
    }
    
};

#endif /* ABB_h */
