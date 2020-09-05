#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
template <class T>
class Node{
public:
   ///atributos
    T data;
    Node <T> *pNext;
    ///métodos
    Node (){
        pNext=NULL;
    }
    Node ( T data){
        this->data = data;
        pNext=NULL;
    }


#endif // NODE_H_INCLUDED

