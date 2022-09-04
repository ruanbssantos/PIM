#include <stdio.h>
#include <stdlib.h> 
#include <string.h> //BIBLIOTECA PARA FUNÇÕES STRING
#include <locale.h> //CARACTER ESPECIAL DO PORTUGUES
#include <windows.h> //USAR COMANDOS DO WINDOWS
#include <time.h> //PEGAR DATA E HORA DO SISTEMA
#include <ctype.h> //CONTÉM FUNÇÕES DO TIPO BOOLEANN COMO ISDIGIT
#include <stdbool.h> //LÊ BOOLEANO

//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include "_inc/struct.c" //TODAS AS FUNÇÕES DO SISTEMA - SEMPRE DEVE ESTAR NO INICIO
#include "_inc/struct.c" //TODAS AS STRUCT DO SISTEMA


//=======================================================================================================
//FUNCTIONS CHAMADAS | PRINCIPAL
//=======================================================================================================
void CABECALHO();
void LIMPA_CONSOLE();
void DH_ATUAL();

//=======================================================================================================
//FUNCTIONS CHAMADAS | LOGIN
//=======================================================================================================
void LG_PRIMEIRO_ACESSO(boolean fl_mostramsg);


FILE *arq;
 

int main(){ 
    //VS CODE ABRIR O ARQUIVO EM ISO 88959-1
    //setlocale(LC_ALL,"Portuguese"); 
    system("king Consulting");
    CABECALHO();
    //FULL SCREEN
    //keybd_event ( VK_MENU, 0x36, 0, 0 ); 
    //keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
    //keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
    //keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
  
    // arq = fopen("Login.txt","rb");
    // fclose(arq);

    // if(arq==NULL)
    // {
    //     LG_PRIMEIRO_ACESSO(true);
    // }

    // int nivel_acesso;
    // if (nivel_acesso ==2){
    //     int op;

    //     do{
    //         CABECALHO();

    //         printf("1 - Cadastros\n");
    //         printf("2 - Clientes\n");
    //         printf("3 - Pedidos\n");
    //         printf("4 - Funcionários\n");
    //         printf("5 - Relatários\n");
    //         printf("6 - Configurações\n");
    //         printf("0 - Sair\n\n\n");

    //         printf("Escolha uma opção: ");
    //         scanf("%i", &op); 

    //         switch(op)
    //         {
    //             case 1:
    //                 printf('Em CONSTRUÇÃO...');
    //                 system("pause >nul");
    //                 break;
    //             case 2:
    //                 printf('Em CONSTRUÇÃO...');
    //                 break; 
    //             case 3:
    //                 printf('Em CONSTRUÇÃO...');
    //                 break; 
    //             case 4:
    //                 printf('Em CONSTRUÇÃO...');
    //                 break; 
    //             case 5:
    //                 printf('Em CONSTRUÇÃO...');
    //                 break; 
    //             case 6:
    //                 printf('Em CONSTRUÇÃO...');
    //                 break;
    //             case 0: 
    //                 printf("Obrigado pela visita, até mais...\n\n"); 
    //                 system("pause >nul");
    //                 exit(1);
    //                 break;
    //             default:
    //                 op = -1;
                    
    //                 printf("\n\nOpção inválida. Selecione uma opção correta acima...\n");
    //                 printf("\033[0m"); 
    //                 system("pause");
    //                 break;
    //         }
            


    //     }while(op!='0');
    // }
    return 0;
}

//=======================================================================================================
//FUNCTIONS COLOR
//=======================================================================================================
 
//=======================================================================================================
//FUNCTIONS PRINCIPAL
//=======================================================================================================

