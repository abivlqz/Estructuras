//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 21/10/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ABB.h"
int main(){
    ABB t;
    
    t.meterABB(12);
    t.meterABB(3);
    t.meterABB(14);
    t.meterABB(1);
    t.meterABB(15);
    t.meterABB(13);
    t.meterABB(25);
    t.meterABB(11);
    t.meterABB(17);
    t.meterABB(30);
    t.meterABB(10);
    t.meterABB(7);
    t.meterABB(9);
    t.meterABB(31);
    t.meterABB(29);
    t.meterABB(6);
    
//    cout<<"El numero de nodos hoja = "<<t.contarNodosHoja()<<endl;
//    cout<<"El numero de nodos padre = "<<t.contarNodosPadre()<<endl;
//    cout<<"El numero de nodos padre con un solo hijo = "<<t.contarNodosPadreUnHijo()<<endl;
//     cout<<"El numero de nodos padre con un solo hijo izquierda= "<<t.contarNodosPadreUnHijoIzquierda()<<endl;
//     cout<<"El numero de nodos padre con un solo hijo derecha = "<<t.contarNodosPadreUnHijoDerecha()<<endl;
    cout<<"El numero de nodos menores a 3 son = "<<t.numNodosMenores(3)<<endl;
    cout<<"El numero de nodos mayores a 3 son = "<<t.numNodosMayores(3)<<endl;
    cout<<"El predecesor de el nodo con valor 11 es "<<t.predecesorValor(11)<<endl;
    cout<<"EL arbol en preorden es "<<endl;
    t.imprimirPre();
    cout<<endl;
    
    cout<<"EL arbol en inorden es "<<endl;
    t.imprimirIn();
    cout<<endl;
    
    cout<<"EL arbol en postorden es "<<endl;
    t.imprimirPost();
    cout<<endl;
   
    
    cout<<" los numeros en el rango 3 a 15 son = "<<t.nodosRange(3, 15)<<endl;
    
    cout<<"El numero de nodos en el nivel 5 = "<<t.anchura(5)<<endl;
     return 0;
    
}
