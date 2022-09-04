
#include "struct.c" //TODAS AS STRUCTS DO SISTEMA3
//=======================================================================================================
//FUNCTIONS PRINCIPAL
//======================================================================================================= 
//LIMPA O CONSOLE
void COLOR_RED(){
    printf("\033[0;31m");
}
void COLOR_GREEN(){
    printf("\033[0;32m");
}
void COLOR_RESET(){
    printf("\033[0m"); 
}

//=======================================================================================================
//FUNCTIONS PRINCIPAL
//======================================================================================================= 
//LIMPA O CONSOLE
void LIMPA_CONSOLE(){
    system("cls"); 
}
//CRIA CABECALHO NO TOPO
void CABECALHO(){
 
    STRC_DH DH;
    char color_red[] = "\033[0;31m";
    char color_green[] = "\033[0;32m";
    char color_yellow[] = "\033[0;33m";
    char color_blue[] = "\033[0;34m";
    char color_purple[] = "\033[0;35m";
    char color_cyan[] = "\033[0;36m"; 
    char color_reset[] = "\033[0m";
    LIMPA_CONSOLE();
  
    
    printf("%s=============================================================================================%s\n",color_red,color_reset);
    printf("%s=============================================================================================%s\n",color_green,color_reset);
    printf("%s=============================================================================================%s\n",color_yellow,color_reset);
    printf("%s=============================================================================================%s\n",color_blue,color_reset);
    printf("%s=============================================================================================%s\n",color_purple,color_reset);
    printf("%s=============================================================================================%s\n",color_cyan,color_reset);
    
 
    DH_ATUAL(&DH);
    printf("=============================================================================================\n");
    printf("======== King Consulting Corporation (c). Todos os direitos reservados [Versão 1.0] =========\n");
    printf("=============================================================================================\n");
    printf("|Bem Vindo admin, boa tarde!  %s \n\n\n\n",DH.DH_COMPLETA);
 

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
//FUNCTIONS LOGIN
//=======================================================================================================

void LG_PRIMEIRO_ACESSO(boolean fl_mostramsg){
    CABECALHO();

    STRC_LOGIN LOGIN;

    int i = 0, valida_cpf = 0;

    char cpf[11];

    char c;
    char senha[50]= "";
    int a=0;
    
    COLOR_GREEN();
    printf("Atenção!\n");
    COLOR_RESET();
    printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n\n");

    if(fl_mostramsg == true) system("pause"); 

    do{

        printf("\n\nDigite o seu CPF: ");
        gets(LOGIN.USUARIO);

        i = strlen(LOGIN.USUARIO);

        if (i != 11){
            COLOR_RED();
            printf("\nErro!");
            COLOR_RESET();
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
 