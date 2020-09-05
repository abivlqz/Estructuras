//  Proyecto: Vector
//  main.cpp
//  Estructuras de Datos
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo2
//  Creado el 05/09/2020
//  Este programa realiza operaciones a un vector de acuerdo a las instrucciones de un archivo txt llamado "operaciones.txt", 'a x' agrega un entero al vector,'b' ordena ascendentemente al vector, 'c' invierte el vector, 'd' imprime el tamaño del vector, 'e' imprime los elementos del vector, 'f' ordena descendentemente el vector.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
// Funcion mostrarVector que imprime en pantalla todos los elementos de un vector separados por espacios, usando iteradores.
// Su parametro es el vector de enteros que se requiere imprimir, no tiene retornos
void mostrarVector(vector<int> & vector1){
    vector<int>::iterator i;
    for (i = vector1.begin(); i!=vector1.end(); i++) {
        cout<<*i<<" ";
    }
}

// Funcion modificarVector que lee el archivo operaciones.txt y de acuerdo al numero de casos prueba y consultas establecidos en el mismo archivo, realiza las operaciones a x, b, c, d, e y f a un vector de enteros.
// Sus parametros son: un archivo txt abierto y un vector de tipo entero, no tiene retornos
void modificarVector(fstream & archivo, vector<int> & vector){
    int T, Q;
    string stringCasos,stringConsultas,lines,operacion;
    // Se lee la primera linea del archivo que indica el numero de casos prueba
    getline(archivo,stringCasos);
    // Se convierte de string a entero
    stringstream stoInt(stringCasos);
    stoInt>>T;
    // se verifica que el numero de casos prueba sea valido, de lo contrario manda un mensaje de error
    if (T<=100 && T>0) {
            for (int numCasos = 0; numCasos<T; numCasos++) {
            // se lee la linea que indica el numero de consultas que hay en el caso donde se encuentra el ciclo
            getline(archivo,stringConsultas);
            // Se convierte de string a entero
            stringstream stoInt(stringConsultas);
            stoInt>>Q;
            // Se lee la linea que contiene las consultas del caso numCasos.
            getline(archivo,lines);
            // Se guarda un string de la linea con las consultas
            stringstream linestream(lines);
            // variable que almacenara el entero que se requiera agregar al vector en cada caso prueba
            int numVector = 0;
            // contador del numero de consultas que se resetea en cada caso prueba
            int numConsultas = 0;
            // Se verifica que el numero de consultas sea valido, de lo contrario manda un mensaje de error
            if (Q<=100 && Q>0) {
                while (numConsultas<Q) {
                        // se lee cada consulta delimitado por espacios y se guarda en un string
                        getline(linestream,operacion,' ');
                        if (operacion=="a") {
                            // Se lee de nuevo hasta que encuentre un numero a la derecha
                            linestream>>numVector;
                            // Agrega el numero al final del vector
                            vector.push_back(numVector);
                            numConsultas++;
                        }
                        else if (operacion=="b"){
                            // ordena el vector de manera ascendente
                            sort(vector.begin(), vector.end());
                            numConsultas++;
                        }else if (operacion=="c"){
                            // invierte el vector
                            reverse(vector.begin(), vector.end());
                            numConsultas++;
                        }
                        else if (operacion=="d"){
                            // imprime el tamaño del vector
                            cout<<vector.size()<<" ";
                            numConsultas++;
                        }
                        else if (operacion=="e"){
                            // imprime el vector en pantalla usando el método mostrarVector()
                            mostrarVector(vector);
                            numConsultas++;
                        }
                        else if (operacion=="f"){
                            // ordena el vector de manera descendente
                            sort(vector.begin(), vector.end(),greater<int>());
                            numConsultas++;
                        }
                    }
                    // Despues de realizar las consultas de un caso prueba, se borra el contenido del vector para realizar un nuevo caso
                    vector.clear();
                    cout<<endl;
            }else{
                    cout<<"El numero de consultas en el caso prueba numero "<<numCasos+1<<" sobrepasa el rango establecido de [1,100]"<<endl;
                    // Se define a T como un numero invalido para que el programa no continue
                    T=0;
                 }
            }
    }else
        cout<<"El numero de casos prueba sobrepasa el rango establecido de [1,100]"<<endl;
    archivo.close();
}

// Programa Principal
int main(){
    vector<int>vector;
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open("operaciones.txt");
    //Verificamos si el archivo se pudo abrir, de lo contrario manda un mensaje de error
    if (nuevoArchivo.is_open())
        // Modicamos el vector creado de acuerdo a las instrucciones en el archivo
        modificarVector(nuevoArchivo, vector);
    else
        cout<<"No se ha encontrado el archivo o no se ha podido abrir "<<endl;
    
    return 0;
}
