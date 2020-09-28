//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 24/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>


using namespace std;

void mostrarQ(stack<int > p){
    stack<int> pila= p;
    while (!pila.empty()) {
        cout<<" "<<pila.top();
        pila.pop();
    }
    cout<<endl;
    
}
int main(){
    stack<int > pila;
    pila.push(12);
    pila.push(20);
    pila.push(10);
    pila.push(35);
    
    cout<<" la pila original es:"<<endl;
    mostrarQ(pila);
    cout<<" el tamaño de la pila es:"<<endl;
    cout<<pila.size()<<endl;
    cout<<" top:"<<endl;
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<" la pila despues de un pop es:"<<endl;
    mostrarQ(pila);
    return 0;
}

