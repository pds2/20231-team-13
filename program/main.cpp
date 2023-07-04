#include "../include/menu.h"
#include "../include/cadastro.h"
#include "../include/comanda.h"
#include "../include/estoque.h"
#include "../include/caixa.h"
#include "../include/cardapio.h"

#include <iostream>
#include <string>



int main() {
    Menu _menu;
    Cadastro _cadastro;
    Comanda _comanda;
    Estoque _estoque;
    Caixa _caixa;
    Cardapio _cardapio;


    const std::string senhaGerente = "12345";
    unsigned int menuOptions1 = 0;
    unsigned int menuOptions2 = 0;
    for (;;)
    {
        _menu.MenuStart();
        std::cin >> menuOptions1;
        if(menuOptions1 == 1)
        {
            _menu.MenuCliente();
            std::cin >> menuOptions2;
            if (menuOptions2 == 1)
            {
                int id = 0;
                std::string nome;
                std::string telefone;
                std::string cpf;

                std::cout<< "Digite o ID: " << std::endl;
                std::cin >> id;

                std::cout<< "Digite o seu nome: " << std::endl;
                std::cin >> nome;

                std::cout<< "Digite o seu telefone: " << std::endl;
                std::cin >> telefone;

                std::cout<< "Digite o seu CPF: " << std::endl;
                std::cin >> cpf;


                _cadastro.novo_cliente(id,nome,telefone,cpf);
                

            }

            if (menuOptions2 == 2)
            {
                
            }


            
            
        }
        if (menuOptions1 == 2)
        {
            std::string senha;
            std::cout << "Digite a senha: ";
            std::cin >> senha;
            std::cout << std::endl;
            if (senha != senhaGerente)
            {
                std::cout << "Senha Incorreta"<< std::endl;
                continue;
            }
            if (senha == senhaGerente)
            {
                _menu.MenuGerente();
                std::cin >> menuOptions2;
                if(menuOptions2 == 1)
                {
                    std::string item;
                    std::cout << "Nome do item: " << std::endl;
                    std::cin >> item;

                    int quantidade;
                    std::cout << "Quantidade: " << std::endl;
                    std::cin >> quantidade;

                    _estoque.adicionar_estoque(item,quantidade);
                }

                if (menuOptions2 == 2)
                {
                    std::string item;
                    std::cout << "Nome do item: " << std::endl;
                    std::cin >> item;

                    int quantidade;
                    std::cout << "Quantidade: " << std::endl;
                    std::cin >> quantidade;

                    _estoque.remover_estoque(item,quantidade);
                }

                if (menuOptions2 == 3)
                {
                    _caixa.exibirExtrato();
                }
                if (menuOptions2 == 4)
                {
                    std::string nomeEntrada;
                    double preco;
                    Entrada novoEntrada(nomeEntrada,preco);
                    _cardapio.adicionarPrato(novoEntrada);
                }
                 if (menuOptions2 == 5)
                {
                    std::string nomePrincipal;
                    double preco;
                    PratoPrincipal novoPrincipal(nomePrincipal,preco);
                    _cardapio.adicionarPrato(novoPrincipal);
                }
                 if (menuOptions2 == 6)
                {
                    std::string nomeSobremesa;
                    double preco;
                    Sobremesa novoSobremesa(nomeSobremesa,preco);
                    _cardapio.adicionarPrato(novoSobremesa);
                }
                if (menuOptions2 == 7)
                {
                    _comanda.exibirPedidos();
                }
                if (menuOptions2 == 0)
                {
                    continue;
                }
                
                
                
                
                
            }
            
            

        }
        if(menuOptions1 == 0)
        {
            exit(0);
        }
        
    }
    
}
