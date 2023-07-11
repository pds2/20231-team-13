<h1 align="center">🍔 Software para Restaurante</h1>

<p align="center">
  <b>Software desenvolvido em terminal para facilitar a organização de um restaurante.</b>
</p>

<p align="center">
  <b>Desenvolvedores:</b><br>
  👨‍💻 Marcelo Félix Hochreiter<br>
  👩‍💻 Bárbara Ferreira Ramos<br>
  👩‍💻 Samira Araujo Malaquias Souza<br>
  👨‍💻 Samuel Lucca Viana Miranda
</p>

<p align="center">
  <img src="https://img.shields.io/badge/-Histórias%20de%20Usuário-%F0%9F%93%9D">
</p>

## Histórias de Usuário

📖 **História 1: Visualização do Cardápio**

Como um cliente, desejo visualizar todo o cardápio, separado por categorias específicas juntamente com o preço, para que eu possa avaliar e acompanhar minha preferência de pedido.

✅ Critérios de aceitação:
- Deve ser possível adicionar uma bebida.
- Deve ser possível adicionar um preço.
- Deve ser possível definir a quantidade de porções.
- Após escolher, devo comunicar o meu pedido.

📖 **História 2: Cadastro de Cliente**

Como um cliente, desejo realizar meu cadastro único para poder realizar meu pedido.

✅ Critérios de aceitação:
- Deve possuir número da comanda único.
- Deve possuir nome.
- Deve possuir telefone.

📖 **História 3: Atualização do Estoque**

É necessário saber e atualizar a quantidade existente de cada produto para garantir que todos os pedidos feitos sejam válidos.

✅ Critérios de aceitação:
- Deve ser possível alterar a quantidade de uma comida.
- Deve ser atualizado após cada pedido feito.

📖 **História 4: Controle de Comanda**

É preciso ter controle do que foi consumido por cada cliente. A comanda computa tudo o que foi consumido por um determinado cliente e suas quantidades.

✅ Critérios de aceitação:
- Deve ser possível alterar a quantidade de uma comida.
- Deve ser atualizado após cada pedido feito.
- Deve conter forma de entrega do pedido.

📖 **História 5: Contabilização de Rendimento**

Como gerente do restaurante, quero poder contabilizar o rendimento do restaurante e efetuar as transações com os clientes.

✅ Critérios de aceitação:
- Deve contabilizar todas as cobranças feitas.
- Deve retornar as transações totais.
- Deve efetuar operações de depósito e retirada do caixa.

📖 **História 6: Fechamento da Conta**

Como cliente, quero saber o valor total dos produtos que eu consumi e escolher a minha forma de pagamento, para que eu possa pagar o restaurante.

✅ Critérios de aceitação:
- Deve somar o valor de todos os produtos consumidos.
- Deve disponibilizar as alternativas de pagamento.
- Deve informar ao caixa quando a conta for paga.

<p align="center">
  <img src="https://img.shields.io/badge/Instruções%20de%20Uso-%F0%9F%93%9D">
</p>

## Instruções de Uso

### Pré-requisitos

- Compilador C++ (recomenda-se o g++)
- SQLite3

### Configuração do Ambiente

1. Clone este repositório em sua máquina local.
2. Instale o SQLite seguindo as instruções adequadas ao seu sistema operacional.
3. Para melhor visualização do banco de dados (estoque), instale o Beekeeper-Studio ou um programa de sua preferência.

#### Windows

- Acesse o site oficial do SQLite em https://www.sqlite.org/index.html.
- Na seção de downloads, encontre a versão adequada para o seu sistema operacional Windows.
- Baixe o arquivo de instalação (por exemplo, sqlite-tools-win32-x86-3360000.zip).
- Extraia o conteúdo do arquivo ZIP para um diretório de sua escolha.
- Adicione o diretório onde o SQLite foi instalado ao seu PATH do sistema.

#### Linux

- Abra o terminal.
- Execute o seguinte comando para instalar o SQLite:
- - Aguarde o processo de instalação ser concluído.

### Compilação

1. Abra um terminal.
2. Navegue até o diretório raiz do projeto.
3. Execute o comando `make` para compilar o código.

### Execução

Após a compilação, ainda no terminal, execute um dos seguintes comandos:

- Para executar o programa principal:
Siga as instruções do terminal.

<p align="center">
  <img src="https://img.shields.io/badge/Usuários%20e%20Senhas%20de%20Teste-%F0%9F%91%A5">
</p>

## Usuários e Senhas de Teste

Para utilizar o banco de dados:

- Estoque: execute o MENU GERENTE
- Senha:12345
  - Opção (1) - Adicionar produto ao estoque

Utilize essas informações para realizar testes no sistema. 🚀



