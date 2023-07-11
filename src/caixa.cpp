#include "../include/caixa.h"


Caixa::Caixa(){
    _saldo=0;
}

void Caixa::contabilizarConta(Conta conta){
    if(conta.get_contaPaga()){
        contas.push_back(conta);
        double valorTotal = conta.get_valorTotal();
        std::cout << valorTotal << std::endl;
        _saldo = _saldo + valorTotal;
    }
    else {
        std::cout << "A conta nao foi paga. Não e possível contabiliza-la." << std::endl;
    }
}


void Caixa::exibirExtrato(){
    std::cout << "Saldo: " << _saldo << std::endl;

    std::cout << "Contas pagas:" << std::endl;
        for (Conta conta : contas) {
            std::cout<<"+"<<conta.get_valorTotal() << std::endl << std::endl;
        }
    // std::cout << "Transacoes de retirada:"<< std::endl;
    //     for (Transacao* transacao: transacoes){
    //         std::cout<<"-"<< transacao->_valor << std::endl;
    //     }
}

double Caixa::saldoFinal(){
    return _saldo;
}