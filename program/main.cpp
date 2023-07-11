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
    Comanda comandaAtual;

    
    Prato* novoPrincipal = new PratoPrincipal("Macarrao", 30);
    _cardapio.adicionarPrato(novoPrincipal);

    novoPrincipal = new PratoPrincipal("Risotto", 60);
    _cardapio.adicionarPrato(novoPrincipal);

    novoPrincipal = new PratoPrincipal("Tropeiro", 15);
    _cardapio.adicionarPrato(novoPrincipal);

    Prato* novaSobremesa = new Sobremesa("Sorvete", 10);
    _cardapio.adicionarPrato(novaSobremesa);

    novaSobremesa = new Sobremesa("Churros", 7);
    _cardapio.adicionarPrato(novaSobremesa);

    novaSobremesa = new Sobremesa("Brownie", 17);
    _cardapio.adicionarPrato(novaSobremesa);

    Prato* novaEntrada = new Entrada("Nacho", 15);
    _cardapio.adicionarPrato(novaEntrada);

    novaEntrada = new Entrada("Empada", 23);
    _cardapio.adicionarPrato(novaEntrada);

    novaEntrada = new Entrada("Salada", 10);
    _cardapio.adicionarPrato(novaEntrada);

    for (;;)
    {
    
        _menu.MenuStart();
        std::cin >> menuOptions1;
        if(menuOptions1 == 1)
        {
            try{

            std::cout<< "Vamos comecar o seu cadastro" << std::endl;
            
            int id = 0;
            std::string nome;
            std::string telefone;
            

            std::cout<< "Digite o ID: " << std::endl;
            std::cin >> id;

            std::cout<< "Digite o seu nome: " << std::endl;
            std::cin >> nome;

            std::cout<< "Digite o seu telefone: " << std::endl;
            std::cin >> telefone;


            Cadastro clienteAtual = Cadastro(id ,nome,telefone);
            _cadastros.push_back(clienteAtual);

            comandaAtual = Comanda(&clienteAtual);
            _comandas[clienteAtual.get_nome()]= comandaAtual;

            } catch(id_invalido_e &e)
            {
                std::cout << "ID invalido!" << std::endl;
            }
            catch(nome_invalido_e &e)
            {
                std::cout << "Nome invalido!" << std::endl;
            }
            catch(telefone_invalido_e &e)
            {
                std::cout << "Telefone invalido!" << std::endl;
            }
            
            for (;;)
            {
            try{

                _menu.MenuCliente();
                std::cin >> menuOptions2;


                if (menuOptions2 == 2)
                {
                    _cardapio.exibir();
                }

                if (menuOptions2 == 3)
                {
                    std::string nomeDoPrato;
                    std::cout << "Digite o nome do prato: " << std::endl;
                    cin >> nomeDoPrato;
                    comandaAtual.adicionarPedido(_cardapio.get_prato_escolhido(nomeDoPrato));
                    
                }

                if (menuOptions2 == 4)
                {
                    
                    comandaAtual.exibirPedidos();
                }

                if(menuOptions2 == 5)
                {
                    std::string nomeDoPrato;
                    std::cout << "Digite o nome do prato: " << std::endl;
                    cin >> nomeDoPrato;
                    comandaAtual.cancelarPedido(_cardapio.get_prato_escolhido(nomeDoPrato));
                }

                if (menuOptions2 == 6)
                {
                    Conta _conta(&comandaAtual);
                    _conta.exibirFormasDePagamento();
                }

                if (menuOptions2 == 7)
                {
                    Conta _conta(&comandaAtual);
                    _conta.calcularValorTotal();
                    std::cout << std::endl << _conta.get_valorTotal() << std::endl << std::endl;
                }

                if (menuOptions2 == 8)
                {
                    Conta _conta(&comandaAtual);
                    _conta.calcularValorTotal();
                    std::cout << std::endl << _conta.exibirValorTotalComGorjeta() << std::endl << std::endl;
                }

                if (menuOptions2 == 9)
                {
                    Conta _conta(&comandaAtual);
                    _conta.calcularValorTotal();
                    _conta.informarContaPaga();
                    _caixa.contabilizarConta(_conta);
                }


                if (menuOptions2 == 0)
                {
                    break;
                }


                

            }catch(cliente_invalido_e &e)
            {
                std::cout << "Cliente invalido!" << std::endl;
            }
            catch(preco_invalido_e &e)
            {
                std::cout << "Preco invalido!" << std::endl;
            }
            catch(nome_prato_invalido_e &e)
            {
                std::cout << "Nome do prato invalido!" << std::endl;
            }
            catch(cliente_nao_existe_e &e)
            {
                std::cout << "Cliente nao existe!" << std::endl;
            }
            catch(prato_nao_existe_e &e)
            {
                std::cout << "Este prato nao existe!" << std::endl;
            }
            catch(prato_nao_encontrado_e &e)
            {
                std::cout << "Este prato nao foi encontrado!" << std::endl;
            }
            catch(comanda_nao_existe_e &e)
            {
                std::cout << "Essa comanda nao existe!" << std::endl;
            }
              
            
        }
        }
        
        if (menuOptions1 == 2)
        {   
            
            try {
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
                for(;;){
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

                    std::string unidade;
                    std::cout << "Unidade: " << std::endl;
                    std::cin >> unidade;

                    _estoque.adicionar_estoque(item,quantidade, unidade);
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
                    break;
                }
                }
            }    
                
                
                
                
            } catch(cliente_invalido_e &e)
            {
                std::cout << "Cliente invalido!" << std::endl;
            }
            catch(preco_invalido_e &e)
            {
                std::cout << "Preco invalido!" << std::endl;
            }
            catch(nome_prato_invalido_e &e)
            {
                std::cout << "Nome do prato invalido!" << std::endl;
            }
            catch(cliente_nao_existe_e &e)
            {
                std::cout << "Cliente nao existe!" << std::endl;
            }
            catch(prato_nao_existe_e &e)
            {
                std::cout << "Este prato nao existe!" << std::endl;
            }
            catch(prato_nao_encontrado_e &e)
            {
                std::cout << "Este prato nao foi encontrado!" << std::endl;
            }
            catch(comanda_nao_existe_e &e)
            {
                std::cout << "Essa comanda nao existe!" << std::endl;
            }
            }
            
            

        }
        if(menuOptions1 == 0)
        {
            exit(0);
        }
        
}
    
    
