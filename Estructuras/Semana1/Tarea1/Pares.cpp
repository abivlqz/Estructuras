//
//  Pares.cpp
//  Abigail Guadalupe Velazquez Sanchez A01566592
//  Estructuras de datos
//  Grupo2
//

#include <stdio.h>
#include <iostream>

using namespace std;

//
void Llena(int matriz[10][10], int dim_r, int dim_c){
    
    
    for (int r = 0; r<dim_r; r++) {
        for (int c = 0; c<dim_c; c++) {
            cout<<"Ingresa el elemento de la posicion ["<<r<<" ],["<<c<<"] :"<<endl;
            cin>>matriz[r][c];
        }
    }
    
}

void Pares(int matriz[10][10], int dim_r, int dim_c){
    int X;
    int cont_Pares = 0;
    
    cout<<"Ingresa el numero X para buscar pares donde su suma resultante sea X "<<endl;
    cin>>X;
    
    for (int c = 0; c<dim_c-1; c++) {
        for (int r = 0; r<dim_r; r++) {
            if ((matriz[r][c]+matriz[r][c+1]) == X) {
                cout<<"Par encontrado: "<<matriz[r][c]<<","<< matriz[r][c+1]<<" en el renglon "<<r<<endl;
                cont_Pares++;
            }
        }
    }
    if(cont_Pares == 0){
        cout<<"No se encontro ningun par continuo en la matriz cuya suma resultante fuera "<<X<<endl;
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
    
    
}
