#include <iostream>
#include <regex>
#include  "../include/cadastro.h"

    Cadastro::Cadastro()
    {

    }


   Cadastro::Cadastro(int id,std::string nome,std::string telefone, std::string cpf) {
        try {
            // Verifica se o ID é válido (maior que zero)
            if (id <= 0) {
                throw id_invalido_e();
            }
            this->_id = id;

            // Verifica se o nome não está vazio
            if (nome.empty()) {
                throw nome_invalido_e();
            }
            this->_nome = nome;

            // Verifica se o telefone não está vazio
            if (telefone.empty()) {
                throw telefone_invalido_e();
            }
            this->_telefone = telefone;

            // Verifica se o CPF é válido
            if (!validarCPF(cpf)) {
                throw cpf_invalido_e();
            }
            this->_cpf = cpf;
        } catch (...) {
        // Lógica de tratamento da exceção
    }
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

 bool Cadastro::validarCPF(const std::string& cpf) {
        // Verifica o formato do CPF usando uma expressão regular
        std::regex formatoCPF(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
        if (!std::regex_match(cpf, formatoCPF)) {
            return false;
        }
        return true;
  }