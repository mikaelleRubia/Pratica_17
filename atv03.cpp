#include <iostream>
#include <cmath>

using namespace std;

class Produto{
    private:
        int codigo;
        string nome;
        double preco;
    public:
        Produto() : codigo(0), nome(""), preco(0.0) {};
        Produto(int _codigo, string _nome, double _preco);
        void setCodigo(int _codigo);
        void setNome(string _nome);
        void setPreco(double _preco);
        int getCodigo();
        string getNome();
        double getPreco();
        void exibirProduto();
};


int main(){
    string nome;
    int codigo;
    double preco;
    Produto p;
    cout << "Digite o coodigo do produto: ";
    cin >> codigo;
    p.setCodigo(codigo);
    cout << "Digite o nome do produto: ";
    cin >> nome;
    p.setNome(nome);
    cout << "Digite o preço do produto: ";
    cin >> preco;
    p.setPreco(preco);
    p.exibirProduto();

}






    Produto::Produto(int _codigo, string _nome, double _preco){
        codigo = _codigo;
        nome = _nome;
        preco = _preco;
    }

    void Produto::setCodigo(int _codigo){
        codigo = _codigo;
    }

    void Produto::setNome(string _nome){
        nome = _nome;
    }

    void Produto::setPreco(double _preco){
        preco = _preco;
    }

    int Produto::getCodigo(){
        return codigo;
    }

    string Produto::getNome(){
        return nome;
    }

    double Produto::getPreco(){
        return preco;
    }

    void Produto::exibirProduto() {
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Preco: " << getPreco() << endl;
}