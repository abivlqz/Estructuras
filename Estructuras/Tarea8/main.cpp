//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 24/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

void mostrarQ(queue<int > q){
    queue<int>cola = q;
    while (!cola.empty()) {
        cout<<" "<<cola.front();
        cola.pop();
    }
    cout<<endl;
    
}
int main(){
    queue<int > cola;
    cola.push(5);
    cola.push(30);
    cola.push(15);
    cola.push(35);
    
    cout<<" la cola original es:"<<endl;
    mostrarQ(cola);
    cout<<" el tamaño de la cola es:"<<endl;
    cout<<cola.size()<<endl;
     cout<<" front:"<<endl;
    cout<<cola.front()<<endl;
    cout<<" back:"<<endl;
    cout<<cola.back()<<endl;
    cola.pop();
    cout<<" la cola despues de un pop es:"<<endl;
    mostrarQ(cola);
    return 0;
}
