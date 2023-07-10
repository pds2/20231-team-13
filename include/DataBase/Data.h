#ifndef DATA_H
#define DATA_H

#include <map>
#include <string>
#include "../third_party/sqlite3/sqlite3.h"

class Data {
public:
    Data(std::string nomeArquivo, std::string tabela);
    virtual ~Data();

protected:
    int ExecSQLEmpty(std::string sql);
    virtual void criarTabela() const = 0;

    sqlite3* _db;
    std::string _tabela;
};

#endif
