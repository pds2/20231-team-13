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
    for(Prato* prato: _comanda->pedidos){
        valorTotal += prato->get_preco();    
    }
}

double Conta::get_valorTotal(){
    return valorTotal;
}

void Conta::exibirFormasDePagamento(){
    cout<< "Formas de pagamento disponiveis: Dinheiro, Crédito, Débito e pix"<< endl;
}

bool Conta::informarContaPaga(){
    contaPaga =true;
    cout<< "Pagamento efetuado com sucesso!"<< endl;
}

double Conta::exibirValorTotalComGorjeta(){
    return (valorTotal*1,1);
}

bool Conta::get_contaPaga(){
    return contaPaga;
}