#include <iostream>
#include  "include/cadastro.h"



Cadastro::Cadastro(
    int id,
  std::string nome,
  std::string telefone,
  std::string cpf
)
 {
    _id=id;
  _nome = nome;
  _telefone = telefone;
  _cpf = cpf;
}

unsigned int Cadastro::get_id() {
  return _id;
}
std::string Cadastro::get_nome() {
  return _nome;
}
std::string Cadastro::get_telefone() {
  return _telefone;
}
std::string Cadastro::get_cpf() {
  return _cpf;
}

void Cadastro::novo_cliente(int id, const std::string& nome, const std::string& telefone, const std::string& cpf) {
        Cadastro novoCliente(id, nome, telefone, cpf);
        novoCliente._id = id;
        novoCliente._nome = nome;
        novoCliente._telefone = telefone;
        novoCliente._cpf = cpf;

        _novocliente.push_back(novoCliente);
    }

