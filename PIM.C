#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>


typedef struct
{
    char usuario[12];
    char telefone[11];
    int status;
    char nome[50];

}s_pizzaiolo;
s_pizzaiolo c_pizzaiolo;

typedef struct
{
    char usuario[11];
    int nivel;
    char senha[20];
    int status;

}acesso_login;
acesso_login ctt;

typedef struct
{
    int cod_pizza;
    char sabor_pizza[30];
    char descricao_pizza[100];
    float preco_pizza;

}cadastro_sabor;
cadastro_sabor ctt1;

typedef struct
{
    int cod_pizza;
    char sabor[30];
    int quantidade;

}s_conta_sabor;
s_conta_sabor c_conta_sabor;

typedef struct
{
    int cod_bebida;
    char descricao[50];
    float preco_bebida;


}s_bebida;
s_bebida c_bebida;

typedef struct
{
    int cod_prod;
    int unidade;
    float preco_bcusto;
    char nome_produto[50];


}s_estoque;
s_estoque c_estoque;

typedef struct
{
    int Qtd_pizza;
    char telefone[11];
    char nome_Cli[50];
    char logradouro[100];
    char data[25];
    int mes;
    int ano;
    float taxa_entrega;
    float valor_receber;
    char form_pagmt[8];
    float total;
    float troco;
    char usu_atendente[20];
    int numero_pedido;
    char status_pedido[30];
    int qtd_bebida;



}s_pedidos;
s_pedidos c_pedido;

typedef struct
{
    int numero_pedido;
    char sabor[100];
    char desc_sabor[200];
    float valor_pagar;


}sabor_pedidos;
sabor_pedidos c_sabor_pedidos;

typedef struct
{
    int numero_pedido;
    char decricao[50];
    float valor_pagar;


}bebidas_pedidos;
bebidas_pedidos c_bebida_pedidos;

typedef struct
{
    int numero_pedido;
    char motivo[200];

}s_devolucao;
s_devolucao c_devolucao;

typedef struct
{
    char telefone[11];
    char nome[50];
    char logradouro[100];

}cad_cliente;
cad_cliente c_cliente;



//VARIÁVEIS PÚBLICAS
int op;
int achou_cod;// id da pizza
FILE *arq;


//VARIÁVEIS PARA LOGUIN
int validador_acesso = 0, valida_cad_usuario = 0, nivel_acesso = 0;
char busca_usuario[11], salva_usuario[20];//salva usuario logado

//FUNÇÕES PADRÕES
void cabecalho();
void flush_in();

//FUNÇÕES DAS PIZZAS
void menu_pizzas();
void inserir_Pizza();
void listar_pizzas();
void pesquisar_sabor_pizzas();
void editar_sabor();
void Localizar_cod_pizza();
void realizar_pedido();

//FUNÇÕES DE LOGIN
void menu_usuario();
void inserir_usuario();
void listar_usuario();
void comparar_usuario_senha();
void localizar_usuario_cadastrado();
void primeiro_acesso();
void alterar_acesso_adm();
void alterar_acesso_atendente();
void pesquisar_usuario();
void alt_senha_padrao();
void alterar_senha_administrador();


//MENUS
void menu_clientes();
void menu_pedidos();
void menu_sabor_nv1();
void menu_relatorios();
void menu_funcionarios();
void menu_cadastro();
void menu_bebidas_nv1();

//CLIENTE
void cadastro_cliente();
void listar_clientes();
void localizar_cliente_cadastrado();
void alterar_cad_cliente();
void pesquisar_cliente();

//FUNÇOES DE PEDIDO
void busca_cliente();
void busca_sabor();
void busca_meios_sabor();
void busca_meio_sabor_1();
void busca_pedido_cozinha();
void Localizar_numero_pedido();
void encaminhar_pedido_entrega();
void finalizar_pedido();
void busca_pedido_encaminhado();
void listar_pedidos_concluidos();
void listar_pedidos_devolvido();
void busca_bebida();
void listar_pedidos_cancelado();

//FUNÇÕES DE RELATORIOS
void relatorio_positivo_dia();
void relatorio_positivo_mes();
void total_perda();
void total_lucro();
void relatorio_negativo_dia();
void relatorio_negativo_mes();
void listar_todos_pedidos_cancelado();
void total_vendas();

//FUNÇÕES PIZZAIOLO
void menu_pizzaiolo();
void inserir_pizzaiolo();
void localizar_pizzaiolo_cadastrado();
void listar_pizzaiolo();
void verificar_tel_pizzaiolo();
void alterar_pizzaiolo_adm();
void editar_bebidas();

//FUNÇÕES BEBIDA
void menu_bebidas();
void listar_bebidas();
void inserir_bebida();
void Localizar_cod_bebida();
void pesquisar_bebida();

//FUNÇÕES DE ESTOQUE
void menu_estoque();
void inserir_estoque();
void Localizar_cod_produto();
void listar_estoque();
void pesquisar_produto();
void editar_estoque();




main(void){

    setlocale(LC_ALL, "Portuguese");

    system("title Pizzaria King's");

    arq = fopen("Login.txt","rb");
    fclose(arq);

        if(arq==NULL)
        {
           primeiro_acesso();
        }

    do{
        cabecalho();
        comparar_usuario_senha();

        if (validador_acesso ==1)
        {
            printf("Acesso permitido... Seja bem-vindo!\n\n");
        }
        else if (validador_acesso ==0)
        {
            printf("Acesso negado...\n\n");
        }

    system ("pause");

    }while (validador_acesso!=1);


    if (nivel_acesso ==2){

        do
        {

            cabecalho();

            printf("1 - Cadastros");
            printf("\n2 - Clientes");
            printf("\n3 - Pedidos");
            printf("\n4 - Funcionários");
            printf("\n5 - Relatórios");
            printf("\n6 - Alterar senha de acesso");
            printf("\n0 - Sair\n\n");

            printf("Escolha uma opção: ");
            scanf("%i", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    menu_cadastro();
                break;
                case 2:
                    menu_clientes();
                break;
                case 3:
                    menu_pedidos();
                break;
                case 4:
                    menu_funcionarios();
                break;
                case 5:
                    menu_relatorios();
                break;
                case 6:
                    alterar_senha_administrador();
                break;

                case 0:
                    printf("\n===========================================\n\n");
                    printf("Obrigado pela visita, até mais...\n\n");
                    printf("===========================================\n\n");
                    system("pause >nul");
                    exit(1);
                break;
                default:
                    printf("Opção inválida...");
                    break;
            }
            op = -1;


        }while(op!=0);
    }

    else
    {
         do
        {

        cabecalho();
        printf("1 - Pizzas");
        printf("\n2 - Bebidas");
        printf("\n3 - Clientes");
        printf("\n4 - Pedidos");
        printf("\n5 - Alterar senha de acesso");
        printf("\n0 - Sair\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        switch(op)
        {
            case 1:
                menu_sabor_nv1();
            break;
            case 2:
                menu_bebidas_nv1();
            break;
            case 3:
                menu_clientes();
            break;
            case 4:
                menu_pedidos();
            break;
            case 5:
                alterar_acesso_atendente();
            break;
            case 0:
                printf("\n===========================================\n\n");
                printf("Obrigado pela visita, até mais...\n\n");
                printf("===========================================\n\n");
                system("pause >nul");
                exit(1);
            break;
            default:
                printf("Opção inválida...");
                break;
        }
        op = true;


        }while(op!=0);
    }
}

// MENU
void menu_sabor_nv1(){
    do
    {
        cabecalho();
        printf("1 - Listar todos os sabores");
        printf("\n2 - Pesquisar sabor");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    listar_pizzas();
                break;
                case 2:
                    pesquisar_sabor_pizzas();
                break;
                default:
                    printf("Opção Inválida");
                    break;
            }
        }

    }while(op!=0);
}

void menu_bebidas_nv1(){
    do
    {
        cabecalho();
        printf("1 - Listar todos as bebidas");
        printf("\n2 - Pesquisar bebida");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    listar_bebidas();
                break;
                case 2:
                    pesquisar_bebida();
                break;

            }
        }

    }while(op!=0);
}

void menu_clientes(){
    do
    {
        cabecalho();
        printf("1 - Incluir cliente");
        printf("\n2 - Alterar cliente");
        printf("\n3 - Pesquisar cliente");
        printf("\n4 - Listar todos os clientes");
        printf("\n0 - Voltar ao menu principal\n\n");


        printf("Escolha uma opção: ");
        scanf("%i", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    cadastro_cliente();
                break;
                case 2:
                    alterar_cad_cliente();
                break;
                case 3:
                    pesquisar_cliente();
                break;
                case 4:
                    listar_clientes();
                break;
                default:
                    printf("Opção inválida...");
                    break;
            }
        }

    }while(op!=0);
}

void menu_pedidos(){
    do
    {
        cabecalho();
        printf("1 - Novo pedido");
        printf("\n2 - Listar pedidos na cozinha");
        printf("\n3 - Listar pedidos enviados para entrega");
        printf("\n4 - Listar pedidos concluídos");
        printf("\n5 - Listar pedidos devolvidos");
        printf("\n6 - Listar pedidos cancelados");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%i", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:

                    arq = fopen("Clientes.txt","rb");
                    if(arq!=NULL)
                    {
                        fclose(arq);
                        arq = fopen("SaborPizzas.txt","rb");
                        if(arq!=NULL)
                        {
                            fclose(arq);
                            arq = fopen("Bebidas.txt","rb");
                            if(arq!=NULL)
                            {
                                fclose(arq);
                                realizar_pedido();
                            }else{
                                cabecalho();
                                printf("\nNão há bebidas cadastrada na base de dados.\n\n");
                                system("pause");
                            }
                        }else{
                            cabecalho();
                            printf("\nNão há sabores cadastrado na base de dados.\n\n");
                            system("pause");

                        }
                    }else{
                        cabecalho();
                        printf("\nNão há clientes cadastrado na base de dados.\n\n");
                        system("pause");
                    }

                break;
                case 2:
                    busca_pedido_cozinha();
                break;
                case 3:
                    busca_pedido_encaminhado();
                break;
                case 4:
                    listar_pedidos_concluidos();
                break;
                case 5:
                    listar_pedidos_devolvido();
                break;
                case 6:
                    listar_pedidos_cancelado();
                break;
                default:
                    printf("Opção inválida...");
                break;
            }
        }

    }while(op!=0);
}

void menu_relatorios(){
    do
    {
        cabecalho();
        printf("1 - Relatório diário (+)");
        printf("\n2 - Relatório mensal (+)");
        printf("\n3 - Total de vendas");
        printf("\n4 - Relatório diário (-)");
        printf("\n5 - Relatório mensal (-)");
        printf("\n6 - Total de perdas");
        printf("\n7 - Cancelamentos");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    relatorio_positivo_dia();
                break;
                case 2:
                    relatorio_positivo_mes();
                break;
                case 3:
                    total_vendas();
                break;
                case 4:
                    relatorio_negativo_dia();
                break;
                case 5:
                    relatorio_negativo_mes();
                break;
                case 6:
                    total_perda();
                break;
                case 7:
                    listar_todos_pedidos_cancelado();
                break;
                default:
                    printf("Opção inválida...");
                break;
            }
        }

    }while(op!=0);
}

void menu_funcionarios(){
    do
    {
        cabecalho();
        printf("1 - Pizzaiolo");
        printf("\n2 - Atendente");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    menu_pizzaiolo();
                break;
                case 2:
                    menu_usuario();
                break;
                default:
                    printf("Opção inválida...");
                break;
            }
        }

    }while(op!=0);
}

void menu_cadastro(){
    do
    {
        cabecalho();
        printf("1 - Pizzas");
        printf("\n2 - Bebidas");
        printf("\n3 - Estoque");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    menu_pizzas();
                break;
                case 2:
                    menu_bebidas();
                break;
                case 3:
                    menu_estoque();
                break;
                default:
                    printf("Opção inválida...");
                break;
            }
        }

    }while(op!=0);
}

//CÓDIGO PARA FUNÇÕES DAS PIZZZAS (CONSULTAR, CADASTRAR E ALTERAR)
void menu_pizzas(){
    do
    {
        cabecalho();
        printf("1 - Incluir sabor");
        printf("\n2 - Alterar sabor");
        printf("\n3 - Pesquisar sabor");
        printf("\n4 - Listar todos os sabores");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    inserir_Pizza();
                break;
                case 2:
                    editar_sabor();
                break;
                case 3:
                    pesquisar_sabor_pizzas();
                break;
                case 4:
                    listar_pizzas();
                break;

            }
        }

    }while(op!=0);
    //op = true;
}

