#ifndef CAIXA_H
#define CAIXA_H

#include "conta.h"
#include <vector>
#include <iostream>
#include <string>


class Transacao{
    friend class Caixa;
    private:
    double _valor;
    std::string _descricao;

    public:
    Transacao(double valor, std::string descricao);

};

class Caixa{
    private:
    std::vector<Conta> contas;
    std::vector<Transacao*> transacoes;
    double _saldo;

    public:
    Caixa();
    void contabilizarConta(Conta conta);
    void contabilizarTransacao(Transacao* transacao);
    double saldoFinal();
    void exibirExtrato();
};



#endif