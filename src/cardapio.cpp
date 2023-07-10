#include "../include/cardapio.h"
#include <string>

Prato:: Prato(const std::string nome, double preco) {
        if (nome.empty()) {
            throw nome_prato_invalido_e();
        }
        _nome = nome;

        if (preco <= 0) {
            throw preco_invalido_e();
        _preco = preco;
    }
}

double Prato::get_preco() const {
  return _preco;
}

 void Prato::exibir() const {
        std::cout << "Nome: " << this->_nome << ", Preco: R$" << this->_preco << std::endl;
    }

  Entrada::Entrada(const std::string nome, double preco)
        : Prato(nome, preco) {
    }
 void Entrada::exibir() const {
        std::cout << "Entrada - ";
        Prato::exibir();
    }
     PratoPrincipal::PratoPrincipal(const std::string nome, double preco)
        : Prato(nome, preco) {
        }
void PratoPrincipal::exibir() const {
        std::cout << "Prato Principal - ";
        Prato::exibir();
    }

     Sobremesa::Sobremesa(const std::string nome, double preco)
        : Prato(nome, preco) {
    }
void Sobremesa::exibir() const {
        std::cout << "Sobremesa - ";
        Prato::exibir();
    }

    void Cardapio::adicionarPrato(Prato* prato) {
        pratos.push_back(prato);
    }
     void Cardapio::exibir() const {
        for (const  Prato* prato : pratos) {
            prato->exibir();
        }
    
    }