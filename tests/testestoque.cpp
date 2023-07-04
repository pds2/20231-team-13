#include "../third_party/doctest.h"
#include "../include/estoque.h"

TEST_CASE("Teste"){
    Estoque _estoque;
    _estoque.adicionar_estoque("salmao",10);
    _estoque.adicionar_estoque("bolo",12);
    CHECK(_estoque.get_quantidade("salmao") == 10);
    CHECK(_estoque.get_quantidade("salmao") == 12);
    
    _estoque.remover_estoque("salmao",5);
    _estoque.remover_estoque("bolo",2);
    CHECK(_estoque.get_quantidade("salmao") == 5);
    CHECK(_estoque.get_quantidade("bolo") == 10);

}