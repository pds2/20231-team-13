#include "../include/menu.h"

void Menu::MenuStart()
{
    std::cout << "MENU" << std::endl;
    std::cout << "(1)- Menu Cliente." << std::endl;
    std::cout << "(2)- Menu Gerente." << std::endl;
    std::cout << "(0)- Sair." << std::endl;
    std::cout << "Digite sua opção: " ;
}

void Menu::MenuGerente()
{
        std::cout << "MENU GERENTE" << std:: endl;
    std::cout << "(1)- Adicionar produto ao estoque." << std::endl;
    std::cout << "(2)- Remover produto do estoque." << std::endl;
    std::cout << "(3)- Exibir extrato do caixa." << std::endl;
    std::cout << "(4)- Adicionar Prato Entrada" << std::endl;
    std::cout << "(5)- Adicionar Prato Principal" << std::endl;
    std::cout << "(6)- Adicionar Prato Sobremesa." << std::endl;
    std::cout << "(7)- Exibir Pedidos." << std::endl;
    std::cout << "(0)- Sair" << std::endl;
    std::cout << "Digite sua opção: ";

}

void Menu::MenuCliente()
{
    std::cout << "MENU CLIENTE" << std:: endl;
    std::cout << "(1)- Criar novo cadastro." << std::endl;
    std::cout << "(2)- Exibir cardapio." << std::endl;
    std::cout << "(3)- Adicionar pedidos." << std::endl;
    std::cout << "(4)- Exibir Pedidos." << std::endl;
    std::cout << "(5)- Cancelar pedido." << std::endl;
    std::cout << "(6)- Exibir formas de pagamento." << std::endl;
    std::cout << "(7)- Exibir valor total." << std::endl;
    std::cout << "(8)- Exibir valor total com gorjeta." << std::endl;
    std::cout << "(9)- Efetuar pagamento" << std::endl;
    std::cout << "(0)- Sair" << std::endl;
    std::cout << "Digite sua opção: ";


}
