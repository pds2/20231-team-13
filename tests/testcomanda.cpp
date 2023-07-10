#include "../third_party/doctest.h"
#include "../include/comanda.h"
#include "../include/cadastro.h"
#include "../include/cardapio.h"

TEST_CASE("teste da comanda"){
    Cadastro cliente(123,"Joao","123456789","1234567890");
    Comanda comanda(&cliente);
    CHECK(comanda.getCliente()==&cliente);

    Prato prato1("Prato", 10.0);

    comanda.adicionarPedido(&prato1);

    const std::vector<Prato*>& pedidos = comanda.getPedidos();
    REQUIRE(pedidos.size() == 1);
    CHECK(pedidos[0] == &prato1);

    Prato prato2("Prato 2", 20.0);
    Prato prato3("Prato 3", 30.0);
    comanda.adicionarPedido(&prato2);

    CHECK_THROWS_AS(comanda.cancelarPedido(&prato3), prato_nao_encontrado_e);

}
