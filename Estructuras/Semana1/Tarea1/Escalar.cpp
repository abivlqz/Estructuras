//
//  Escalar.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez
//  A01566592
//  Grupo2
//

#include <stdio.h>
#include <iostream>

using namespace std;


void Llena(int matriz[10][10], int dim){
    
    
    for (int r = 0; r<dim; r++) {
        for (int c = 0; c<dim; c++) {
            cout<<"Ingresa el elemento de la posicion ["<<r<<" ],["<<c<<"] :"<<endl;
            cin>>matriz[r][c];
        }
    }
    
}

bool Calcula(int matriz [10][10], int dim){
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
    cout<<"Ingresa la dimension de tu matriz"<<endl;
    cin>>dim;
    int matriz[10][10];
    
    Llena(matriz, dim);
    
    if (Calcula(matriz, dim))
        cout<<"Es una matriz escalar "<<endl;
    else
     cout<<"NO ES una matriz escalar "<<endl;
    
    return 0;
}



