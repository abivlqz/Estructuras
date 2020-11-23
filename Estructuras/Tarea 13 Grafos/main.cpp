//  Tarea13
//  main.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 15/11/2020
//  Este programa pide al usuario el nombre del archivo (con extension) txt que contendrá un grafo implementado en una matriz de adyacencias.
//  El programa imprime un menú con 3 opciones a realizar.
//  El programa imprime en pantalla ya sea el recorrido por anchura o profundidad del grafo o imprime si hay un camino de un nodo a otro.
//  Solo imprime un camino posible e imprime el total del recorrido de ese camino.
//  Este proyecto trae dos archivo de prueba llamado "grafo.txt" y otro llamado "grafo2.txt" para que se pueda visualizar que las operaciones dan resultados correctos.

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Stack.h"
#include <queue>
using namespace std;

int numNodos;

// Funcion cargarMatriz que lee el archivo dado por el usuario, guarda la matriz de adyacencias
// Sus parametros son: un archivo txt abierto, una matriz de capacidad de 100 nodos, no tiene retornos
void cargarMatriz(fstream& nuevoArchivo,int mat[][100] ){
    int prioridad;
    string firstLine,valor;
    //Se lee la primera linea que indica el numero de nodos de la matriz
    getline(nuevoArchivo,firstLine);
    // Convierte el string a int
    stringstream stoInt(firstLine);
    stoInt>>numNodos;
    string lines;
    while (!nuevoArchivo.eof()) {
        for (int i = 0; i<numNodos; i++) {
            //Lee linea por linea el txt
            getline(nuevoArchivo,lines);
            //Lee en la linea i un string hasta que se encuentre con un espacio
            stringstream linestream(lines);
            for (int j = 0; j<numNodos; j++) {
            getline(linestream,valor,' ');
            // Convierte el valor a int
            stringstream stoInt(valor);
            stoInt>>prioridad;
            mat[i][j]=prioridad;
            }
        }
    }
    nuevoArchivo.close();
}

// Funcion DepthFirst que dada una matriz de adyacencias, realiza un recorrido por todos los nodos por profundidad utilizando una pila
// Sus parametros son: una matriz de capacidad de 100 nodos, una pila de enteros, no tiene retornos
void DepthFirst(int mat[][100],Stack<int>& nodos){
    
    int aux=0;
    // false es en espera, true es procesado
    //arreglo de banderas de procesado o en espera de los nodos
    bool status[100]={false};
    //se mete el primer nodo asumimos que se agregaron en orden numerico
    nodos.push(0);
    while (!nodos.isEmpty()&& status[nodos.peek()]!=true) {
        //Se procesa el tope de la pila
        cout<<nodos.peek()<<" ";
        //Se guarda el nodo para despues buscar sus vecinos
        aux=nodos.peek();
        // cambiamos el nodo a procesado
        status[nodos.peek()]=true;
        // se elimina de la pila
        nodos.pop();
        // se empieza del ultimo nodo ya que se agrega del mayor al menor a la pila
        for (int j= numNodos-1; j>=0; j--) {
            // Se buscan los vecinos en espera del nodo que se acaba de procesar
            if (mat[aux][j]!=0 && status[j]!=true) {
                //Se meten a la pila
                nodos.push(j);
            }
        }
    }
    cout<<endl;
}

// Funcion DepthFirstS que dada una matriz de adyacencias, determina si existe un camino de un nodo a otro, e imprime el primer camino que encuentra, realizando un recorrido por profundidad.
// Sus parametros son: una matriz de capacidad de 100 nodos, una pila de enteros, dos enteros indicando el nodo origen y el nodo destino
void DepthFirstS(int mat[][100],Stack<int>& nodos,int x, int y){
    bool encontrado=false;
    int aux,temp=0;
    int total=0;
    queue<int> nodosvisitados;
    int aux2=0;
    // false es en espera, true es procesado
    //arreglo de banderas de procesado o en espera de los nodos
    bool status[100]={false};
    //se mete el primer nodo asumimos que se agregaron en orden numerico
    nodos.push(x);
    
    while (!nodos.isEmpty() && status[nodos.peek()]!=true && encontrado==false) {
        //Se procesa el tope de la pila
        //Se guarda el nodo para despues buscar sus vecinos
        aux=nodos.peek();
        //El numero de nodos visitados aumenta
        aux2+=1;
        // Se realiza el registro del recorrido
        nodosvisitados.push(aux);
        // cambiamos el nodo a procesado
        status[nodos.peek()]=true;
        // se elimina de la pila
        nodos.pop();
        
        // se empieza del ultimo nodo ya que se agrega del mayor al menor a la pila
        for (int j= numNodos-1; j>=0; j--) {
            // Se buscan los vecinos en espera del nodo que se acaba de procesar
            if (mat[aux][j]!=0 && status[j]!=true) {
                //Se meten a la pila
                nodos.push(j);
               
            if (j==y){
            //El numero de nodos visitados aumenta
            aux2+=1;
            nodosvisitados.push(nodos.peek());
            // Si j coincide con y se ha encontrado y si hay camino
            encontrado=true;
            }
                           
            }
           
        }
       
    }
    cout<<endl;
    
    if (encontrado){
        cout<<"Si hay camino"<<endl;
        // Se imprime el registro del recorrido
        for (int i = 0; i<aux2-1; i++) {
            temp=nodosvisitados.front();
            cout<<temp<<"->";
            nodosvisitados.pop();
            // Se suma el arco entre los nodos visitados
            total+=mat[temp][nodosvisitados.front()];
        }
        // Se imprime el nodo destino
        cout<<nodosvisitados.front()<<endl;
        // Se imprime la suma de los arcos del recorrido
        cout<<"El total del recorrido es ="<<total<<endl;
    }
    else
        cout<<"No hay camino"<<endl;
    
        
}

