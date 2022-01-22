#include <iostream>
#include "tablero.h"

using namespace std;



Tablero::Tablero(){
    Ficha *** casilla;
    casilla = new Ficha**[8];
    for(int i=0; i<8; i++)
        casilla[i] = new Ficha*[8];
    
    this->tablero = casilla;
    setear_fichas();
}

void Tablero::setear_fichas(){
    /*
    Torre torrew('w');
    Caballo caballow('w');
    Alfil alfilw('w');
    Rey reyw('w');
    Reina reinaw('w');
    Peon peonw('w');
    Torre torreb('b');
    Caballo caballob('b');
    Alfil alfilb('b');
    Rey reyb('b');
    Reina reinab('b');
    Peon peonb('b');
    Vacio vacio;

    this->tablero[0][0]->asignar_ficha(&torreb);
    this->tablero[1][0]->asignar_ficha(&caballob);
    this->tablero[2][0]->asignar_ficha(&alfilb);
    this->tablero[3][0]->asignar_ficha(&reinab);
    this->tablero[4][0]->asignar_ficha(&reyb);
    this->tablero[5][0]->asignar_ficha(&alfilb);
    this->tablero[6][0]->asignar_ficha(&caballob);
    this->tablero[7][0]->asignar_ficha(&torreb);
    this->tablero[0][7]->asignar_ficha(&torrew);
    this->tablero[1][7]->asignar_ficha(&caballow);
    this->tablero[2][7]->asignar_ficha(&alfilw);
    this->tablero[3][7]->asignar_ficha(&reinaw);
    this->tablero[4][7]->asignar_ficha(&reyw);
    this->tablero[5][7]->asignar_ficha(&alfilw);
    this->tablero[6][7]->asignar_ficha(&caballow);
    this->tablero[7][7]->asignar_ficha(&torrew);
    for(int i=0; i<7; i++){
        this->tablero[i][1]->asignar_ficha(&peonb);
        this->tablero[i][6]->asignar_ficha(&peonw);
        for(int j=2; j<6; j++){
            this->tablero[i][j]->asignar_ficha(&vacio);
        }
    }*/
    this->tablero[0][0]= new Torre('b');
    this->tablero[0][1]= new Caballo('b');
    this->tablero[0][2]= new Alfil('b');
    this->tablero[0][3]= new Reina('b');
    this->tablero[0][4]= new Rey('b');
    this->tablero[0][5]= new Alfil('b');
    this->tablero[0][6]= new Caballo('b');
    this->tablero[0][7]= new Torre('b');
    for(int i=0; i<8; i++){
        this->tablero[1][i]= new Peon('b');
        this->tablero[6][i]= new Peon('w');
        for(int j=2; j<6; j++){
            this->tablero[j][i]= new Vacio;
        }
    }
    this->tablero[7][0]= new Torre('w');
    this->tablero[7][1]= new Caballo('w');
    this->tablero[7][2]= new Alfil('w');
    this->tablero[7][3]= new Reina('w');
    this->tablero[7][4]= new Rey('w');
    this->tablero[7][5]= new Alfil('w');
    this->tablero[7][6]= new Caballo('w');
    this->tablero[7][7]= new Torre('w');
}

bool Tablero::es_valido(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (this->tablero[i][j]->puede_comer_rey())
                return false;
        }
    }
    return true;
}

bool Tablero::menu_mover(char jugador){
    int fila;
    int columna;
    int fila2;
    int columna2;
    cout << "----------------------------------" << endl;
    cout << "TURNO DE LAS ";
    if(jugador=='w')
        cout <<"BLANCAS"<<std::endl;
    else
        cout << "NEGRAS"<<std::endl;
    cout << "----------------------------------" << endl;
    imprimir();
    cout << "Ingrese la coordenada x [entre 0 - 8] -> ";    cin >> columna;
    while(columna < 0 || columna > 7) {
        cout << "Columna no valida. Ingrese de nuevo. [entre 0 - 8]";
        cin >> columna; 
    }
    
    cout << "Ingrese la coordenada y [entre 0 - 8] -> ";    cin >> fila;
    while(fila < 0 || fila > 7) {
        cout << "Fila no valida. Ingrese de nuevo. [entre 0 - 8]";
        cin >> fila; 
    }
    if(tablero[fila][columna]->esta_vacia()){
        cout << "La casilla esta vacia" << std::endl;
        return false;
    }
    else
        cout << "En la posicion (" << fila << ", " << columna << ") hay un(a) " << tablero[fila][columna]->devolver_nombre() << endl;
    
    
    cout << "Ingrese la coordenada x [entre 0 - 8] -> ";    cin >> columna2;
    while(columna2 < 0 || columna2 > 7) {
        cout << "Columna no valida. Ingrese de nuevo. [entre 0 - 8]";
        cin >> columna2; 
    }
    
    cout << "Ingrese la coordenada y [entre 0 - 8] -> ";    cin >> fila2;
    while(fila2 < 0 || fila2 > 7) {
        cout << "Fila no valida. Ingrese de nuevo. [entre 0 - 8]";
        cin >> fila2; 
    }

    if  (tablero[fila][columna]->es_movimiento_valido(fila,columna,fila2,columna2,!tablero[fila2][columna2]->esta_vacia()) && 
        (tablero[fila2][columna2]->devolver_equipo() != tablero[fila][columna]->devolver_equipo())){
        //tablero[fila][columna]->mover(fila2,columna2);
        mover(fila,columna,fila2,columna2);
        return true;
    }

    return false;
}

void Tablero::mover(int cxs, int cys, int cxl, int cyl){
    this->tablero[cxl][cyl]->asignar_ficha(this->tablero[cxs][cys]);
    this->tablero[cxs][cys]->vaciar();

}

void Tablero::imprimir(){
    cout << "++++++++++" << std::endl;
    for(int i=0; i<8; i++){
        cout << "+";
        for(int j=0; j<8; j++){
            this->tablero[i][j]->imprimir();
        }
        cout << "+" << std::endl;
    }
    cout << "++++++++++" << std::endl;
}

