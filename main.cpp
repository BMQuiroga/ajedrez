#include <iostream>
#include "tablero.h"
//#include "ficha.cpp"
using namespace std;

int main(){
    bool partido = true;
    bool turnovalido = false;
    char ganador;
    Tablero *tablero = new Tablero;
    while (partido){
        while(!turnovalido){
            turnovalido = tablero->menu_mover('w');
        }
        turnovalido = false;
        if(tablero->jaque_mate('w','b')){
            partido = false;
            ganador = 'w';
            turnovalido = true; //para que pase el turno de las negras
        }
        while(!turnovalido){
            turnovalido = tablero->menu_mover('w');//PARA PRUEBAS
        }
        turnovalido = false;
        if(tablero->jaque_mate('b','w')){
            partido = false;
            ganador = 'b';
        }
    }
    tablero->destruir();
    return 0;
}