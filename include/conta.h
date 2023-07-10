#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include "comanda.h"

using namespace std;

class comanda_nao_existe_e{};

class Conta{
    private:
    Comanda* _comanda;
    double valorTotal;
    bool contaPaga;
    double gorjeta;

    public:
    Conta(Comanda* comanda);
    void calcularValorTotal();
    double get_valorTotal();
    void exibirFormasDePagamento();
    void informarContaPaga();
    double exibirValorTotalComGorjeta();
    bool get_contaPaga();
};




#endif