#include <iostream>
#include <limits>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

#include <iostream>
#include <cmath>

using namespace std;

class Produto
{
private:
    int codigo;
    string nome;
    double preco;

public:
    Produto() : codigo(0), nome(""), preco(0.0){};
    Produto(int _codigo, string _nome, double _preco);
    void setCodigo(int _codigo);
    void setNome(string _nome);
    void setPreco(double _preco);
    int getCodigo();
    string getNome();
    double getPreco();
    void exibirProduto();
};

class Estoque
{
private:
    int codigo;
    vector<Produto> produtos;
    vector<int> qtd_Produto;

public:
    Estoque();
    vector<Produto> getProdutos();
    vector<int> getQtd_Produto();
    // Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto);
    void adicionar(Produto, int);
    void remover(int);
    // void alterar(posicaodoproduto, qtd);
    void alterar(int, int);
    void vender(int, int);
    void listar();
};

bool add_Produto(Estoque &estoque);
int buscarProduto(Estoque estoque);


class Carrinho{
    private:
       vector<Produto> produtos_;
       vector<int> qtd;

    public:
        Carrinho();
        Carrinho(Produto produto, int qtd);
        vector<Produto> getProdutos_();
        void adicionarProduto(Produto produto, int qtde);
        void removerProduto(Produto  produto, int qtde); 
        void calcularValorTotal();
        void exibirCarrinho();
        bool estaVazio() const;
          
};



int menu();
int menuEstoque();
int menuVendas();
int menuCarrinho();

void pause();
void limpaTela();

