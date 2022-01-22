#include "ficha.h"

class Tablero {
    protected:
        Ficha ***tablero;
    public:
        Tablero();
        void setear_fichas();
        bool es_valido();
        bool menu_mover(char jugador);
        void mover(int cxs, int cys, int cxl, int cyl);
        void imprimir();

};

