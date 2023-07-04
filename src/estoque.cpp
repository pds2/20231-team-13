#include"../include/estoque.h"
#include"iostream"

void Estoque::adicionar_estoque(string item, int quantidade) {
        estoque[item] += quantidade;
    }
void Estoque::remover_estoque(string item, int quantidade) {
        if (estoque[item] >= quantidade) {
            estoque[item] -= quantidade;
        } else {
            cout << "Quantidade insuficiente de " << item << " no estoque." << endl;
        }
    }

int Estoque::get_quantidade(std::string nomeDoProduto)
{
    return estoque[nomeDoProduto];
}