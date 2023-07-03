#include "../third_party/doctest.h"
#include "../include/comanda.h"
#include "../include/cadastro.h"
#include "../include/cardapio.h"
#include "../include/conta.h"

TEST_CASE("teste conta"){
    Cadastro cliente(1, "Cliente", "123456789", "123456789");
        Prato prato1("Prato1", 10.0);
        Prato prato2("Prato2", 15.0);
        Comanda comanda(&cliente);
        comanda.adicionarPedido(&prato1);
        comanda.adicionarPedido(&prato2);
        Conta conta(&comanda);
        conta.calcularValorTotal();
        double valorTotalEsperado = prato1.get_preco() + prato2.get_preco();
        CHECK(conta.get_valorTotal() == valorTotalEsperado);
        CHECK(conta.exibirValorTotalComGorjeta() == valorTotalEsperado*1.1);
        conta.informarContaPaga();
        CHECK(conta.get_contaPaga() == true);
}