void pesquisar_sabor_pizzas(){
    int idP=0;
    int validar =0;
        do
        {
            cabecalho();
            printf("===========================================\n");
            printf("Digite o código: ");
            scanf("%i", &idP);
            printf("===========================================\n");


            arq = fopen("SaborPizzas.txt","rb"); //login


            while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1){


                if (ctt1.cod_pizza == idP)
                {

                    printf("\nSabor: %s", ctt1.sabor_pizza);
                    printf("\nDescrição: %s", ctt1.descricao_pizza);
                    printf("\nValor: R$%.2f\n", ctt1.preco_pizza);
                    printf("\n===========================================\n");
                    validar = 1;
                }
            }
            fclose(arq);

                if (validar == 0){
                    printf("\nCódigo não localizado...\n");
                    printf("\n===========================================\n");
                }
                validar = 0;



        printf("\nDeseja realizar nova consulta? [S/N]: ");
        }while(tolower(getche()) =='s');

}

void listar_pizzas(){
    cabecalho();
    arq = fopen("SaborPizzas.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {
            while(fread(&ctt1,sizeof(cadastro_sabor),1,arq)==1)
            {
                printf("===========================================\n");
                printf("|Código: %i\n", ctt1.cod_pizza);
                printf("===========================================\n");
                printf("\nSabor: %s", ctt1.sabor_pizza);
                printf("\nDescrição: %s", ctt1.descricao_pizza);
                printf("\nValor:_____________ R$%.2f\n\n", ctt1.preco_pizza);

            }
            printf("===========================================\n");


    }
    fclose(arq);
    getch();
}

void inserir_Pizza(){

        Localizar_cod_pizza();// localizar id da pizza
        cabecalho();

        ctt1.cod_pizza = achou_cod;

        printf("===========================================\n");
        printf("|ID: %i\n", ctt1.cod_pizza);
        printf("===========================================\n\n");

        printf("Digite o sabor: ");
        gets(ctt1.sabor_pizza);

        printf("Digite a descrição: ");
        gets(ctt1.descricao_pizza);

        printf("Valor (Ex 10,50): R$");
        scanf("%f", &ctt1.preco_pizza);
        flush_in();


        printf("\n===========================================\n");
        printf("\nDeseja cadastrar sabor Nº%i? [S/N]: ", ctt1.cod_pizza);
        if (tolower(getche()) =='s'){
            arq = fopen("SaborPizzas.txt","a+b");
            fwrite(&ctt1,sizeof(cadastro_sabor),1,arq);
            fclose(arq);
            printf("\n\nSabor criado com sucesso...");
        }
        printf("\n \n");
        system("pause");

}

void editar_sabor(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    char AltSabor[30];

    cabecalho();
    printf("===========================================\n");
    printf("Digite o Sabor: ");
    gets(AltSabor);
    printf("===========================================\n");

    arq = fopen("SaborPizzas.txt","r+b");

    op = -1;
    while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1 && op!=0)
    {
        if(strcmp(AltSabor,ctt1.sabor_pizza)==0)
        {
            printf("\nID: %i\n", ctt1.cod_pizza);
            printf("\n1 - Sabor: %s",ctt1.sabor_pizza);
            printf("\n2 - Descrição: %s",ctt1.descricao_pizza);
            printf("\n3 - Valor: R$%.2f", ctt1.preco_pizza);
            printf("\n0 - Voltar");
            printf("\n===========================================\n");


            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo sabor: ");
                    gets(ctt1.sabor_pizza);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o sabor? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&ctt1,sizeof(cadastro_sabor),1,arq) == sizeof(cadastro_sabor);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 2:
                    printf("\n===========================================\n");
                    printf("\nDigite a nova descrição: ");
                    gets(ctt1.descricao_pizza);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar a descrição? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&ctt1,sizeof(cadastro_sabor),1,arq) == sizeof(cadastro_sabor);
                        printf("\n\nAlteração realizada com sucesso...");
                    }
                break;

                case 3:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo valor (Ex 10,50): R$");
                    scanf("%f", &ctt1.preco_pizza);
                    flush_in();

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o valor? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&ctt1,sizeof(cadastro_sabor),1,arq) == sizeof(cadastro_sabor);
                        printf("\n\nAlteração realizada com sucesso...");
                    }
                break;

                case 0:
                    fclose(arq);
                    return menu_pizzas();
                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção inválida...\n");
                    printf("\n===========================================\n\n");
                    fclose(arq);
                    system("pause");
                    return editar_sabor();
                break;
            }

        }
        posicao = posicao + sizeof(cadastro_sabor);
        fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void Localizar_cod_pizza(){

    arq = fopen("SaborPizzas.txt","rb");

    if(arq==NULL)
    {
        achou_cod = 1;

    }else{

        while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1) {
            achou_cod = ctt1.cod_pizza;
            achou_cod++;
        }

        fclose(arq);
    }

}

//FUNÇÕES DE BEBIDAS
void menu_bebidas(){
    do
    {
        cabecalho();
        printf("1 - Incluir bebida");
        printf("\n2 - Alterar bebida");
        printf("\n3 - Pesquisar bebida");
        printf("\n4 - Listar todos as bebidas");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    inserir_bebida();
                break;
                case 2:
                    editar_bebidas();
                break;
                case 3:
                    pesquisar_bebida();
                break;
                case 4:
                    listar_bebidas();
                break;

            }
        }

    }while(op!=0);
}

void inserir_bebida(){

        Localizar_cod_bebida();// localizar id da bebida
        cabecalho();

        c_bebida.cod_bebida = achou_cod;

        printf("===========================================\n");
        printf("|ID: %i\n", c_bebida.cod_bebida);
        printf("===========================================\n\n");

        printf("Digite a descrição: ");
        gets(c_bebida.descricao);

        printf("Valor (Ex 10,50): R$");
        scanf("%f", &c_bebida.preco_bebida);
        flush_in();


        printf("\n===========================================\n");
        printf("\nDeseja cadastrar bebida Nº%i? [S/N]: ", c_bebida.cod_bebida);
        if (tolower(getche()) =='s'){
            arq = fopen("Bebidas.txt","a+b");
            fwrite(&c_bebida,sizeof(s_bebida),1,arq);
            fclose(arq);
            printf("\n\nBebida criada com sucesso...");
        }
        printf("\n \n");
        system("pause");

}

void Localizar_cod_bebida(){

    arq = fopen("Bebidas.txt","rb");

    if(arq==NULL)
    {
        achou_cod = 1;

    }else{

        while(fread(&c_bebida, sizeof(s_bebida), 1, arq)==1) {
            achou_cod = c_bebida.cod_bebida;
            achou_cod++;
        }

        fclose(arq);
    }

}

void listar_bebidas(){
    cabecalho();
    arq = fopen("Bebidas.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {
            while(fread(&c_bebida,sizeof(s_bebida),1,arq)==1)
            {
                printf("===========================================\n");
                printf("|Código: %i\n", c_bebida.cod_bebida);
                printf("===========================================\n");
                printf("\nDescrição: %s", c_bebida.descricao);
                printf("\nValor: R$%.2f\n\n", c_bebida.preco_bebida);

            }
            printf("===========================================\n");


    }
    fclose(arq);
    getch();
}

void editar_bebidas(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    int cod_produto;

    cabecalho();
    printf("===========================================\n");
    printf("Digite o código: ");
    scanf("%i", &cod_produto);
    printf("===========================================\n");

    arq = fopen("Bebidas.txt","r+b");

    op = -1;
    while(fread(&c_bebida, sizeof(s_bebida), 1, arq)==1 && op!=0)
    {
        if(c_bebida.cod_bebida == cod_produto)
        {
            printf("\n1 - Descrição: %s", c_bebida.descricao);
            printf("\n2 - Valor: R$%.2f", c_bebida.preco_bebida);
            printf("\n0 - Voltar");
            printf("\n===========================================");

            printf("\n\nEscolha uma opção: ");
            scanf("%d", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    printf("\n===========================================\n");
                    printf("\nDigite a nova descrição: ");
                    gets(c_bebida.descricao);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar a descrição? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_bebida,sizeof(s_bebida),1,arq) == sizeof(s_bebida);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 2:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo valor (Ex 10,50): R$");
                    scanf("%f", &c_bebida.preco_bebida);
                    flush_in();

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o valor? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_bebida,sizeof(s_bebida),1,arq) == sizeof(s_bebida);
                        printf("\n\nAlteração realizada com sucesso...");
                    }
                break;

                case 0:
                    fclose(arq);
                    return menu_bebidas();
                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(s_bebida);
        fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void pesquisar_bebida(){
    int idP=0;
    int validar =0;
        do
        {
            cabecalho();

            printf("===========================================\n");
            printf("Digite o código: ");
            scanf("%i", &idP);
            printf("===========================================\n");


            arq = fopen("Bebidas.txt","rb");


            while(fread(&c_bebida, sizeof(s_bebida), 1, arq)==1){


                if (c_bebida.cod_bebida == idP)
                {

                    printf("\nDescrição: %s", c_bebida.descricao);
                    printf("\nValor: R$%.2f\n\n", c_bebida.preco_bebida);
                    printf("===========================================\n");
                    validar = 1;
                }
            }
            fclose(arq);

                if (validar == 0){
                    printf("\nCódigo não localizado...\n");
                    printf("\n===========================================\n");
                }
                validar = 0;



        printf("\nDeseja realizar nova consulta? [S/N]: ");
        }while(tolower(getche()) =='s');

}

//ESTOQUE
void menu_estoque(){
    do
    {
        cabecalho();
        printf("1 - Incluir produto");
        printf("\n2 - Alterar produto");
        printf("\n3 - Pesquisar produto");
        printf("\n4 - Listar todos os produtos");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    inserir_estoque();
                break;
                case 2:
                    editar_estoque();
                break;
                case 3:
                    pesquisar_produto();
                break;
                case 4:
                    listar_estoque();
                break;

            }
        }

    }while(op!=0);
    //op = true;
}

void inserir_estoque(){

        Localizar_cod_produto();
        cabecalho();

        c_estoque.cod_prod = achou_cod;

        printf("===========================================\n");
        printf("|ID: %i\n", c_estoque.cod_prod);
        printf("===========================================\n\n");

        printf("Digite o nome: ");
        gets(c_estoque.nome_produto);

        printf("\nValor pago(Ex 10,50): R$");
        scanf("%f", &c_estoque.preco_bcusto);
        flush_in();

        printf("\nDigite a quantidade (UND): ");
        scanf("%i", &c_estoque.unidade);
        flush_in();



        printf("\n===========================================\n");
        printf("\nDeseja cadastrar o produto Nº%i? [S/N]: ", c_estoque.cod_prod);
        if (tolower(getche()) =='s'){
            arq = fopen("Estoque.txt","a+b");
            fwrite(&c_estoque,sizeof(s_estoque),1,arq);
            fclose(arq);
            printf("\n\nProduto cadastrado com sucesso...");
        }
        printf("\n \n");
        system("pause");

}

void Localizar_cod_produto(){

    arq = fopen("Estoque.txt","rb");

    if(arq==NULL)
    {
        achou_cod = 1;

    }else{

        while(fread(&c_estoque, sizeof(s_estoque), 1, arq)==1) {
            achou_cod = c_estoque.cod_prod;
            achou_cod++;
        }

        fclose(arq);
    }

}

void listar_estoque(){
    cabecalho();
    arq = fopen("Estoque.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {
            while(fread(&c_estoque,sizeof(s_estoque),1,arq)==1)
            {
                printf("===========================================\n");
                printf("|Código do produto: %i\n", c_estoque.cod_prod);
                printf("===========================================\n");
                printf("\nDescrição: %s", c_estoque.nome_produto);
                printf("\nValor pago: R$%.2f\n", c_estoque.preco_bcusto);
                printf("\nQuantidade: %i (UND)\n\n", c_estoque.unidade);

            }
            printf("===========================================\n");


    }
    fclose(arq);
    getch();
}

void pesquisar_produto(){

    char nome[50];
    int validar =0;
        do
        {
            cabecalho();

            printf("===========================================\n");
            printf("Digite o nome: ");
            gets(nome);
            printf("===========================================\n");


            arq = fopen("Estoque.txt","rb");


            while(fread(&c_estoque,sizeof(s_estoque),1,arq)==1){

                if (strcmp(nome,c_estoque.nome_produto)==0)
                {
                    printf("\nCódigo do produto: %i\n", c_estoque.cod_prod);
                    printf("\nNome: %s", c_estoque.nome_produto);
                    printf("\nValor pago: R$%.2f\n", c_estoque.preco_bcusto);
                    printf("\nQuantidade: %i (UND)\n\n", c_estoque.unidade);
                    printf("===========================================\n");
                    validar = 1;
                }
            }
            fclose(arq);

            if (validar == 0){
                printf("\nProduto não cadastrado...\n");
                printf("\n===========================================\n");
            }
            validar = 0;


        printf("\nDeseja realizar nova consulta? [S/N]: ");
        }while(tolower(getche()) =='s');


}

