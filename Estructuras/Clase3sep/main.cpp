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
    
    int a[5]= {1,2,3,12,5};
    int *p = a+1;
    int *q=new int[3];
    for (int i = 0; i<3; i++) {
       *q= *(p++);
        cout<<*(q)<<endl;
    }
     
    return 0;
}
