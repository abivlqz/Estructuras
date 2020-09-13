//
//  LinkedList.h
//  Estructuras
//
//

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
using namespace std;

template <class T>

    // Clase Nodo, el cual guarda un atributo de cualquier tipo y un apuntador a otra estructura igual del mismo tipo
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

    //clase LinkedList cuyo atributo es un apuntador al inicio de la estructura, la cual estara formada por cero, uno o varios nodos
template <class T>
class LinkedList{
private:
    Node <T> *Head;
public:
    //Constructor que inicializa el apuntador (atributo a NULL)
    LinkedList(){
        Head=NULL;
    }
    //Desctructor, libera la memoria de todos los nodos que tenga
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
        // Se comprueba que la lista no este vacía
        if (Head!=NULL) {
            Node<T> *y = Head;
            Node<T> * x= Head;
            // contador que recorre el apuntador que señala el nodo final
            int contador = 0;
            // se inicializa start para que recorra desde el primer nodo
            int start = 0;
            // se inicializa end para que delimite el corrimiento del ultimo nodo
            int end =getSize()-1;
            // mientras que no se crucen los corrimientos
            while (start<end) {
                // el while hace que el apuntador "y" este en el final correspondiente
                while (contador < end) {
                    y= y->pNext;
                    contador++;
                }
                // intercambia los datos de los nodos a los que esta apuntando "x" y "y"
                intercambiarDatos(x, y);
                // el apuntador del inicio se recorre un lugar mas a la derecha
                x=x->pNext;
                // se reinicia el apuntador "y" y el delimitador end se hace mas chico
                y=Head;
                end--;
                // el delimitador start se hace mas grande
                start++;
                // se reinicia el contador que busca el "ultimo" nodo para hacer
                // el intercambio corrspondiente
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
        // Validamos que la lista no este vacía
        if (Head!=NULL) {
            // apuntador que le dira al nodo auxiliar en donde intercambiar los datos
            Node<T> * pAux= Head;
            // Nodo auxiliar que se utilizara para ir recorriendo los datos de los nodos
            // va ir guardando el que recorrio para colocarlo en el siguiente nodo
            // que se encuentre.
            Node<T> *nodeAux = new Node<T>(Head->data);
            // El corrimiento se hara n veces, n siendo el numero de nodos en la lista
            int numNodos = getSize();
            // si el corrimiento "x" es negativo, se puede convierte positivo restandole
            // a el numero de nodos, el numero x, se consigue el corrimiento
            // a la izquierda
            if (x<0)
                x=getSize()+x;
            while (cont1<numNodos) {
               while (cont2<x) {// el corrimiento se hace cada "x" posiciones en la lista
                    if (pAux->pNext!=NULL) {// se recorre y el cont2 registra cuantas posiciones ha avanzado ese nodo
                        pAux=pAux->pNext;
                        cont2++;
                    }else{// si llega al final de la lista, el apuntador se regresa al nodo inicial
                        pAux=Head;
                        cont2++;
                    }
                }// se intercambia el dato donde el apuntador aux se quedo en el ciclo,
                //  y el dato que se encuentra en el nodo aux
                intercambiarDatos(pAux, nodeAux);
                // se reinicia el contador de posiciones recorridas por un nodo
                cont2=0;
                // se aumenta el num de elementos que ya han sido movidos x posiciones
                cont1++;
            }
            // se borra el nodo auxiliar que se creo para guardar temporalmente el valor
            // de un nodo que fue recorrido
            delete nodeAux;
            }
    }
    
    /// Operator ==
    /// Parámetro: la lista L con la que se compara la otra lista (que se pasa por referencia).
    /// Descripción: Revisa si dos listas encadenadas tienen el mismo contenido y en el mismo orden, regresa un valor bool.
    bool operator ==(LinkedList<T> &L){
        int aux=0;
        int cont = 0;
        // se valida que sean del mismo tamaño
        if (this->getSize() == L.getSize()) {
            // si las dos listas tienen min 1 elemento
            if (this->Head!=NULL &&  L.Head!=NULL) {
                 Node<T> * pL1 = this->Head;
                 Node<T> * pL2 = L.Head;
                // el auxiliar ayuda a que deje de comparar nodos al momento
                // en que encuentra uno diferente y así, no llega hasta el final
                 while (cont<getSize() && aux==0) {
                     // se comparan los datos en los nodos, si es diferente el aux se le suma 1
                     if (pL1->data != pL2->data) {
                         aux ++;
                        
                     }
                     // se recorren los dos apuntadores en ambas listas
                      pL1 = pL1->pNext;
                      pL2 = pL2->pNext;
                      cont++;
                 }// si aux es 0 significa que no encontro ningun nodo diferente entonces
                //   ambas listas si son iguales
                if (aux==0) {
                    return true;
                }else{// de lo contrario regresa que no son iguales
                    return false;
                }
            // si ambas listas estan vacías entonces si son iguales
            }else if (this->Head==NULL &&  L.Head==NULL){
                return true;
            }// de lo contrario no son iguales
            else{
                return false;
            }
        // si no son del mismo tamaño no son iguales
        }else{
            return false;
        }
   }
    
    /// Operator +=
    /// Parámetro: una LinkedList de tipo de dato T.
    /// Descripción: Apendiza toda la info de la lista encadenada L2, al final de la lista encadenada L1, no tiene retornos.
    void operator+=(const LinkedList<T>& L2){
        Node<T> *pp= Head;
        Node<T> *pp2= L2.Head;
        // si la lista 2 esta vacía, que no modifique y regrese la lista 1
        if (L2.Head==NULL) {
            return;
        }
        else {
            // si la primer lista esta vacía, que cree un nodo Head con el valor del
            // primer elemento de la lista 2
            if (Head==NULL) {
                Head = new Node<T>(pp2->data);
                pp=Head;
            }else{
                // si no esta vacía, que encuentre el ultimo nodo de la lista 1
                while (pp->pNext!=NULL) {
                    pp=pp->pNext;
                }
                // que cree un nodo con el valor de primer nodo de la lista 2 y que
                // lo asigne al pNext del ultimo nodo de la L1
                pp->pNext=new Node<T>(pp2->data);
                pp=pp->pNext;
            }
            // si la lista dos no se ha acabado
            while (pp2->pNext!=NULL) {
            // recorre el apuntador en la lista 2
            pp2=pp2->pNext;
            // crea un nuevo nodo al final de la lista L1 con el data del apuntador pp2
            pp->pNext=new Node<T>(pp2->data);
            // recorre el apuntador de la L1 al nodo recien copiado de L2
            pp=pp->pNext;
            }
        }
    }
    
    /// Método remove
    /// Parámetro: dos numeros : x & y de tipo entero.
    /// Descripción: Borra x nodos a partir de la posición y( o sea el elemento y también se borra). Se valida que haya
    /// suficientes nodos para borra a partir de la posición y, en caso de que x sea mayor a la cantidad de nodos que
    /// quedan a partir de la posición, se borran todos los que quedan. No tiene retornos
    void remove(int x, int y){
        Node<T>*pp = Head;
        Node<T>*pp2 = Head;
        Node<T> *aux = NULL;
        int cont=0;
        int sizeInic=getSize();
        // se comprueba que la lista no este vacía
        if (Head!=NULL) {
            //si el numero de nodos que se requiere borrar es mayor a los nodos que quedan
            // se redefine x para que sea igual a los que quedan
            if ((y+x)>sizeInic) {
                x=sizeInic-y;
            }
            // ciclo que se asegura de borrar x nodos solamente
            while (cont<x) {
                // resetea los apuntadores al inicio despues de que se elimina un nodo
                pp=Head;
                pp2=Head;
                // Proceso de borrado si se requiere borrar nodos desde el nodo Head
                if (y==0) {
                    // se borra el primer nodo y se redefine Head
                    if (Head->pNext!=NULL) {
                        Head= Head->pNext;
                        delete pp;
                        cont++;
                    } else {
                        // si solo hay un nodo en la lista entonces se borra
                        // y Head se pone en null para indicar que la lista esta vacía
                        delete pp;
                        Head=NULL;
                        cont++;
                    }
                   
                }
                // Proceso de borrado si se requiere borrar nodos intermedios
                else if((y+x)<sizeInic&&y>0) {
                    // el ciclo deja el apuntador pp uno antes del cual se quiere borrar
                    for (int i = 0; i<(y-1); i++) {
                        pp=pp->pNext;
                    }
                    // el pp2 apunta al cual se quiere borrar
                    pp2=pp->pNext;
                    // el pNext del uno antes, se vuelve el siguiente nodo del
                    // cual se quiere borrar
                    pp->pNext = pp2->pNext;
                    delete pp2;
                    cont++;
                    
                }
                // Proceso de borrado si se requiere borrar desde un nodo hasta el final
                // de la lista, es decir, si se borra desde el último
                else if ((y+x)>=sizeInic){
                    // se encuentra el ultimo y aux apunta al penultimo nodo
                    while (pp->pNext!=NULL) {
                        aux=pp;
                        pp=pp->pNext;
                    }
                    // se borrael ultimo nodo
                    delete pp;
                    // aux ahora es el ultimo, por tanto su pNext tiene que indicar null
                    if (aux!=NULL) {
                        aux->pNext=NULL;
                    } else {// si aux es null significa que solo habia un elemento
                        // y por tanto la lista esta vacía y head tiene que indicar a null
                        Head=NULL;
                    }
                    cont++;
                }
            }
        }
    }

};


#endif /* LinkedList_h */
