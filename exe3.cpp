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
        // Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto);
        void adicionar(Produto, int);
        void remover(int);
        // void alterar(posicaodoproduto, qtd);
        void alterar(int, int);
        void vender(int, int);
        void listar();
};

int menu();
int menuEstoque();
int menuVendas();

void pause();
void limpaTela();


int main(){
    int opc, opc2;
    Estoque estoque = Estoque();

    do{
        limpaTela();
        opc = menu();
        switch(opc){
            case 1:
                do{
                    limpaTela();
                    opc2 = menuEstoque();
                    switch(opc2){
                        
                    }
                }while(opc2 != 0);
                break;
            case 2:
                do{
                    limpaTela();
                    opc2 = menuVendas();
                    switch(opc2){
                        case 1:
                            limpaTela();
                            cout << "Listar produto carrinho" << endl;
                            pause();
                            break;
                        case 2:
                            limpaTela();
                            cout << "Adicionar produto ao carrinho" << endl;
                            pause();
                            break;
                        case 3:
                            limpaTela();
                            cout << "Remover produto do carrinho" << endl;
                            pause();
                            break;
                        case 4:
                            limpaTela();
                            cout << "Finalizar compras" << endl;
                            pause();
                            break;
                        case 5:
                            limpaTela();
                            cout << "Limpar carrinho" << endl;
                            pause();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida!" << endl;
                            pause();
                    }
                }while(opc2 != 0);
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!" << endl;
                pause();
        }
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

// Estoque::Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto){
//     this->codigo = codigo;
//     this->produtos = produtos;
//     this->qtd_Produto = qtd_Produto;
// }

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

int menuEstoque(){
    int op;
    cout << "######### Menu Estoque #########" << endl;
    cout << "1 - Adicionar produto" << endl;
    cout << "2 - Remover produto" << endl;
    cout << "3 - Alterar quantidade de um produto" << endl;
    cout << "4 - Atualizar estoque pós venda de um produto" << endl;
    cout << "0 - Voltar ao menu principal" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

int menuVendas(){
    int op;
    cout << "######### Menu Vendas #########" << endl;
    cout << "1 - Listar produto carrinho" << endl;
    cout << "2 - Adicionar produto ao carrinho" << endl;
    cout << "3 - Remover produto do carrinho" << endl;
    cout << "4 - Finalizar compra" << endl;
    cout << "5 - Limpar carrinho" << endl;
    cout << "0 - Voltar ao menu principal" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

int menu(){
    int op;
    cout << "######### Menu Principal #########" << endl;
    cout << "1 - Gerenciar Estoque" << endl;
    cout << "2 - Gerenciar Vendas" << endl;
    cout << "0 - Sair" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

