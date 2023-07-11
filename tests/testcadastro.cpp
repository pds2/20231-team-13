#include "../third_party/doctest.h"
#include "../include/cadastro.h"



    TEST_CASE("01-ID inválido") {
        CHECK_THROWS_AS(Cadastro(-1, "João", "12345"), id_invalido_e());
    }

    
    TEST_CASE("02-Nome vazio") {
        CHECK_THROWS_AS(Cadastro(1, "", "12345"), nome_invalido_e());
    }

    
    TEST_CASE("03-Telefone vazio") {
        CHECK_THROWS_AS(Cadastro(1, "João", ""), telefone_invalido_e());
    }



    TEST_CASE("04-Dados válidos") {
        CHECK_NOTHROW(Cadastro(1, "João", "12345"));
    }
