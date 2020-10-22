#include <iostream>
#include "ABB.h"
#include <stdio.h>
using namespace std;

int main()
{
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
   // t.Print();
    cout<<endl;
    cout<<"la suma de los nodos es : "<<t.AddNodes()<<endl;
    if (t.FindValue(14))
        cout<<"si se encontro"<<endl;
    else
       cout<<"no se encontro"<<endl;
    cout<<"los niveles son: "<<t.Height()<<endl;
    cout<<"hay "<<t.nodosHoja()<< "  nodos hoja "<<endl;
    
    return 0;
}


