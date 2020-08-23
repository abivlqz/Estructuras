//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 22/08/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Producto{
    //Atributos
private:
    string nombre;
    int gramos, calorias;
    
public:
    //Constructor1
    Producto(string _nombre, int _gramos, int _calorias){
        nombre = _nombre;
        gramos = _gramos;
        calorias = _calorias;
        
    }
    //Constructor2 para el arreglo de objetos
    Producto(){
        
    }
    //Metodos de acceso
    string getNombre(Producto p){
        return nombre;
    }
    int getGramos(Producto p){
        return gramos;
    }
    int getCalorias(Producto p){
        return calorias;
    }
    void setNombre(string _nombre){
        nombre = _nombre;
    }
    void setGramos(int _gramos){
        gramos = _gramos;
    }
    void setCalorias(int _calorias){
        calorias = _calorias;
    }
    
    void mostrarProducto(){
        cout<<"Nombre del producto "<<nombre<<endl;
        cout<<"cantidad de gramos "<<gramos<<endl;
        cout<<"cantidad de calorias "<<calorias<<endl;
    }
    
    
};

// Funcion que lee el archivo
void LeerArchivo(Producto aProducto[],int capArray){
    
    int numProductos,gramos,calorias;
    string firstLine;
    char nombreArchivo[30];

    //Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open(nombreArchivo, ios::in);
    //Se lee la primera linea que indica el numero de productos del programa
    getline(nuevoArchivo,firstLine);
    stringstream stoInt(firstLine);
    stoInt>>numProductos;
    cout<<numProductos<<endl;
    
    string lines;
    while (!nuevoArchivo.eof() && nuevoArchivo.is_open()) {
        for (int i = 0; i<numProductos; i++) {
            getline(nuevoArchivo,lines,' ');
            cout<<"La linea que lee es "<<lines<<endl;
            aProducto[i].setNombre(lines);
            getline(nuevoArchivo,lines,' ');
            stringstream stoInt(lines);
            stoInt>>gramos;
            cout<<"La linea que lee es "<<lines<<endl;
            aProducto[i].setGramos(gramos);
            getline(nuevoArchivo,lines,' ');
            stoInt>>calorias;
            cout<<"La linea que lee es "<<lines<<endl;
            aProducto[i].setCalorias(calorias);
        }
    }
    for (int i = 0; i<=numProductos; i++) {
        aProducto[i].mostrarProducto();
    }
    
    
    

}



int main(int argc, const char * argv[]) {
    
    Producto* aProducto = new Producto[100];
    LeerArchivo(aProducto, 100);
    
    return 0;
}
