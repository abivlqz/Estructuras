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

void mostrarQ(priority_queue<int, vector<int>,greater<> >q){
   priority_queue<int, vector<int>,greater<> >cola = q;
    while (!cola.empty()) {
        cout<<" "<<cola.top();
        cola.pop();
    }
    cout<<endl;
    
}
int main(){
    priority_queue<int, vector<int>,greater<> > cola;
    cola.push(5);
    cola.push(30);
    cola.push(15);
    cola.push(35);
    
    cout<<" la cola original es:"<<endl;
    mostrarQ(cola);
    cout<<" el tamaño de la cola es:"<<endl;
    cout<<cola.size()<<endl;
    cout<<" front:"<<endl;
    cout<<cola.top()<<endl;
    cola.pop();
    cout<<" la cola despues de un pop es:"<<endl;
    mostrarQ(cola);
    return 0;
}

