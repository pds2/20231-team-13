#include "../include/comanda.h"

Comanda::Comanda(Cadastro* cliente){
    _cliente=cliente;
}

void Comanda::adicionarPedido(Prato* prato){
    pedidos.push_back(prato);
}

void Comanda::exibirPedidos(){
    cout<< "Comanda#" << _cliente->_nome << endl;
    for(Prato* prato : pedidos){
        prato->exibir();
    }
}

void Comanda::cancelarPedido(Prato* prato) {
    // Procura o prato na lista de pedidos
    auto it = find(pedidos.begin(), pedidos.end(), prato);

    if (it != pedidos.end()) {
        // Remove o prato da lista de pedidos
        pedidos.erase(it);
        cout << "Pedido removido!" << endl;
    } else {
        cout << "Pedido não encontrado!" << endl;
    }
}