int main()
{
    Produto p1(1, "Arroz", 5.48);
    Produto p2(2, "Feijao", 7.99);
    Produto p3(3, "Macarrao", 1.85);


    Carrinho carrinho(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 2);
    carrinho.adicionarProduto(p1, 2);
    carrinho.adicionarProduto(p1, 10);
    carrinho.adicionarProduto(p1, 2);
  

    int opc, opc2, auxInt,auxInt2;
    char sn;
    Estoque estoque = Estoque();

    do
    {
        limpaTela();
        opc = menu();
        switch (opc)
        {
        case 1:
            do
            {
                limpaTela();
                opc2 = menuEstoque();
                switch (opc2)
                {
                case 1:
                    do
                    {
                        limpaTela();
                        if (add_Produto(estoque))
                        {
                            cout << "Produto adicionado com sucesso!" << endl;
                        }
                        else
                        {
                            cout << "Erro ao adicionar produto!" << endl;
                            cout << "Tente novamente!" << endl;
                        }
                        pause();
                        cout << "Deseja adicionar outro produto? (S/N): ";
                        cin >> sn;
                    } while (sn != 'n' && sn != 'N');
                    break;
                case 2:
                    limpaTela();
                    auxInt = buscarProduto(estoque);
                    if (auxInt == -1)
                    {
                        cout << "Produto nao encontrado!" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        estoque.remover(auxInt);
                        cout << "Produto removido com sucesso!" << endl;
                        pause();
                    }
                    break;
                case 3:
                    limpaTela();
                    auxInt = buscarProduto(estoque);
                    if (auxInt == -1)
                    {
                        cout << "Produto nao encontrado!" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "Nome do produto: " << estoque.getProdutos()[auxInt].getNome() << endl;
                        cout << "Quantidade atual em estoque: " << estoque.getQtd_Produto()[auxInt] << endl;
                        cout << "Digite a nova quantidade do produto no estoque: ";
                        cin >> auxInt2;
                        estoque.alterar(auxInt, auxInt2);
                        cout << "Produto alterado com sucesso!" << endl;
                        pause();
                    }
                    break;
                case 4:
                    limpaTela();
                    if (estoque.getProdutos().empty())
                    {
                        cout << "Nao ha produtos no estoque!" << endl;
                    }
                    else
                    {
                        estoque.listar();
                    }
                    pause();
                    break;
                case 0:
                    limpaTela();
                    break;
                default:
                    limpaTela();
                    cout << "Opcao invalida!" << endl;
                    pause();
                }
            } while (opc2 != 0);
            break;
        case 2:
            do
            {
                limpaTela();
                opc2 = menuVendas();
                switch (opc2)
                {
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
            } while (opc2 != 0);
            break;
        case 3:
           
            do
            {
                limpaTela();
                opc2 = menuCarrinho();
                switch (opc2)
                {
                case 1:
                    limpaTela();
                    // função de add produto no carrinho
                    pause();
                    break;
                case 2:
                    limpaTela();
                    
                    if(carrinho.estaVazio()){
                        cout << "Carrinho vazio" << endl;
                    }else{
                        carrinho.calcularValorTotal();

                    }
                    pause();
                    break;
                case 3:
                    limpaTela();

                    if(carrinho.estaVazio()){
                        cout << "Carrinho vazio" << endl;
                    }else{
                        carrinho.exibirCarrinho();

                    }

                    pause();
                    break;
                case 4:
                    limpaTela();
                    // função de remover produto no carrinho
                    pause();
                    break;
                case 0:

                    break;
                default:
                    limpaTela();
                    cout << "Opcao invalida!" << endl;
                    pause();
                }
            } while (opc2 != 0);
            break;    
        case 0:
            break;
        default:
            cout << "Opcao invalida!" << endl;
            pause();
        }
    } while (opc != 0);
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

//////
// Produto
//////

Produto::Produto(int _codigo, string _nome, double _preco)
{
    codigo = _codigo;
    nome = _nome;
    preco = _preco;
}

void Produto::setCodigo(int _codigo)
{
    codigo = _codigo;
}

void Produto::setNome(string _nome)
{
    nome = _nome;
}

void Produto::setPreco(double _preco)
{
    preco = _preco;
}

int Produto::getCodigo()
{
    return codigo;
}

string Produto::getNome()
{
    return nome;
}

double Produto::getPreco()
{
    return preco;
}

void Produto::exibirProduto()
{
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Preco: " << getPreco() << endl;
}

//////
// Estouque
/////

Estoque::Estoque()
{
    this->codigo = -1;
    this->produtos.resize(0);
    this->qtd_Produto.resize(0);
}

// Estoque::Estoque(int codigo, vector<Produto> produtos, vector<int> qtd_Produto){
//     this->codigo = codigo;
//     this->produtos = produtos;
//     this->qtd_Produto = qtd_Produto;
// }

vector<Produto> Estoque::getProdutos()
{
    return this->produtos;
}

vector<int> Estoque::getQtd_Produto()
{
    return this->qtd_Produto;
}

void Estoque::adicionar(Produto p, int qtd)
{
    this->produtos.push_back(p);
    this->qtd_Produto.push_back(qtd);
}

int buscarProduto(Estoque estoque)
{
    int cod;
    int tam = estoque.getProdutos().size();
    cout << "Digite o codigo do produto: ";
    cin >> cod;

    for (int i = 0; i < tam; i++)
    {
        if (estoque.getProdutos()[i].getCodigo() == cod)
        {
            return i;
        }
    }
    return -1;
}

void Estoque::remover(int pos)
{
    this->produtos.erase(this->produtos.begin() + pos);
    this->qtd_Produto.erase(this->qtd_Produto.begin() + pos);
}

void Estoque::alterar(int pos, int qtd)
{
    this->qtd_Produto[pos] = qtd;
}

void Estoque::vender(int pos, int qtd)
{
    if (qtd_Produto[pos] >= qtd)
    {
        qtd_Produto[pos] -= qtd;
    }
    else
    {
        cout << "Quantidade insuficiente!" << endl;
    }
}

void Estoque::listar()
{
    cout << "############# Estoque lista de produtos #############" << endl;
    for (int i = 0; i < int(this->produtos.size()); i++)
    {
        this->produtos[i].exibirProduto();
        cout << "Quantidade em estoque: " << this->qtd_Produto[i] << endl;
        cout << "------------------------------------------------" << endl;
    }
}

bool add_Produto(Estoque &estoque)
{
    Produto p;
    string nome;
    double preco;
    bool ok;
    int qtd, cod;
    cout << "############# Adicionar Produto #############" << endl;

    cout << "Digite o codigo do produto: ";
    cin >> cod;
    ok = true;
    for (Produto p2 : estoque.getProdutos())
    {
        if (p2.getCodigo() == cod)
        {
            ok = false;
        }
    }
    if (!ok)
    {
        cout << "Codigo ja cadastrado!" << endl;
        return false;
    }
    p.setCodigo(cod);

    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, nome);
    p.setNome(nome);
    cout << "Digite o preco do produto: ";
    cin >> preco;
    p.setPreco(preco);
    cin.clear();
    cout << "Digite a quantidade do produto: ";
    cin >> qtd;

    estoque.adicionar(p, qtd);

    return true;
}

Carrinho::Carrinho()
{
    this->produtos_.resize(0);
    this->qtd.resize(0);
}

Carrinho::Carrinho(Produto produto, int qta)
{
    this->produtos_.push_back(produto);
    this->qtd.push_back(qta);
}


void Carrinho::adicionarProduto(Produto produto, int qtde){
    for(int i=0; i<this->produtos_.size(); i++){
        if(this->produtos_[i].getCodigo() == produto.getCodigo()){
            qtd[i] +=qtde;
            return;
        }
        
    }

    this->produtos_.push_back(produto);
    this->qtd.push_back(qtde);
}

void Carrinho::removerProduto(Produto produto, int qtde){
    int removidos = 0;
    for(int i = 0; i < produtos_.size(); i++){
        if(produtos_[i].getCodigo() == produto.getCodigo() && removidos < qtde){
            produtos_.erase(produtos_.begin() + i);
            removidos++;
        }
    }

    cout<<"Foram removidos "<<removidos<<" "<<produto.getNome()<<"(s) do carrinho!"<<endl;
}

bool Carrinho::estaVazio() const {
        return produtos_.empty();
}

void Carrinho::exibirCarrinho()
{
    cout << "#############  lista de produtos no carrinho #############" << endl;
    for (int i = 0; i < int(this->produtos_.size()); i++)
    {
        cout << "\t" << " - "<< this->produtos_[i].getNome() << "(" << 
        this->produtos_[i].getPreco() << ") "<< "x " << qtd[i] << endl;
       
    }
}

void Carrinho::calcularValorTotal()
{
    double total = 0.0;

    cout << "#############  Valor total #############" << endl;
    for (int i = 0; i < int(this->produtos_.size()); i++)
    {
        total += (this->produtos_[i].getPreco() * qtd[i]);
    }
    cout << total << endl;
}


int menuCarrinho()
{
    int op;
    cout << "######### Menu Carrinho #########" << endl;
    cout << "1 - Adicionar produto no carrinho" << endl;
    cout << "2 - Calcular valor total" << endl;
    cout << "3 - Listar produto do carrinho" << endl;
    cout << "4 - Remover produto do carrinho" << endl;
    cout << "0 - Voltar ao menu principal" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

int menuEstoque()
{
    int op;
    cout << "######### Menu Estoque #########" << endl;
    cout << "1 - Adicionar produto" << endl;
    cout << "2 - Remover produto" << endl;
    cout << "3 - Alterar quantidade de um produto" << endl;
    cout << "4 - Listar produtos" << endl;
    cout << "0 - Voltar ao menu principal" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

int menuVendas()
{
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

int menu()
{
    int op;
    cout << "######### Menu Principal #########" << endl;
    cout << "1 - Gerenciar Estoque" << endl;
    cout << "2 - Gerenciar Vendas" << endl;
    cout << "3 - Gerenciar Carrinho" << endl;
    cout << "0 - Sair" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}
