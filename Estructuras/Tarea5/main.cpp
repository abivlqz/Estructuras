//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 30/08/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

   
class Complejo{
private:
    //atributos
    double pReal, pImag;
    
public:
    //Constructor1
    Complejo(double pReal,double pImag){
        this->pReal = pReal;
        this->pImag = pImag;
    }
    //Constructor2 para un arreglo de objetos
    Complejo(){
        
    }
    
    Complejo operator +(Complejo& complejo){
        Complejo resultado;
        resultado.pReal = this->pReal + complejo.pReal;
        resultado.pImag = this->pImag + complejo.pImag;
        return resultado;
    }
    
    Complejo operator -(Complejo& complejo){
        Complejo resultado;
        resultado.pReal = this->pReal - complejo.pReal;
        resultado.pImag = this->pImag -complejo.pImag;
        return resultado;
    }
    
    Complejo operator * (Complejo& complejo){
        Complejo resultado;
        resultado.pReal = (this->pReal*complejo.pReal)-(this->pImag*complejo.pImag);
        resultado.pImag = (this->pReal*complejo.pImag)+(this->pImag*complejo.pReal);
        return resultado;
        
    }
    
    Complejo operator / (Complejo& complejo){
        Complejo resultado;
        double denominador = (complejo.pReal*complejo.pReal)+(complejo.pImag*complejo.pImag);
        double nomReal = (this->pReal*complejo.pReal)+(this->pImag*complejo.pImag);
        double nomImag = (this->pImag*complejo.pReal)-(this->pReal*complejo.pImag);
        resultado.pReal = nomReal/denominador;
        resultado.pImag = nomImag/denominador;
        return resultado;
    }
    
    bool operator == (Complejo& complejo){
        if (this->pReal == complejo.pReal && this->pImag == complejo.pImag) {
            return true;
        }else return false;
    }
    
    void mostrarComplejo(){
        cout<<"el resultado de esta operacion con complejos es "<<pReal<<" + "<<pImag<<"i "<<endl;
    }
    
};


int main(){
    Complejo c1(-3,-2);
    Complejo c2(-3,-2);
    Complejo c3(2,1);
    
    Complejo resultadoSuma = c1+c2;
    Complejo resultadoResta = c1-c2;
    Complejo resultadoMult = c1*c2*c3;
    Complejo resultadoDivision = c1/c2;
    if (c1==c2) {
        cout<<"Los dos complejos son iguales "<<endl;
    }else
        cout<<"No son iguales"<<endl;
    
    resultadoSuma.mostrarComplejo();
    resultadoResta.mostrarComplejo();
    resultadoMult.mostrarComplejo();
    resultadoDivision.mostrarComplejo();
    
    
    return 0;
}
