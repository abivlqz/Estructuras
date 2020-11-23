//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 09/11/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 10;

int sumaDependencias(char mat[MAX][MAX], int numNodos){
    int sumDep=0;
    for(int i=0;i<numNodos;i++){
        for(int j=0;j<numNodos;j++){
            if(mat[i][j]== 'T')
                sumDep+=1;
        }
    }
    return sumDep;
}

void llenarMatriz (char mat[MAX][MAX], int numNodos){
    for(int i=0;i<numNodos;i++){
        for(int j=0;j<numNodos;j++){
        cout<<"Escribe la dependencia ("<<i<<","<<j<<")"<<endl;
        cin>>mat[i][j];
        }
    }
}

int main()
{
    char matriz[MAX][MAX];
    int numNodos;
    cout<<"Cuantos nodos hay en el grafo"<<endl;
    cin>>numNodos;
    for(int i=0;i<numNodos;i++){
        for(int j=0;j<numNodos;j++){
        cout<<"Escribe la dependencia ("<<i<<","<<j<<")"<<endl;
        cin>>matriz[i][j];
        }
    }

    cout<<"El numero de dependencias es: "<<sumaDependencias(matriz,numNodos)<<endl;

    return 0;
}

