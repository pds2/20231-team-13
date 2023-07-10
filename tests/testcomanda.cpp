#include "../third_party/doctest.h"
#include "../include/comanda.h"
#include "../include/cadastro.h"
#include "../include/cardapio.h"

TEST_CASE("01-criar comanda"){
    Cadastro cliente(123,"Joao","123456789","1234567890");
    Comanda comanda(&cliente);
    CHECK(comanda.getCliente()==&cliente);
}

TEST_CASE("02- criar comanda para cliente inexistente"){
    CHECK_THROWS_AS(Comanda comanda(nullptr), cliente_nao_existe_e());
}

TEST_CASE("03- adicionar prato"){
    Cadastro cliente(123,"Joao","123456789","1234567890");
    Comanda comanda(&cliente);
    Prato prato1("Prato", 10.0);

    comanda.adicionarPedido(&prato1);

    const std::vector<Prato*>& pedidos = comanda.getPedidos();
    REQUIRE(pedidos.size() == 1);
    CHECK(pedidos[0] == &prato1);
}

TEST_CASE("04- cancela prato que nao existe na comanda"){
    Cadastro cliente(123,"Joao","123456789","1234567890");
    Comanda comanda(&cliente);
    Prato prato1("Prato", 10.0);
    comanda.adicionarPedido(&prato1);
    Prato prato2("Prato 2", 20.0);
    Prato prato3("Prato 3", 30.0);
    comanda.adicionarPedido(&prato2);
    CHECK_THROWS_AS(comanda.cancelarPedido(&prato3), prato_nao_encontrado_e);
}

TEST_CASE("05- cancelar pedido"){
    Cadastro cliente(123,"Joao","123456789","1234567890");
    Comanda comanda(&cliente);
    Prato prato1("Prato", 10.0);
    Prato prato2("Prato 2", 20.0);
    comanda.adicionarPedido(&prato1);
    comanda.adicionarPedido(&prato2);
    comanda.cancelarPedido(&prato2);
    
    const std::vector<Prato*>& pedidos = comanda.getPedidos();
    REQUIRE(pedidos.size() == 1);
    CHECK(pedidos[0] == &prato1);
}