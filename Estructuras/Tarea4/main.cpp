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

int numProductos;
class Producto{
    //Atributos
private:
    string nombre;
    int gramos, calorias;
    
public:
    //Constructor1
    Producto(string nombre, int gramos, int calorias){
        this->nombre = nombre;
        this->gramos = gramos;
        this->calorias = calorias;
        
    }
    //Constructor2 para el arreglo de objetos
    Producto(){
        
    }
    //Metodos de acceso
    string getNombre(){
        return nombre;
    }
    int getGramos(){
        return gramos;
    }
    int getCalorias(){
        return calorias;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setGramos(int gramos){
        this->gramos = gramos;
    }
    void setCalorias(int calorias){
        this->calorias = calorias;
    }
    
    void mostrarProducto(){
        cout<<nombre<<" ";
        cout<<gramos<<" ";
        cout<<calorias<<endl;
    }
    
    //compara producto < otro producto pasado por referencia
    bool operator <(Producto& producto){
        if (producto.getNombre()<this->nombre) {
            return false;
        }
        else if (producto.getNombre()<this->nombre){
            return true;
        }
        else{
            if (producto.getGramos()<this->gramos) {
                return false;
            }
            else if (producto.getGramos()<this->gramos){
                return true;
            }
            else{
                if (producto.getCalorias()<this->calorias) {
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        
        
        
    }
    
    
};

// Funcion que lee el archivo y guarda los valores en su respectivo atributo de su clase
void ObtenerInfo(Producto aProducto[],int capArray){
    
    int gramos,calorias;
    string firstLine,nombre;
    char nombreArchivo[30];

    //Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open(nombreArchivo);
    
    //Se lee la primera linea que indica el numero de productos del programa
    getline(nuevoArchivo,firstLine);
    // Convierte el string a int
    stringstream stoInt(firstLine);
    stoInt>>numProductos;
    
    
    string lines;
    while (!nuevoArchivo.eof() && nuevoArchivo.is_open()) {
        for (int i = 0; i<=numProductos; i++) {
            //Lee linea por linea el txt
            getline(nuevoArchivo,lines);
            //Lee en la linea i un string hasta que se encuentre con un espacio
            stringstream linestream(lines);
            getline(linestream,nombre,' ');
           // cout<<"La linea que lee es "<<nombre<<" va en el loop "<<i<<endl;
            // Le asignamos el valor al atributo de ese producto
            aProducto[i].setNombre(nombre);
            // Lee en la linea i un int hasta que se encuentra con un espacio
            linestream>>gramos >>calorias;
            // Le asignamos el valor al atributo de ese producto
            aProducto[i].setGramos(gramos);
            aProducto[i].setCalorias(calorias);
            
        }
    }
    if (!nuevoArchivo.is_open()) {
        cout<<"No se ha encontrado o no se ha podido abrir el archivo con ese nombre"<<endl;
    }
    
    
    for (int i = 0; i<=numProductos; i++) {
        aProducto[i].mostrarProducto();
    }
    
    
    

}

void sortProductos(Producto aProducto[],int capArray){
    bool intercambio = true;
    for (int i = 0; i<numProductos && intercambio; i++) {
        intercambio = false;
        for (int j = 0; j<(numProductos-i); j++) {
            
            if (aProducto[j+1]<aProducto[j]) {//Aqui usa el operador < que se definio en la clase
                
                Producto aux = aProducto[j];
                aProducto[j]=aProducto[j+1];
                aProducto[j+1]=aux;
                intercambio=true;
                cout<<"hubo intercambio en"<<aProducto[j].getNombre()<<" y en "<<aProducto[j+1].getNombre()<<endl;
            }
        }
    }
    
    
   
}






int main(int argc, const char * argv[]) {
    
    Producto* aProducto = new Producto[100];
    ObtenerInfo(aProducto, 100);
    sortProductos(aProducto, 100);
    for (int i = 0; i<=numProductos; i++) {
           aProducto[i].mostrarProducto();
       }
    
    return 0;
}
