//  Vector
//  main.cpp
//  Estructuras
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 02/08/2020
//  Este programa
//  Se adjunta un archivo txt llamado 'operaciones.txt'
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void mostrarVector(vector<int> & vector1){
    vector<int>::iterator i;
    for (i = vector1.begin(); i!=vector1.end(); i++) {
        cout<<*i<<" ";
    }
}


void modificarVector(fstream & archivo, vector<int> & vector){
    int T, Q;
    string operacion;
    string stringCasos,stringConsultas,lines;
    getline(archivo,stringCasos);
    stringstream stoInt(stringCasos);
    stoInt>>T;
    //cout<<T<<endl;
    
    for (int numCasos = 0; numCasos<T; numCasos++) {
        getline(archivo,stringConsultas);
        stringstream stoInt(stringConsultas);
        stoInt>>Q;
        getline(archivo,lines);
        stringstream linestream(lines);
        int numVector = 0;
        int numConsultas = 0;
        // cout<<Q<<endl;
        while (numConsultas<Q) {
            
            getline(linestream,operacion,' ');
            //cout<<operacion<<" ";
            if (operacion=="a") {
                linestream>>numVector;
                vector.push_back(numVector);
                numConsultas++;
            }
            else if (operacion=="b"){
                sort(vector.begin(), vector.end());
                numConsultas++;
            }else if (operacion=="c"){
                reverse(vector.begin(), vector.end());
                numConsultas++;
            }
            else if (operacion=="d"){
                cout<<vector.size()<<" ";
                numConsultas++;
            }
            else if (operacion=="e"){
                mostrarVector(vector);
                numConsultas++;
            }
            else if (operacion=="f"){
                sort(vector.begin(), vector.end(),greater<int>());
                numConsultas++;
            }
        }
        vector.clear();
        cout<<endl;
    }
}

// Programa Principal
int main(){
    vector<int>vector;
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open("operaciones.txt");
    //Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
    if (nuevoArchivo.is_open())
        modificarVector(nuevoArchivo, vector);
    else
        cout<<"No se ha encontrado el archivo o no se ha podido abrir "<<endl;
    
    return 0;
}