void editar_estoque(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    int cod;

    cabecalho();

    printf("===========================================\n");
    printf("Digite o código: ");
    scanf("%i", &cod);
    printf("===========================================\n");

    arq = fopen("Estoque.txt","r+b");

    op = -1;
    while(fread(&c_estoque, sizeof(s_estoque), 1, arq)==1 && op!=0)
    {
        if(cod == c_estoque.cod_prod)
        {
            printf("\nID: %i\n", c_estoque.cod_prod);
            printf("\n1 - Nome: %s",c_estoque.nome_produto);
            printf("\n2 - Valor pago: R$%.2f", c_estoque.preco_bcusto);
            printf("\n3 - Quantidade: %i (UND)", c_estoque.unidade);
            printf("\n0 - Voltar");
            printf("\n===========================================\n");


            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo nome: ");
                    gets(c_estoque.nome_produto);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o nome? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_estoque,sizeof(s_estoque),1,arq) == sizeof(s_estoque);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 2:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo valor pago (Ex 10,50): R$");
                    scanf("%f", &c_estoque.preco_bcusto);
                    flush_in();

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o valor? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_estoque,sizeof(s_estoque),1,arq) == sizeof(s_estoque);
                        printf("\n\nAlteração realizada com sucesso...");
                    }
                break;

                case 3:
                    printf("\n===========================================\n");
                    printf("\nDigite a nova quantidade (UND): ");
                    scanf("%i", &c_estoque.unidade);
                    flush_in();

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar a quantidade? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_estoque,sizeof(s_estoque),1,arq) == sizeof(s_estoque);
                        printf("\n\nAlteração realizada com sucesso...");
                    }
                break;

                case 0:
                    fclose(arq);
                    return menu_estoque();
                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção inválida...\n");
                    printf("\n===========================================\n\n");
                    fclose(arq);
                    system("pause");
                    return editar_estoque();
                break;
            }

        }
        posicao = posicao + sizeof(s_estoque);
        fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

//CÓDIGO DE FUNÇÕES PARA LOGIN
void menu_usuario(){
    do
    {
        cabecalho();
        printf("1 - Incluir usuário");
        printf("\n2 - Alterar usuário");
        printf("\n3 - Pesquisar usuário");
        printf("\n4 - Listar todos os usuários");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                   inserir_usuario();
                break;
                case 2:
                    alterar_acesso_adm();
                break;
                case 3:
                    pesquisar_usuario();
                break;
                case 4:
                    listar_usuario();
                break;
            }
        }

    }while(op!=0);

}

void primeiro_acesso(){

    cabecalho();
    int i = 0, valida_Numero =0;
    char cpf [11];

    char c;
    char senha[50]= "";
    int a=0;

    printf("*Primeiro acesso será concedido nível administrativo...\n\n");

    do{

        printf("Digite o seu CPF: ");
        gets(ctt.usuario);

        i = strlen(ctt.usuario);
            if (i > 11){
                printf("\nCPF inválido...\n\n");
                system("pause");
                return primeiro_acesso();
            }
        i=0;

       while(i < 11){

            ctt.usuario[i];
                if (isdigit(ctt.usuario[i])==true){
                    valida_Numero = 1;
                }else if (isdigit(ctt.usuario[i])==false){
                     printf("\nCPF inválido...\n\n");
                     system("pause");
                     return primeiro_acesso();
                    valida_Numero = 0;
                    break;
                }
                i++;
        }
    }while (valida_Numero != 1);

    printf("\nDigite a senha: ");

    do{
        c=getch();
        if(isprint(c)){
            senha[a]=c;
            a++;
            printf("*");
            strcpy(ctt.senha,senha);
        }
        else if(c==8&&a){
            senha[a]='\0';
            a--;
            printf("\b \b");
            strcpy(ctt.senha,senha);
        }

    }while(c!=13);

    ctt.nivel = 2;
    ctt.status = 1;


    printf("\n===========================================\n");
    printf("\nDeseja finalizar cadastro? [S/N]: ");

        if (tolower(getche()) =='s'){
            arq = fopen("Login.txt","a+b");
            fwrite(&ctt,sizeof(acesso_login),1,arq);
            fclose(arq);
            printf("\n\nLogin criado com sucesso...");

        }

        printf("\n \n");
        system("pause");

}

void localizar_usuario_cadastrado(){

    valida_cad_usuario = 0;    int i = 0, valida_Numero =0;

    do{
        printf("Digite o CPF: ");
        gets(busca_usuario);

        i = strlen(busca_usuario);
        if (i > 11){
            printf("\n===========================================\n");
            printf("\nCPF inválido...\n");
            printf("\n===========================================\n\n");
            return localizar_usuario_cadastrado();
        }
        i=0;

        while(i < 11){

            busca_usuario[i];
                if (isdigit(busca_usuario[i])==true){
                    valida_Numero = 1;
                }else if (isdigit(busca_usuario[i])==false){
                    printf("\n===========================================\n");
                     printf("\nCPF inválido...\n");
                     printf("\n===========================================\n\n");
                     return localizar_usuario_cadastrado();
                }
                i++;
        }

    }while (valida_Numero != 1);

        arq = fopen("Login.txt","rb");

            while(fread(&ctt, sizeof(acesso_login), 1, arq)==1){

                if (strcmp(busca_usuario,ctt.usuario)==0)
                {
                    valida_cad_usuario = 1;
                }
            }
            fclose(arq);


}

void comparar_usuario_senha(){

    char Busca_Senha[50];
    char c;
    char senha[50]= "";
    int a=0;

    cabecalho();

    validador_acesso = 0;

    printf("Digite o CPF: ");
    gets(salva_usuario);
    printf("Digite a senha: ");

    do{
        c=getch();
        if(isprint(c)){
            senha[a]=c;
            a++;
            printf("*");
            strcpy(Busca_Senha,senha);
        }
        else if(c==8&&a){
            senha[a]='\0';
            a--;
            printf("\b \b");
            strcpy(Busca_Senha,senha);
        }

    }while(c!=13);


    if (strcmp(salva_usuario, "kingadmin")==0 && strcmp(Busca_Senha,"1234")==0){
        cabecalho();
        validador_acesso =1;
        nivel_acesso =2;
        strcpy(salva_usuario, "adm");
    }else{

        cabecalho();

        arq = fopen("Login.txt","rb");

        while(fread(&ctt, sizeof(acesso_login), 1, arq)==1){

            if (strcmp(salva_usuario,ctt.usuario)==0 && strcmp(Busca_Senha,ctt.senha)==0 && ctt.status == 1)
            {
                if (strcmp(ctt.senha, "123456")==0){
                    fclose(arq);
                    alt_senha_padrao();
                    break;

                }else{
                    validador_acesso = 1;
                    nivel_acesso = ctt.nivel;
                }
            }

        }
        fclose(arq);
    }
}

void listar_usuario(){
    arq = fopen("Login.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {
        cabecalho();

        while(fread(&ctt,sizeof(acesso_login),1,arq)==1)
            {
                printf("Status: ");
                if(ctt.status == 1)
                {
                    printf("Ativo");
                }
                else if(ctt.status == 0)
                {
                    printf("Inativo");
                }
                printf("\n\nUsuário: %s", ctt.usuario);
                printf("\nNível de acesso: ");
                if(ctt.nivel == 1)
                {
                    printf("Atendente");
                }
                else if(ctt.nivel == 2)
                {
                    printf("Administrador");
                }
                printf("\n===========================================\n\n");
            }
    }
    fclose(arq);
    getch();
}

void inserir_usuario(){

    do{
    cabecalho();
    localizar_usuario_cadastrado();

    if (valida_cad_usuario ==1){

        printf("\n===========================================\n");
        printf("\nCPF já cadastrado...\n");
        printf("\n===========================================\n\n");
        system("pause");
    }

    }while (valida_cad_usuario!=0);

    ctt.status =1;
    strcpy(ctt.usuario, busca_usuario);
    strcpy(ctt.senha, "123456");

    do{

        printf("\n===========================================\n");
        printf("\nNível de acesso:");
        printf("\n1 - Atendente");
        printf("\n2 - Administrador");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &ctt.nivel);

        if (ctt.nivel != 1 && ctt.nivel !=2){

            printf("\n\n===========================================\n");
            printf("\nOpção selecionada inválida...\n");
        }

    }while(ctt.nivel != 1 && ctt.nivel != 2);

    printf("\n===========================================\n");
    printf("\nDeseja finalizar cadastro? [S/N]: ");

    if (tolower(getche()) =='s'){
        arq = fopen("Login.txt","a+b");
        fwrite(&ctt,sizeof(acesso_login),1,arq);
        fclose(arq);
        printf("\n\nLogin criado com sucesso...");
    }

    printf("\n \n");
    system("pause");
}

