#include <iostream>
#include <cstdlib>
#include "ficha.h"

using namespace std;

//class Ficha;

void Ficha::imprimir(){
    if(this->equipo=='w')
        cout << "\033[0m";
    if(this->equipo=='b')
        cout << "\033[1;38;5;136m";
    if(this->equipo=='n')
        cout << "\033[32;1m";
    cout << this->caracter << "\033[0m";


}
/*
Torre::~Torre(){

}

Caballo::~Caballo(){
    
}

Alfil::~Alfil(){
    
}

Rey::~Rey(){
    
}

Reina::~Reina(){
    
}

Peon::~Peon(){
    
}

Vacio::~Vacio(){
    
}*/

void Ficha::vaciar(){
    this->nombre = "Vacio";
    this->caracter = ' ';
    this->equipo = 'n';
}

bool Ficha::puede_comer_rey(){
    return false;
}

bool Ficha::esta_vacia(){
    return (!(this->equipo=='w' || this->equipo=='b'));
}

std::string Ficha::devolver_nombre(){
    return this->nombre;
}

char Ficha::devolver_caracter(){
    return this->caracter;
}


void Ficha::asignar_ficha(Ficha * ficha){
    this->nombre = ficha->devolver_nombre();
    this->caracter = ficha->devolver_caracter();
    this->equipo = ficha->devolver_equipo();

}

char Ficha::devolver_equipo(){
    return this->equipo;
}



Torre::Torre(char equipo){
    this->nombre = "Torre";
    this->caracter = 'R';
    this->equipo = equipo;
}

bool Torre::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return(
        (cxs==cxl && cys!=cyl) || (cys==cyl && cxs!=cxl)
    );
}


Caballo::Caballo(char equipo){
    this->nombre = "Caballo";
    this->caracter = 'H';
    this->equipo = equipo;
}

bool Caballo::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return(
        (abs(cxs-cxl)==2 && abs(cys-cyl)==1) || (abs(cys-cyl)==2 && abs(cxs-cxl)==1)
    );
}



Alfil::Alfil(char equipo){
    this->nombre = "Alfil";
    this->caracter = 'B';
    this->equipo = equipo;
}

bool Alfil::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return(
        (abs(cxs-cxl)==abs(cys-cyl)) && ((cxs=!cxl) || (cys=!cyl))
    );
}


Rey::Rey(char equipo){
    this->nombre = "Rey";
    this->caracter = 'K';
    this->equipo = equipo;
}

bool Rey::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return(
        (abs(cxs-cxl)>=1 && abs(cys-cyl)>=1) && ((cxs=!cxl) || (cys=!cyl))
    );
}


Reina::Reina(char equipo){
    this->nombre = "Reina";
    this->caracter = 'Q';
    this->equipo = equipo;
}

bool Reina::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return(
        ((cxs==cxl && cys!=cyl) || (cys==cyl && cxs!=cxl)) || ((abs(cxs-cxl)==abs(cys-cyl)) && ((cxs=!cxl) || (cys=!cyl)))
    );
}



Peon::Peon(char equipo){
    this->nombre = "Peon";
    this->caracter = 'P';
    this->equipo = equipo;
}

bool Peon::es_movimiento_valido(int cys, int cxs, int cyl, int cxl, bool come){
    if(this->equipo=='b'){
        if(come)
            return(
                (cys+1==cyl) && (abs(cxs-cxl)==1)
            );
        if(cxs==1){
            return(
                (cxs==cxl) && (cys+1==cyl || cys+2==cyl)
            );
        }
        else{
            return(
                (cxs==cxl) && (cys+1==cyl)
            );
        }
    }
    if(this->equipo=='w'){
        if(come)
            return(
                (cys-1==cyl) && (abs(cxs-cxl)==1)
            );
        if(cxs==6){
            return(
                (cxs==cxl) && /*((cys-1==cyl) || cys-2==cyl)*/ (abs(cys-cyl)<=2) && (cyl=!cys)
            );
        }
        else{
            return(
                (cxs==cxl) && /*(cys-1==cyl)*/ abs(cys-cyl)==1
            );
        }
    }
    return false;
}



Vacio::Vacio(){
    this->nombre = "Vacio";
    this->caracter = ' ';
    this->equipo = 'n';
}

bool Vacio::es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come){
    return false;
}