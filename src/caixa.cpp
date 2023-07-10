#include "../include/caixa.h"

Transacao::Transacao(double valor, string descricao){
    _valor=valor;
    _descricao=descricao;
}

Caixa::Caixa(){
    _saldo=0;
}

void Caixa::contabilizarConta(Conta* conta){
    if(conta->get_contaPaga()){
        contas.push_back(conta);
        double valorTotal = conta->get_valorTotal();
        _saldo += valorTotal;
    }
    else {
        cout << "A conta não foi paga. Não é possível contabilizá-la." << endl;
    }
}

void Caixa::contabilizarTransacao(Transacao* transacao){
    transacoes.push_back(transacao);
        double valor = transacao->_valor;
        _saldo += valor;
}

void Caixa::exibirExtrato(){
    cout << "Contas pagas:" << endl;
        for (Conta* conta : contas) {
            cout<<"+"<<conta->get_valorTotal() << endl;
        }
    cout << "Transacoes de retirada:"<< endl;
        for (Transacao* transacao: transacoes){
            cout<<"-"<< transacao->_valor << endl;
        }
}

double Caixa::saldoFinal(){
    return _saldo;
}