void alterar_acesso_adm(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    char alt_usuario[11];

    cabecalho();
    printf("===========================================\n");
    printf("Digite o CPF: ");
    gets(alt_usuario);
    printf("===========================================\n");

    arq = fopen("Login.txt","r+b");

    op = -1;
    while(fread(&ctt, sizeof(acesso_login), 1, arq)==1 && op!=0)
    {
        if(strcmp(alt_usuario,ctt.usuario)==0)
        {
            printf("\n1 - Status: ");
                if(ctt.status == 1)
                {
                    printf("Ativo");
                }
                else if(ctt.status == 0)
                {
                    printf("Inativo");
                }
            printf("\n\n2 - Nível: ");
                if(ctt.nivel == 1)
                {
                    printf("Atendente");
                }
                else if(ctt.nivel == 2)
                {
                    printf("Administrador");
                }
            printf("\n3 - Usuário: %s", ctt.usuario);
            printf("\n4 - Resetar senha");
            printf("\n0 - Voltar");
            printf("\n===========================================");

            printf("\n\nEscolha uma opção: ");
            scanf("%d", &op);
            flush_in();

            switch(op)
            {
                case 1:
                printf("\n===========================================\n");
                printf("\nDeseja alterar o status? [S/N]: ");
                if (tolower(getche()) =='s'){
                    if (ctt.status==1){
                        ctt.status =0;
                        printf("\n\nUsuário desativado...");
                    }else{
                        ctt.status = 1;
                        printf("\n\nUsuário ativado...");

                    }
                    fseek(arq, posicao, SEEK_SET);
                    achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                }

                break;

                case 2:
                        do{
                            printf("\n===========================================\n");
                            printf("\nNível de acesso:");
                            printf("\n1 - Atendente");
                            printf("\n2 - Administrador");
                            printf("\n\nEscolha uma opção: ");
                            scanf("%d", &ctt.nivel);
                            flush_in();

                            if (ctt.nivel != 1 && ctt.nivel !=2){

                                printf("\n\n===========================================\n");
                                printf("\nOpção selecionada inválida...\n");
                            }

                        }while(ctt.nivel != 1 && ctt.nivel != 2);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o nível do usuário? [S/N]: ");
                    if (tolower(getche()) =='s'){
                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                            printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 3:
                    do{
                    fclose(arq);
                    printf("\n===========================================\n\n");
                    localizar_usuario_cadastrado();
                    printf("\n===========================================\n");
                        if (valida_cad_usuario ==1)
                        {
                            printf("\nCPF já cadastrado...\n");
                        }

                    }while (valida_cad_usuario!=0);

                    strcpy(ctt.usuario, busca_usuario);

                    printf("\nDeseja alterar o CPF do usuário? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        arq = fopen("Login.txt","r+b");
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 4:

                    printf("\n===========================================\n");
                    printf("\nDeseja resetar a senha de acesso? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        strcpy(ctt.senha, "123456");

                        printf("\n\nSenha redefinida para o padrão...");

                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                    }
                break;
                case 0:
                    fclose(arq);
                    return menu_usuario();
                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(acesso_login);
        fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void alterar_acesso_atendente(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    char comparar_senha[20];
    char c;
    char senha[50]= "";
    int a=0;

    cabecalho();

    arq = fopen("Login.txt","r+b");

    op = -1;
    while(fread(&ctt, sizeof(acesso_login), 1, arq)==1 && op!=0)
    {
        if(strcmp(salva_usuario,ctt.usuario)==0)
        {
            printf("(*) Alteração permitida somente pelo seu gestor\n");
            printf("\n*Nível: ");
            if(ctt.nivel == 1){
                    printf("Atendente");
            }else{
                    printf("Administrador");
            }
            printf("\n*Usuário: %s\n", ctt.usuario);
            printf("\n1 - Alterar senha");

            printf("\n0 - Voltar");
             printf("\n===========================================\n");

            printf("\nEscolha uma opção: ");
            scanf("%d", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    printf("\n===========================================\n");
                    printf("\nDigite a senha atual: ");
                    do{
                        c=getch();
                        if(isprint(c)){
                            senha[a]=c;
                            a++;
                            printf("*");
                            strcpy(comparar_senha,senha);
                        }
                        else if(c==8&&a){
                            senha[a]='\0';
                            a--;
                            printf("\b \b");
                            strcpy(comparar_senha,senha);
                        }

                    }while(c!=13);

                    if (strcmp(comparar_senha, ctt.senha)==0){
                        printf("\n===========================================\n");
                        printf("\nDigite a nova senha: ");
                        a=0;
                        do{
                            c=getch();
                            if(isprint(c)){
                                senha[a]=c;
                                a++;
                                printf("*");
                                strcpy(ctt.senha,senha);
                            }
                            else if(c==8&&a){
                                senha[a]='\0';
                                a--;
                                printf("\b \b");
                                strcpy(ctt.senha,senha);
                            }

                        }while(c!=13);

                        printf("\n===========================================\n");
                        printf("\nDeseja alterar a senha? [S/N]: ");
                        if (tolower(getche()) =='s'){

                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                            printf("\n\nAlteração realizada com sucesso...");
                            break;
                        }

                    }else{
                        printf("\n===========================================\n");
                        printf("\n\nSenha digitada inválida...");
                    }

                break;
                case 0:

                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(acesso_login);
        fseek(arq, posicao, SEEK_SET);

    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void alterar_senha_administrador(){

    int posicao = 0;
    int achou = 0;
    char comparar_senha[20];
    char c;
    char senha[50]= "";
    int a=0;


    cabecalho();

    arq = fopen("Login.txt","r+b");

    op = -1;
    while(fread(&ctt, sizeof(acesso_login), 1, arq)==1 && op!=0)
    {
        if(strcmp(salva_usuario,ctt.usuario)==0)
        {
            printf("Usuário: %s\n", ctt.usuario);
            printf("\n1 - Alterar senha");

            printf("\n0 - Voltar");
            printf("\n===========================================\n");

            printf("\nEscolha uma opção: ");
            scanf("%i", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    printf("\n===========================================\n");
                    printf("\nDigite a senha atual: ");
                     do{
                        c=getch();
                        if(isprint(c)){
                            senha[a]=c;
                            a++;
                            printf("*");
                            strcpy(comparar_senha,senha);
                        }
                        else if(c==8&&a){
                            senha[a]='\0';
                            a--;
                            printf("\b \b");
                            strcpy(comparar_senha,senha);
                        }

                    }while(c!=13);

                    if (strcmp(comparar_senha, ctt.senha)==0){
                        printf("\n===========================================\n");
                        printf("\nDigite a nova senha: ");
                        a=0;
                        do{
                            c=getch();
                            if(isprint(c)){
                                senha[a]=c;
                                a++;
                                printf("*");
                                strcpy(ctt.senha,senha);
                            }
                            else if(c==8&&a){
                                senha[a]='\0';
                                a--;
                                printf("\b \b");
                                strcpy(ctt.senha,senha);
                            }

                        }while(c!=13);

                        printf("\n===========================================\n");
                        printf("\nDeseja alterar a senha? [S/N]: ");
                        if (tolower(getche()) =='s'){

                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                            printf("\n\nAlteração realizada com sucesso...");
                            break;
                        }

                    }else{
                        printf("\n===========================================\n");
                        printf("\n\nSenha digitada inválida...");
                    }

                break;
                case 0:

                break;
                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(acesso_login);
        fseek(arq, posicao, SEEK_SET);

    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void pesquisar_usuario(){

    do
    {
    char usuario[11];
    int validar =0;

    cabecalho();
    printf("===========================================\n");
    printf("Digite o CPF: ");
    gets(usuario);
    printf("===========================================\n");

    arq = fopen("Login.txt","rb");

    while(fread(&ctt, sizeof(acesso_login), 1, arq)==1)
    {
        if(strcmp(usuario,ctt.usuario)==0)
        {
            validar = 1;
            printf("\nStatus: ");
                if(ctt.status == 1)
                {
                    printf("Ativo");
                }
                else if(ctt.status == 0)
                {
                    printf("Inativo");
                }
            printf("\n\nUsuário: %s", ctt.usuario);
            printf("\n\nNível: ");
                if(ctt.nivel == 1)
                {
                    printf("Atendente");
                }
                else if(ctt.nivel == 2)
                {
                    printf("Administrador");
                }
                printf("\n\n===========================================\n");
        }

    }
    fclose(arq);

    if (validar == 0){
        printf("\nUsuário não localizado...\n");
        printf("\n===========================================\n");
    }
    validar = 0;

    printf("\nDeseja realizar nova consulta? [S/N]: ");
        }while(tolower(getche()) =='s');

}

void alt_senha_padrao(){
    int posicao = 0;
    int achou = 0;
    char comparar_senha[20];
    char c;
    char senha[50]= "";
    int a=0;

    cabecalho();

    printf("*Senha padrão, por gentileza realizar a troca.\n\n");

    arq = fopen("Login.txt","r+b");

    op = -1;
    while(fread(&ctt, sizeof(acesso_login), 1, arq)==1 && op!=0)
    {
        if(strcmp(salva_usuario,ctt.usuario)==0)
            {
                printf("Digite a nova senha: ");
                do{
                    c=getch();
                    if(isprint(c)){
                        senha[a]=c;
                        a++;
                        printf("*");
                        strcpy(ctt.senha,senha);
                    }
                    else if(c==8&&a){
                        senha[a]='\0';
                        a--;
                        printf("\b \b");
                        strcpy(ctt.senha,senha);
                    }

                }while(c!=13);
                fseek(arq, posicao, SEEK_SET);
                achou= fwrite(&ctt,sizeof(acesso_login),1,arq) == sizeof(acesso_login);
                printf("\n===========================================\n");
                printf("\nAlteração realizada com sucesso...\n\n");
            }

    posicao = posicao + sizeof(acesso_login);
    fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    system("pause");
    return comparar_usuario_senha();

}

void cabecalho(){
    system("cls");
    printf("==============================================================================\n");
    printf("| King Consulting Corporation (c). Todos os direitos reservados [Versão 1.0] |\n");
    printf("==============================================================================\n\n\n");



}

void flush_in(){
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != '\n' && ch != EOF) {}
}


//VARIAVEIS PARA LOCALIZAR CLIENTE
char busca_telefone[11], valida_clientes = 0;// utilizada para confirmar cliente

//CADASTRO DE CLIENTE
void cadastro_cliente(){

        do{
            cabecalho();
            localizar_cliente_cadastrado();

            if (valida_clientes ==1)
            {
                printf("\n===========================================\n");
                printf("\nNúmero já cadastrado...\n");
                printf("\n===========================================\n\n");
                system("pause");
            }

        }while (valida_clientes!=0);


        printf("\nDigite o endereço de entrega: ");
        gets(c_cliente.logradouro);

        printf("\nNome: ");
        gets(c_cliente.nome);


        printf("\n===========================================\n");
        printf("\nDeseja finalizar cadastro? [S/N]: ");

        if (tolower(getche()) =='s'){
                strcpy(c_cliente.telefone, busca_telefone);

                arq = fopen("Clientes.txt","a+b");
                fwrite(&c_cliente,sizeof(cad_cliente),1,arq);
                fclose(arq);
                printf("\n\nCliente cadastrado com sucesso...");
        }

        printf("\n \n");
        system("pause");
}

void localizar_cliente_cadastrado(){

    int i = 0, valida_Numero =0;
    valida_clientes = 0;

    do{
        printf("Digite o telefone do Cliente: ");
        gets(busca_telefone);

        i = strlen(busca_telefone);
        if (i > 11 || i < 8){
            printf("\n===========================================\n");
            printf("\nNúmero de telefone inválido...\n");
            printf("\n===========================================\n\n");
            return localizar_cliente_cadastrado();
        }
        i--;

        while(i>0){

            busca_telefone[i];
                if (isdigit(busca_telefone[i])==true){
                    valida_Numero = 1;
                }else if (isdigit(busca_telefone[i])==false){
                    printf("\n===========================================\n");
                     printf("\nNúmero de telefone inválido...\n");
                     printf("\n===========================================\n\n");
                     return localizar_cliente_cadastrado();
                }
                i--;
        }

    }while (valida_Numero != 1);


    arq = fopen("Clientes.txt","rb");

    while(fread(&c_cliente,sizeof(cad_cliente),1,arq)==1){

        if (strcmp(busca_telefone,c_cliente.telefone)==0)
        {
            valida_clientes = 1;
        }
    }

    fclose(arq);
}

void listar_clientes(){

    cabecalho();

    arq = fopen("Clientes.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {

        while(fread(&c_cliente,sizeof(cad_cliente),1,arq)==1)
            {
                printf("Telefone: %s\n", c_cliente.telefone);
                printf("\nNome: %s", c_cliente.nome);
                printf("\nEndereço de entrega: %s", c_cliente.logradouro);
                printf("\n===========================================\n\n");
            }
    }
    fclose(arq);
    getch();
}

void alterar_cad_cliente(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    char alt_telefone[11];

    cabecalho();
    printf("===========================================\n");
    printf("Digite o telefone: ");
    gets(alt_telefone);
    printf("===========================================\n");

    arq = fopen("Clientes.txt","r+b");

    op = -1;
    while(fread(&c_cliente,sizeof(cad_cliente),1,arq)==1 && op!=0)
    {
        if(strcmp(alt_telefone,c_cliente.telefone)==0)
        {
            printf("\n1 - Telefone: %s", c_cliente.telefone);
            printf("\n2 - Nome: %s", c_cliente.nome);
            printf("\n3 - Endereço: %s", c_cliente.logradouro);
            printf("\n0 - Voltar");
            printf("\n===========================================");

            printf("\n\nEscolha uma opção: ");
            scanf("%i", &op);
            flush_in();

            switch(op)
            {
                case 1:
                    do{
                        fclose(arq);
                        printf("\n===========================================\n\n");
                        localizar_cliente_cadastrado();
                        printf("\n===========================================\n");
                            if (valida_clientes ==1)
                            {
                                printf("\nNúmero já cadastrado...\n");
                            }

                        }while (valida_clientes!=0);

                        printf("\nDeseja alterar o telefone do Cliente? [S/N]: ");
                        if (tolower(getche()) =='s'){
                            strcpy(c_cliente.telefone, busca_telefone);

                            arq = fopen("Clientes.txt","r+b");
                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&c_cliente,sizeof(cad_cliente),1,arq) == sizeof(cad_cliente);

                            printf("\n\nAlteração realizada com sucesso...");
                        }

                break;

                case 2:
                    printf("\n===========================================\n");
                    printf("\nDigite o novo nome: ");
                    gets(c_cliente.nome);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o nome do Cliente? [S/N]: ");
                        if (tolower(getche()) =='s'){
                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&c_cliente,sizeof(cad_cliente),1,arq) == sizeof(cad_cliente);
                            printf("\n\nAlteração realizada com sucesso...");
                        }
                break;

                case 3:

                    printf("\n===========================================\n");
                    printf("\nDigite o novo endereço: ");
                    gets(c_cliente.logradouro);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o endereço do Cliente? [S/N]: ");
                        if (tolower(getche()) =='s'){
                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&c_cliente,sizeof(cad_cliente),1,arq) == sizeof(cad_cliente);
                            printf("\n\nAlteração realizada com sucesso...");
                        }


                break;
                case 0:
                    fclose(arq);
                    return menu_clientes();
                break;


                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(cad_cliente);
        fseek(arq, posicao, SEEK_SET);
    }
    op=-1;
    fclose(arq);

    printf("\n \n");
    system("pause");
}

void pesquisar_cliente(){

    char telefone[11];
    int validar =0;
        do
        {
            cabecalho();

            printf("===========================================\n");
            printf("Digite o telefone: ");
            gets(telefone);
            printf("===========================================\n");


            arq = fopen("Clientes.txt","rb");


            while(fread(&c_cliente,sizeof(cad_cliente),1,arq)==1){

                if (strcmp(telefone,c_cliente.telefone)==0)
                {

                    printf("\nNome: %s", c_cliente.nome);
                    printf("\nEndereço: %s", c_cliente.logradouro);
                    printf("\n===========================================\n");
                    validar = 1;
                }
            }
            fclose(arq);

            if (validar == 0){
                printf("\nTelefone não cadastrado...\n");
                printf("\n===========================================\n");
            }
            validar = 0;



        printf("\nDeseja realizar nova consulta? [S/N]: ");
        }while(tolower(getche()) =='s');


}


//PIZZAIOLO
void menu_pizzaiolo(){
    do
    {
        cabecalho();
        printf("1 - Incluir pizzaiolo");
        printf("\n2 - Alterar pizzaiolo");
        printf("\n4 - Listar todos os pizzaiolo");
        printf("\n0 - Voltar ao menu principal\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &op);
        flush_in();

        if (op != 0){

            switch(op)
            {
                case 1:
                    inserir_pizzaiolo();
                break;
                case 2:
                    alterar_pizzaiolo_adm();
                break;
                case 3:
                    pesquisar_usuario();
                break;
                case 4:
                    listar_pizzaiolo();
                break;
            }
        }

    }while(op!=0);

}

void inserir_pizzaiolo(){

    do{
    cabecalho();
    localizar_pizzaiolo_cadastrado();

        if (valida_cad_usuario ==1){

            printf("\n===========================================\n");
            printf("\nCPF já cadastrado...\n");
            printf("\n===========================================\n\n");
            system("pause");
        }

    }while (valida_cad_usuario!=0);

    c_pizzaiolo.status =1;
    strcpy(c_pizzaiolo.usuario, busca_usuario);

    verificar_tel_pizzaiolo();
    strcpy(c_pizzaiolo.telefone, busca_telefone);

    printf("\nDigite o nome completo: ");
    gets(c_pizzaiolo.nome);



    printf("\n===========================================\n");
    printf("\nDeseja finalizar cadastro? [S/N]: ");

    if (tolower(getche()) =='s'){
        arq = fopen("Pizzaiolo.txt","a+b");
        fwrite(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq);
        fclose(arq);
        printf("\n\nPizzaiolo criado com sucesso...");
    }

    printf("\n \n");
    system("pause");
}

void localizar_pizzaiolo_cadastrado(){

    valida_cad_usuario = 0;
    int i = 0, valida_Numero =0;

    do{
        printf("Digite o CPF: ");
        gets(busca_usuario);

        i = strlen(busca_usuario);
        if (i > 11){
            printf("\n===========================================\n");
            printf("\nCPF inválido...\n");
            printf("\n===========================================\n\n");
            return localizar_pizzaiolo_cadastrado();
        }
        i=0;

        while(i < 11){

            busca_usuario[i];
                if (isdigit(busca_usuario[i])==true){
                    valida_Numero = 1;
                }else if (isdigit(busca_usuario[i])==false){
                    printf("\n===========================================\n");
                     printf("\nCPF inválido...\n");
                     printf("\n===========================================\n\n");
                     return localizar_pizzaiolo_cadastrado();
                }
                i++;
        }

    }while (valida_Numero != 1);

        arq = fopen("Pizzaiolo.txt","rb");

            while(fread(&c_pizzaiolo, sizeof(s_pizzaiolo), 1, arq)==1){

                if (strcmp(busca_usuario,c_pizzaiolo.usuario)==0)
                {
                    valida_cad_usuario = 1;
                }
            }
            fclose(arq);
}

void verificar_tel_pizzaiolo(){

    int i = 0, valida_Numero =0;


    do{
        printf("\nDigite o número de telefone: ");
        gets(busca_telefone);

        i = strlen(busca_telefone);
        if (i > 11 || i < 8){
            printf("\n===========================================\n");
            printf("\nNúmero de telefone inválido...\n");
            printf("\n===========================================\n\n");
            return verificar_tel_pizzaiolo();
        }
        i--;

        while(i>0){

            busca_telefone[i];
                if (isdigit(busca_telefone[i])==true){
                    valida_Numero = 1;
                }else if (isdigit(busca_telefone[i])==false){
                    printf("\n===========================================\n");
                     printf("\nNúmero de telefone inválido...\n");
                     printf("\n===========================================\n\n");
                     return verificar_tel_pizzaiolo();
                }
                i--;
        }

    }while (valida_Numero != 1);
}

void listar_pizzaiolo(){

     cabecalho();

    arq = fopen("Pizzaiolo.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.");
    }
    else
    {

        while(fread(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq)==1)
            {
                printf("Status: ");
                if(c_pizzaiolo.status == 1)
                {
                    printf("Ativo");
                }
                else if(c_pizzaiolo.status == 0)
                {
                    printf("Inativo");
                }
                printf("\n\nCPF: %s", c_pizzaiolo.usuario);
                printf("\nNome: %s", c_pizzaiolo.nome);
                printf("\nTelefone: %s", c_pizzaiolo.telefone);
                printf("\n===========================================\n\n");
            }
    }
    fclose(arq);
    getch();
}

void alterar_pizzaiolo_adm(){
    int posicao = 0; // Inicio do Arquivo;
    int achou = 0;
    char alt_usuario[11];

    cabecalho();

    printf("Digite o CPF: ");
    gets(alt_usuario);
    printf("===========================================\n");

    arq = fopen("Pizzaiolo.txt","r+b");

    op = -1;
    while(fread(&c_pizzaiolo, sizeof(s_pizzaiolo), 1, arq)==1 && op!=0)
    {
        if(strcmp(alt_usuario,c_pizzaiolo.usuario)==0)
        {
            printf("\n\n1 - Status: ");
                if(c_pizzaiolo.status == 1)
                {
                    printf("Ativo");
                }
                else if(c_pizzaiolo.status == 0)
                {
                    printf("Inativo");
                }

            printf("\n2 - CPF: %s", c_pizzaiolo.usuario);
            printf("\n3 - Nome: %s", c_pizzaiolo.nome);
            printf("\n4 - Telefone: %s", c_pizzaiolo.telefone);
            printf("\n0 - Voltar");
            printf("\n===========================================");

            printf("\n\nEscolha uma opção: ");
            scanf("%d", &op);
            flush_in();

            switch(op)
            {
                case 1:
                printf("\n===========================================\n");
                printf("\nDeseja alterar o status? [S/N]: ");
                if (tolower(getche()) =='s'){



                    if (c_pizzaiolo.status == 1){
                        c_pizzaiolo.status =0;
                        printf("\n\nPizzaiolo desativado...");
                    }else{
                        c_pizzaiolo.status = 1;
                        printf("\n\nPizzaiolo ativado...");

                    }
                    fseek(arq, posicao, SEEK_SET);
                    achou= fwrite(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq) == sizeof(s_pizzaiolo);

                }

                break;

                case 2:

                    do{
                        fclose(arq);
                        printf("\n===========================================\n\n");
                        localizar_pizzaiolo_cadastrado();
                        printf("\n===========================================\n");
                        if (valida_cad_usuario ==1)
                        {
                            printf("\nCPF já cadastrado...\n");
                        }

                    }while (valida_cad_usuario!=0);

                    strcpy(c_pizzaiolo.usuario, busca_usuario);

                    printf("\nDeseja alterar o CPF do pizzaiolo? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        arq = fopen("Pizzaiolo.txt","r+b");
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq) == sizeof(s_pizzaiolo);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 3:

                    printf("\n===========================================\n");
                    printf("\nDigite o novo nome: ");
                    gets(c_pizzaiolo.nome);

                    printf("\n===========================================\n");
                    printf("\nDeseja alterar o nome do pizzaiolo? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq) == sizeof(s_pizzaiolo);
                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 4:
                    fclose(arq);
                    printf("\n===========================================\n");
                    verificar_tel_pizzaiolo();
                    printf("\n===========================================\n");

                    printf("\nDeseja alterar o telefone do pizzaiolo? [S/N]: ");
                    if (tolower(getche()) =='s'){
                        strcpy(c_pizzaiolo.telefone, busca_telefone);

                        arq = fopen("Pizzaiolo.txt","r+b");
                        fseek(arq, posicao, SEEK_SET);
                        achou= fwrite(&c_pizzaiolo,sizeof(s_pizzaiolo),1,arq) == sizeof(s_pizzaiolo);

                        printf("\n\nAlteração realizada com sucesso...");
                    }

                break;

                case 0:
                    fclose(arq);
                    return menu_pizzaiolo();
                break;

                default:
                    printf("\n===========================================\n");
                    printf("\nOpção selecionada inválida...");
                break;
            }

        }
        posicao = posicao + sizeof(acesso_login);
        fseek(arq, posicao, SEEK_SET);
    }
    fclose(arq);

    printf("\n \n");
    system("pause");
}

//VARIAVEIS PARA PEDIDO
int validar_cliente;// achar cliente para pedido
char busc_telefone[11];
int cod_pizza=0, numero_pedido;// localizar o sabor para pedido
float valor1;// compara maior valor do meio sabor.

FILE* arq1;// utilizado em abertura de mais de um bloco de notas



//PEDIDO
void realizar_pedido(){

        cabecalho();

        int opcao_pizza, opcao_forma = 0;

        //utilizado somente para sabores
        char sabor[100][100];
        char descricao[100][200];
        float valor[100], total_sabor =0;
        int i = 0, voltas;

        //utilizado somente para bebidas
        char descricao_bebida[100][200];
        float valor_bebida[100], total_bebida =0;
        int voltas_bebidas = 0, valida_bebida = 0;

        char mostradata[11];
        time_t agora;
        struct tm *data_hora_atual;



        Localizar_numero_pedido();
        busca_cliente();


            if (validar_cliente == 1) {

                printf("\nNP: %i", numero_pedido);
                printf("\nNome: %s", c_pedido.nome_Cli);
                printf("\nTelefone: %s", busc_telefone);
                printf("\nEndereço de entrega: %s", c_pedido.logradouro);

                do{

                    do{

                        printf("\n\n===========================================\n");
                        printf("\nModalidade da pizza:\n");
                        printf("\n1 - Tradicional");
                        printf("\n2 - 1/2");
                        printf("\n0 - Cancelar pedido\n\n");
                        printf("Escolha a opção: ");
                        scanf("%i", &opcao_pizza);
                        flush_in();
                        printf("\n===========================================\n");

                            switch (opcao_pizza){

                            case 1:
                                busca_sabor();

                            break;
                            case 2:
                                strcpy(c_sabor_pedidos.sabor, "1/2 ");
                                busca_meio_sabor_1();
                                busca_meios_sabor();
                                opcao_pizza = 1;
                            break;
                            case 0:
                                return menu_pedidos();
                            break;
                            default:
                                printf("\nOpção selecionada inválida....");
                                opcao_pizza = 0;
                            break;

                            }

                    }while(opcao_pizza != 1);


                    printf("\nSabor: %s", c_sabor_pedidos.sabor);
                    printf("\nDescrição: %s", c_sabor_pedidos.desc_sabor);
                    printf("\nValor:_____________ R$%.2f", c_sabor_pedidos.valor_pagar);
                    printf("\n\n===========================================\n");

                    strcpy(sabor[i], c_sabor_pedidos.sabor);
                    strcpy(descricao[i], c_sabor_pedidos.desc_sabor);
                    valor[i] = c_sabor_pedidos.valor_pagar;


                    i++;


            printf("\nDeseja solicitar mais uma pizza? [S/N]:");
            }while(tolower(getche()) =='s');

                    voltas = i;

                    for (i =0; i<voltas; i++){
                        total_sabor += valor[i];
                    }


                printf("\n\n===========================================\n");
                printf("\nDeseja solicitar bebida? [S/N]:");
                if (tolower(getche()) =='s'){

                    i = 0, valida_bebida = 1;

                     do{
                        printf("\n\n===========================================\n");
                        busca_bebida();

                        printf("\nDescrição: %s\n", c_bebida_pedidos.decricao);
                        printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);

                        strcpy(descricao_bebida[i], c_bebida_pedidos.decricao);
                        valor_bebida[i] = c_bebida_pedidos.valor_pagar;

                        i++;

                    printf("\n===========================================\n");
                    printf("\nDeseja solicitar mais uma bebida? [S/N]:");
                    }while(tolower(getche()) =='s');

                    voltas_bebidas = i;

                    for (i =0; i<voltas_bebidas; i++){
                        total_bebida += valor_bebida[i];
                    }

                }


                printf("\n\n===========================================\n");
                printf("\nDigite a taxa de entrega (Ex R$3,50): R$");

                scanf("%f", &c_pedido.taxa_entrega);
                printf("\n===========================================\n");

                do{
                    printf("\nForma de pagamento:");
                    printf("\n1 - Dinheiro");
                    printf("\n2 - Cartão");
                    printf("\n0 - Cancelar pedido\n");
                    printf("\nEscolha a forma de pagamento: ");
                    scanf("%i", &opcao_forma);
                    printf("\n\n===========================================\n");
                    c_pedido.total = c_pedido.taxa_entrega + total_sabor + total_bebida;

                        switch(opcao_forma){

                            case 1:
                                strcpy(c_pedido.form_pagmt, "Dinheiro");

                                printf("\nTotal:________________R$%.2f\n", c_pedido.total);
                                printf("\n===========================================\n");
                                do{
                                    printf("\nValor a receber (Ex R$50,50): R$");
                                    scanf("%f", &c_pedido.valor_receber);

                                    if (c_pedido.valor_receber < c_pedido.total){
                                        printf("\n===========================================\n");
                                        printf("\nValor menor que o total!");
                                        printf("\n\n===========================================\n");

                                    }

                                }while(c_pedido.valor_receber < c_pedido.total);




                                c_pedido.troco = c_pedido.valor_receber - c_pedido.total;

                            break;

                            case 2:
                                strcpy(c_pedido.form_pagmt, "Cartão");
                                c_pedido.valor_receber = c_pedido.total;
                                c_pedido.troco = 0;

                            break;
                            case 0:
                                return menu_pedidos();
                            break;
                            default:
                            printf("\nOpção selecionada inválida....");
                            printf("\n===========================================\n");
                            opcao_pizza = 0;
                            break;


                        }
                }while (opcao_forma != 1 && opcao_forma != 2);


                c_pedido.numero_pedido = numero_pedido;
                c_pedido.Qtd_pizza = voltas;
                c_pedido.qtd_bebida = voltas_bebidas;
                strcpy(c_pedido.usu_atendente, salva_usuario);

                cabecalho();

                agora = time(NULL);
                strftime( c_pedido.data, sizeof(c_pedido.data), "%d.%m.%Y - 00:00:00", localtime( &agora ) );
                strncpy(mostradata, c_pedido.data, 10);

                time(&agora);
                data_hora_atual = localtime(&agora);
                c_pedido.mes = data_hora_atual->tm_mon+1;
                c_pedido.ano = data_hora_atual->tm_year+1900;

                printf("===========================================\n");
                printf("NP: %i\n", c_pedido.numero_pedido);
                printf("===========================================\n\n");
                printf("Telefone: %s\n", c_pedido.telefone);
                printf("Nome: %s\n", c_pedido.nome_Cli);
                printf("Endereço: %s\n\n", c_pedido.logradouro);
                printf("===========================================\n");
                printf("Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                printf("===========================================\n\n");

                for (i=0; i<voltas; i++){
                    printf("Sabor: %s\n", sabor[i]);
                    printf("Descrição: %s\n", descricao[i]);
                    printf("Valor da pizza: R$%.2f\n", valor[i]);
                    //printf("Observação: %s\n\n", c_pedido.obs_pedido);
                    printf("\n-------------------------------------------\n\n");
                }

                if (valida_bebida == 1){
                    printf("===========================================\n");
                    printf("Qtd de bebida: %i\n", voltas_bebidas);
                    printf("===========================================\n\n");

                    for (i=0; i<voltas_bebidas; i++){
                        printf("Descrição: %s\n", descricao_bebida[i]);
                        printf("Valor da bebida: R$%.2f\n", valor_bebida[i]);
                        printf("\n-------------------------------------------\n\n");
                    }


                }
                printf("===========================================\n\n");

                printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);

                if (valida_bebida == 1){
                printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                }
                printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);

                printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                printf("Troco:_____________________________R$%.2f\n", c_pedido.troco);
                printf("\n===========================================\n\n");
                printf("Usuário: %s\n", c_pedido.usu_atendente);
                printf("Data: %s\n", mostradata);
                printf("\n===========================================\n\n");



                printf("Deseja finalizar pedido? [S/N]: ");
                if (tolower(getche()) =='s'){

                    strcpy(c_pedido.status_pedido, "Em preparo");

                    arq = fopen("Pedidos.txt","a+b");

                    fwrite(&c_pedido,sizeof(s_pedidos),1,arq);
                    fclose(arq);

                    arq = fopen("Pedidos_sabor.txt", "a+b");
                    c_sabor_pedidos.numero_pedido = numero_pedido;

                    for (i=0; i<voltas; i++){

                        c_sabor_pedidos.numero_pedido;
                        strcpy(c_sabor_pedidos.sabor, sabor[i]);
                        strcpy(c_sabor_pedidos.desc_sabor, descricao[i]);
                        c_sabor_pedidos.valor_pagar = valor[i];
                        fwrite(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq);

                    }
                    fclose(arq);

                    if (valida_bebida == 1){
                        arq = fopen("Pedidos_bebidas.txt", "a+b");
                        c_bebida_pedidos.numero_pedido = numero_pedido;

                        for (i=0; i<voltas_bebidas; i++){

                            c_bebida_pedidos.numero_pedido;
                            strcpy(c_bebida_pedidos.decricao, descricao_bebida[i]);
                            c_bebida_pedidos.valor_pagar = valor_bebida[i];
                            fwrite(&c_bebida_pedidos,sizeof(s_bebida),1,arq);

                        }
                        fclose(arq);
                    }

                    printf("\n\nPedido encaminhado a cozinha...\n\n");
                    system("pause");
                }

            }else if (validar_cliente == 0){
                printf("\nCliente não cadastrado na base de dados...\n\n");
                system("pause");
            }

}

void Localizar_numero_pedido(){

    arq = fopen("Pedidos.txt","rb");


    if(arq==NULL)
    {
        numero_pedido = 1;
    }
    else{
         while(fread(&c_pedido, sizeof(s_pedidos), 1, arq)==1)
        {
        numero_pedido = c_pedido.numero_pedido;
        numero_pedido++;
        }

        fclose(arq);
    }


}

void busca_cliente (){



            validar_cliente = 0;

            printf("Digite o telefone do Cliente: ");
            gets(busc_telefone);
            printf("===========================================\n");

            arq = fopen("Clientes.txt","rb");

            if(arq==NULL)
            {
                printf("\nNão há clientes cadastrado na base de dados.\n\n");
                system("pause");
                exit(0);
            }

            while(fread(&c_cliente, sizeof(cad_cliente), 1, arq)==1){

                if (strcmp(busc_telefone,c_cliente.telefone)==0)
                {
                    validar_cliente = 1;
                    strcpy(c_pedido.nome_Cli, c_cliente.nome);
                    strcpy(c_pedido.logradouro, c_cliente.logradouro);
                    strcpy(c_pedido.telefone, busc_telefone);


                }

            }
    fclose(arq);
}

void busca_sabor(){
    int validar =0;

    cod_pizza = true;
    printf("\nCódigo de sabor: ");
    scanf("%i", &cod_pizza);
    printf("\n===========================================\n");


    arq = fopen("SaborPizzas.txt","rb");


    if(arq==NULL)
    {

        printf("\nNão há sabores cadastrado na base de dados.\n\n");
        system("pause");
        exit(0);
    }

    while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1){


        if (ctt1.cod_pizza == cod_pizza)
        {
            strcpy(c_sabor_pedidos.sabor, ctt1.sabor_pizza);
            c_sabor_pedidos.valor_pagar = ctt1.preco_pizza;
            strcpy(c_sabor_pedidos.desc_sabor, ctt1.descricao_pizza);
            validar = 1;
        }
    }
    fclose(arq);

    if (validar == 0){
        printf("\nCódigo não localizado...\n");
        printf("\n===========================================\n");
        return busca_sabor();
    }
    validar = 0;

}

void busca_bebida(){
    int validar =0;
    int cod_bebida;

    printf("\nCódigo da bebida: ");
    scanf("%i", &cod_bebida);
    printf("\n===========================================\n");


    arq = fopen("Bebidas.txt","rb");

    if(arq==NULL)
    {
        printf("\nNão há bebidas cadastrada na base de dados.\n\n");
        system("pause");
        exit(0);
    }


    while(fread(&c_bebida, sizeof(s_bebida), 1, arq)==1){


        if (c_bebida.cod_bebida == cod_bebida)
        {
            strcpy(c_bebida_pedidos.decricao, c_bebida.descricao);
            c_bebida_pedidos.valor_pagar = c_bebida.preco_bebida;
            validar = 1;
        }
    }
    fclose(arq);

    if (validar == 0){
        printf("\nCódigo não localizado...\n");
        printf("\n===========================================\n");
        return busca_bebida();
    }
    validar = 0;

}

void busca_meios_sabor(){
    int validar =0;
    char sabor[30], desc[100];



    cod_pizza = true;
    printf("\nCódigo de sabor: ");
    scanf("%i", &cod_pizza);
    printf("\n===========================================\n");


    arq = fopen("SaborPizzas.txt","rb");

    if(arq==NULL)
    {
        printf("\nNão há sabores cadastrado na base de dados.\n\n");
        system("pause");
        exit(0);
    }

    strncat(c_sabor_pedidos.sabor, " 1/2 ", 5);


    while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1){


        if (ctt1.cod_pizza == cod_pizza){

            strcpy(sabor, ctt1.sabor_pizza);
            c_sabor_pedidos.valor_pagar = ctt1.preco_pizza;
            strcpy(desc, ctt1.descricao_pizza);

            validar = 1;
        }
    }
    fclose(arq);

    if (validar == 0){
        printf("\nCódigo não localizado...\n");
        printf("\n===========================================\n");
        return busca_meios_sabor();
    }

    validar = 0;
    strncat(c_sabor_pedidos.sabor, sabor, 100);

    if (valor1 > c_sabor_pedidos.valor_pagar){
        c_sabor_pedidos.valor_pagar = valor1;
    }


}

void busca_meio_sabor_1(){
    int validar =0;

    cod_pizza = true;
    printf("\nCódigo de sabor: ");
    scanf("%i", &cod_pizza);
    printf("\n===========================================\n");


    arq = fopen("SaborPizzas.txt","rb");

    if(arq==NULL)
    {
        printf("Não há sabores cadastrado na base de dados.\n\n");
        system  ("pause");
        exit(0);
    }


    while(fread(&ctt1, sizeof(cadastro_sabor), 1, arq)==1){


        if (ctt1.cod_pizza == cod_pizza){

            strncat(c_sabor_pedidos.sabor, ctt1.sabor_pizza, 30);
            valor1 = ctt1.preco_pizza;
            strcpy(c_sabor_pedidos.desc_sabor, ctt1.descricao_pizza);
            validar = 1;
        }
    }
    fclose(arq);

    if (validar == 0){
        printf("\nCódigo não localizado...\n");
        printf("\n===========================================\n");
        return busca_meio_sabor_1();
    }
    validar = 0;


}

void busca_pedido_cozinha(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor;
    cabecalho();
    arq = fopen("Pedidos.txt","rb");


    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_pedidos();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Em preparo")==0){

                    total_sabor = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){


                        if (c_sabor_pedidos.numero_pedido == np){

                        printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                        printf("Descrição: %s\n", c_sabor_pedidos.desc_sabor);
                        printf("___________________________________________\n\n");
                        }

                    }
                    fclose(arq1);

                }

            }
            fclose(arq);

            if (valida == 1){
                encaminhar_pedido_entrega();
            }
            else if(valida ==0){
                printf("Não há nenhum pedido na cozinha....\n\n");
                system("pause");
            }



}

void encaminhar_pedido_entrega (){

        int posicao = 0; // Inicio do Arquivo;
        int achou = 0;
        int pedido, opcao, valida;

        printf("===========================================\n");
        printf("\n1 - Encaminhar pedido para entrega");
        printf("\n2 - Cancelar pedido");
        printf("\n0 - Voltar");
        printf("\n\nEscolha uma opção: ");
        scanf("%i", &opcao);
        flush_in();

        switch(opcao)
        {
            case 1:
                printf("\n===========================================\n");
                printf("\nSelecione o NP: ");
                scanf("%i", &pedido);
                flush_in();

                arq = fopen("Pedidos.txt","r+b");

                valida =0;
                op = -1;
                while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1 && op!=0)
                {
                    if(c_pedido.numero_pedido == pedido && strcmp(c_pedido.status_pedido,"Em preparo")==0)
                    {
                        printf("\n===========================================\n");
                        printf("\nEncaminhar pedido Nº%i para entrega? [S/N]: ", pedido);
                        valida = 1;

                        if (tolower(getche()) =='s'){
                            strcpy(c_pedido.status_pedido, "Pedido encaminhado");

                            fseek(arq, posicao, SEEK_SET);
                            achou= fwrite(&c_pedido,sizeof(s_pedidos),1,arq) == sizeof(s_pedidos);

                            printf("\n\nPedido encaminhado para entrega...");

                        }


                    }

                    posicao = posicao + sizeof(s_pedidos);
                    fseek(arq, posicao, SEEK_SET);

                }
                op = -1;
                fclose(arq);
                if (valida == 0){
                    printf("\n===========================================\n");
                    printf("\nNúmero de pedido inválido...\n\n");
                    system("pause");
                    return busca_pedido_cozinha();
                }
            break;

            case 2:

                printf("\n===========================================\n");
                printf("\nSelecione o NP: ");
                scanf("%i", &pedido);
                flush_in();

                arq = fopen("Pedidos.txt","r+b");

                valida =0;
                op = -1;
                while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1 && op!=0)
                {
                    if(c_pedido.numero_pedido == pedido && strcmp(c_pedido.status_pedido,"Em preparo")==0)
                    {

                        printf("\n===========================================\n");
                        printf("\nPedido Nº%i foi preparado? [S/N]: ", pedido);
                        valida = 1;

                        if (tolower(getche()) =='n'){

                            printf("\n===========================================\n");
                            printf("\nDeseja realmente cancelar o pedido Nº%i? [S/N]: ", pedido);
                            valida = 1;

                            if (tolower(getche()) =='s'){

                                strcpy(c_pedido.status_pedido, "Pedido cancelado");

                                fseek(arq, posicao, SEEK_SET);
                                achou= fwrite(&c_pedido,sizeof(s_pedidos),1,arq) == sizeof(s_pedidos);

                                printf("\n\nPedido cancelado...");
                            }

                        }else{
                            printf("\n\nO pedido deve ser despachado para entrega e selecionado como devolvido...");
                        }


                    }

                    posicao = posicao + sizeof(s_pedidos);
                    fseek(arq, posicao, SEEK_SET);

                }
                op = -1;
                fclose(arq);
                if (valida == 0){
                    printf("\n===========================================\n");
                    printf("\nNúmero de pedido inválido...\n\n");
                    system("pause");
                    return busca_pedido_cozinha();
                }


            break;

            case 0:
                return menu_pedidos();
                break;
            default:
                printf("\n===========================================\n");
                printf("\nOpção inválida...\n");
                printf("\n===========================================\n\n");
                system("pause");
                return busca_pedido_cozinha();
                break;



        }
        printf ("\n \n");
        system("pause");

}

void busca_pedido_encaminhado(){

    int np, valida =0;
    float total_sabor=0, total_bebida =0;
    char mostradata[11];

    cabecalho();
    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_pedidos();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido encaminhado")==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);


                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);
                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);

            if (valida == 1){
                finalizar_pedido();
            }
            else if(valida ==0){
                printf("Não há nenhum pedido sendo entregue...\n\n");
                system("pause");
            }

}

void finalizar_pedido(){

        int posicao = 0; // Inicio do Arquivo;
        int achou = 0;
        int pedido, opcao, valida;

        printf("===========================================\n");
        printf("\n1 - Finalizar pedido");
        printf("\n0 - Voltar");
        printf("\n\nEscolha uma opção: ");
        scanf("%i", &opcao);
        flush_in();

        switch(opcao)
        {
            case 1:
                printf("\n===========================================\n");
                printf("\nSelecione o NP: ");
                scanf("%i", &pedido);
                flush_in();

                arq = fopen("Pedidos.txt","r+b");

                valida =0;
                op = -1;
                while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1 && op!=0)
                {
                    if(c_pedido.numero_pedido == pedido && strcmp(c_pedido.status_pedido,"Pedido encaminhado")==0)
                    {
                        do{
                            printf("\n===========================================\n");
                            printf("\n1 - Pedido entregue");
                            printf("\n2 - Pedido devolvido");
                            printf("\n0 - Sair");
                            printf("\n\nEscolha uma opção: ");
                            scanf("%i", &opcao);
                            flush_in();

                        }while(opcao != 1 && opcao !=2 && opcao != 0);

                        switch(opcao)
                        {
                            case 1:
                                printf("\n===========================================\n");
                                printf("\nFinalizar pedido Nº%i como concluído? [S/N]: ", pedido);
                                valida = 1;

                                if (tolower(getche()) =='s'){
                                    strcpy(c_pedido.status_pedido, "Pedido concluído");

                                    fseek(arq, posicao, SEEK_SET);
                                    achou= fwrite(&c_pedido,sizeof(s_pedidos),1,arq) == sizeof(s_pedidos);

                                    printf("\n\nPedido finalizado com sucesso...");

                                }
                            break;

                            case 2:
                                //printf("\n===========================================\n");
                                printf("\n==============================================================================\n");
                                printf("\n*Atenção: Finalizando nesse modo será considerado como custo negativo!\n");
                                //printf("\n===========================================\n");
                                printf("\n==============================================================================\n");
                                printf("\nDeseja realmente continuar? [S/N]: ");
                                valida = 1;
                                if (tolower(getche()) =='s'){

                                    printf("\n===========================================\n");
                                    printf("\nQual motido da devolução?\n");
                                    gets(c_devolucao.motivo);

                                    printf("\nFinalizar pedido Nº%i como devolvido? [S/N]: ", pedido);
                                    valida = 1;

                                    if (tolower(getche()) =='s'){
                                        strcpy(c_pedido.status_pedido, "Pedido devolvido");
                                        c_devolucao.numero_pedido = pedido;

                                        arq1 = fopen("Motivo.txt","a+b");
                                        fwrite(&c_devolucao,sizeof(s_devolucao),1,arq1);
                                        fclose(arq1);

                                        fseek(arq, posicao, SEEK_SET);
                                        achou= fwrite(&c_pedido,sizeof(s_pedidos),1,arq) == sizeof(s_pedidos);

                                        printf("\n\nPedido finalizado com sucesso...");
                                    }

                                }
                            break;
                            case 0:
                                fclose(arq);
                                return menu_pedidos();
                            break;
                        }


                    }

                    posicao = posicao + sizeof(s_pedidos);
                    fseek(arq, posicao, SEEK_SET);

                }
                op = -1;
                fclose(arq);
                if (valida == 0){
                    printf("\n===========================================\n");
                    printf("\nNúmero de pedido inválido...\n\n");
                    system("pause");
                    return busca_pedido_encaminhado();
                }
                break;

            case 0:
                return menu_pedidos();
                break;
            default:
                printf("\n===========================================\n");
                printf("\nOpção inválida...\n");

                printf("\n===========================================\n\n");
                system("pause");
                return busca_pedido_encaminhado();
                break;



        }
        printf ("\n \n");
        system("pause");

}

void listar_pedidos_concluidos(){

    int np, valida =0;
    float total_sabor = 0, lucro = 0, total_bebida = 0;
    char mostradata[11];
    char comp_data[25];


    cabecalho();

    time_t agora;
    agora = time(NULL);
    strftime( comp_data, sizeof(comp_data), "%d.%m.%Y - 00:00:00", localtime( &agora ) );

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_pedidos();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido concluído")==0 && strcmp(c_pedido.data, comp_data)==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    lucro += c_pedido.total;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);
                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);

            if (valida == 1){
                printf("===========================================\n");
                printf("|Total:_____________________R$%.2f\n", lucro);
                printf("===========================================\n\n");
            }
           else if(valida ==0){
                printf("Não há pedidos concluídos hoje...\n\n");
            }
            getch();
}

void listar_pedidos_devolvido(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor, total_negativo = 0, total_bebida = 0;
    char comp_data[25];


    cabecalho();

    time_t agora;
    agora = time(NULL);
    strftime( comp_data, sizeof(comp_data), "%d.%m.%Y - 00:00:00", localtime( &agora ) );

    arq = fopen("Pedidos.txt","rb");



    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_pedidos();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido devolvido")==0 && strcmp(c_pedido.data, comp_data)==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);


                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    total_negativo += c_pedido.total;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);

                    arq1 = fopen("Motivo.txt", "rb");
                    while(fread(&c_devolucao,sizeof(s_devolucao),1,arq1)==1){

                        if (c_devolucao.numero_pedido == np){

                            printf("Motivo: %s\n", c_devolucao.motivo);

                        }

                    }
                    fclose(arq1);

                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);


            if (valida == 1){
                printf("===========================================\n");
                printf("|Total:_____________________R$-%.2f\n", total_negativo);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("Não há pedidos devolvidos hoje...\n\n");
            }


            getch();
}

