//  Pares.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 11/08/2020
//  Este programa permite llenar una matriz de orden ncolumnas y nfilas solicitada al usuario, solicita un valor X e imprime en pantalla los pares continuos cuya suma resultante sea X y en que renglon de la matriz se encuentran.
#include <stdio.h>
#include <iostream>

using namespace std;

// Funcion LLena solicita al usuario llenar una matriz de dos dimensiones
// Sus parametros son una matriz de tipo entero y  el numero de filas y columnas de la matriz de tipo entero, no regresa nada.
void Llena(int matriz[10][10], int numRows, int numCol){
    for (int r = 0; r<numRows; r++) {
        for (int c = 0; c<numCol; c++) {
            cout<<"Ingresa el elemento de la posicion ["<<r<<" ],["<<c<<"] :"<<endl;
            cin>>matriz[r][c];
        }
    }
}

// Funcion Pares compara los pares continuos por renglon de una matriz de n filas y n columnas e imprime en pantalla el par continuo cuya suma sea X, un numero solicitado al usuario, e imprime en que renglon se encontro dicho par.
// Sus parametros son: una matriz de tipo entero, el numero de filas y el numero de columnas delimitando dicha matriz, y no regresa nada.
void Pares(int matriz[10][10], int numRows, int numCol){
    int numX;
    int cont_Pares = 0;
    
    cout<<"Ingresa el numero X para buscar pares continuos donde su suma resultante sea X "<<endl;
    cin>>numX;
    
    for (int c = 0; c<numCol-1; c++) {
        for (int r = 0; r<numRows; r++) {
            if ((matriz[r][c]+matriz[r][c+1]) == numX) {
                cout<<"Par encontrado: "<<matriz[r][c]<<","<< matriz[r][c+1]<<" en el renglon "<<r<<endl;
                cont_Pares++;
            }
        }
    }
    if(cont_Pares == 0){
        cout<<"No se encontro ningun par continuo en la matriz cuya suma resultante fuera "<<numX<<endl;
    }
}


int main(){
    
    int filas, columnas;
    int matriz[10][10];
    cout<<"Ingresa el numero de filas de tu matriz "<<endl;
    cin>>filas;
    cout<<"Ingresa el numero de columnas de tu matriz "<<endl;
    cin>>columnas;
    
    Llena(matriz, filas, columnas);
    Pares(matriz, filas, columnas);
    
    return 0;
}
