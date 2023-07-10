#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "../include/comanda.h"
#include "../include/cardapio.h"
#include "../include/DataBase/EstoqueDados.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Estoque{
  public:
    Estoque();

    void adicionar_estoque(string item, float quantidade, string unidade);

    void remover_estoque(string item, float quantidade);

    float get_quantidade(string nomeDoProduto);

    private:
      EstoqueDados _estoque;
};


#endif