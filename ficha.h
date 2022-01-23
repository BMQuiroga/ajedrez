#include <iostream>

class Ficha {
    protected:
        std::string nombre;
        char caracter;
        char equipo;
        //int coordx;
        //int coordy;
    public:
        //virtual ~Ficha() = 0;
        //virtual void mover(int x, int y);
        virtual bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come) = 0;
        //bool puede_comer_rey(int cxs, int cys, int cxk, int cyk);
        bool esta_vacia();
        std::string devolver_nombre();
        char devolver_caracter();
        char devolver_equipo();
        //void asignar_ficha(Ficha* ficha);
        //void vaciar();
        void imprimir();
};

class Torre: public Ficha {
    public:
        //void mover(int x, int y);
        //~Torre();
        Torre(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Caballo: public Ficha {
    public:
        //void mover(int x, int y);
        //~Caballo();
        Caballo(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Alfil: public Ficha {
    public:
        //void mover(int x, int y);
        //~Alfil();
        Alfil(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Rey: public Ficha {
    public:
        //void mover(int x, int y);
        //~Rey();
        Rey(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Reina: public Ficha {
    public:
        //void mover(int x, int y);
        //~Reina();
        Reina(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Peon: public Ficha {
    public:
        //void mover(int x, int y);
        //~Peon();
        Peon(char equipo);
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);

};

class Vacio: public Ficha {
    public:
        //void mover(int x, int y);
        //~Vacio();
        Vacio();
        bool es_movimiento_valido(int cxs, int cys, int cxl, int cyl, bool come);
};