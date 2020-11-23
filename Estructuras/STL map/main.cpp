//
//  main.cpp
//  Estructuras
//
//  Created by Aby Velazquez on 14/11/20.
//  Copyright © 2020 Aby Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <string>
using namespace std;


class Trabajador{

public:
    string curp;
    string nombre;
    bool operator < (const Trabajador& t1)const{
        if (this->curp<t1.curp)
        return true;
        else return false;
    }
    
};

int main(){
    set<Trabajador> setCheckinTrabajadores;
    setCheckinTrabajadores.insert({"VESA190700CD","Abigail"});
    setCheckinTrabajadores.insert({"VESO190700CD","Omar"});
    setCheckinTrabajadores.insert({"VAPO190801CD","Oscar"});
    setCheckinTrabajadores.insert({"VESO190700CD","Omar"});
    for(const auto& t:setCheckinTrabajadores){
        
        cout<< "Los trabajadores que han venido a trabajar hoy son:  "<<t.nombre<<" "<<" con el curp "<<t.curp<<endl;
    }
    cout<<"El numero de trabajadores que vinieron es : "<<setCheckinTrabajadores.size()<<endl;
    return 0;
}







//    map<string,vector<int>>MapGruposSemestral;
//    MapGruposSemestral["TC1018.2"].push_back(1566592);
//    MapGruposSemestral["TC1018.2"].push_back(1566582);
//    MapGruposSemestral["TC1018.2"].push_back(1566572);
//    MapGruposSemestral["TC1018.2"].push_back(1366597);
//    MapGruposSemestral["TC2030.1"].push_back(1366597);
//    MapGruposSemestral["TC2030.1"].push_back(1566592);
//
//    for (auto &grupo: MapGruposSemestral) {
//        cout<<"En el grupo : "<<grupo.first<< " estan inscritos : "<<endl;
//        for (auto &matriculas: grupo.second) {
//            cout<<matriculas<<endl;
//        }
//        cout<<endl;
//    }
