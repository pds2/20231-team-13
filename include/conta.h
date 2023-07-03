#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include "comanda.h"
using namespace std;

class Conta{
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
    void informarContaPaga();
    void exibirValorTotalComGorjeta();
};




#endif