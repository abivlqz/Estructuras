//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 03/09/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList <int> L;
    L.addFirst(4);
    L.addFirst(1);
    L.addFirst(14);
    L.addFirst(7);
    
    L.printList();
    return 0;
}
