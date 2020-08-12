//  Escalar.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 11/08/2020
//  Este programa permite llenar una matriz de orden n solicitada al usuario, y verifica si se trata de una matriz escalar.

#include <stdio.h>
#include <iostream>

using namespace std;

//Funcion LLena solicita al usuario llenar una matriz cuadrada de dos dimensiones
// Sus parametros son una matriz de tipo entero y la dimension de la matriz de tipo entero, no regresa nada.
void Llena(int matriz[10][10], int dim){
    for (int r = 0; r<dim; r++) {
        for (int c = 0; c<dim; c++) {
            cout<<"Ingresa el elemento de la posicion ["<<r<<" ],["<<c<<"] :"<<endl;
            cin>>matriz[r][c];
        }
    }
}

// Funcion Calcula compara los elementos diagonales de una matriz cuadrada para
// identificar si son iguales, sus parametros son una matriz de tipo entero y la dimension
// de la matriz de tipo entero. Regresa una variable booleana verdadera si sus elementos en la diagonal son iguales.
bool Calcula(int matriz [10][10], int dim){
    //Valor inicial con el que se hara la comparacion de elementos en la diagonal
    int valorInicial= matriz[0][0];
    bool escalar = true;
    
    for (int rc = 0; rc<dim; rc++) {
        if (matriz[rc][rc]!=valorInicial) {
            escalar = false;
            break;
        }
    }
    return escalar;
}


int main(){
    
    int dim;
    int matriz[10][10];
    cout<<"Ingresa la dimension de tu matriz"<<endl;
    cin>>dim;
    Llena(matriz, dim);
    
    if (Calcula(matriz, dim))
        cout<<"Es una matriz escalar "<<endl;
    else
     cout<<"NO ES una matriz escalar "<<endl;
    
    return 0;
}



