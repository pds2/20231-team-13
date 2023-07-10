#include "../include/caixa.h"

Transacao::Transacao(double valor, std::string descricao){
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
        std::cout << "A conta nao foi paga. Não e possível contabiliza-la." << std::endl;
    }
}

void Caixa::contabilizarTransacao(Transacao* transacao){
    transacoes.push_back(transacao);
        double valor = transacao->_valor;
        _saldo += valor;
}

void Caixa::exibirExtrato(){
    std::cout << "Contas pagas:" << std::endl;
        for (Conta* conta : contas) {
            std::cout<<"+"<<conta->get_valorTotal() << std::endl;
        }
    std::cout << "Transacoes de retirada:"<< std::endl;
        for (Transacao* transacao: transacoes){
            std::cout<<"-"<< transacao->_valor << std::endl;
        }
}

double Caixa::saldoFinal(){
    return _saldo;
}