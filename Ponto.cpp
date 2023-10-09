#include "Ponto.h"

Ponto::Ponto(){

}

Ponto::Ponto(int x, int y){
    this->x = x;
    this->y = y;
}

int Ponto::getX(){
    return this->x;
}

int Ponto::getY(){
    return this->y;
}

void Ponto::setCoordenadas(int x, int y){
    this->x = x;
    this->y = y;
}

double Ponto::distancia_ate_origem(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}