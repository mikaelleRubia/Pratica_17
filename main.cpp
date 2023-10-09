#include "Ponto.cpp"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){

    Ponto p1(3, 4);
    double distancia_p1 = p1.distancia_ate_origem();
    cout<<"A distancia do ponto ("<<p1.getX()<<", "<<p1.getY()<<") ate a origem eh de aproximadamente "<<fixed<<setprecision(1)<<distancia_p1<<endl;
    
    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    double distancia_p2 = p2.distancia_ate_origem();
    cout<<"\nA distancia do ponto ("<<p2.getX()<<", "<<p2.getY()<<") ate a origem eh de aproximadamente "<<fixed<<setprecision(5)<<distancia_p2<<endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.distancia_ate_origem();
    double distancia_p4 = p4.distancia_ate_origem();
    cout<<"\nA distancia do ponto ("<<p3.getX()<<", "<<p3.getY()<<") ate a origem eh "<<fixed<<setprecision(1)<<distancia_p3
        <<" e do  ("<<p4.getX()<<", "<<p4.getY()<<") eh "<<fixed<<setprecision(1)<<distancia_p4<<endl;

    cout<<endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for(int i = 0; i < 3; i++){
        double distancia = pontos[i].distancia_ate_origem();
        cout<<"Distancia do ponto"<<i+1<<" ate a origem: "<<setprecision(5)<<distancia<<endl;
    }

    Ponto p5;
    cout<<"\nCoordenadas do ponto p5: ("<<p5.getX()<<", "<<p5.getY()<<")"<<endl;
    p5.setCoordenadas(8, -3);
    cout<<"Novas coordenadas do ponto p5: ("<<p5.getX()<<", "<<p5.getY()<<")"<<endl;

    return 0;
}