void listar_pedidos_cancelado(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor, total_negativo = 0, total_bebida = 0;
    char comp_data[25];


    cabecalho();

    time_t agora;
    agora = time(NULL);
    strftime( comp_data, sizeof(comp_data), "%d.%m.%Y - 00:00:00", localtime( &agora ) );

    arq = fopen("Pedidos.txt","rb");



    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
    }else{


            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido cancelado")==0 && strcmp(c_pedido.data, comp_data)==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);


                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    total_negativo += c_pedido.total;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);
                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);


            if (valida == 1){
                printf("Obs: Pedidos finalizado como cancelado NÃO entra no faturamento negativo!\n\n");
            }
            else if(valida ==0){
                printf("Não há pedidos devolvidos hoje...\n\n");
            }
            getch();
        }

}

//TELAS DE RELATORIOS
void relatorio_positivo_dia(){

    int np, valida =0, conta_bebida=0, conta_pizzas = 0, form_cartao = 0, form_dinheiro = 0;
    float total_sabor, lucro = 0, total_bebida = 0, valor_total_bebida = 0, valor_total_sabor=0, total_taxa_entrega =0;
    char data[25];
    char mostradata[11];

    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }
            printf("Digite a data [EX DD.MM.AAAA]: ");
            gets(data);
            printf("==============================================================================\n\n");

            strncat(data, " - 00:00:00", 11);

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {

                    if (strcmp(c_pedido.data,data)==0 && strcmp(c_pedido.status_pedido,"Pedido concluído")==0){

                        total_sabor = 0, total_bebida = 0;

                        printf("===========================================\n");
                        printf("| NP: %i\n", c_pedido.numero_pedido);
                        printf("===========================================\n\n");
                        np = c_pedido.numero_pedido;
                        valida = 1;
                        strncpy(mostradata, c_pedido.data, 10);

                        printf("Telefone: %s\n", c_pedido.telefone);
                        printf("Nome: %s\n", c_pedido.nome_Cli);
                        printf("Endereço: %s\n", c_pedido.logradouro);
                        printf("Data: %s\n\n", mostradata);

                        printf("==================\n");
                        printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                        printf("==================\n\n");
                        conta_pizzas += c_pedido.Qtd_pizza;

                        arq1 = fopen("Pedidos_sabor.txt", "rb");
                        while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                            if (c_sabor_pedidos.numero_pedido == np){

                                printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                                printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_sabor += c_sabor_pedidos.valor_pagar;
                                valor_total_sabor += c_sabor_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);

                        if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");
                        conta_bebida += c_pedido.qtd_bebida;


                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                            while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                                if (c_bebida_pedidos.numero_pedido == np){

                                    printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                    printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                    printf("___________________________________________\n\n");
                                    total_bebida += c_bebida_pedidos.valor_pagar;
                                    valor_total_bebida += c_bebida_pedidos.valor_pagar;

                                }

                            }
                            fclose(arq1);
                        }


                        printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                        if (c_pedido.qtd_bebida != 0){
                        printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                        }
                        printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                        printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                        printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                        printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                        printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                        lucro += c_pedido.total;
                        total_taxa_entrega +=  c_pedido.taxa_entrega;


                        printf("Usuário: %s\n", c_pedido.usu_atendente);
                        printf("Status: %s\n", c_pedido.status_pedido);
                        printf("___________________________________________\n\n\n");

                        if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                            form_dinheiro++;
                        }else{
                            form_cartao++;
                        }

                    }

            }
            fclose(arq);

            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");

                if (conta_bebida != 0){

                printf("Qtd de bebidas: %i\n", conta_bebida);
                printf("Valor total das bebidas:___________R$%.2f\n\n", valor_total_bebida);

                }

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", valor_total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);

                printf("===========================================\n");
                printf("|Total:_____________________R$%.2f\n", lucro);
                printf("===========================================\n\n");

            }else if(valida ==0){
                printf("\nNão há histórico no período selecionado...\n\n");
            }

            getch();
}

