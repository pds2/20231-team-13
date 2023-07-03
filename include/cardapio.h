#ifndef PDS2_CARDAPIO_H
#define PDS2_CARDAPIO_H

#include <string>
#include <vector>
#include<iostream>


class nome_invalido_e {};
class preço_invalido_e {};

class Prato {
protected:
    std::string _nome;
    double _preco;

public:
    Prato(const std::string& nome, double preco);
    std::string get_nome() const;
    double get_preco() const;
    virtual ~Prato();
     void exibir() const;
};

class Entrada : public Prato {
public:
    Entrada(const std::string& nome, double preco);

    void exibir() const;
};
class PratoPrincipal : public Prato {
public:
    PratoPrincipal(const std::string& nome, double preco);

    void exibir() const;
};
class Sobremesa : public Prato {
public:
    Sobremesa(const std::string& nome, double preco);

    void exibir() const;
};

class Cardapio {
private:
    std::vector<Prato*> pratos;

public:
    ~Cardapio();

    void adicionarPrato(Prato* prato);

    void exibir() const;
};

#endif