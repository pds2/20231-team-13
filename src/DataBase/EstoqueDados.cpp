#include <iostream>
#include <map>
#include <string>
#include "../include/DataBase/EstoqueDados.h"
#include "../include/DataBase/Data.h"

EstoqueDados::EstoqueDados(std::string nomeArquivo, std::string tabela) : Data(nomeArquivo, tabela) {
    criarTabela();
}

void EstoqueDados::criarTabela() const{
    std::string sql = "CREATE TABLE " + _tabela + "("
                      "NOME           TEXT    NOT NULL,"
                      "QUANTIDADE     REAL    NOT NULL,"
                      "UNIDADE        TEXT    NOT NULL)";

    // Cria a tabela SQL
    sqlite3_exec(_db, sql.c_str(), nullptr, nullptr, nullptr);
}

void EstoqueDados::Atualiza(std::string nome, int valorPraAtualizar, std::string unidade) {
    // Checa se o produto já foi adicionado; caso não, adiciona
    if (Procurar(nome)["Status"].compare("NotFound") == 0) {
        adiciona(nome, valorPraAtualizar, unidade);
    } else {
        // Caso sim, atualiza os dados
        std::string sql = "UPDATE " + _tabela + " SET QUANTIDADE = " + std::to_string(valorPraAtualizar) +
                          " WHERE NOME = '" + nome + "';";

        ExecSQLEmpty(sql);

        sql = "UPDATE " + _tabela + " SET UNIDADE = '" + unidade +
                          "' WHERE NOME = '" + nome + "';";

        ExecSQLEmpty(sql);
    }
}

void EstoqueDados::adiciona(std::string nome, float quantidade, std::string unidade) {
    // Prepara a consulta SQL com os valores inseridos
    std::string sql = "INSERT INTO " + _tabela + " (NOME, QUANTIDADE, UNIDADE) VALUES ('" + nome + "', '" +
                      std::to_string(quantidade) + "', '" + 
                      unidade + "');";
    ExecSQLEmpty(sql);
}

void EstoqueDados::Remove(std::string nome) {
    // Prepara a consulta SQL com os valores inseridos
    std::string sql = "DELETE FROM " + _tabela + " WHERE NOME = '" + nome + "';";

    ExecSQLEmpty(sql);
}



int callbackProcurarLinhaSQL(void* data, int argc, char** argv, char** colNames) {
    std::map<std::string, std::string>* result = static_cast<std::map<std::string, std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        std::string value = (argv[i] ? argv[i] : "NULL");
        std::string colName = colNames[i];
        (*result)[colName] = value;
    }

    return 0;
}

std::map<std::string, std::string> EstoqueDados::Procurar(const std::string& nome) {
    std::map<std::string, std::string> valores;

    // Prepara a consulta SQL para obter a linha com o nome especificado
    std::string consultaSQL = "SELECT * FROM " + _tabela + " WHERE NOME = '" + nome + "';";

    // Executa a consulta SQL e chama a função de retorno de chamada (callback)
    int rc = sqlite3_exec(_db, consultaSQL.c_str(), callbackProcurarLinhaSQL, &valores, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << "Nao foi possivel executar: " << consultaSQL << std::endl << sqlite3_errmsg(_db);
    } else{
        std::cout << "Executado: " << consultaSQL << std::endl;
    }

    if (valores.empty()) {
        valores["Status"] = "NotFound";
    }

    return valores;
}