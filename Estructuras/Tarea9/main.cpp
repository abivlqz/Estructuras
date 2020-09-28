//  Tarea9
//  main.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 26/10/2020
//  Este programa incluye
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include <cctype>
#include <string>

using namespace std;

int add(int e1, int e2){
    return e1+e2;
}

int mult(int e1, int e2){
    return e1*e2;
}

int sub(int e1, int e2){
    return e1-e2;
}

int divi(int e1, int e2){
    return e1/e2;
}

void modificarPilas(Stack<string>& pOper,  Stack<int>& pNum){
    int e1,e2;
    e2=pNum.peek();
    pNum.pop();
    e1=pNum.peek();
    pNum.pop();
    if (pOper.peek()=="(add")
        pNum.push(add(e1, e2));
    else if (pOper.peek()=="(sub")
    pNum.push(sub(e1, e2));
    else if (pOper.peek()=="(mult")
    pNum.push(mult(e1, e2));
    else if (pOper.peek()=="(div")
    pNum.push(divi(e1, e2));
    
    pOper.pop();
    
}



void leerArchivo(fstream & archivo, Stack<string> &pOper,  Stack<int> &pNum){
    ofstream nuevoArchivo("Res.txt");
    string linea;
    string elemento;
    string auxString;
    int numAux;
    while (!archivo.eof()) {
        getline(archivo,linea);
        stringstream linestream(linea);
        while (!linestream.eof()) {
            getline(linestream,elemento,' ');
            if (elemento == "(add"||elemento == "(sub"||elemento == "(mult"||elemento == "(div") {
                pOper.push(elemento);
            }
            else {
                for (int i = 0; i<elemento.length(); i++) {
                    if (isdigit(elemento[i])) {
                        auxString=elemento[i];
                        numAux= stoi(auxString);
                        pNum.push(numAux);
                        //cout<<numAux<<endl;
                    }
                    else if (elemento[i]==')'){
                        modificarPilas(pOper, pNum);
                    }
                }
            }
        }
        pNum.mostrar();
        nuevoArchivo<<pNum.peek()<<endl;
        pNum.pop();
        cout<<endl;
    }
}




int main(){
    
    Stack<string> pilaOperadores;
    Stack<int> numeros;
    char nombreArchivo[30];
    //Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    //Declaramos y abrimos el archivo
    fstream Archivo;
    Archivo.open(nombreArchivo);
    //Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
    if (Archivo.is_open()){
        leerArchivo(Archivo, pilaOperadores, numeros);
    }
    else
        cout<<"No se encontro el archivo"<<endl;
    
    return 0;
}