//CRIA CABECALHO NO TOPO
void CABECALHO(){
 
    STRC_DH DH;

    LIMPA_CONSOLE();
  
    DH_ATUAL(&DH);
    printf("=============================================================================================\n");
    printf("======== King Consulting Corporation (c). Todos os direitos reservados [Versão 1.0] =========\n");
    printf("=============================================================================================\n");
    printf("|Bem Vindo admin, boa tarde!  %s \n\n\n\n",DH.DH_COMPLETA);
 

} 
//LIMPA O CONSOLE
void LIMPA_CONSOLE(){
    system("cls"); 
}
//RETORNA DATA E HORA BR ATUAL
void DH_ATUAL(STRC_DH *P){
 
    time_t DH;
    struct tm * STRC_TEMPO; 

    time(&DH);
    STRC_TEMPO = localtime(&DH);
 
    strftime(P->DH_COMPLETA, sizeof(P->DH_COMPLETA), "%d/%m/%Y  %H:%M:%S",  STRC_TEMPO);
    strftime(P->DT_COMPLETA, sizeof(P->DT_COMPLETA), "%d/%m/%Y",  STRC_TEMPO);
    strftime(P->DIA, sizeof(P->DIA), "%d",  STRC_TEMPO);
    strftime(P->MES, sizeof(P->MES), "%m",  STRC_TEMPO);
    strftime(P->ANO, sizeof(P->ANO), "%Y",  STRC_TEMPO);
    strftime(P->HORAS, sizeof(P->HORAS), "%H",  STRC_TEMPO); 
    strftime(P->MINUTOS, sizeof(P->MINUTOS), "%M",  STRC_TEMPO); 
    strftime(P->SEGUNDOS, sizeof(P->SEGUNDOS), "%S",  STRC_TEMPO); 
  
}

//=======================================================================================================
//FUNCTIONS DECLARACAO | LOGIN
//=======================================================================================================

void LG_PRIMEIRO_ACESSO(boolean fl_mostramsg){

    CABECALHO();

    STRC_LOGIN LOGIN;

    int i = 0, valida_cpf = 0;

    char cpf[11];

    char c;
    char senha[50]= "";
    int a=0;

    printf("Atenção!\n");
    printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n\n");
                
    if(fl_mostramsg == true) system("pause"); 

    do{

        printf("\n\nDigite o seu CPF: ");
        gets(LOGIN.USUARIO);

        i = strlen(LOGIN.USUARIO);
        
        if (i != 11){
            printf("\nErro!\n");
            printf("\nO CPF deve conter onze dígitos...\n\n");
            system("pause");
            return LG_PRIMEIRO_ACESSO(false);
        } 

        for(i = 0; i < 11; i++){ 
            if (isdigit(LOGIN.USUARIO[i])==false){
                printf("\nErro!\n");
                printf("\nO CPF deve conter somente caracteres númericos, dígito inválido...\n\n");
                system("pause"); 
                return LG_PRIMEIRO_ACESSO(false); 
                break;
            }
        }
        valida_cpf = 1;
        // while(i < 11){

        //     LOGIN.USUARIO[i];
            
        //     if (isdigit(LOGIN.USUARIO[i])==true){
        //         fl_cpf = 1;
        //     }else if (isdigit(LOGIN.USUARIO[i])==false){
        //         printf("\nErro!\n");
        //         printf("\nO CPF deve conter somente caracteres númericos...\n\n");
        //         system("pause");
        //         return LG_PRIMEIRO_ACESSO(); 
        //     }
        //     i++;
        // }
    }while (valida_cpf != 1);

    // printf("\nDigite a senha: ");

    // do{
    //     c=getch();
    //     if(isprint(c)){
    //         senha[a]=c;
    //         a++;
    //         printf("*");
    //         strcpy(LOGIN.senha,senha);
    //     }
    //     else if(c==8&&a){
    //         senha[a]='\0';
    //         a--;
    //         printf("\b \b");
    //         strcpy(LOGIN.senha,senha);
    //     }

    // }while(c!=13);

    // LOGIN.nivel = 2;
    // LOGIN.status = 1;


    // printf("\n===========================================\n");
    // printf("\nDeseja finalizar cadastro? [S/N]: ");

    // if (tolower(getche()) =='s'){
    //     arq = fopen("Login.txt","a+b");
    //     fwrite(&LOGIN,sizeof(LOGIN),1,arq);
    //     fclose(arq);
    //     printf("\n\nLogin criado com sucesso...");

    // }

    // printf("\n \n");
    // system("pause");

}