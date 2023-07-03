#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include "comanda.h"
using namespace std;

class Conta{
    friend class Caixa;
    private:
    Comanda* _comanda;
    double valorTotal;
    bool contaPaga;
    double gorjeta;

    public:
    Conta(Comanda* comanda);
    void calcularValorTotal();
    void exibirValorTotal();
    void exibirFormasDePagamento();
    bool informarContaPaga();
    void exibirValorTotalComGorjeta();
};




#endif