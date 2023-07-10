#include "../include/estoque.h"
#include "../include/DataBase/EstoqueDados.h"
#include <iostream>
#include <stdexcept>

Estoque::Estoque() : _estoque("Data.db", "ESTOQUE") {}

void Estoque::adicionar_estoque(std::string item, float quantidade, std::string unidade) {
    std::map<std::string, std::string> produto = _estoque.Procurar(item);
    if (produto["Status"].compare("NotFound") == 0) {
        _estoque.Atualiza(item, quantidade, unidade);
    } else {
        _estoque.Atualiza(item, std::stof(produto["QUANTIDADE"]) + quantidade, unidade);
    }
}

void Estoque::remover_estoque(std::string item, float quantidade) {
    std::map<std::string, std::string> produto = _estoque.Procurar(item);
    if (std::stof(produto["QUANTIDADE"]) >= quantidade) {
        _estoque.Atualiza(produto["NOME"], std::stof(produto["QUANTIDADE"]) - quantidade, produto["UNIDADE"]);
    } else {
        std::cout << "Quantidade insuficiente de " << item << " no estoque." << std::endl;
    }
}

float Estoque::get_quantidade(std::string nomeDoProduto) {
    std::map<std::string, std::string> produto = _estoque.Procurar(nomeDoProduto);
    if (produto["Status"].compare("NotFound") == 0) {
        throw std::runtime_error("Erro: Esse item não está registrado!");
    } else {
        float quantidadeFloat = std::stof(produto["QUANTIDADE"]);
        return quantidadeFloat;
    }
  
    return 0;
}
