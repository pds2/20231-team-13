#include "../third_party/doctest.h"
#include "../include/comanda.h"
#include "../include/cadastro.h"
#include "../include/cardapio.h"
#include "../include/conta.h"

Conta criaconta(){
    Cadastro cliente(1, "Cliente", "123456789", "123456789");
    Prato prato1("Prato1", 10);
    Prato prato2("Prato2", 15);
    Comanda comanda(&cliente);
    comanda.adicionarPedido(&prato1);
    comanda.adicionarPedido(&prato2);
    Conta conta (&comanda);
    return conta;
}

TEST_CASE("teste valor total"){
    CHECK(criaconta().get_valorTotal() == 25);
}

TEST_CASE("teste valor com gorjeta"){
    CHECK(criaconta().exibirValorTotalComGorjeta() == 27.5);
}

TEST_CASE("teste informar conta paga"){
    Cadastro cliente(1, "Cliente", "123456789", "123456789");
    Prato prato1("Prato1", 10);
    Prato prato2("Prato2", 15);
    Comanda comanda(&cliente);
    comanda.adicionarPedido(&prato1);
    comanda.adicionarPedido(&prato2);
    Conta conta (&comanda);
    conta.informarContaPaga();
    CHECK(conta.get_contaPaga() == true);
}
