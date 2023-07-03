#include "../include/conta.h"

Conta::Conta(Comanda* comanda){
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

void Conta::exibirValorTotal(){
    cout<< "Valor total: R$" << valorTotal << endl;
}

void Conta::exibirFormasDePagamento(){
    cout<< "Formas de pagamento disponiveis: Dinheiro, Crédito, Débito e pix"<< endl;
}

void Conta::informarContaPaga(){
    contaPaga =true;
    cout<< "Pagamento efetuado com sucesso!"<< endl;
}

void Conta::exibirValorTotalComGorjeta(){
    cout<< "Valor total com gorjeta: R$" << (valorTotal*1,1)<<endl;
}