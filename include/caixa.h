#ifndef CAIXA_H
#define CAIXA_H

#include "conta.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Transacao{
    friend class Caixa;
    private:
    double _valor;
    string _descricao;

    public:
    Transacao(double valor, string descricao);

};

class Caixa{
    private:
    vector<Conta*> contas;
    vector<Transacao*> transacoes;
    double _saldo;

    public:
    Caixa();
    void contabilizarConta(Conta* conta);
    void contabilizarTransacao(Transacao* transacao);
    double saldoFinal();
    void exibirExtrato();
};



#endif