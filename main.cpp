#include <iostream>
#include "tablero.h"
//#include "ficha.cpp"


using namespace std;

int main(){
    bool partido = true;
    bool turnovalido = false;
    Tablero *tablero = new Tablero;
    while (partido){
        while(!turnovalido){
            turnovalido = tablero->menu_mover('w');
        }
        turnovalido = false;
        while(!turnovalido){
            turnovalido = tablero->menu_mover('w');//PARA PRUEBAS
        }
        turnovalido = false;
    }
    tablero->destruir();
    return 0;
}