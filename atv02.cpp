#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    private:
        int x;
        int y;
    public:
        Ponto() : x(0), y(0) {};
        Ponto(int x, int y);
        void setX(int x);
        void setY(int y);
        void setCoordenadas(int x, int y);
        int getX();
        int getY();
        double calcularDistanciaOrigem() const;
       // double distanciaEntePontos(Ponto p);

};

    int main(){
        Ponto p1(3,4);
        cout << "Distancia entre os pontos " << p1.getX()  << " , "  << p1.getY() << " ate a origem e : " << p1.calcularDistanciaOrigem() << endl;
        Ponto p2(-2,7);
        p2.setCoordenadas(1,1);
       cout << "Distancia entre os pontos " << p2.getX()  << " , " << p2.getY() << " ate a origem e : " << p2.calcularDistanciaOrigem() << endl;
       Ponto p3(0,3);
       Ponto p4(4,0);
       cout << "Distancia entre os pontos " << p3.getX()  << " , " << p3.getY() << " ate a origem e : " << p3.calcularDistanciaOrigem() << endl;
       cout << "Distancia entre os pontos " << p4.getX()  << " , " << p4.getY() << " ate a origem e : " << p4.calcularDistanciaOrigem() << endl;

        Ponto pontos[3];

        pontos[0].setCoordenadas(2,2);
        pontos[1].setCoordenadas(-1,5);
        pontos[2].setCoordenadas(0,0);

        for(int i = 0; i < 3; i++){
            cout << "Distancia do ponto "<< i+1 << "  " <<pontos[i].getX()  << " , " << pontos[i].getY() << " ate a origem e : " << pontos[i].calcularDistanciaOrigem() << endl;
        }

        Ponto p5;
        cout << "Coordenadas do ponto p5: " << p5.getX()  << " , " << p5.getY() << endl;
        p5.setCoordenadas(8,-3);
         cout << "Novas Coordenadas do ponto p5: " << p5.getX()  << " , " << p5.getY() << endl;
    }


Ponto::Ponto(int _x, int _y){
            x = _x;
            y = _y;
        }
        void Ponto::setX(int _x){
          x = _x;
        }
        void Ponto::setY(int _y){
          y = _y;
        }

        void Ponto::setCoordenadas(int _x, int _y){
            x = _x;
            y = _y;
        }
        int Ponto::getX(){
            return x;
        }
        int Ponto::getY(){
            return y;
        }

        // double Ponto::distanciaEntePontos(Ponto p){
        //     return sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2));
        // }

         double Ponto::calcularDistanciaOrigem() const {
        return std::sqrt(x * x + y * y);
    }
        