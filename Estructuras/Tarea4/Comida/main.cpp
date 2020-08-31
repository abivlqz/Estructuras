//
//  Comida.cpp
//  Estructuras
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 23/08/2020
//  Este programa solicita al usuario el nombre de un archivo con su debida extension, y permite ordenar de menor a mayor los objetos Producto siguiendo una jerarquía por : nombre de producto, despues gramaje y por último calorías. Por último, imprime en pantalla el arreglo de objetos de tipo Producto ordenados en pantalla.
//  Se adjunta un archivo txt de prueba con el nombre 'Dieta.txt', al ingresar el nombre se tiene que poner con todo y extension.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Producto.h"
using namespace std;

int numProductos;
// Funcion ObtenerInfo que lee el archivo linea por linea, separa por espacios y guarda las variables en su respectivo atributo (nombre, gramos o calorías) en un arreglo de objetos de tipo Producto.
// Sus parametros son un arreglo de objetos de la clase Producto, la dimension de dicho arreglo y el archivo abierto del que se leera la informacion, no tiene retornos.
void ObtenerInfo(Producto aProducto[],int capArray, fstream& nuevoArchivo){
    int gramos,calorias;
    string firstLine,nombre;
    //Se lee la primera linea que indica el numero de productos del programa
    getline(nuevoArchivo,firstLine);
    // Convierte el string a int
    stringstream stoInt(firstLine);
    stoInt>>numProductos;
    string lines;
    while (!nuevoArchivo.eof()) {
        for (int i = 0; i<=numProductos; i++) {
            //Lee linea por linea el txt
            getline(nuevoArchivo,lines);
            //Lee en la linea i un string hasta que se encuentre con un espacio
            stringstream linestream(lines);
            getline(linestream,nombre,' ');
            // Le asignamos el valor al atributo de ese producto
            aProducto[i].setNombre(nombre);
            // Lee en la linea i un int hasta que se encuentra con un espacio
            linestream>>gramos >>calorias;
            // Le asignamos el valor al atributo de ese producto
            aProducto[i].setGramos(gramos);
            aProducto[i].setCalorias(calorias);
        }
    }
    nuevoArchivo.close();
}

// Funcion SortProductos que ordena el arreglo de Objetos por el metodo burbuja, es decir, compara pares consecutivos de objetos, y si el segundo es menor que el primero, los intercambia
// Para comparar los objetos de tipo Producto usa el operador <, que se definio en la clase Producto
// Sus parametros son un arreglo de objetos de la clase producto, y la capacidad de dicho arreglo, no tiene retornos.
void SortProductos(Producto aProducto[],int capArray){
    bool intercambio = true;
    for (int i = 0; i<numProductos && intercambio; i++) {
        intercambio = false;
        for (int j = 0; j<(numProductos-i); j++) {

            if (aProducto[j+1]<aProducto[j]) {//Aqui usa el operador < que se definio en la clase Producto
                Producto aux = aProducto[j];
                aProducto[j]=aProducto[j+1];
                aProducto[j+1]=aux;
                intercambio=true;
            }
        }
    }
}
// Programa Principal
int main() {
    // Se inicializa el arreglo de objetos con capacidad de hasta 100
    Producto* aProducto = new Producto[100];
    char nombreArchivo[30];
    //Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open(nombreArchivo);
    //Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
    if (nuevoArchivo.is_open()) {
        
        ObtenerInfo(aProducto, 100, nuevoArchivo);
        //Mostramos los productos sin ordenar
        cout<<"Entrada :"<<endl;
        for (int i = 0; i<=numProductos; i++) {
            aProducto[i].mostrarProducto();
        }
        SortProductos(aProducto, 100);
        cout<<"------------------------------------"<<endl;
        // Mostramos los productos ordenados
        cout<<"Salida:"<<endl;
        for (int i = 0; i<=numProductos; i++) {
               aProducto[i].mostrarProducto();
           }
    }else{
        cout<<"No se ha encontrado el archivo o no se ha podido abrir "<<endl;
    }
    return 0;
}
