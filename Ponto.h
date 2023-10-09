#include <cmath>
#ifndef PONTO_H
#define PONTO_H

class Ponto{
    private:
        int x, y;
    public:
        Ponto();
        Ponto(int, int);
        int getX();
        int getY();
        void setCoordenadas(int, int);
        double distancia_ate_origem();
};

#endif