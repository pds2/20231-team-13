#include "../include/comanda.h"

Comanda::Comanda(Cadastro* cliente){
    _cliente=cliente;
}

void Comanda::adicionarPedido(Prato* prato){
    pedidos.push_back(prato);
}

void Comanda::exibirPedidos(){
    cout<< "Comanda#" << _cliente->get_nome() << endl;
    for(Prato* prato : pedidos){
        prato->exibir();
    }
}