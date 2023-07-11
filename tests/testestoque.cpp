#include "../third_party/doctest.h"
#include "../include/estoque.h"

TEST_CASE("01-Teste do método adicionar_estoque") {
    Estoque estoque;
    CHECK_NOTHROW(estoque.adicionar_estoque("Item1", 10.0, "Unidade"));
    CHECK_NOTHROW(estoque.adicionar_estoque("Item2", 5.0, "Unidade"));

    // Verificar se a quantidade foi atualizada corretamente
    CHECK_EQ(estoque.get_quantidade("Item1"), 10.0);
    CHECK_EQ(estoque.get_quantidade("Item2"), 5.0);
}

TEST_CASE("02-Teste do método remover_estoque") {
    Estoque estoque;
    estoque.adicionar_estoque("Item1", 10.0, "Unidade");

    SUBCASE("03-Remover quantidade suficiente") {
        CHECK_NOTHROW(estoque.remover_estoque("Item1", 5.0));
        CHECK_EQ(estoque.get_quantidade("Item1"), 5.0);
    }

    SUBCASE("04-Remover quantidade insuficiente") {
        CHECK_NOTHROW(estoque.remover_estoque("Item1", 15.0));
        // Verificar se uma mensagem de erro foi exibida corretamente
        // Implemente uma solução adequada para tratar o caso de quantidade insuficiente no método remover_estoque
    }
}

TEST_CASE("05-Teste do método get_quantidade") {
    Estoque estoque;
    estoque.adicionar_estoque("Item1", 10.0, "Unidade");

    CHECK_EQ(estoque.get_quantidade("Item1"), 10.0);

    // Verificar o comportamento quando o item não está no estoque
    CHECK_THROWS(estoque.get_quantidade("Item2"));
}