#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "../include/comanda.h"
#include "../include/cardapio.h"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Estoque{
  private:
    unordered_map<string, int> estoque;

    public:
    void adicionar_estoque(string item, int quantidade);

    void remover_estoque(string item, int quantidade);
}


#endif





