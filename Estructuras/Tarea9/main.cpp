//  Tarea9
//  main.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 27/10/2020
//  Este programa pide al usuario el nombre del archivo (con extension) txt que contendrá en cada línea una expresion en lenguaje Lisp ,y genera
//  un nuevo archivo txt llamado "Respuestas.txt" con los resultados de dichas expresiones.
//  El programa evalúa las expresiones "add","sub","mult" y "div", solo con digitos del 0-9 y los resultados siempre seran enteros.
// Este proyecto trae dos archivo de prueba llamado "prueba.txt" y otro llamado "prueba2.txt" para que se pueda visualizar que las operaciones dan resultados correctos.

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include <cctype>
#include <string>

using namespace std;
// Funcion add que realiza una suma de dos enteros
// Sus parametros son: dos numeros enteros
// Retorna un entero
int add(int e1, int e2){
    return e1+e2;
}
// Funcion mult que realiza una multiplicacion de dos enteros
// Sus parametros son: dos numeros enteros
// Retorna un entero
int mult(int e1, int e2){
    return e1*e2;
}
// Funcion sub que realiza una resta de dos enteros
// Sus parametros son: dos numeros enteros
// Retorna un entero
int sub(int e1, int e2){
    return e1-e2;
}
// Funcion divi que realiza una division de dos enteros, si el resultado tiene un decimal
// redondea al entero en donde se quedo
// Sus parametros son: dos numeros enteros
// Retorna un entero
int divi(int e1, int e2){
    return e1/e2;
}

// Funcion modificarPilas que ejecuta la expresion que se encuentra en el tope
// de la pila de strings junto con los numeros tope de la pila de numeros.
// Sus parametros son: una pila de strings y una pila de enteros, no tiene retornos
void modificarPilas(Stack<string>& pOper,  Stack<int>& pNum){
    int e1,e2;
    // se guarda el tope de la pila en un entero
    e2=pNum.peek();
    // se elimina de la pila
    pNum.pop();
    // se guarda el nuevo tope de la pila en un entero
    // es e1 obligatoriamente por que siempre es el que entra antes que el e2
    e1=pNum.peek();
    // se elimiina de la pila
    pNum.pop();
    // se checa cual es la expresion que se encuentra en el tope pOper
    // el resultado de esa expresion se añade al tope de la pila pNum
    // para que pueda ser "reutilizado" por las expresiones que faltan de ejecutar
    if (pOper.peek()=="(add")
        pNum.push(add(e1, e2));
    else if (pOper.peek()=="(sub")
    pNum.push(sub(e1, e2));
    else if (pOper.peek()=="(mult")
    pNum.push(mult(e1, e2));
    else if (pOper.peek()=="(div")
    pNum.push(divi(e1, e2));
    // al finalizar de ejecucion de la expresion, se elimina del tope de pOper
    pOper.pop();
    
}

// Funcion leerArchivo que lee el archivo dado por el usuario, guarda las operaciones
// que se encuentra en una pila de strings y los numeros del 0-9 que encuentra
// cuando se encuentra con un ')' se ejecuta la expresion que se encuentra en los topes
// de la pila de strings junto con los numeros tope de la pila de numeros.
// Sus parametros son: un archivo txt abierto, una pila de strings y una pila de enteros, no tiene retornos
void leerArchivo(fstream & archivo, Stack<string> &pOper,  Stack<int> &pNum){
    // Se declara el archivo en el que se guardaran los resultados de cada linea
    ofstream nuevoArchivo("Respuestas.txt");
    string linea;
    string elemento;
    string auxString;
    // entero auxiliar que guarda el numero que se encuentra en el string
    int numAux;
    // condicion para que lea todas las lineas que se encuentre en el txt
    while (!archivo.eof()) {
        getline(archivo,linea);
        // para convertir cada linea que se lea en un tipo archivo
        stringstream linestream(linea);
        while (!linestream.eof()) {
            // se separa por espacios lo que se encuentre en la linea
            getline(linestream,elemento,' ');
            // si se encuentra con una expresion, la mete a la pila de operaciones
            if (elemento == "(add"||elemento == "(sub"||elemento == "(mult"||elemento == "(div") {
                pOper.push(elemento);
            }
            else { // de lo contrario, se checa caracter por caracter el elemento
                   // para encontrar numeros o parentesis cerrados
                for (int i = 0; i<elemento.length(); i++) {
                    // si el caracter es un numero lo convierte a int y lo agrega a la pila de numeros
                    if (isdigit(elemento[i])) {
                        auxString=elemento[i];
                        numAux= stoi(auxString);
                        pNum.push(numAux);
                    }// si el caracter es un parentesis cerrado significa que se puede completar una expresion
                    else if (elemento[i]==')'){
                        // llamamos la funcion que completa una expresion y modifica la pilas pOper y pNum
                        if (!pOper.isEmpty())//comprobamos que aun queden expresiones por realizar
                            modificarPilas(pOper, pNum);
                    }
                }
            }
        }
        // agregamos al nuevo archivo el resultado de cada linea,
        // al final el resultado es el único elemento en la pila de numeros
        // por tanto, es el tope
        nuevoArchivo<<pNum.peek()<<endl;
        // eliminamos el resultado para que la pila comience siempre vacía en la siguiente linea del txt
        pNum.pop();
    }
    
    //cerramos los dos archivos al finalizar de analizar todas las expresiones
    nuevoArchivo.close();
    archivo.close();
}

// Programa Principal
int main(){
    // Declaramos las dos pilas que usaremos para ejecutar las expresiones lisp
    Stack<string> pilaOperadores;
    Stack<int> numeros;
    char nombreArchivo[30];
    // Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    // Declaramos y abrimos el archivo
    fstream Archivo;
    Archivo.open(nombreArchivo);
    // Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
    if (Archivo.is_open())
        leerArchivo(Archivo, pilaOperadores, numeros);
    else
        cout<<"No se encontro el archivo"<<endl;
    return 0;
}


