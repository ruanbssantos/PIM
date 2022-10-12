
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
    //King’s office
    printf("%s ♕ KING'S OFFICE CORPORATION (C). TODOS OS DIREITOS RESERVADOS [VERSÃO 1.0] %s%s",COLOR_GREEN,COLOR_RESET,COLOR_PURPLE);
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
    strftime(P->DIA_SEMANA, sizeof(P->DIA_SEMANA), "%w",  STRC_TEMPO);

    // printf("DH_COMPLETA: %s", P->DH_COMPLETA);
    // printf("\nDT_COMPLETA: %s", P->DT_COMPLETA);
    // printf("\nDIA: %s", P->DIA);
    // printf("\nMES: %s", P->MES);
    // printf("\nANO: %s", P->ANO);
    // printf("\nHORAS: %s", P->HORAS);
    // printf("\nMINUTOS: %s", P->MINUTOS);
    // printf("\nSEGUNDOS: %s", P->SEGUNDOS);
    // printf("\nDIA_SEMANA: %s", P->DIA_SEMANA);

    // int d    = 30   ; //Day     1-31
    // int m    = 13  ; //Month   1-12`
    // int y    = 9999 ; //Year    2013`  
    // int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;  
    // printf("\n %i", weekday);
    // printf("\n\ntm_mday=%i", STRC_TEMPO->tm_mday);
    // printf("\ntm_sec=%i", STRC_TEMPO->tm_sec);
    // printf("\ntm_min=%i", STRC_TEMPO->tm_min);
    // printf("\ntm_hour=%i", STRC_TEMPO->tm_hour);
    // printf("\ntm_mday=%i", STRC_TEMPO->tm_mday);
    // printf("\ntm_mon=%i", STRC_TEMPO->tm_mon);
    // printf("\ntm_year=%i", STRC_TEMPO->tm_year);
    // printf("\ntm_wday=%i", STRC_TEMPO->tm_wday);
    // printf("\ntm_yday=%i", STRC_TEMPO->tm_yday);
    // printf("\ntm_isdst=%i", STRC_TEMPO->tm_isdst);
   
 

}


