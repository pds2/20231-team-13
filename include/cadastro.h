#ifndef PDS2_CADASTRO_H
#define PDS2_CADASTRO_H

#include <string>
#include <vector>
#include<iostream>


/*
 * A classe cadastro 
 guarda o número da comanda,
 nome,
telefone e
 cpf.
 */
class Cadastro {
  private:
    unsigned int _id;
    std::string _nome;
    std::string _telefone;
    std::string _cpf;
    std::vector<Cadastro> _novocliente; // Vetor para armazenar os clientes

  public:
    /*
     * @brief constrói o cadastro 
     */
    Cadastro(int id,std::string nome,std::string telefone, std::string cpf);

    /*
     * @brief pega o identificador da comanda
     */
    unsigned int get_id();

    /*
     * @brief pega o nome do cliente
     */
    std::string get_nome();

    /*
     * @brief pega o telefone do cliente
     */
    std::string get_telefone();

    /*
     * @brief pega o cpf do cliente
     */
    std::string get_cpf();
    /*
     * @brief adiciona um novo cliente
     */
    void novo_cliente(int id, const std::string& nome, const std::string& telefone, const std::string& cpf);

};
#endif