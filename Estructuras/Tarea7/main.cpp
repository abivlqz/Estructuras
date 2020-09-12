//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 09/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    
    LinkedList<int>L1;
    LinkedList<int>L2;
//    L1.addFirst(5);
//    L1.addFirst(4);
//    L1.addFirst(3);
//    L1.addFirst(2);
//    L1.addFirst(1);
    
    L2.addFirst(10);
    L2.addFirst(9);
    L2.addFirst(8);
    L2.addFirst(7);
    L2.addFirst(6);
    
    L1.printList();
    cout<<endl;
    L1+=L2;
   
    L1.printList();
       cout<<endl;
   
    
    
    
    return 0;
}
