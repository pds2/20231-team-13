#include "../third_party/doctest.h"
#include "../include/caixa.h"
#include "../include/comanda.h"
#include "../include/conta.h"

TEST_CASE("01-Teste da classe Caixa") {
    Caixa caixa;

    // Teste 1: Contabilizar conta paga
   SUBCASE("Contabilizar conta paga") {
    Comanda comanda; // Crie uma instância de Comanda
    Conta conta(&comanda); // Passe o ponteiro para Comanda no construtor de Conta
    caixa.contabilizarConta(&conta);

    CHECK_EQ(caixa.saldoFinal(), 100);
}


   SUBCASE("02-Contabilizar conta não paga") {
    Comanda comanda; // Crie uma instância de Comanda
    Conta conta(&comanda); // Passe o ponteiro para Comanda no construtor de Conta
    caixa.contabilizarConta(&conta);

    CHECK_EQ(caixa.saldoFinal(), 0.0);
}

    // Teste 3: Contabilizar transação
    SUBCASE("03-Contabilizar transação") {
        Transacao transacao(-50.0, "Retirada");
        caixa.contabilizarTransacao(&transacao);

        CHECK_EQ(caixa.saldoFinal(), -50.0);
    }

    // Teste 4: Exibir extrato
    SUBCASE("04-Exibir extrato") {
        std::ostringstream oss;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        caixa.exibirExtrato();

        std::cout.rdbuf(coutBuffer);

        std::string expectedOutput =
            "Contas pagas:\n"
            "+100\n"
            "Transacoes de retirada:\n"
            "-50\n";

        CHECK_EQ(oss.str(), expectedOutput);
    }
}
