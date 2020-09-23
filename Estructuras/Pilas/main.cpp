#include <iostream>
#include<string>
#include <sstream>
#include "Stack.h"
using namespace std;



bool esValido(string parentesis, Stack<char>& abiertos){
    
    for (int i = 0; i<parentesis.length(); i++) {
        if (parentesis.at(i)=='{'||parentesis.at(i)=='('||parentesis.at(i)=='[') {
            abiertos.push(parentesis.at(i));
        }
        if (parentesis.at(i)=='}'||parentesis.at(i)==')'||parentesis.at(i)==']') {
            if (abiertos.peek()=='{' && parentesis.at(i)=='}') {
                abiertos.pop();
            }
            if (abiertos.peek()=='(' && parentesis.at(i)==')') {
                abiertos.pop();
            }
            if (abiertos.peek()=='[' && parentesis.at(i)==']') {
                abiertos.pop();
            }
        }
        
    
   }
    if (abiertos.isEmpty())
        return true;
    else
        return false;
    
}


int main()
{
    Stack <char> abiertos;
    string parentesis = "{[()]({}){}}";
    
    if (esValido(parentesis, abiertos))
        cout<<"El string es valido"<<endl;
    else
        cout<<"el string no es valido"<<endl;
    
    
        
    
    
    
    
    
    
    
    return 0;

}

