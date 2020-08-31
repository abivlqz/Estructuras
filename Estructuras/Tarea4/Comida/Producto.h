//
//  Producto.h
//  Estructuras
//
//  Created by Aby Velazquez on 24/08/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//
using namespace std;
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
    //Metodos de acceso getters y setters
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
    // Imprime en pantalla los atributos del objeto
    void mostrarProducto(){
        cout<<nombre<<" ";
        cout<<gramos<<" ";
        cout<<calorias<<endl;
    }
    
    //operador que compara dos objetos de tipo Producto
    bool operator <(Producto& producto){
        //Convertir los nombres de productos a letras minusculas para que la comparacion sea conforme al abecedario y no ASCII
        string auxName1 =this->nombre,auxName2= producto.getNombre();
        for (int i = 0; i < auxName1.length(); i++) {
          auxName1[i] = tolower(auxName1[i]);
        }
        for (int i = 0; i < auxName2.length(); i++) {
          auxName2[i] = tolower(auxName2[i]);
        }
        //Si el nombre del producto1 es menor al producto2 el comparador declara que el producto1
        // es menor
        if (auxName1<auxName2) {
            return true;
        }
        else if (auxName1>auxName2){
            return false;
        }
        else{//Si los nombres de productos son iguales
            //Si los gramos del producto1 son menor a los del producto2 el comparador declara que el producto1  es menor
            if (this->gramos<producto.getGramos()) {
                return true;
            }
            else if (this->gramos>producto.getGramos()){
                return false;
            }
            else{// Si la cantidad de gramos de un producto son iguales
                 //Si las calorias del producto1 son menor a los del producto2 el comparador declara que el producto1  es menor
                if (this->calorias<producto.getCalorias()) {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        
        
        
    }
    
    
};
