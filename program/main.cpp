#include "../include/menu.h"
#include <iostream>
#include <string>



int main() {
    Menu _menu;
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
            }
            
            

        }
        if(menuOptions1 == 0)
        {
            exit(0);
        }
        
    }
    
}