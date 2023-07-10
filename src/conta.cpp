#include "../include/conta.h"

Conta::Conta(Comanda* comanda){
    if(comanda==nullptr){
        throw comanda_nao_existe_e();
    }
    _comanda=comanda;
    valorTotal=0;
    contaPaga=false;
    gorjeta=0;
}

void Conta::calcularValorTotal(){
    for(Prato* prato: _comanda->getPedidos()){
        valorTotal += prato->get_preco();    
    }
}

double Conta::get_valorTotal(){
    return valorTotal;
}

void Conta::exibirFormasDePagamento(){
    std::cout<< "Formas de pagamento disponiveis: Dinheiro, Credito, Debito e pix"<< std::endl;
}

void Conta::informarContaPaga(){
    contaPaga =true;
    std::cout<< "Pagamento efetuado com sucesso!"<< std::endl;
}

double Conta::exibirValorTotalComGorjeta(){
    return (valorTotal*1,1);
}

bool Conta::get_contaPaga(){
    return contaPaga;
}