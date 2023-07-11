#include "../third_party/doctest.h"
#include "../include/caixa.h"
#include "../include/comanda.h"
#include "../include/conta.h"



    
   TEST_CASE("01-Contabilizar conta paga") {
    Caixa caixa;
    Comanda comanda; // Crie uma instância de Comanda
    Conta conta(&comanda); // Passe o ponteiro para Comanda no construtor de Conta
    caixa.contabilizarConta(conta);

    CHECK_EQ(caixa.saldoFinal(), 100);
}


   TEST_CASE("02-Contabilizar conta não paga") {
    Caixa caixa;
    Comanda comanda; // Crie uma instância de Comanda
    Conta conta(&comanda); // Passe o ponteiro para Comanda no construtor de Conta
    caixa.contabilizarConta(conta);

    CHECK_EQ(caixa.saldoFinal(), 0.0);
}