void relatorio_positivo_mes(){


    int np, valida =0, conta_bebida=0, conta_pizzas = 0, form_cartao = 0, form_dinheiro = 0;
    float total_sabor, lucro = 0, total_bebida = 0, valor_total_bebida = 0, valor_total_sabor=0, total_taxa_entrega =0;

    int mes, ano;
    char mostradata[11];

    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }
            printf("Digite o mês desejado (MM): ");
            scanf("%i", &mes);
            flush_in();
            printf("Digite o ano desejado (AAAA): ");
            scanf("%i", &ano);
            printf("==============================================================================\n\n");

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {


                if (c_pedido.mes == mes && strcmp(c_pedido.status_pedido,"Pedido concluído")==0 && c_pedido.ano == ano){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");
                    conta_pizzas += c_pedido.Qtd_pizza;


                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;
                            valor_total_sabor += c_sabor_pedidos.valor_pagar;


                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");
                        conta_bebida += c_pedido.qtd_bebida;

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;
                                valor_total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    lucro += c_pedido.total;
                    total_taxa_entrega +=  c_pedido.taxa_entrega;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);
                    printf("___________________________________________\n\n\n");

                    if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                        form_dinheiro++;
                    }else{
                        form_cartao++;
                    }

                }

            }
            fclose(arq);

            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");

                if (conta_bebida != 0){

                printf("Qtd de bebidas: %i\n", conta_bebida);
                printf("Valor total das bebidas:___________R$%.2f\n\n", valor_total_bebida);

                }

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", valor_total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);

                printf("===========================================\n");
                printf("|Total:_____________________R$%.2f\n", lucro);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("\nNão há histórico no período selecionado...\n\n");
            }

            getch();
}

