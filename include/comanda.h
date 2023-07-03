#ifndef COMANDA_H
#define COMANDA_H

#include "cadastro.h"
#include "cardapio.h"
#include <vector>
#include <iostream>
#include <string>
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
//oi
};




#endif