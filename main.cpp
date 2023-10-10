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
    void setCoodenadas(double _x, double _y);
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

void Ponto::setCoodenadas(double _x, double _y) {
    x = _x;
    y = _y;

}

int main() {
    Ponto ponto1(3, 4);

    double distanciaEntrePontos = ponto1.calcularDistancia();
    cout << "Distancia entre os pontos: " << distanciaEntrePontos << endl;

    Ponto ponto2(-2, 7);
    ponto2.setCoodenadas(1, 1);
    double distanciaEntrePontos_p2 = ponto2.calcularDistancia();
    cout << "Distancia entre os pontos 2: " << distanciaEntrePontos_p2 << endl;

    Ponto ponto3(0, 3);
    double distanciaEntrePontos_p3 = ponto3.calcularDistancia();

    Ponto ponto4(4, 0);
    double distanciaEntrePontos_p4 = ponto4.calcularDistancia();

    cout << "Distancia entre os pontos: " <<"(" << ponto3.getX() <<", " << ponto3.getY() <<") ate a origem e: " << distanciaEntrePontos_p3 <<  
    "e o ponto " <<"(" << ponto4.getX() <<", " << ponto4.getY() <<") ate a origem e: " << distanciaEntrePontos_p4 << endl;

    Ponto pontos[3];
    pontos[0].setCoodenadas(2, 2);
    pontos[1].setCoodenadas(-1, 5);
    pontos[2].setCoodenadas(0, 0);

    for (int i = 0; i < 3; i++){
        double distancia= pontos[i].calcularDistancia();
        cout << "Distancia do ponto " << i + 1 << " ate a origem: " << distancia<< endl;

    }

    return 0;
}