// Funcion BreadthFirst que dada una matriz de adyacencias, realiza un recorrido por todos los nodos por anchura utilizando una fila
// Sus parametros son: una matriz de capacidad de 100 nodos, una fila de enteros, no tiene retornos
void BreadthFirst(int mat[][100],queue<int>& nodos){
    int aux=0;
    //Arreglo con banderas de procesado,listo o en espera
    string status[100];
    //Se mete el primer nodo asumimos que se agregaron en orden numerico
    nodos.push(0);
    while (!nodos.empty()) {
        //Se procesa el primer elemento de la fila
        cout<<nodos.front()<<" ";
        //Se guarda el nodo para despues buscar sus vecinos
        aux=nodos.front();
        //Se cambia el status a procesado
        status[aux]="Procesado";
        // Se elimina de la fila
        nodos.pop();
        // Se busca de menor a mayor ya que asi se agrega a la fila
        for (int j=0; j<numNodos; j++) {
            // Si los vecinos del nodo estan en espera se meten a la fila
            if (mat[aux][j]!=0 && status[j]!="Procesado" && status[j]!="Listo") {
                nodos.push(j);
                //Se cambia el estado del vecino a listo
                status[j]="Listo";
            }
        }
    }
    cout<<endl;
}

// Funcion imprimirMenu que imprime en pantalla las opciones del menu y da de retorno un character para determinar que opcion ejecutar
char imprimirMenu( ){
    char letra;
    
    cout<<endl;
    cout<<" a.  Saber el recorrido a profundidad (Depth first)"<<endl;
    cout<<" b. Saber el recorrido recorrido en anchura (Breadth first)"<<endl;
    cout<<" c. Saber si existe un camino de un nodo a otro nodo e imprimirlo "<<endl;
    cout<<" d. SALIR"<<endl;
    cout<<" Escribir la letra correspondiente "<<endl;
    cin>>letra;
    return letra;
}


// Programa Principal
int main(){
    //Matriz con capacidad de hasta 100 nodos
    int matriz[100][100];
    char letra;
    int x,y;
    Stack<int> nodospila;
    queue<int> nodosfila;
    char nombreArchivo[30];
       //Preguntamos el nombre del archivo
       cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
       cin.getline(nombreArchivo, 30);
       //Declaramos y abrimos el archivo
       fstream nuevoArchivo;
       nuevoArchivo.open(nombreArchivo);
       //Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
       if (nuevoArchivo.is_open()) {
           cargarMatriz(nuevoArchivo, matriz);
           cout<<" -------- BIENVENID@, ¿Qué deseas saber de tu grafo?     -----------"<<endl;
           letra=imprimirMenu();
           while (letra=='a') {
               cout<<"El recorrido en profundidad es : "<<endl;
               DepthFirst(matriz, nodospila);
               cout<<endl;
               letra=imprimirMenu();
           }
           while (letra=='b') {
               cout<<"El recorrido en anchura es : "<<endl;
               BreadthFirst(matriz, nodosfila);
               cout<<endl;
               letra=imprimirMenu();
           }
           while (letra=='c') {
               cout<<"Ingresa el nodo origen"<<endl;
               cin>>x;
               cout<<"Ingresa el nodo destino"<<endl;
               cin>>y;
               DepthFirstS(matriz, nodospila, x, y);
               cout<<endl;
               letra=imprimirMenu();
           }
           while (letra=='d') {
              return 0;
           }
           while (letra!='a' && letra!='b' && letra!='c' && letra!='d') {
               cout<<"Ingresa una opción válida "<<endl;
               letra=imprimirMenu();
           }
           
       }else{
           cout<<"No se ha encontrado el archivo o no se ha podido abrir "<<endl;
       }
    return 0;
}
