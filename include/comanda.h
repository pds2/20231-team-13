#ifndef COMANDA_H
#define COMANDA_H

#include "cadastro.h"
#include "cardapio.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Comanda{
    friend class Conta;
    private:
    Cadastro* _cliente;
    vector<Prato*> pedidos;


    public:
    Comanda(Cadastro* cliente);
    void adicionarPedido(Prato* prato);
    void exibirPedidos();
    void cancelarPedido(Prato* prato);

};




#endif