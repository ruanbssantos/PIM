
#include "struct.c" //TODAS AS STRUCTS DO SISTEMA3
#include "variables.c" //TODAS AS STRUCTS DO SISTEMA3
  
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
      
    LIMPA_CONSOLE();
    DH_ATUAL(&DH);
  
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, i, contador;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left; 
  
    if (columns%2 != 0) columns--;

    contador  = (columns - 78) / 2;
    //linha superior
    printf("%s╔",color_purple);
    for (i = 1; i <= contador; i++){
        printf("═");
    }
    printf("%s KING CONSULTING CORPORATION (C). TODOS OS DIREITOS RESERVADOS [VERSÃO 1.0] %s%s",color_green,color_reset,color_purple);
    for (i = 1; i <= contador+1; i++){
        printf("═");
    }
    printf("╗%s\n",color_reset);

    
    contador  = (columns - 24) / 2;
    //linha MEIO
    printf("%s╟",color_purple);
    for (i = 1; i <= contador; i++){
        printf(" ");
    }
    printf("%s %s %s%s",color_yellow,DH.DH_COMPLETA,color_reset,color_purple);
    for (i = 1; i <= contador+1; i++){
        printf(" ");
    }
    printf("╢%s\n",color_reset);

    
    contador = columns - 1; 
    //linha inferior
    printf("%s╚",color_purple);
    for (i = 1; i <= contador; i++){
        printf("═");
    }
    printf("╝%s\n\n",color_reset); 

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
     
    printf("%sAtenção!%s\n",color_yellow,color_reset); 
    printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n\n");

    if(fl_mostramsg == true) system("pause"); 

    do{

        printf("\n\nDigite o seu CPF: ");
        gets(LOGIN.USUARIO);

        i = strlen(LOGIN.USUARIO);

        if (i != 11){
            printf("\n%sErro!%s\n",color_red,color_reset); 
            printf("O CPF deve conter onze dígitos...\n\n");
            system("pause");
            return LG_PRIMEIRO_ACESSO(false);
        } 

        for(i = 0; i < 11; i++){ 
            if (isdigit(LOGIN.USUARIO[i])==false){
                printf("\n%sErro!%s\n",color_red,color_reset); 
                printf("O CPF deve conter somente caracteres númericos, dígito inválido...\n\n");
                system("pause"); 
                return LG_PRIMEIRO_ACESSO(false); 
                break;
            }
        }
        valida_cpf = 1; 
    }while (valida_cpf != 1);

    printf("\nDigite a senha: ");

    do{
        c=getch();
        if(isprint(c)){
            senha[a]=c;
            a++;
            printf("*");
            strcpy(LOGIN.SENHA,senha);
        }
        else if(c==8&&a){
            senha[a]='\0';
            a--;
            printf("\b \b");
            strcpy(LOGIN.SENHA,senha);
        }

    }while(c!=13);

    LOGIN.NIVEL = 2;
    LOGIN.STATUS = 1;

    printf("\n\nDeseja finalizar cadastro? %s[S/N]%s: ",color_yellow,color_reset);

    if (tolower(getche()) =='s'){
        arq = fopen("ARQUIVOS/Login.txt","a+b");
        fwrite(&LOGIN,sizeof(LOGIN),1,arq);
        fclose(arq);
        printf("\n\nAcesso criado com sucesso...");

    }

    printf("\n \n");
    system("pause");

}
 
 