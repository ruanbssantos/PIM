
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
    
    LIMPA_CONSOLE();
    STRC_DH DH;      
    DH_ATUAL(&DH);
  
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, i, contador;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left; 
  
    if (columns%2 != 0) columns--;

    contador  = (columns - 78) / 2;
    //linha superior
    printf("%s╔",COLOR_PURPLE);
    for (i = 1; i <= contador; i++){
        printf("═");
    }
    printf("%s KING CONSULTING CORPORATION (C). TODOS OS DIREITOS RESERVADOS [VERSÃO 1.0] %s%s",COLOR_GREEN,COLOR_RESET,COLOR_PURPLE);
    for (i = 1; i <= contador+1; i++){
        printf("═");
    }
    printf("╗%s\n",COLOR_RESET);

    
    contador  = (columns - 24) / 2;
    //linha MEIO
    printf("%s╟",COLOR_PURPLE);
    for (i = 1; i <= contador; i++){
        printf(" ");
    }
    printf("%s %s %s%s",COLOR_YELLOW,DH.DH_COMPLETA,COLOR_RESET,COLOR_PURPLE);
    for (i = 1; i <= contador+1; i++){
        printf(" ");
    }
    printf("╢%s\n",COLOR_RESET);

    
    contador = columns - 1; 
    //linha inferior
    printf("%s╚",COLOR_PURPLE);
    for (i = 1; i <= contador; i++){
        printf("═");
    }
    printf("╝%s\n\n",COLOR_RESET); 

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

    int i = 0, valida_cpf = 0,  a = 0; 
    char senha[100]= "", c; 
     
    printf("%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET); 
    printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n\n");

    if(fl_mostramsg == true) system("pause"); 

    do{

        printf("\n\nDigite o seu CPF: ");
        gets(LOGIN.USUARIO);

        i = strlen(LOGIN.USUARIO);

        if (i != 11){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET); 
            printf("O CPF deve conter onze dígitos...\n\n");
            system("pause");
            return LG_PRIMEIRO_ACESSO(false);
        } 

        for(i = 0; i < 11; i++){ 
            if (isdigit(LOGIN.USUARIO[i])==false){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET); 
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

    printf("\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);

    if (tolower(getche()) =='s'){
        arq = fopen(ARQ_LOGIN,"a+b");
        fwrite(&LOGIN,sizeof(LOGIN),1,arq);
        fclose(arq);
        printf("\n\nAcesso criado com sucesso...");
    }

    printf("\n\n");
    system("pause");

}

void LOGIN_VALIDA_ACESSO(boolean *session, int *session_nivelAcesso){
 
    STRC_LOGIN LOGIN;
     
    char COMPARA_SENHA[100]; 
    char SENHA[100] = "", USUARIO[20], c;
    int a=0;
    
    *session = false;

    printf("Digite o CPF: ");
    gets(USUARIO); 
 
    printf("\nDigite a senha: ");

    do{
        c=getch();
        
        if(isprint(c)){
            SENHA[a]=c;
            a++;
            printf("*");
            strcpy(COMPARA_SENHA,SENHA);
        }else if(c==8 && a){
            SENHA[a]='\0';
            a--;
            printf("\b \b");
            strcpy(COMPARA_SENHA,SENHA);
        }

    }while(c!=13);
 
  
    arq = fopen(ARQ_LOGIN,"r");
    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
        
        // printf("\n %s|%s USUARIO " , USUARIO,LOGIN.USUARIO);   
        // printf(" %i| NIVEL " ,LOGIN.NIVEL);   
        // printf(" %s|%s|%s SENHA " , COMPARA_SENHA,SENHA,LOGIN.SENHA);   
        // printf(" %i| STATUS \n\n" , LOGIN.STATUS);
 
        if (strcmp(USUARIO,LOGIN.USUARIO) == 0 && strcmp(COMPARA_SENHA,LOGIN.SENHA) == 0 && LOGIN.STATUS == 1){ 
            //if (strcmp(ctt.senha, "123456")==0){
            //    fclose(arq);
            //    alt_senha_padrao();
            //    break;
            //} 
            *session_nivelAcesso = LOGIN.NIVEL;
            *session = true;          
            break;  
        }

    }
    fclose(arq);
   
}
