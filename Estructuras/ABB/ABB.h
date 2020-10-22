#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <cmath>
#include <iostream>

using namespace std;

class NodeTree
{
public:
    int Data;
    NodeTree *Left, *Right;
    NodeTree( ){ Left = Right = NULL; }
    NodeTree(int value)
    { Data = value; Left = Right = NULL; }
};

class ABB
{
private:
    NodeTree *root;
public:
    //Constructor
    ABB( ) { root = NULL; }
    //Destructor
    ~ABB( ) {
        NodeTree *pP=root;
        libera(pP);
    }
    /// Método para realizar el destructor
    void libera(NodeTree *r){
       if (r != NULL){
        libera(r->Left);
        libera(r->Right);
        delete r;
       }
    }

NodeTree* encuentraPadre (int iValor)
    {
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

    //Mayor de los menores
    NodeTree* predecesor (NodeTree *pActual)
    {
        NodeTree *pP = pActual->Left;
        while (pP->Right != NULL )
            pP = pP->Right;
        return pP;
    }

    //Menor de los mayores
    NodeTree* sucesor (NodeTree *pActual)
    {
        NodeTree *pP = pActual->Right;
        while (pP->Left != NULL )
            pP = pP->Left;
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

/// Imprimir el arbol

void P_Print(NodeTree *pP){
    if (pP != NULL){
        cout<<pP->Data<<" ";
        P_Print(pP->Left);
        P_Print(pP->Right);
    }
    else
        return;
}
void Print() {
    NodeTree *pP = root;
    P_Print(pP);
}

/// Metodo Height manda llamar a Altura que calcula la altura de un arbol
    // Parametro : ninguno, Retorno: un entero
    int Height(){
        NodeTree* pp = root;
        return Altura(pp);
        
    }
    //Metodo Altura calcula la altura de un arbol
    //Parametro: root
    //Retorno: un entero
    
    int Altura(NodeTree * pp){

        if (pp==NULL) {
            return 0;
        }else{
            return (1+max(Altura(pp->Left),Altura(pp->Right)));
            
        }
        
    }
    
    int nodosHoja(){
        NodeTree* pp=root;
        if (pp==NULL)
            return 0;
        else
        return SumaHoja(pp);
    }
    
    int SumaHoja(NodeTree *r){
        if (r->Left!=NULL && r->Right!=NULL)
            return SumaHoja(r->Right)+SumaHoja(r->Left);
        else if(r->Right!=NULL)
              return SumaHoja(r->Right);
        else if (r->Left!=NULL)
              return SumaHoja(r->Left);
        else
            return 1;
    }
    

///Metodo suma nodos-recibe root y suma todos los valores que hay en el arbol, regresa la suma de los nodos
    int sumaNodos(NodeTree* pp){
        if (pp!=NULL) {
            return ((pp->Data)+sumaNodos(pp->Left)+sumaNodos(pp->Right));
        }
        return 0;
    }

/// Método AddNodes- Suma de los nodos de un árbol
    int AddNodes(){
        NodeTree* pp = root;
        return sumaNodos(pp);
    }

/// Método FindValue - Boolean que indica si se encontró o no un elemento en el árbol
/// Parametro: valor entero a buscar en el arbol.
    bool FindValue(int valor){
        NodeTree* pP= root;
        while (pP!=NULL) {
            if (valor==pP->Data) {
                return true;
            }
            else
                pP=(pP->Data>valor?pP->Left:pP->Right);
        }
        return false;
        
        
    }
    
};




#endif // ABB_H_INCLUDED

