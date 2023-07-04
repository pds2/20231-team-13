#include "../include/comanda.h"

Comanda::Comanda()
{

}

Comanda::Comanda(Cadastro* cliente){
    if (cliente== nullptr){
        throw cliente_nao_existe_e();
    }
    _cliente=cliente;
}

void Comanda::adicionarPedido(Prato* prato){
    if (prato == nullptr){
        throw prato_nao_existe_e();
    }
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
        throw prato_nao_encontrado_e();
    }
}

Cadastro* Comanda::getCliente() const {
    return _cliente;
}

vector<Prato*>& Comanda::getPedidos() {
        return pedidos;
    }

void Comanda::adicionarComanda(Cadastro* cliente)
{
    if (cliente== nullptr){
        throw cliente_nao_existe_e();
    }
    _cliente=cliente;
}





