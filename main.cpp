#include <iostream>
#include <map>
#include "./include/data.h"

using namespace std;

int main() {
   char arquivo[] = "teste.db";
   Data db = Data(arquivo, "ESTOQUE");

   std::map<std::string, std::string> res;

   db.AtualizaEstoque("Pao", 5, "unidade");
   res = db.ProcurarLinha("Pao");
   cout << res["QUANTIDADE"] << endl;

   db.AtualizaEstoque("Contra-File", 8, "kg");
   res = db.ProcurarLinha("Contra-File");
   cout << res["QUANTIDADE"] << " " << res["UNIDADE"] << endl;

   db.AtualizaEstoque("Macarrao", 5, "pacotes");
   db.RemoveEstoque("Pao");
   res = db.ProcurarLinha("Pao");
   cout << res["QUANTIDADE"] << endl;
   
}