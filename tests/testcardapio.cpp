#include "../third_party/doctest.h"
#include "../include/cardapio.h"
#include "../include/cadastro.h"
#include <string>




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


    // Limpar o cardápio (liberar memória)
    for (Prato* prato : cardapio.get_pratos()) {
        delete prato;
    }
}