//=======================================================================================================
//FUNCTIONS VALIDAÇÃO
//=======================================================================================================
void LOGIN_VALIDA_ACESSO(boolean *session, int *session_nivelAcesso){

    STRC_LOGIN LOGIN;

    char COMPARA_SENHA[100];
    char SENHA[100] = "", USUARIO[20], c;
    int a=0;

    *session = false;

    printf("Digite o email: ");
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


    arq = fopen(ARQ_LOGIN,"rb");
    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){

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

int VALIDA_EMAIL(boolean *emailValidado_fl, char email[]){
 

    int count_arroba = 0, count_espacoBranco = 0, count_pontos = 0, conta_pontos_fl = 0, ultimoDigito;

    if(strlen(email) == 0){
        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
        printf("O e-mail é obrigatório...\n\n");
        emailValidado_fl = false;
    }else if (strlen(email) > 100){
        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
        printf("Máximo de 100 caracteres permitidos...\n\n");
        emailValidado_fl = false;
    } else {  
        for (int i=0; i < strlen(email); i++) {
            //printf("\n%i | %c | %d",i,email[i],isalpha(email[i]));
            if(email[i] == '@'){
                count_arroba++;
                conta_pontos_fl = 1;
            }
            if(email[i] == ' ') count_espacoBranco++;
            if(email[i] == '.' && conta_pontos_fl == true) count_pontos++;
        }
 
        if(isalpha(email[strlen(email)-1]) == 0) emailValidado_fl = false;
        if(count_arroba == 0 || count_espacoBranco > 0 || count_pontos == 0) emailValidado_fl = false;

        if(emailValidado_fl == false){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("E-mail informado inválido...\n\n");
        }
 
    }
  
    return emailValidado_fl;
}

//=======================================================================================================
//USUÁRIOS
//=======================================================================================================
void MENU_USUARIOS(){ 
    char op;
    do{
        CABECALHO();
        printf("[%s1%s] - Cadastrar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Pesquisar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar\n",COLOR_YELLOW,COLOR_RESET);
    
        printf("Escolha uma opção acima: ");
        op = getchar();  

        if(op == "") op = "x";

        switch(op)
        {
            case '1':
                printf("Em CONSTRUÇÃO...");
                system("pause >nul");
                break;
            case '2':
                printf("Em CONSTRUÇÃO...");
                system("pause");
                break; 
            default: 
                printf("\n\nOpção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
            }
            
    }while(op!='0');
    return 0;
}
//=======================================================================================================
//USUÁRIOS
//=======================================================================================================
void CADASTRA_USUARIO(boolean fl_mostramsg){
    CABECALHO();

    STRC_LOGIN LOGIN;

    int i = 0;
    char senha[100]= "", c, confirm;

    printf("%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n\n");

    if(fl_mostramsg == true) system("pause");

    boolean validaEmail = false;

    //EMAIL
    do{ 
        printf("\n\nDigite o seu email: ");
        gets(LOGIN.USUARIO);
        validaEmail = VALIDA_EMAIL(true,LOGIN.USUARIO);
    }while (validaEmail == false);

    //SENHA
    do{
        printf("\nDigite a senha: ");
        do{ 
            c=getch();

            //printf("\n\nValor= %c | %i",c, c);
            if(c!=13){
                if(isprint(c)){
                    senha[i]=c;
                    i++;
                    printf("*");
                    //strcpy(LOGIN.SENHA,senha);
                }else if(c==8&&i){
                    senha[i]='\0';
                    i--;
                    printf("\b \b");
                    //strcpy(LOGIN.SENHA,senha);
                }
            }

        }while(c!=13); 

        if(strlen(senha) == 0){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("A senha é obrigatória...\n\n");
        } 

    }while(strlen(senha) == 0);
    strcpy(LOGIN.SENHA,senha);
    printf("\nSenha: %s",LOGIN.SENHA);

    //NOME COMPLETO
    do{
        printf("\n\nDigite o nome: ");
        gets(LOGIN.NOME_COMPLETO);

        if(strlen(LOGIN.NOME_COMPLETO) == 0){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("O nome é obrigatório...\n\n");
        } 

    }while(strlen(LOGIN.NOME_COMPLETO) == 0);
    printf("Nome Completo: %s",LOGIN.NOME_COMPLETO);

    //CELULAR
    char CELULAR[15];
    boolean validaCelular;      
    do{
        validaCelular = true;
        printf("\n\nDigite o celular com DDD (somente números): ");
        gets(CELULAR);
        if(strlen(CELULAR) > 0){
            if(strlen(CELULAR) < 11 || strlen(CELULAR) > 11){ 
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Número de celular deve possuir 11 dígitos...\n\n");
                validaCelular = false;
            } else {
                for (i=0; i < strlen(CELULAR); i++) { 
                    if(isdigit(CELULAR[i]) == 0){ 
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Celular deve conter somente números de 0-9...\n\n");
                        validaCelular = false;
                        break;
                    } 
                }
            }     
        }  

    }while(validaCelular == false);
    strcpy(LOGIN.CELULAR,CELULAR);
    //printf("Celular: %s | %i",LOGIN.CELULAR);
      
    LOGIN.NIVEL = 2;
    LOGIN.STATUS = 1;
 
    do{
        printf("\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
        confirm = tolower(getche());

        if(confirm == 's'){
            arq = fopen(ARQ_LOGIN,"a+b");
            fwrite(&LOGIN,sizeof(LOGIN),1,arq);
            fclose(arq);
            printf("\n\nAcesso criado com sucesso...");
        }

    } while(confirm != 's' && confirm != 'n');

    arq = fopen(ARQ_LOGIN,"rb");
    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){

        printf("\n USUARIO %s",LOGIN.USUARIO);
        printf("\n NOME_COMPLETO %s",LOGIN.NOME_COMPLETO);
        printf("\n SENHA %s",LOGIN.SENHA);
        printf("\n CELULAR %s",LOGIN.CELULAR);
        printf("\n NIVEL %i",LOGIN.NIVEL);
        printf("\n STATUS %i\n\n ",LOGIN.STATUS);

    }
    fclose(arq);

    printf("\n\n");
    system("pause");

}
