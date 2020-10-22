//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 30/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>

using namespace std;

//Funcion recursiva que suma un numero y regresa la suma de sus digitos en un entero
// Parametro: num
// Salida: suma de los digitos de num
int sumaDigitos(int Num){
    if (Num<10)
        return Num;
    
    return (Num%10+sumaDigitos(Num/10));
    //2865
        //5+ sumadigitos(286)
}       //6+ sumadigitos(28)
        // 8+ sumadigitos(2)
        // 2+ sumadigitos(0)
        // 0 end
        // 5+6+8+2+0

int main(){
   
    LinkedList<int>L;
   
    L.addFirst(5);
    L.addLast(6);
    L.addLast(2);
    L.addLast(4);
    cout<<L.sumaCuadrados()<<endl;
   
   // cout<<sumaDigitos(2865)<<endl;
    
    
}
