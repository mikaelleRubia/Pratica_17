#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    Ponto();
    Ponto(double _y, double _x);
    double calcularDistancia();
    double getX() const;
    void setX(double _x);
    double getY() const;
    void setY(double _y);
};

Ponto::Ponto() {
    y = 0.0;
    x = 0.0;
}

Ponto::Ponto(double _y, double _x) {
    y = _y;
    x = _x;
}

double Ponto::getX() const {
    return x;
}

void Ponto::setX(double _x) {
    x = _x;
}

double Ponto::getY() const {
    return y;
}

void Ponto::setY(double _y) {
    y = _y;
}

double Ponto::calcularDistancia() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {
    Ponto ponto1(3, 4);

    double distanciaEntrePontos = ponto1.calcularDistancia();

    cout << "Distancia entre os pontos: " << distanciaEntrePontos << endl;

    return 0;
}
