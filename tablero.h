#include "ficha.h"

class Tablero {
    protected:
        Ficha ***tablero;
    public:
        Tablero();
        Tablero(Tablero * tablero);
        ~Tablero();
        void setear_fichas();
        bool es_valido(char jugador);
        bool menu_mover(char jugador);
        void mover_provisional(int cxs, int cys, int cxl, int cyl);
        void mover_definitivo(int cxs, int cys, int cxl, int cyl);
        void imprimir();
        bool validador_de_movimientos(int cxs, int cys, int cxl, int cyl, char ficha);
        void borrar_vacio_provisional(int x, int y);
        void encontrar_rey(char jugador, int x, int y);
    

};

