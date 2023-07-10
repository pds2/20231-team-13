#include "../third_party/doctest.h"
#include "../include/cadastro.h"



TEST_CASE("Teste do construtor Cadastro") {
    // Teste 1: ID inválido
    SUBCASE("ID inválido") {
        CHECK_THROWS_AS(Cadastro(-1, "João", "12345", "12345678910"), id_invalido_e());
    }

    // Teste 2: Nome vazio
    SUBCASE("Nome vazio") {
        CHECK_THROWS_AS(Cadastro(1, "", "12345", "12345678910"), nome_invalido_e());
    }

    // Teste 3: Telefone vazio
    SUBCASE("Telefone vazio") {
        CHECK_THROWS_AS(Cadastro(1, "João", "", "12345678910"), telefone_invalido_e());
    }

    // Teste 4: CPF inválido
    SUBCASE("CPF inválido") {
        CHECK_THROWS_AS(Cadastro(1, "João", "12345", "123456"), cpf_invalido_e());
    }

    // Teste 5: Dados válidos
    SUBCASE("Dados válidos") {
        CHECK_NOTHROW(Cadastro(1, "João", "12345", "12345678910"));
    }
}