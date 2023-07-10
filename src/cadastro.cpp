#include <iostream>
#include <regex>
#include  "../include/cadastro.h"

    Cadastro::Cadastro()
    {

    }


   Cadastro::Cadastro(int id,std::string nome,std::string telefone) {
            // Verifica se o ID é válido (maior que zero)
            if (id <= 0) {
                throw id_invalido_e();
            }
            this->_id = id;

            // Verifica se o nome não está vazio
            if (nome.empty()) {
                throw nome_invalido_e();
            this->_nome = nome;
            }
            // Verifica se o telefone não está vazio
            if (telefone.empty()) {
                throw telefone_invalido_e();
            this->_telefone = telefone;
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


 