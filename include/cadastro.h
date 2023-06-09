#ifndef PDS2_CADASTRO_H
#define PDS2_CADASTRO_H

#include <string>
#include <vector>
#include<iostream>
#include <stdexcept>
#include <regex>
/*
 * A classe cadastro 
 guarda o número da comanda,
 nome,
telefone 
 */

class id_invalido_e {};
class nome_invalido_e {};
class telefone_invalido_e {};
class Cadastro {
 
  private:
    unsigned int _id;
    std::string _nome;
    std::string _telefone;
  public:
    /*
     * @brief constrói o cadastro 
     */
    Cadastro();
    Cadastro(int id,std::string nome,std::string telefone);



    /*
     * @brief pega o identificador da comanda
     */
    unsigned int get_id();

    /*
                if (menuOptions2 == 7)
                {
                    

    /*
     * @brief pega o telefone do cliente
     */
    std::string get_telefone();



    std::string get_nome();

};
#endif