void total_perda(){

    int np, valida =0, conta_pizzas = 0, form_cartao = 0, form_dinheiro = 0;
    float total_sabor, custo = 0, valor_total_sabor=0, total_taxa_entrega =0;

    char mostradata[11];



    cabecalho();

    arq = fopen("Pedidos.txt","rb");


    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido devolvido")==0){

                    total_sabor = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");
                    conta_pizzas += c_pedido.Qtd_pizza;

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;
                            valor_total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    printf("Valor total das pizza:_____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    //printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    //printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    //("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    custo += total_sabor + c_pedido.taxa_entrega;
                    total_taxa_entrega +=  c_pedido.taxa_entrega;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);

                    arq1 = fopen("Motivo.txt", "rb");
                    while(fread(&c_devolucao,sizeof(s_devolucao),1,arq1)==1){

                        if (c_devolucao.numero_pedido == np){

                            printf("Motivo: %s\n\n", c_devolucao.motivo);

                        }

                    }
                    fclose(arq1);

                    printf("___________________________________________\n\n\n");

                    if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                        form_dinheiro++;
                    }else{
                        form_cartao++;
                    }

                }

            }
            fclose(arq);

            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", valor_total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);

                printf("===========================================\n");
                printf("|Total:_____________________R$-%.2f\n", custo);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("\nNão há histórico no período selecionado...\n\n");
            }


            getch();
}

