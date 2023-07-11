#ifndef CAIXA_H
#define CAIXA_H

#include "conta.h"
#include <vector>
#include <iostream>
#include <string>


class Caixa{
    private:
    std::vector<Conta> contas;
    double _saldo;

    public:
    Caixa();
    void contabilizarConta(Conta conta);
    double saldoFinal();
    void exibirExtrato();
};



#endif