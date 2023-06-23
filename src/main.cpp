#include"include/cadastro.h"
#include"include/caixa.h"
#include"include/cardapio.h"
#include <iostream>
int main() {
    Cardapio cardapio;

    cardapio.adicionarPrato(new Entrada("Salada", 10.0));
    cardapio.adicionarPrato(new PratoPrincipal("Bife com batatas", 25.0));
    cardapio.adicionarPrato(new Sobremesa("Pudim", 8.0));

    cardapio.exibir();

    return 0;
}