# include <iostream>
# include <limits>
# include <cstring>
# include <vector>
# include <iomanip>

using namespace std;

class Produto{
    
};
class Estoque{
    int codigo;
    vector<Produto> produtos;
    vector<int> qtd_Produto;
    public:
        Estoque();
        Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto);
        void adicionar(Produto, int);
        void remover(int);
        // void alterar(posicaodoproduto, qtd);
        void alterar(int, int);
        void vender(int, int);
        void listar();
};

void pause();
void limpaTela();


int main(){
    
    int opc;
    do{
        limpaTela();


        

        
        pause();
    }while(opc != 0);
    return 0;
}


void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}

Estoque::Estoque(){
    this->codigo = -1;
    this->produtos.resize(0);
    this->qtd_Produto.resize(0);
}

Estoque::Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto){
    this->codigo = codigo;
    this->produtos = produtos;
    this->qtd_Produto = qtd_Produto;
}

void Estoque::adicionar(Produto p, int qtd){
    this->produtos.push_back(p);
    this->qtd_Produto.push_back(0);
}

void Estoque::remover(int pos){
    this->produtos.erase(this->produtos.begin() + pos);
    this->qtd_Produto.erase(this->qtd_Produto.begin() + pos);
}

void Estoque::alterar(int pos, int qtd){
    this->qtd_Produto[pos] = qtd;
}

void Estoque::vender(int pos, int qtd){
    if(qtd_Produto[pos] >= qtd){
        qtd_Produto[pos] -= qtd;
    }
    else{
        cout << "Quantidade insuficiente!" << endl;
    }
}

