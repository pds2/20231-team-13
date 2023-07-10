#include "../include/menu.h"
#include "../include/cadastro.h"
#include "../include/comanda.h"
#include "../include/estoque.h"
#include "../include/caixa.h"
#include "../include/cardapio.h"
#include "../include/conta.h"

#include <iostream>
#include <string>



int main() {
   


    const std::string senhaGerente = "12345";
    unsigned int menuOptions1 = 0;
    unsigned int menuOptions2 = 0;
    Menu _menu;
    vector<Cadastro> _cadastros;
    Estoque _estoque;
    Caixa _caixa;
    Cardapio _cardapio;
    std::map<std::string,Comanda> _comandas;

    try{
    for (;;)
    {
  
        _menu.MenuStart();
        std::cin >> menuOptions1;
        if(menuOptions1 == 1)
        {
            std::string cpfCliente;
            std::cout << "Digite seu cpf: " << std::endl;
            std::cin >> cpfCliente;

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


                Cadastro clienteAtual = Cadastro(id ,nome,telefone,cpf);
                _cadastros.push_back(clienteAtual);

                Comanda comandaAtual = Comanda(&clienteAtual);
                _comandas[clienteAtual.get_cpf()]= comandaAtual;
                

            }

            

            if (menuOptions2 == 2)
            {
                _cardapio.exibir();
            }

            if (menuOptions2 == 3)
            {
                std::string nomeDoPrato;
                std::cout << "Digite o nome do prato: " << std::endl;
                cin >> nomeDoPrato;
                _comandas[cpfCliente].adicionarPedido(_cardapio.get_prato_escolhido(nomeDoPrato));
            }

            if (menuOptions2 == 4)
            {
                
                _comandas[cpfCliente].exibirPedidos();
            }

            if(menuOptions2 == 5)
            {
                std::string nomeDoPrato;
                std::cout << "Digite o nome do prato: " << std::endl;
                cin >> nomeDoPrato;
                _comandas[cpfCliente].cancelarPedido(_cardapio.get_prato_escolhido(nomeDoPrato));
            }

            if (menuOptions2 == 6)
            {
                Conta _conta(&_comandas[cpfCliente]);
                _conta.exibirFormasDePagamento();
            }

            if (menuOptions2 == 7)
            {
                Conta _conta(&_comandas[cpfCliente]);
                _conta.calcularValorTotal();
            }

            if (menuOptions2 == 8)
            {
                Conta _conta(&_comandas[cpfCliente]);
                _conta.exibirValorTotalComGorjeta();
            }

            if (menuOptions2 == 9)
            {
                Conta _conta(&_comandas[cpfCliente]);
                _conta.informarContaPaga();
            }


            if (menuOptions2 == 0)
            {
                continue;
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
                    std::cout << "Digite o nome da entrada: " << std::endl;
                    std::cin >> nomeEntrada;

                    double preco;
                    std::cout << "Digite o preço: " << std::endl;
                    std::cin >>preco;

                   // Entrada novoEntrada(nomeEntrada,preco);
                   Prato* novoEntrada = new Entrada(nomeEntrada, preco);
                    _cardapio.adicionarPrato(novoEntrada);
                }
                 if (menuOptions2 == 5)
                {
                    std::string nomePrincipal;
                    std::cout << "Digite o nome do prato principal: " << std::endl;
                    std::cin >>nomePrincipal;

                    double preco =0 ;
                    std::cout << "Digite o preço: " << std::endl;
                    std::cin >> preco;

                   // PratoPrincipal novoPrincipal(nomePrincipal,preco);
                    Prato* novoPrincipal = new PratoPrincipal(nomePrincipal, preco);
                    _cardapio.adicionarPrato(novoPrincipal);
                }
                 if (menuOptions2 == 6)
                {
                    std::string nomeSobremesa;
                    std::cout << "Digite o nome da sobremesa: " << std::endl;
                    std::cin >> nomeSobremesa;

                    double preco;
                    std::cout << "Digite o preço: " << std::endl;
                    std::cin >>preco;

                    //Sobremesa novoSobremesa(nomeSobremesa,preco);
                    Prato* novaSobremesa = new Sobremesa(nomeSobremesa, preco);
                    _cardapio.adicionarPrato(novaSobremesa);
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

    } catch(id_invalido_e )
    {
        std::cout << "ID invalido!" << std::endl;
    }
    catch(nome_invalido_e)
    {
        std::cout << "Nome invalido!" << std::endl;
    }
    catch(telefone_invalido_e)
    {
        std::cout << "Telefone invalido!" << std::endl;
    }
    catch(cpf_invalido_e)
    {
        std::cout << "CPF invalido!" << std::endl;
    }
     catch(cliente_invalido_e)
    {
        std::cout << "Cliente invalido!" << std::endl;
    }
     catch(preco_invalido_e)
    {
        std::cout << "Preco invalido!" << std::endl;
    }
     catch(nome_prato_invalido_e)
    {
        std::cout << "Nome do prato invalido!" << std::endl;
    }
     catch(cliente_nao_existe_e)
    {
        std::cout << "Cliente nao existe!" << std::endl;
    }
     catch(prato_nao_existe_e)
    {
        std::cout << "Este prato nao existe!" << std::endl;
    }
     catch(prato_nao_encontrado_e)
    {
        std::cout << "Este prato nao foi encontrado!" << std::endl;
    }
     catch(comanda_nao_existe_e)
    {
        std::cout << "Essa comanda nao existe!" << std::endl;
    }

    
}