void total_lucro(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor, lucro = 0, total_bebida = 0;


    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido concluído")==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    lucro += c_pedido.total;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n\n", c_pedido.status_pedido);

                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);


            if (valida == 1){
                printf("===========================================\n");
                printf("|Total:_____________________R$%.2f\n", lucro);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("Não há pedidos devolvidos...\n\n");
            }


            getch();
}

void listar_todos_pedidos_cancelado(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor, total_negativo = 0, total_bebida = 0;


    cabecalho();

    arq = fopen("Pedidos.txt","rb");



    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido cancelado")==0){

                    total_sabor = 0, total_bebida = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);


                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){

                        printf("===================\n");
                        printf("|Qtd de bebida: %i\n", c_pedido.qtd_bebida);
                        printf("===================\n\n");

                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                printf("Descrição: %s\n", c_bebida_pedidos.decricao);
                                printf("Valor da bebida: R$%.2f\n", c_bebida_pedidos.valor_pagar);
                                printf("___________________________________________\n\n");
                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    if (c_pedido.qtd_bebida != 0){
                    printf("Valor total das bebidas:___________R$%.2f\n", total_bebida);
                    }
                    printf("Valor total das pizzas:____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    total_negativo += c_pedido.total;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);
                    printf("___________________________________________\n\n\n");

                }

            }
            fclose(arq);


            if (valida == 1){
                printf("Obs: Pedidos finalizado como cancelado NÃO entra no faturamento negativo!\n\n");
            }
            else if(valida ==0){
                printf("Não há pedidos devolvidos hoje...\n\n");
            }


            getch();
}

void relatorio_negativo_dia(){

    int np, valida =0, conta_pizzas = 0, form_cartao = 0, form_dinheiro = 0;
    float total_sabor, custo = 0, valor_total_sabor=0, total_taxa_entrega =0;

    char data[25];
    char mostradata[11];

    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }
            printf("Digite a data [EX DD.MM.AAAA]: ");
            gets(data);
            printf("==============================================================================\n\n");

            strncat(data, " - 00:00:00", 11);

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {

                if (strcmp(c_pedido.data,data)==0 && strcmp(c_pedido.status_pedido,"Pedido devolvido")==0){

                    total_sabor = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");
                    conta_pizzas += c_pedido.Qtd_pizza;

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;
                            valor_total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    printf("Valor total das pizza:_____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    //printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    //printf("Total a pagar:_____________________R$%.2f\n\n", c_pedido.total);
                    //printf("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    custo += total_sabor + c_pedido.taxa_entrega;
                    total_taxa_entrega +=  c_pedido.taxa_entrega;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);

                    arq1 = fopen("Motivo.txt", "rb");
                    while(fread(&c_devolucao,sizeof(s_devolucao),1,arq1)==1){

                        if (c_devolucao.numero_pedido == np){

                            printf("Motivo: %s\n\n", c_devolucao.motivo);

                        }

                    }
                    fclose(arq1);

                    printf("___________________________________________\n\n\n");

                    if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                        form_dinheiro++;
                    }else{
                        form_cartao++;
                    }


                }


            }
            fclose(arq);


            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", valor_total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);

                printf("===========================================\n");
                printf("|Total:_____________________R$-%.2f\n", custo);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("\nNão há histórico no período selecionado...\n\n");
            }

            getch();
}

void relatorio_negativo_mes(){

    int np, valida =0, conta_pizzas = 0, form_cartao = 0, form_dinheiro = 0;
    float total_sabor, custo = 0, valor_total_sabor=0, total_taxa_entrega =0;
    int mes, ano;
    char mostradata[11];

    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }
            printf("Digite o mês desejado (MM): ");
            scanf("%i", &mes);
            flush_in();
            printf("Digite o ano desejado (AAAA): ");
            scanf("%i", &ano);
            printf("==============================================================================\n\n");

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {


                if (c_pedido.mes == mes && strcmp(c_pedido.status_pedido,"Pedido devolvido")==0 && c_pedido.ano == ano){

                    total_sabor = 0;

                    printf("===========================================\n");
                    printf("| NP: %i\n", c_pedido.numero_pedido);
                    printf("===========================================\n\n");
                    np = c_pedido.numero_pedido;
                    valida = 1;
                    strncpy(mostradata, c_pedido.data, 10);

                    printf("Telefone: %s\n", c_pedido.telefone);
                    printf("Nome: %s\n", c_pedido.nome_Cli);
                    printf("Endereço: %s\n", c_pedido.logradouro);
                    printf("Data: %s\n\n", mostradata);

                    printf("==================\n");
                    printf("|Qtd de pizza: %i\n", c_pedido.Qtd_pizza);
                    printf("==================\n\n");
                    conta_pizzas += c_pedido.Qtd_pizza;

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            printf("Sabor: %s\n", c_sabor_pedidos.sabor);
                            printf("Valor da pizza: R$%.2f\n", c_sabor_pedidos.valor_pagar);
                            printf("___________________________________________\n\n");
                            total_sabor += c_sabor_pedidos.valor_pagar;
                            valor_total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    printf("Forma de pagamento: %s\n\n", c_pedido.form_pagmt);
                    printf("Valor total das pizza:_____________R$%.2f\n", total_sabor);
                    printf("Taxa de entrega:___________________R$%.2f\n\n", c_pedido.taxa_entrega);
                    //printf("Valor recebido:____________________R$%.2f\n", c_pedido.valor_receber);
                    //printf("Total a pagar:_____________________R$%.2f\n", c_pedido.total);
                    //("Troco:_____________________________R$%.2f\n\n", c_pedido.troco);
                    custo += total_sabor + c_pedido.taxa_entrega;
                    total_taxa_entrega +=  c_pedido.taxa_entrega;

                    printf("Usuário: %s\n", c_pedido.usu_atendente);
                    printf("Status: %s\n", c_pedido.status_pedido);

                    arq1 = fopen("Motivo.txt", "rb");
                    while(fread(&c_devolucao,sizeof(s_devolucao),1,arq1)==1){

                        if (c_devolucao.numero_pedido == np){

                            printf("Motivo: %s\n\n", c_devolucao.motivo);

                        }

                    }
                    fclose(arq1);

                    printf("___________________________________________\n\n\n");

                    if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                        form_dinheiro++;
                    }else{
                        form_cartao++;
                    }

                }

            }
            fclose(arq);

            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", valor_total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);

                printf("===========================================\n");
                printf("|Total:_____________________R$-%.2f\n", custo);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("\nNão há histórico no período selecionado...\n\n");
            }

            getch();
}

void total_vendas(){

    int np, valida =0;
    char mostradata[11];
    float total_sabor, lucro = 0, total_bebida = 0, total_taxa_entrega = 0;
    int conta_pizzas= 0, conta_bebida =0, volta = 0, form_dinheiro = 0, form_cartao = 0;

    cabecalho();

    arq = fopen("Pedidos.txt","rb");

    if(arq==NULL)
    {
        printf("Arquivo inexistente ou faltando, contate o administrador.\n\n");
        system("pause");
        return menu_relatorios();
    }

            while(fread(&c_pedido,sizeof(s_pedidos),1,arq)==1)
            {
                if (strcmp(c_pedido.status_pedido,"Pedido concluído")==0){

                    volta++;
                    valida = 1;
                    conta_pizzas += c_pedido.Qtd_pizza;
                    total_taxa_entrega+= c_pedido.taxa_entrega;
                    lucro += c_pedido.total;
                    np = c_pedido.numero_pedido;

                    arq1 = fopen("Pedidos_sabor.txt", "rb");
                    while(fread(&c_sabor_pedidos,sizeof(sabor_pedidos),1,arq1)==1){

                        if (c_sabor_pedidos.numero_pedido == np){

                            total_sabor += c_sabor_pedidos.valor_pagar;

                        }

                    }
                    fclose(arq1);

                    if (c_pedido.qtd_bebida != 0){


                        conta_bebida += c_pedido.qtd_bebida;


                        arq1 = fopen("Pedidos_bebidas.txt", "rb");
                        while(fread(&c_bebida_pedidos,sizeof(bebidas_pedidos),1,arq1)==1){

                            if (c_bebida_pedidos.numero_pedido == np){

                                total_bebida += c_bebida_pedidos.valor_pagar;

                            }

                        }
                        fclose(arq1);
                    }


                    if (strcmp(c_pedido.form_pagmt,"Dinheiro")==0){
                        form_dinheiro++;
                    }else{
                        form_cartao++;
                    }

                }

            }
            fclose(arq);


            if (valida == 1){

                printf("===========================================\n");
                printf("|Consolidado:\n");
                printf("===========================================\n\n");
                if (conta_bebida != 0){

                printf("Qtd de bebidas: %i\n", conta_bebida);
                printf("Valor total das bebidas:___________R$%.2f\n\n", total_bebida);

                }

                printf("Qtd de pizzas: %i\n", conta_pizzas);
                printf("Valor total das pizzas:____________R$%.2f\n\n", total_sabor);



                printf("Taxa de entrega:___________________R$%.2f\n\n", total_taxa_entrega);



                printf("Pagamentos com cartão: %i\n", form_cartao);
                printf("Pagamentos com dinheiro: %i\n\n", form_dinheiro);


                printf("===========================================\n");
                printf("|Total:_____________________R$%.2f\n", lucro);
                printf("===========================================\n\n");
            }
            else if(valida ==0){
                printf("Não há pedidos na base de dados...\n\n");
            }


            getch();
}
