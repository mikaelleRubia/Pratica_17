# include <iostream>
# include <limits>
# include <cstring>
# include <vector>
# include <cmath>
# include <iomanip>

using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:
        Ponto();
        Ponto(float _x, float _y);

        float getX();
        void setX(float x);

        float getY();
        void sety(float y);

        void setCoordenadas(float _x, float _y);

        void le_ponto();

        float distancia();

        void operator=(Ponto p);

        bool operator==(Ponto p);

        Ponto operator+(Ponto p);

        string toString();
};

Ponto::Ponto(){
    x = 0;
    y = 0;
}

Ponto::Ponto(float _x, float _y){
    x = _x;
    y = _y;
}

float Ponto::getX(){
    return x;
}

void Ponto::setX(float _x){
    x = _x;
}

float Ponto::getY(){
    return y;
}

void Ponto::sety(float _y){
    y = _y;
}

void Ponto::setCoordenadas(float _x, float _y){
    x = _x;
    y = _y;
}

void Ponto::le_ponto(){
    cout << "Informe as coordenadas do ponto: " << endl;
    cout << "Valor de X: ";
    cin >> x;
    cout << "Valor de Y: ";
    cin >> y;
}

float Ponto::distancia(){
    Ponto p = Ponto(0,0);
    return sqrtf((pow((p.getX() - this->getX()),2)) + (pow((p.getY() - this->getY()),2)));
}

void Ponto::operator=(Ponto p){
    x = p.getX();
    y = p.getY();
}
bool Ponto::operator==(Ponto p){
    return x == p.getX() && y == p.getY();
}

Ponto Ponto::operator+(Ponto p){
    return Ponto(x + p.getX(), y + p.getY());
}
string Ponto::toString(){
    return "(X: " + to_string(x) + ", Y: " + to_string(y) + ")";
}


int main()
{
    double distancia;

    Ponto p1(3, 4);
    distancia = p1.distancia();

    cout << "Distancia: " << setprecision(1) << distancia << endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    distancia = p2.distancia();

    cout << "Distancia: " << setprecision(5) << distancia << endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.distancia();
    double distancia_p4 = p4.distancia();

    cout << "Distancia P3 ate a origem e: " << setprecision(1) << distancia_p3 << endl;
    cout << "Distancia P4 ate a origem e: " << setprecision(1) << distancia_p4 << endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for (int i = 0; i < 3; ++i) {
        distancia = pontos[i].distancia();
        cout << "Distância do ponto " << i + 1 << " até a origem: " << setprecision(5) << distancia << endl;
    }
    
    Ponto p5;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;

    return 0;
}

