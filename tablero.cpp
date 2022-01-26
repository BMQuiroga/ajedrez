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

Tablero::Tablero(Tablero * anterior){
    Ficha *** casilla;
    casilla = new Ficha**[8];
    for(int i=0; i<8; i++)
        casilla[i] = new Ficha*[8];
    
    this->tablero = casilla;
     for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            this->tablero[i][j] = anterior->tablero[i][j];
        }
    }
}

void Tablero::setear_fichas(){
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
        //this->tablero[6][i]= new Peon('w');
        this->tablero[6][i]= new Vacio;//ESTE NO VA
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

void Tablero::encontrar_rey(char jugador, int *x, int *y){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (this->tablero[i][j]->devolver_caracter()=='K'){
                if (this->tablero[i][j]->devolver_equipo()==jugador){
                    *x = j;
                    *y = i;
                    return;
                }
            }
        }
    }
}

bool Tablero::es_valido(char jugador){
    int reyx = 0;
    int reyy = 0;
    encontrar_rey(jugador,&reyx,&reyy);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (this->tablero[i][j]->devolver_equipo()!=jugador){
                if (this->tablero[i][j]->es_movimiento_valido(j,i,reyx,reyy,true)){
                    if(validador_de_movimientos(j,i,reyx,reyy,tablero[i][j]->devolver_caracter())){
                        cout << "La pieza de (" << j << ", " << i << ") puede comerte al rey" << endl;
                        return false;
                    }
                } 
            }
        }
    }
    return true;
}

bool Tablero::menu_mover(char jugador){
    int fila;
    int columna;
    int fila2;
    int columna2;
    bool come = false;
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
        cout << "En la posicion (" << columna << ", " << fila << ") hay un(a) " << tablero[fila][columna]->devolver_nombre() << endl;
    
    if(tablero[fila][columna]->devolver_equipo()!=jugador){
        cout << "Esta ficha no es tuya!" << endl;
        return false;
    }


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

    if(columna==columna2 && fila==fila2){
        cout << "No poder moverte en el lugar!" << endl;
        return false;
    }

    if(tablero[fila2][columna2]->devolver_equipo()==jugador){
        cout << "No podes capturar tu propia ficha!" << endl;
        return false;
    }

    if(tablero[fila2][columna2]->devolver_equipo()!='n'){
        come = true;
    }

    //if  (tablero[fila][columna]->es_movimiento_valido(fila,columna,fila2,columna2,come)){
    if  (tablero[fila][columna]->es_movimiento_valido(columna,fila,columna2,fila2,come)){
        if (validador_de_movimientos(columna,fila,columna2,fila2,tablero[fila][columna]->devolver_caracter())){
            //Tablero siguiente;
            //siguiente.mover_provisional(fila,columna,fila2,columna2);
            //if(siguiente.es_valido(jugador)){

            Tablero siguiente(this);
            Ficha * aux_llegada = tablero[fila2][columna2];
            Ficha * aux_salida = tablero[fila][columna];
            mover_provisional(fila,columna,fila2,columna2);

            if(es_valido(jugador)){
                //delete siguiente;
                //siguiente.borrar_vacio_provisional(fila,columna);
                //mover_definitivo(fila,columna,fila2,columna2);
                delete aux_llegada;
                return true;
            }
            else{
                delete aux_salida;
                this->tablero = siguiente.tablero;
                cout << "El movimiento no es valido debido a que tu rey queda en jaque" << endl;
            }

        }
        else
            cout << "El recorrido esta bloqueado, Movimiento invalido" << endl;  

    } 
    else
        cout << "El movimiento no es valido" << endl;
    

    return false;
}

void Tablero::borrar_vacio_provisional(int x, int y){
    delete this->tablero[x][y];
}

void Tablero::mover_provisional(int cxs, int cys, int cxl, int cyl){
    //this->tablero[cxl][cyl]->asignar_ficha(this->tablero[cxs][cys]);
    //this->tablero[cxs][cys]->vaciar();
    //delete this->tablero[cxl][cyl];
    this->tablero[cxl][cyl]= this->tablero[cxs][cys];
    this->tablero[cxs][cys]= new Vacio;
}

void Tablero::mover_definitivo(int cxs, int cys, int cxl, int cyl){
    //this->tablero[cxl][cyl]->asignar_ficha(this->tablero[cxs][cys]);
    //this->tablero[cxs][cys]->vaciar();
    delete this->tablero[cxl][cyl];
    this->tablero[cxl][cyl]= this->tablero[cxs][cys];
    this->tablero[cxs][cys]= new Vacio;
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

void Tablero::destruir(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            delete this->tablero[i][j];
        }
    }
}

bool Tablero::validador_de_movimientos(int cxs, int cys, int cxl, int cyl, char ficha){
    int x = abs(cxs-cxl);
    int y = abs(cys-cyl);
    if (ficha == 'R' || (ficha == 'Q' && (x==0 || y==0))){
        if (x==0){
            if (cys>cyl){
                for(int i=cyl+1; i<cys; i++){
                    if(!tablero[i][cxs]->esta_vacia())
                        return false;
                }
            }
            else{
                for(int i=cys+1; i<cyl; i++){
                    if(!tablero[i][cxs]->esta_vacia())
                        return false;
                }
            }
        }
        if (y==0){
            if (cxs>cxl){
                for(int i=cxl+1; i<cxs; i++){
                    if(!tablero[cys][i]->esta_vacia())
                        return false;
                }
            }
            else{
                for(int i=cxs+1; i<cxl; i++){
                    if(!tablero[cys][i]->esta_vacia())
                        return false;
                }
            }
        }
    }
    if (ficha == 'B' || (ficha == 'Q' && x==y)){
        int final = x-1; //Hecho para que no cuente como "camino" la casilla de llegada, si no estuviera, el alfil no podria comer
        if (cxs>cxl && cys>cyl){//CASO 1
            for (int i=0; i<final; i++){
                if (!tablero[cys-1-i][cxs-1-i]->esta_vacia())
                    return false;
            }
        }
        if (cxs<cxl && cys>cyl){//CASO2
            for (int i=0; i<final; i++){
                if (!tablero[cys-1-i][cxs+1+i]->esta_vacia())
                    return false;
            }
        }
        if (cxs>cxl && cys<cyl){//CASO3
            for (int i=0; i<final; i++){
                if (!tablero[cys+1+i][cxs-1-i]->esta_vacia())
                    return false;
            }
        }
        if (cxs<cxl && cys<cyl){//CASO 4
            for (int i=0; i<final; i++){
                if (!tablero[cys+1+i][cxs+1+i]->esta_vacia())
                    return false;
            }
        }
    }
    return true;
}