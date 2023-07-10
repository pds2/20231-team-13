#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define TEST_CASE 
#define SUBCASE DOCTEST_SUBCASE
#include "../third_party/doctest.h"
#include "../include/cardapio.h"

TEST_CASE("Teste do construtor Prato") {
    // Teste 1: Nome inválido
    SUBCASE("Nome inválido") {
        CHECK_THROWS_AS(Prato("", 10.0), nome_prato_invalido_e);
    }

    // Teste 2: Preço inválido
    SUBCASE("Preço inválido") {
        CHECK_THROWS_AS(Prato("Salada", -5.0), preco_invalido_e);
    }
}

TEST_CASE("Teste do Cardapio") {
    Cardapio cardapio;

    // Teste 1: Adicionar pratos
    SUBCASE("Adicionar pratos") {
        Prato* entrada = new Entrada("Salada", 10.0);
        Prato* pratoPrincipal = new PratoPrincipal("Bife", 25.0);
        Prato* sobremesa = new Sobremesa("Sorvete", 8.0);

        cardapio.adicionarPrato(entrada);
        cardapio.adicionarPrato(pratoPrincipal);
        cardapio.adicionarPrato(sobremesa);

        // Verificar se os pratos foram adicionados corretamente
        CHECK(cardapio.getPratos().size() == 3);
    }

    // Teste 2: Exibir cardápio
    SUBCASE("Exibir cardápio") {
        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        cardapio.exibir();

        std::cout.rdbuf(oldCoutBuffer);

        // Verificar se a saída do cardápio está correta
        std::string expectedOutput =
            "Entrada - Nome: Salada, Preco: R$10\n"
            "Prato Principal - Nome: Bife, Preco: R$25\n"
            "Sobremesa - Nome: Sorvete, Preco: R$8\n";

        CHECK(output.str() == expectedOutput);
    }

    // Limpar o cardápio (liberar memória)
    for (Prato* prato : cardapio.getPratos()) {
        delete prato;
    }
}

TEST_CASE("Teste do cálculo do valor total do Cardapio") {
    Cardapio cardapio;

    // Adicionar pratos ao cardápio
    cardapio.adicionarPrato(new Entrada("Salada", 10.0));
    cardapio.adicionarPrato(new PratoPrincipal("Bife", 25.0));
    cardapio.adicionarPrato(new Sobremesa("Sorvete", 8.0));

    // Teste do cálculo do valor total
    SUBCASE("Cálculo do valor total") {
        double valorTotal = 0.0;
        for (const Prato* prato : cardapio.getPratos()) {
            valorTotal += prato->get_preco();
        }

        CHECK(valorTotal == doctest::Approx(43.0));
    }

    // Limpar o cardápio (liberar memória)
    for (Prato* prato : cardapio.getPratos()) {
        delete prato;
    }
}
