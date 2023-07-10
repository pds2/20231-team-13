#ifndef COMANDA_H
#define COMANDA_H

#include "cadastro.h"
#include "cardapio.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//verifica se nao é criada uma comanda para um cliente que nao existe
class cliente_nao_existe_e {};
//verifica se o prato existe no cardapio antes de adicionalo à comanda
class prato_nao_existe_e {};
//verifica se o prato existe na comanda antes de retira-lo
class prato_nao_encontrado_e {};


class Comanda{
    private:
    Cadastro* _cliente;
    vector<Prato*> pedidos;


    public:
    Comanda();
    Comanda(Cadastro* cliente);
    void adicionarPedido(Prato* prato);
    void exibirPedidos();
    void cancelarPedido(Prato* prato);
    Cadastro* getCliente() const;
    vector<Prato*>& getPedidos();
    void adicionarComanda(Cadastro* cliente);
};




#endif