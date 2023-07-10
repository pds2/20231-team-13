#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define TEST_CASE 
#define  DOCTEST_SUBCASE
#define  DOCTEST_CHECK
#define  DOCTEST_CHECK_EQ
#include "../third_party/doctest.h"
#include "../include/cardapio.h"
#include "../include/cadastro.h"



TEST_CASE("Teste do construtor Prato") {
    SUBCASE("Nome inválido") {
        CHECK_THROWS_AS(Prato("", 10.0), nome_prato_invalido_e);
    }

    SUBCASE("Preço inválido") {
        CHECK_THROWS_AS(Prato("Salada", -5.0), preco_invalido_e);
    }
}
TEST_CASE("Teste da função exibir() do Cardapio") {
    Cardapio cardapio;

    Prato* entrada = new Entrada("Salada", 10.0);
    Prato* pratoPrincipal = new PratoPrincipal("Bife", 25.0);
    Prato* sobremesa = new Sobremesa("Sorvete", 8.0);

    cardapio.adicionarPrato(entrada);
    cardapio.adicionarPrato(pratoPrincipal);
    cardapio.adicionarPrato(sobremesa);

    SUBCASE("Exibir cardápio") {
        std::ostringstream oss;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        cardapio.exibir();

        std::cout.rdbuf(coutBuffer);

        std::string expectedOutput =
            "Entrada - Nome: Salada, Preco: R$10\n"
            "Prato Principal - Nome: Bife, Preco: R$25\n"
            "Sobremesa - Nome: Sorvete, Preco: R$8\n";

        doctest::CHECK_EQ(oss.str(), expectedOutput);
    }

    // Limpar o cardápio (liberar memória)
    for (Prato* prato : cardapio.get_pratos()) {
        delete prato;
    }
}


    // Limpar o cardápio (liberar memória)
    for (Prato* prato : cardapio.get_pratos()) {
        delete prato;
    }
