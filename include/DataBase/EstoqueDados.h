#ifndef ESTOQUEDADOS_H
#define ESTOQUEDADOS_H

#include <map>
#include <string>
#include "../include/DataBase/Data.h"

class EstoqueDados : public Data {
public:
    EstoqueDados(std::string nomeArquivo, std::string tabela);
    void criarTabela() const;
    void Atualiza(std::string nome, int valorPraAtualizar, std::string unidade);
    void adiciona(std::string nome, float quantidade, std::string unidade);
    void Remove(std::string nome);
    std::map<std::string, std::string> Procurar(const std::string& nome);

private:
    // ...
};

#endif
