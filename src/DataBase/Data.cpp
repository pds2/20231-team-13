#include <iostream>
#include <map>
#include <string>
#include "../third_party/sqlite3/sqlite3.h"
#include "../include/DataBase/Data.h"

int Data::ExecSQLEmpty(std::string sql) {
    char* zErrMsg = nullptr;
    const char* sqlChar = sql.c_str();

    // Executa a consulta SQL
    int rc = sqlite3_exec(_db, sqlChar, nullptr, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cout << "Não foi possível executar: " << sql << std::endl << "Erro: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        std::cout << "Executado: " << sql << std::endl;
        return 0;
    }
}

Data::Data(std::string nomeArquivo, std::string tabela) : _db(nullptr) {
    _tabela = tabela;

    int rc = sqlite3_open(nomeArquivo.c_str(), &_db);

    if (rc != SQLITE_OK) {
        std::cout << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(_db) << std::endl;
    } else {
        std::cout << "Banco de dados aberto" << std::endl;
    }
}

Data::~Data() {
    if (_db != nullptr) {
        std::cout << "Fechando o banco de dados" << std::endl;
        int rc = sqlite3_close(_db);
        if (rc != SQLITE_OK) {
            std::cout << "Erro ao fechar o banco de dados: " << sqlite3_errmsg(_db) << std::endl;
        }
    }
}
