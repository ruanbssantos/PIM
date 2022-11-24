//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //BIBLIOTECA PARA FUNÃÂÃÂÃÂÃÂES STRING
#include <locale.h> //CARACTER ESPECIAL DO PORTUGUES
#include <windows.h> //USAR COMANDOS DO WINDOWS
#include <time.h> //PEGAR DATA E HORA DO SISTEMA
#include <ctype.h> //CONTÃM FUNÃÃES DO TIPO BOOLEANN COMO ISDIGIT
#include <stdbool.h> //LÃ BOOLEANO
#include <conio.h>

typedef struct {
    char DH_COMPLETA[21];
    char DT_COMPLETA[11];
    char DIA[3];
    char MES[3];
    char ANO[5];
    char HORAS[3];
    char MINUTOS[3];
    char SEGUNDOS[3];
    char DIA_SEMANA[3];
}STRC_DH;

typedef struct {
    int ID;
    char USUARIO[100];
    char NOME_COMPLETO[100];
    char SENHA[100];
    char CELULAR[15];
    int NIVEL;
    int STATUS;

}STRC_LOGIN;

typedef struct {
    int ID;
    char NOME_ESPACO[100];
    char CAPACIDADE[100];
    char TP_ESPACO[100];
    char OBSERVACAO[100];
    int STATUS;

}STRC_ESPACO;

typedef struct {
    int ID;
    char ASSUNTO[100];
    int ESPACO_ID;
    int DAY_INICIO;
    int MONTH_INICIO;
    int YEAR_INICIO;
    int HOUR_INICIO;
    int MIN_INICIO;
    long long DH_INICIO;
    int DAY_FIM;
    int MONTH_FIM;
    int YEAR_FIM;
    int HOUR_FIM;
    int MIN_FIM;    
    long long DH_FINAL;
    int USUARIO_ID;
    int STATUS;  
    int AVALIACAO;
    char OBSERVACAO[100];
    
    STRC_LOGIN USUARIO;
    STRC_ESPACO ESPACO;

}STRC_AGENDAMENTO;

//VARIAVEIS DE COR
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_RESET "\033[0m"

//VARIAVEIS DE ARQUIVOS
#define ARQ_LOGIN "ARQUIVOS/Login.bin"
#define ARQ_ESPACO "ARQUIVOS/Espaco.bin"
#define ARQ_AGENDAMENTO "ARQUIVOS/Agendamentos.bin"

FILE *arq;
int session_usuarioID;
int session_nivelAcesso;

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
//CRIA LINHA DIVISORIA
void SEPARADOR(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, i, contador;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left;

    if (columns%2 != 0) columns--;

    contador = columns - 1;
    //linha inferior
    printf("╾");
    for (i = 1; i <= contador; i++){
        printf("┈");
    }
    printf("╼");
}
//BUSCA ULTIMO ID;
void BUSCAR_ID(char BANCO[],int *RETORNO){

    int ID;

    arq = fopen(BANCO,"rb");

    if(arq==NULL){
        *RETORNO = 1;
    } else {

        if (strcmp(ARQ_ESPACO,BANCO) == 0){
            STRC_ESPACO STRC_DEFAULT;
            while(fread(&STRC_DEFAULT, sizeof(STRC_DEFAULT), 1, arq)==1) {
                ID = STRC_DEFAULT.ID;
                ID++;
            }
        } else if (strcmp(ARQ_LOGIN,BANCO) == 0){
            STRC_LOGIN STRC_DEFAULT;
            while(fread(&STRC_DEFAULT, sizeof(STRC_DEFAULT), 1, arq)==1) {
                ID = STRC_DEFAULT.ID;
                ID++;
            }
        } else if (strcmp(ARQ_AGENDAMENTO,BANCO) == 0){
            STRC_AGENDAMENTO STRC_DEFAULT;
            while(fread(&STRC_DEFAULT, sizeof(STRC_DEFAULT), 1, arq)==1) {
                ID = STRC_DEFAULT.ID;
                ID++;
            }
        }

        *RETORNO = ID;
    }

    fclose(arq);

}
//FUNCAO PAARA SAIR DO SISTEMA;
void EXIT(){
    printf("\n\nObrigado pela visita, até mais...\n");
    exit(1);
}
//MSG DE RETORNO
void MSG_RETORNO(){
    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Para retornar, digite ""%s0%s"" a qualquer momento...\n",COLOR_YELLOW,COLOR_RESET);
}
//FORMATA DATA PARA BR
void FORMATA_DATA_HORA(char *retorno[],int year, int month, int day, int hour, int min) {
    char str_day[100],str_month[100],str_year[100],str_hour[100],str_min[100],resultado[100] = "";

    if (day != ""){
        sprintf(str_day, "%02d", day);
        strcat(resultado,str_day);
        strcat(resultado,"/");
    }
    if (month != ""){
        sprintf(str_month, "%02d", month);
        strcat(resultado,str_month);
        strcat(resultado,"/");
    }
    if (year != ""){
        sprintf(str_year, "%04d", year);
        strcat(resultado,str_year);
        strcat(resultado," - ");
    }
    if (hour != ""){
        sprintf(str_hour, "%02d", hour);
        strcat(resultado,str_hour);
        strcat(resultado,":");
    }
    if (min != ""){
        sprintf(str_min, "%02d", min);
        strcat(resultado,str_min);
    }

    strcpy(retorno,resultado);
}
//PREPARA DATA ENTRADA USUÁRIO
void PREPARA_ENTRADA_DATA(char buscar[],int *dt){
    char *SPLIT;
    int i;

    SPLIT = strtok(buscar, "/");
    i = 0;
    while (SPLIT != NULL) {
        if ((i == 0 && strlen(SPLIT) == 2) || (i == 1 && strlen(SPLIT) == 2) || (i == 2 && strlen(SPLIT) == 4)){
            dt[i] = atoi(SPLIT);
        } else {
            dt[i] = 0;
        }
        i++;
        SPLIT = strtok(NULL, "/");
    }

}
//PREPARA DH STRUCT LONG - SAIDA
void PREPARA_DATA_STRC(long long *retorno,int year, int month, int day, int hour, int min){

    //printf("\n\n%d | %d | %d | %d | %d", year,month,day,hour,min);
    char str_day[100],str_month[100],str_year[100],str_hour[100],str_min[100],resultado[100] = "";
    char *eptr;

    if (year != ""){
        sprintf(str_year, "%04d", year);
        strcat(resultado,str_year);
    }
    if (month != ""){
        sprintf(str_month, "%02d", month);
        strcat(resultado,str_month);
    }
    if (day != ""){
        sprintf(str_day, "%02d", day);
        strcat(resultado,str_day);
    }
    if (hour != ""){
        sprintf(str_hour, "%02d", hour);
        strcat(resultado,str_hour);
    }
    if (min != ""){
        sprintf(str_min, "%02d", min);
        strcat(resultado,str_min);
    }

    *retorno = strtoll(resultado, &eptr, 10);
    //STRING PARA LONG LONG
    //printf("\n\nCONVERSÃO: %lld", *retorno);

}
//PREPARA DATA ENTRADA USUÁRIO
void PREPARA_ENTRADA_HORA(char buscar[],int *hr){
    char *SPLIT;
    int i;

    SPLIT = strtok(buscar, ":");
    i = 0;
    while (SPLIT != NULL) {
        if ((i == 0 && strlen(SPLIT) == 2) || (i == 1 && strlen(SPLIT) == 2)){
            hr[i] = atoi(SPLIT);
        } else {
            hr[i] = 0;
        }
        i++;
        SPLIT = strtok(NULL, ":");
    }

}
//=======================================================================================================
//FUNCTIONS VALIDAÇÃO
//=======================================================================================================
void LOGIN_VALIDA_ACESSO(boolean *session){

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
            session_usuarioID = LOGIN.ID;
            session_nivelAcesso = LOGIN.NIVEL;
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
        } else {
            STRC_LOGIN LOGIN;
            arq = fopen(ARQ_LOGIN,"rb");
            if(arq  != NULL) {
                while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
                    if (strcmp(email,LOGIN.USUARIO) == 0 ){
                        emailValidado_fl = false;
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("E-mail já cadastrado na base de dados...\n\n");
                        break;
                    }

                }
            }
            fclose(arq);
        }

    }

    return emailValidado_fl;
}
int VALIDA_ENTRADA_NUMERO(){
    char op[100];
    scanf("%s",op);
    fflush(stdin);
    for (int i=0; i < strlen(op); i++) {
        if(isdigit(op[i]) == 0){
            return -1;
            break;
        }
    }
    return atoi(op);
}
int VALIDA_ENTRADA_DATA(int d, int m, int y){
    //VALIDA ANO
    if (y >= 1800 && y <= 2999) {
        //VALIDA MES
        if (m >= 1 && m <= 12) {
            //VALIDA DIA
            if (d >= 1 && d <= 31) {
                if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return 1; //VALIDA DIA QUANDO OS MESES FOR (ABRIL/JUNHO/SETEMBRO/NOVEMBRO) = 30 DIAS
                else if ((d >= 1 && d <= 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return 1; //VALIDA DIA QUANDO OS MESES FOR (JANEIRO/MARÇO/MAIO/JULHO/AGOSTO/OUTUBRO/DEZEMBRO) = 31 DIAS
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return 1; //VALIDA DIA QUANDO O MES FOR FEVEREIRO E O ANO NÃO FOR BISSEXTO
                else if (d == 29 && m == 2 &&  ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 100 == 0 && y % 400 == 0)))
                    return 1; //VALIDA DIA QUANDO O MES FOR FEVEREIRO E O ANO FOR BISSEXTO (REGRA: MICROSOFT > https://learn.microsoft.com/pt-br/office/troubleshoot/excel/determine-a-leap-year)
                else
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Data digitada inválida...\n\n");
                    return 0;
            } else {
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Dia digitado inválido...\n\n");
                return 0;
            }
        } else {
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("Mês digitado inválido...\n\n");
            return 0;
        }
    } else {
        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
        printf("Ano digitado inválido...\n\n");
        return 0;
    }
}
int VALIDA_ENTRADA_HORA(int hour, int min){
    //VALIDA ANO
    if (hour >= 0 && hour <= 23) {
        if (min >= 0 && min <= 59){
            return 1;
        } else {
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("Minutos digitado inválido...\n\n");
            return 0;
        }
    } else {
        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
        printf("Hora digitada inválido...\n\n");
        return 0;
    }
}
int VALIDA_MASCARA_HORA(char buscar[]){
    int count = 0;
    for (int i=0; i < strlen(buscar); i++){
        if(buscar[i] != ':') {
            if (isdigit(buscar[i]) == 0) return 0;
        } else {
            count++;
        }
    }

    if (count == 1) return 1;
    else return 0;
}
//=======================================================================================================
//MENUS
//=======================================================================================================
void MENU_PRINCIPAL(){
    int op;

    do{
        CABECALHO();
        printf("%sMenu inicial%s\n\n",COLOR_GREEN,COLOR_RESET);

        if (session_nivelAcesso == 2){
            printf("[%s1%s] - Colaboradores\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Espaços\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s3%s] - Agendamentos\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s4%s] - Relatórios\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s5%s] - Alterar senha\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s0%s] - Sair",COLOR_YELLOW,COLOR_RESET);

            printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            op = VALIDA_ENTRADA_NUMERO();

            switch(op)
            {
                case 1:
                    MENU_USUARIOS();
                    break;
                case 2:
                    MENU_ESPACOS();
                    break;
                case 3:
                    MENU_AGENDAMENTOS();
                    break;
                case 4:
                    MENU_RELATORIOS();
                    break;
                case 5:
                    ALTERAR_SENHA();
                    break;
                case 0:
                    EXIT();
                    break;
                default:
                    printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }

        } else {

            printf("[%s1%s] - Agendamentos\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Alterar senha\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s0%s] - Sair",COLOR_YELLOW,COLOR_RESET);

            printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            op = VALIDA_ENTRADA_NUMERO();

            switch(op)
            {
                case 1:
                    MENU_AGENDAMENTOS();
                    break;
                case 2:
                    ALTERAR_SENHA();
                    break;
                case 0:
                    EXIT();
                    break;
                default:
                    printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }
        }

    }while(op!=0);

    return;
}
void MENU_USUARIOS(){
    int op;
    boolean cadastroFinalizado;

    do{
        CABECALHO();
        printf("%sMenu inicial >%s %sColaboradores%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Cadastrar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Pesquisar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Alterar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha uma opção acima: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1:
                CADASTRA_USUARIO(false, &cadastroFinalizado);
                break;
            case 2:
                SUB_MENU_USUARIOS();
                break;
            case 3:
                ALTERAR_USUARIO(true);
                break;
            case 0:
                MENU_PRINCIPAL();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
            }

    }while(op!=0);

    return;
}
void MENU_ESPACOS(){
    int op;

    do{
        CABECALHO();
        printf("%sMenu inicial >%s %sEspaços%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Cadastrar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Pesquisar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Alterar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha uma opção acima: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1:
                CADASTRA_ESPACO();
                break;
            case 2:
                SUB_MENU_ESPACOS();
                break;
            case 3:
                ALTERAR_ESPACO(true);
                break;
            case 0:
                MENU_PRINCIPAL();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(op!=0);
    return;
}
void MENU_AGENDAMENTOS(){
    int op;

    do{
        CABECALHO();
        printf("%sMenu inicial >%s %sAgendamentos%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Solicitar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Check-in\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Check-out\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s4%s] - Cancelamento\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s5%s] - Histórico\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha uma opção acima: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1:
                CADASTRA_AGENDAMENTO();
                break;
            case 2:
                LISTAR_AGENDAMENTOS(2,1,2);
                break;
            case 3:
                LISTAR_AGENDAMENTOS(3,2,3);
                break;
            case 4:
                LISTAR_AGENDAMENTOS(4,NULL,4);
                break;
            case 5:
                LISTAR_AGENDAMENTOS(5,NULL,NULL);
                break;
            case 0:
                MENU_PRINCIPAL();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
            }

    }while(op!=0);

    return;
}
void MENU_RELATORIOS(){
    int op;
    do{
        CABECALHO();
        printf("%sMenu inicial >%s %sRelatórios%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Detalhado\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Ranking espaço\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha o filtro desejado: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1:
                SUB_MENU_RELATORIOS();
                break;
            case 2:
                REL_RANKING_AGENDAMENTOS();
                break;
            case 0:
                MENU_PRINCIPAL();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(op!=0);
    return 0;
}
//=======================================================================================================
//SUB-MENUS
//=======================================================================================================
void SUB_MENU_USUARIOS(){
    int op;
    do{
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sPesquisar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Nome\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - E-mail\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Todos\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha o filtro desejado: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1: case 2: case 3:
                LISTAR_USUARIOS(op);
                break;
            case 0:
                MENU_USUARIOS();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(op!=0);
    return 0;
}
void SUB_MENU_ESPACOS(){
    int op;
    do{
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sPesquisar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Nome\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Tipo\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Todos\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha o filtro desejado: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1: case 2: case 3:
                LISTAR_ESPACO(op);
                break;
            case 0:
                MENU_ESPACOS();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(op!=0);
    return 0;
}
void SUB_MENU_RELATORIOS(){
    int op;
    do{
        CABECALHO();
        printf("%sMenu inicial > Relatórios >%s %sDetalhado%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Código do colaborador solicitante\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Código do agendamento\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Código/nome do espaço\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s4%s] - Agendados\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s5%s] - Em andamento\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s6%s] - Finalizados\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s7%s] - Cancelado\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s8%s] - Todos\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha o filtro desejado: ");
        op = VALIDA_ENTRADA_NUMERO();

        switch(op)
        {
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
                REL_DETALHADO_AGENDAMENTOS(op);
                break;
            case 0:
                MENU_RELATORIOS();
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(op!=0);
    return 0;
}
//=======================================================================================================
//COLABORADORES
//=======================================================================================================
void CADASTRA_USUARIO(boolean fl_primeiroAcesso, boolean *cadastroFinalizado){
    CABECALHO();
    printf("%sMenu inicial > Colaboradores >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

    *cadastroFinalizado = false;

    STRC_LOGIN LOGIN;

    char confirm;

    if(fl_primeiroAcesso == true){
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Primeiro acesso detectado, o primeiro cadastro será concedido nível administrativo...\n");
        system("pause");
        printf("\n");
    } else {
        MSG_RETORNO();
    }

    //EMAIL
    if (VALIDA_DADOS_USUARIO("EMAIL",&LOGIN) == false) return 0;

    //EMAIL
    if (VALIDA_DADOS_USUARIO("SENHA",&LOGIN) == false) return 0;

    //NOME COMPLETO
    if (VALIDA_DADOS_USUARIO("NOMECOMPLETO",&LOGIN) == false) return 0;

    //CELULAR
    if (VALIDA_DADOS_USUARIO("CELULAR",&LOGIN) == false) return 0;

    //NIVEL
    if(fl_primeiroAcesso == true) {
        LOGIN.NIVEL = 2;
    } else {
        if (VALIDA_DADOS_USUARIO("NIVEL",&LOGIN) == false) return 0;
    }

    //STATUS SEMPRE ATIVO
    LOGIN.STATUS = 1;

    do{
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

        printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.NOME_COMPLETO);
        printf("\n\n%sEmail:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.USUARIO);
        printf("\n\n%sCelular:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.CELULAR);
        printf("\n\n%sNível:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.NIVEL==1?"Comum":"Administrativo");
        //printf("\n\n%sSenha:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.SENHA);

        do{
            printf("\n\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        } while(confirm != 's' && confirm != 'n');

        if(confirm == 's'){
            BUSCAR_ID(ARQ_LOGIN,&LOGIN.ID);
            arq = fopen(ARQ_LOGIN,"a+b");
            fwrite(&LOGIN,sizeof(LOGIN),1,arq);
            fclose(arq);
            printf("\n\nColaborador criado com sucesso...");
            *cadastroFinalizado = true;
        }

    } while(confirm != 's' && confirm != 'n');

    printf("\n\n");
    system("pause");
    return 0;

}
void LISTAR_USUARIOS(int op){

    STRC_LOGIN LOGIN;
    int count_usuario;
    char buscar[100];
    char tipoPesquisa[100];
    char confirm;
    int i;

    if (op == 1) strcpy(tipoPesquisa,"Nome");
    else if(op == 2) strcpy(tipoPesquisa,"E-mail");
    else strcpy(tipoPesquisa,"Todos");

    do{
        count_usuario = 0;
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sPesquisar - %s%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,tipoPesquisa,COLOR_RESET);
        MSG_RETORNO();

        arq = fopen(ARQ_LOGIN,"rb");

        if(op != 3){
            printf("\nDigite o %s: ", op==1?"nome":"e-mail");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
        }

        while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){

            if (op == 1) {
                if(strcmp(strupr(buscar),LOGIN.NOME_COMPLETO) == 0){
                    PRINTAR_USUARIO(&LOGIN);
                    count_usuario++;
                }
            } else if (op == 2){
                if(strcmp(buscar,LOGIN.USUARIO) == 0){
                    PRINTAR_USUARIO(&LOGIN);
                    count_usuario++;
                }
            } else {
                PRINTAR_USUARIO(&LOGIN);
                count_usuario++;
            }
        }
        fclose(arq);

        if(count_usuario == 0){
            printf("\n%sAviso!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Nenhum colaborador encontrado!");
            confirm = 'n';
        } else {
            do{
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Deseja alterar algum colaborador?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                confirm = tolower(getche());
            } while(confirm != 's' && confirm != 'n');
        }

        if(confirm == 's'){
            ALTERAR_USUARIO(0);
        } else {
            do{
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Deseja realizar uma nova consulta?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                confirm = tolower(getche());
            } while(confirm != 's' && confirm != 'n');
        }

    } while(confirm == 's');

    return 0;
}
void ALTERAR_USUARIO(boolean fl_criaCabecalho){
    STRC_LOGIN LOGIN;
    char buscar[100],STR_ID[100];
    int count_usuario = 0,op,posicaoArq = 0;
    boolean validaAlteracao;

    if(fl_criaCabecalho == 1){
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        MSG_RETORNO();
    } else {
        printf("\n\n");
    }

    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Digite o e-mail ou código do colaborador que deseja alterar: ");
    gets(buscar);

    arq = fopen(ARQ_LOGIN,"rb");

    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
        sprintf(STR_ID,"%d",LOGIN.ID);
        if(strcmp(buscar,LOGIN.USUARIO) == 0 || strcmp(buscar,STR_ID) == 0){
            count_usuario++;
            do{
                validaAlteracao = false;
                CABECALHO();
                printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
                MSG_RETORNO();

                printf("\n[%s1%s] - %sNome:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NOME_COMPLETO);
                printf("\n[%s2%s] - %sEmail:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.USUARIO);
                printf("\n[%s3%s] - %sCelular:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.CELULAR);
                printf("\n[%s4%s] - %sNível:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NIVEL==1?"Comum":"Administrativo");
                printf("\n[%s5%s] - %sStatus:%s %s%s%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.STATUS==1?COLOR_GREEN:COLOR_RED,LOGIN.STATUS==1?"Ativo":"Inativo",COLOR_RESET);
                printf("\n[%s6%s] - %sSenha%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);
                printf("\n[%s0%s] - %sVoltar%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);

                printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Escolha uma opção acima: ");
                op = VALIDA_ENTRADA_NUMERO();

                switch(op)
                {
                    case 1:
                        //VALIDA NOME USUÁRIO
                        if (VALIDA_DADOS_USUARIO("NOMECOMPLETO",&LOGIN) == true) validaAlteracao = true;
                        break;
                    case 2:
                        //VALIDA EMAIL
                        if (VALIDA_DADOS_USUARIO("EMAIL",&LOGIN) == true) validaAlteracao = true;
                        break;
                    case 3:
                        //VALIDA CELULAR
                        if (VALIDA_DADOS_USUARIO("CELULAR",&LOGIN) == true) validaAlteracao = true;
                        break;
                    case 4:
                        //VALIDA NÍVEL
                        if (VALIDA_DADOS_USUARIO("NIVEL",&LOGIN) == true) validaAlteracao = true;
                        break;
                    case 5:
                        //VALIDA STATUS
                        if (VALIDA_DADOS_USUARIO("STATUS",&LOGIN) == true) validaAlteracao = true;
                        break;
                    case 6:
                        //VALIDA SENHA
                        if (VALIDA_DADOS_USUARIO("SENHA",&LOGIN) == true) validaAlteracao = true;
                        printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                        printf("Senha alterada com sucesso...\n\n");
                        system("pause");
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                        system("pause");
                        break;
                }

                //ALTERA QUANDO LIBERADO
                if (validaAlteracao == true){
                    arq = fopen(ARQ_LOGIN,"r+b");
                    fseek(arq, posicaoArq, SEEK_SET);  //DEFINE O DESLOCAMENTO PARA ONDE ENCONTROU OS DADOS;
                    fwrite(&LOGIN,sizeof(STRC_LOGIN),1,arq) == sizeof(STRC_LOGIN); //REESCREVE OS DADOS  NO ARQUIVO;
                    fclose(arq);
                }

            }while(op!=0);
        }
        posicaoArq = posicaoArq + sizeof(STRC_LOGIN);
        fseek(arq, posicaoArq, SEEK_SET);
    }

    fclose(arq);

    if (count_usuario == 0){
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Nenhum coloborador encontrado...");
        printf("\n\n"); 
        system("pause");
    }

}
int VALIDA_DADOS_USUARIO(char campo[],STRC_LOGIN *STRC_RETORNO){
    int i=0;
    STRC_LOGIN LOGIN;

    if (strcmp("NOMECOMPLETO",campo) == 0){
        //NOME COMPLETO
        int count_espacoBranco, count_numeros;
        boolean validaNome = false;
        do{
            count_espacoBranco = 0, count_numeros = 0;
            printf("\n\nDigite o nome completo: ");
            gets(LOGIN.NOME_COMPLETO);
            if(strlen(LOGIN.NOME_COMPLETO) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O nome é obrigatório...\n\n");
            } else if(strlen(LOGIN.NOME_COMPLETO) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(LOGIN.NOME_COMPLETO,"0") == 0) return 0;
                for (i=0; i < strlen(LOGIN.NOME_COMPLETO); i++) {
                    if(isalpha(LOGIN.NOME_COMPLETO[i]) == 0){
                        if(LOGIN.NOME_COMPLETO[i] == ' ') count_espacoBranco++;
                        else{
                            count_numeros++;
                            break;
                        }
                    } else {
                        LOGIN.NOME_COMPLETO[i] = toupper(LOGIN.NOME_COMPLETO[i]);
                    }
                }

                if(isalpha(LOGIN.NOME_COMPLETO[strlen(LOGIN.NOME_COMPLETO)-1]) == 0) count_espacoBranco = 0;

                if(count_numeros > 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Nome deve conter somente letras de A-Z...\n");
                }else if(count_espacoBranco == 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Nome inválido, digite o nome completo...\n");
                }else{
                    validaNome = true;
                }
            }

        }while(validaNome == false);
        strcpy(STRC_RETORNO->NOME_COMPLETO,LOGIN.NOME_COMPLETO);

    } else if (strcmp("CELULAR",campo) == 0){
        //CELULAR
        char CELULAR[15];
        boolean validaCelular;
        do{
            validaCelular = true;
            printf("\nDigite o celular com DDD (somente números): ");
            gets(LOGIN.CELULAR);

            if(strlen(LOGIN.CELULAR) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            }else if(strlen(LOGIN.CELULAR) > 0){
                if(strcmp(LOGIN.CELULAR,"0") == 0) return 0;
                if(strlen(LOGIN.CELULAR) < 11 || strlen(LOGIN.CELULAR) > 11){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Número de celular deve possuir 11 dígitos...\n\n");
                    validaCelular = false;
                } else {
                    for (i=0; i < strlen(LOGIN.CELULAR); i++) {
                        if(isdigit(LOGIN.CELULAR[i]) == 0){
                            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                            printf("Celular deve conter somente números de 0-9...\n\n");
                            validaCelular = false;
                            break;
                        }
                    }
                }
            }

        }while(validaCelular == false);
        strcpy(STRC_RETORNO->CELULAR,LOGIN.CELULAR);

    } else if(strcmp("EMAIL",campo) == 0){
        //EMAIL
        boolean validaEmail = false;
        do{
            printf("\nDigite o email: ");
            gets(LOGIN.USUARIO);
            if(strlen(LOGIN.USUARIO) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(LOGIN.USUARIO,"0") == 0) return 0;
                validaEmail = VALIDA_EMAIL(true,LOGIN.USUARIO);
            }
        }while (validaEmail == false);
        strcpy(STRC_RETORNO->USUARIO,LOGIN.USUARIO);

    } else if(strcmp("NIVEL",campo) == 0){
        //NÍVEL
        boolean validaNivel;
        do{
            printf("\nEscolha o tipo de colaborador:\n");
            printf("[%s1%s] - Comum\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Administrativo\n",COLOR_YELLOW,COLOR_RESET);

            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            LOGIN.NIVEL = VALIDA_ENTRADA_NUMERO();

            switch(LOGIN.NIVEL)
            {
                case 1: case 2:
                    validaNivel = true;
                    break;
                case 0:
                    return 0;
                default:
                    validaNivel = false;
                    printf("\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }
        }while(validaNivel == false);
        STRC_RETORNO->NIVEL = LOGIN.NIVEL;

    } else if(strcmp("STATUS",campo) == 0){
        //STATUS
        boolean validaStatus;
        do{
            printf("\nEscolha o status do colaborador:\n");
            printf("[%s1%s] - Ativo\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Inativo\n",COLOR_YELLOW,COLOR_RESET);

            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            LOGIN.STATUS = VALIDA_ENTRADA_NUMERO();

            switch(LOGIN.STATUS)
            {
                case 1:
                    validaStatus = true;
                    break;
                case 2:
                    LOGIN.STATUS = 0;
                    validaStatus = true;
                    break;
                case 0:
                    return 0;
                default:
                    validaStatus = false;
                    printf("\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }
        }while(validaStatus == false);
        STRC_RETORNO->STATUS = LOGIN.STATUS;

    } else if(strcmp("SENHA",campo) == 0){
        //SENHA
        char senha[100]="", confirmaSenha[100]="", caracter;
        boolean validaSenha = false;
        do{
            i = 0;
            printf("\nDigite a senha: ");
            do{
                caracter=getch();
                if(caracter!=13){
                    if(isprint(caracter)){
                        senha[i]=caracter;
                        i++;
                        printf("*");
                    }else if(caracter==8&&i){
                        senha[i]='\0';
                        i--;
                        printf("\b \b");
                    }
                }

            }while(caracter!=13);

            if(strlen(senha) == 0){
                printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("A senha é obrigatória...\n\n");
            } else {
                if(strcmp(senha,"0") == 0) return 0;

                i = 0;
                printf("\n\nConfirme a senha: ");
                do{
                    caracter=getch();
                    if(caracter!=13){
                        if(isprint(caracter)){
                            confirmaSenha[i]=caracter;
                            i++;
                            printf("*");
                        }else if(caracter==8&&i){
                            confirmaSenha[i]='\0';
                            i--;
                            printf("\b \b");
                        }
                    }

                }while(caracter!=13);
                if(strcmp(confirmaSenha,"0") == 0) return 0;

                if(strcmp(senha,confirmaSenha) != 0 ){
                    printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("As senhas são diferentes...\n\n");
                    //LIMPAR ARRAY
                    memset(senha, 0, 100);
                    memset(confirmaSenha, 0, 100);
                } else {
                    validaSenha = true;
                }
            }

        }while(validaSenha == false);
        strcpy(STRC_RETORNO->SENHA,senha);
    }
    return 1;
}
void PRINTAR_USUARIO(STRC_LOGIN *USER){
    printf("\n%sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,USER->ID);
    printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,USER->NOME_COMPLETO);
    printf("\n%sEmail:%s %s",COLOR_CYAN,COLOR_RESET,USER->USUARIO);
    printf("\n%sCelular:%s %s",COLOR_CYAN,COLOR_RESET,USER->CELULAR);
    printf("\n%sNível:%s %s",COLOR_CYAN,COLOR_RESET,USER->NIVEL==1?"Comum":"Administrativo");
    //printf("\n%sSenha:%s %s",COLOR_CYAN,COLOR_RESET,USER->SENHA);
    printf("\n%sStatus:%s %s%s%s\n\n",COLOR_CYAN,COLOR_RESET,USER->STATUS==1?COLOR_GREEN:COLOR_RED,USER->STATUS==1?"Ativo":"Inativo",COLOR_RESET);
    SEPARADOR();
    printf("\n");
}
void ALTERAR_SENHA(){

    STRC_LOGIN LOGIN;
    int count_usuario = 0,posicaoArq = 0;
    boolean validaAlteracao = false;
    char confirm;

    CABECALHO();
    printf("%sMenu inicial > Colaboradores >%s %sAlterar senha%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    MSG_RETORNO();

    arq = fopen(ARQ_LOGIN,"rb");
    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
        if(session_usuarioID == LOGIN.ID){
            count_usuario++;
            if (VALIDA_DADOS_USUARIO("SENHA",&LOGIN) == true) validaAlteracao = true;
            else return 0;

            do{
                printf("\n\n\nDeseja realmente alterar? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                confirm = tolower(getche());
            } while(confirm != 's' && confirm != 'n');

            if (validaAlteracao == true && confirm == 's') {
                arq = fopen(ARQ_LOGIN,"r+b");
                fseek(arq, posicaoArq, SEEK_SET);  //DEFINE O DESLOCAMENTO PARA ONDE ENCONTROU OS DADOS;
                fwrite(&LOGIN,sizeof(STRC_LOGIN),1,arq) == sizeof(STRC_LOGIN); //REESCREVE OS DADOS  NO ARQUIVO;
                fclose(arq);
            } else {
                validaAlteracao = false;
            }

            break;
        }
        posicaoArq = posicaoArq + sizeof(STRC_LOGIN);
        fseek(arq, posicaoArq, SEEK_SET);
    }
    fclose(arq);

    if (count_usuario == 0){
        printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
        printf("Houve um erro inesperado, por favor tente novamente mais tarde...\n\n");
        system("pause");
        exit(1);
    } else if (validaAlteracao == true){
        printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Alteração realizada com sucesso...\n\n");
        system("pause");
    }

}
//=======================================================================================================
//ESPAÇO
//=======================================================================================================
void CADASTRA_ESPACO(){

    CABECALHO();
    printf("%sMenu inicial > Espaços >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    MSG_RETORNO();

    STRC_ESPACO ESPACO;
    char confirm; 

    //NOME COMPLETO
    if (VALIDA_DADOS_ESPACO("NOME_ESPACO",&ESPACO) == false) return 0;

    //CAPACIDADE
    if (VALIDA_DADOS_ESPACO("CAPACIDADE",&ESPACO) == false) return 0;

    //TIPO DE ESPACO
    if (VALIDA_DADOS_ESPACO("TP_ESPACO",&ESPACO) == false) return 0;

    //OBSERVACAO
    if (VALIDA_DADOS_ESPACO("OBSERVACAO",&ESPACO) == false) return 0;

    //STATUS
    if (VALIDA_DADOS_ESPACO("STATUS",&ESPACO) == false) return 0;

    do{
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        MSG_RETORNO();

        printf("\n%sNome do espaço:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO.NOME_ESPACO);
        printf("\n\n%sCapidade:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO.CAPACIDADE);
        printf("\n\n%sTipo de espaço:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO.TP_ESPACO);
        printf("\n\n%sObservação:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO.OBSERVACAO);
        printf("\n\n%sStatus:%s %s%s%s",COLOR_CYAN,COLOR_RESET,ESPACO.STATUS==1?COLOR_GREEN:COLOR_RED,ESPACO.STATUS==1?"Ativo":"Inativo",COLOR_RESET);

        do{
            printf("\n\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        } while(confirm != 's' && confirm != 'n');

        if(confirm == 's'){
            BUSCAR_ID(ARQ_ESPACO,&ESPACO.ID);
            arq = fopen(ARQ_ESPACO,"a+b");
            fwrite(&ESPACO,sizeof(ESPACO),1,arq);
            fclose(arq);
            printf("\n\nEspaço criado com sucesso...");
        }

    } while(confirm != 's' && confirm != 'n');

    printf("\n\n");
    system("pause");
    return 0;

}
void LISTAR_ESPACO(int op){
    STRC_ESPACO ESPACO;
    int count = 0, i;
    char tipoPesquisa[100],confirm,buscar[100];

    if (op == 1) strcpy(tipoPesquisa,"Nome");
    else if(op == 2) strcpy(tipoPesquisa,"Tipo");
    else strcpy(tipoPesquisa,"Todos");

    do{
        count = 0;
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sPesquisar - %s%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,tipoPesquisa,COLOR_RESET);
        MSG_RETORNO();

        arq = fopen(ARQ_ESPACO,"rb");

        if(op != 3){
            printf("\nDigite o %s: ", op==1?"nome":"tipo");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
        }

        while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){

            if (op == 1 ) {
               if(strcmp(strupr(buscar),ESPACO.NOME_ESPACO) == 0){
                   PRINTAR_ESPACO(&ESPACO,0);
                   count++;
               }
            } else if (op == 2){
               if(strcmp(strupr(buscar),ESPACO.TP_ESPACO) == 0){
                   PRINTAR_ESPACO(&ESPACO,0);
                   count++;
               }
            } else {
               PRINTAR_ESPACO(&ESPACO,0);
               count++;
            }
        }
        fclose(arq);

        if(count == 0){
            printf("\n%sAviso!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Nenhum espaço encontrado!");
            confirm = 'n';
        } else {
            do{
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Deseja alterar algum espaço?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                confirm = tolower(getche());
            } while(confirm != 's' && confirm != 'n');
        }

        if(confirm == 's'){
            ALTERAR_ESPACO(0);
        } else {
            do{
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Deseja realizar uma nova consulta?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                confirm = tolower(getche());
            } while(confirm != 's' && confirm != 'n');
        }

    } while(confirm == 's');

    return 0;
}
void ALTERAR_ESPACO(boolean fl_criaCabecalho){
    STRC_ESPACO ESPACO;
    char buscar[100], STR_ID[100];
    int i,count = 0,op,posicaoArq = 0;
    boolean validaAlteracao;

    if(fl_criaCabecalho == 1){
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        MSG_RETORNO();
    } else {
        printf("\n\n");
    }

    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Digite o código ou nome do espaço: ");
    gets(buscar);

    arq = fopen(ARQ_ESPACO,"rb");
    while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){
        sprintf(STR_ID,"%d",ESPACO.ID);
        if(strcmp(strupr(buscar),STR_ID) == 0 || strcmp(strupr(buscar),ESPACO.NOME_ESPACO) == 0){
            fclose(arq);
            count++;
            do{
                validaAlteracao = false;
                CABECALHO();
                printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
                MSG_RETORNO();

                printf("\n[%s1%s] - %sNome:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.NOME_ESPACO);
                printf("\n[%s2%s] - %sCapacidade:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.CAPACIDADE);
                printf("\n[%s3%s] - %sTipo:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.TP_ESPACO);
                printf("\n[%s4%s] - %sObservacao:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.OBSERVACAO);
                printf("\n[%s5%s] - %sStatus:%s %s%s%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.STATUS==1?COLOR_GREEN:COLOR_RED,ESPACO.STATUS==1?"Ativo":"Inativo",COLOR_RESET);
                printf("\n[%s0%s] - %sVoltar%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);

                printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Escolha uma opção acima: ");
                op = VALIDA_ENTRADA_NUMERO();

                switch(op)
                {
                    case 1:
                        //VALIDA NOME
                        if (VALIDA_DADOS_ESPACO("NOME_ESPACO",&ESPACO) == true) validaAlteracao = true;
                        break;
                    case 2:
                        //VALIDA CAPACIDADE
                        if (VALIDA_DADOS_ESPACO("CAPACIDADE",&ESPACO) == true) validaAlteracao = true;
                        break;
                    case 3:
                        //VALIDA TIPO
                        if (VALIDA_DADOS_ESPACO("TP_ESPACO",&ESPACO) == true) validaAlteracao = true;
                        break;
                    case 4:
                        //VALIDA OBSERVACAO
                        if (VALIDA_DADOS_ESPACO("OBSERVACAO",&ESPACO) == true) validaAlteracao = true;
                        break;
                    case 5:
                        //VALIDA STATUS
                        if (VALIDA_DADOS_ESPACO("STATUS",&ESPACO) == true) validaAlteracao = true;
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                        system("pause");
                        break;
                }

                //ALTERA QUANDO LIBERADO
                if (validaAlteracao == true){
                    arq = fopen(ARQ_ESPACO,"r+b");
                    fseek(arq, posicaoArq, SEEK_SET);  //DEFINE O DESLOCAMENTO PARA ONDE ENCONTROU OS DADOS;
                    fwrite(&ESPACO,sizeof(STRC_ESPACO),1,arq) == sizeof(STRC_ESPACO); //REESCREVE OS DADOS  NO ARQUIVO;
                    fclose(arq);
                }

            }while(op!=0);
        }
        posicaoArq = posicaoArq + sizeof(STRC_ESPACO);
        fseek(arq, posicaoArq, SEEK_SET);
    }

    fclose(arq);

    if (count == 0){
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Nenhum coloborador encontrado...");
        printf("\n\n"); 
        system("pause");
    }


}
int VALIDA_DADOS_ESPACO(char campo[],STRC_ESPACO *STRC_RETORNO){
    STRC_ESPACO ESPACO;
    boolean valida, validaAux;
    int i;
    if (strcmp("NOME_ESPACO",campo) == 0){
        //NOME DO ESPAÇO
        do{
            valida = false;
            printf("\n\nDigite o nome do espaço: ");
            gets(ESPACO.NOME_ESPACO);
            if(strlen(ESPACO.NOME_ESPACO) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O nome do espaço é obrigatório...\n\n");
            } else if(strlen(ESPACO.NOME_ESPACO) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(ESPACO.NOME_ESPACO,"0") == 0) return 0;
                else{
                    for (i=0; i < strlen(ESPACO.NOME_ESPACO); i++) {
                        ESPACO.NOME_ESPACO[i] = toupper(ESPACO.NOME_ESPACO[i]);
                    }

                    validaAux = true;

                    STRC_ESPACO ESPACO_BUSCA;
                    arq = fopen(ARQ_ESPACO,"rb");
                    if(arq  != NULL) {
                        while(fread(&ESPACO_BUSCA, sizeof(ESPACO_BUSCA), 1, arq)){
                            if (strcmp(ESPACO.NOME_ESPACO,ESPACO_BUSCA.NOME_ESPACO) == 0 ){
                                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                                printf("Nome já cadastrado na base de dados...\n\n");
                                validaAux = false;
                                break;
                            }

                        }
                    }
                    fclose(arq);

                    if (validaAux == true) valida = true;
                }
            }

        }while(valida == false);
        strcpy(STRC_RETORNO->NOME_ESPACO,ESPACO.NOME_ESPACO);

    } else if(strcmp("CAPACIDADE",campo) == 0){
        //CAPACIDADE
        printf("\n\nDigite a capacidade total: ");
        gets(ESPACO.CAPACIDADE);
        if(strlen(ESPACO.CAPACIDADE) > 90){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("Tamanho máximo de 90 caracteres...\n\n");
        } else {
            if(strcmp(ESPACO.CAPACIDADE,"0") == 0) return 0;
            strcpy(STRC_RETORNO->CAPACIDADE,ESPACO.CAPACIDADE);
        }

    } else if(strcmp("TP_ESPACO",campo) == 0){
        //TIPO DE ESPACO
        do{
            valida = false;
            printf("\n\nDigite o tipo de espaço: ");
            gets(ESPACO.TP_ESPACO);
            if(strlen(ESPACO.TP_ESPACO) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O tipo de espaço é obrigatório...\n\n");
            } else if(strlen(ESPACO.NOME_ESPACO) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(ESPACO.TP_ESPACO,"0") == 0) return 0;
                else{
                    for (i=0; i < strlen(ESPACO.TP_ESPACO); i++) {
                        ESPACO.TP_ESPACO[i] = toupper(ESPACO.TP_ESPACO[i]);
                    }
                    valida = true;
                }
            }

        }while(valida == false);
        strcpy(STRC_RETORNO->TP_ESPACO,ESPACO.TP_ESPACO);

    } else if(strcmp("OBSERVACAO",campo) == 0){
        //OBSERVACAO
        printf("\n\nDigite a observação: ");
        gets(ESPACO.OBSERVACAO);
        if(strlen(ESPACO.OBSERVACAO) > 90){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("Tamanho máximo de 90 caracteres...\n\n");
        } else {
            if(strcmp(ESPACO.OBSERVACAO,"0") == 0) return 0;
            strcpy(STRC_RETORNO->OBSERVACAO,ESPACO.OBSERVACAO);
        }

    } else if(strcmp("STATUS",campo) == 0){
        //STATUS
        do{
            valida = false;
            printf("\nEscolha o status do espaço:\n");
            printf("[%s1%s] - Ativo\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Inativo\n",COLOR_YELLOW,COLOR_RESET);

            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            ESPACO.STATUS = VALIDA_ENTRADA_NUMERO();

            switch(ESPACO.STATUS)
            {
                case 1:
                    valida = true;
                    break;
                case 2:
                    ESPACO.STATUS = 0;
                    valida = true;
                    break;
                case 0:
                    return 0;
                default:
                    printf("\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }
        }while(valida == false);
        STRC_RETORNO->STATUS = ESPACO.STATUS;
    }
    return 1;
}
void PRINTAR_ESPACO(STRC_ESPACO *ESPACO, boolean fl_bloqueiaCampos){
    printf("\n%sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,ESPACO->ID);
    printf("\n%sNome do espaço:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO->NOME_ESPACO);
    printf("\n%sCapacidade:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO->CAPACIDADE);
    printf("\n%sTipo de espaço:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO->TP_ESPACO);
    printf("\n%sObservação:%s %s",COLOR_CYAN,COLOR_RESET,ESPACO->OBSERVACAO);
    if (fl_bloqueiaCampos != 1) printf("\n%sStatus:%s %s%s%s\n\n",COLOR_CYAN,COLOR_RESET,ESPACO->STATUS==1?COLOR_GREEN:COLOR_RED,ESPACO->STATUS==1?"Ativo":"Inativo",COLOR_RESET);
    else printf("\n\n");
    SEPARADOR();
    printf("\n");
}
//=======================================================================================================
//AGENDAMENTO
//=======================================================================================================
void CADASTRA_AGENDAMENTO(){

    CABECALHO();
    printf("%sMenu inicial > Agendamentos >%s %sSolicitar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    MSG_RETORNO();

    STRC_AGENDAMENTO AGENDAMENTO;
    char confirm;
    char dt[100];

    //SELECIONA ASSUNTO
    if (VALIDA_DADOS_AGENDAMENTO("ASSUNTO",&AGENDAMENTO) == false) return 0;

    //SELECIONA ESPAÇO
    if (VALIDA_DADOS_AGENDAMENTO("ESPACO",&AGENDAMENTO) == false) return 0;

    //INFORMA DH_FIM E DH_FINAL
    if (VALIDA_DADOS_AGENDAMENTO("DH_FIM_FIM",&AGENDAMENTO) == false) return 0;

    do{
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

        //ASSUNTO
        SEPARADOR();
        printf("\n\n%s[Informações]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n  %sAssunto:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ASSUNTO);
        FORMATA_DATA_HORA(&dt,AGENDAMENTO.YEAR_INICIO,AGENDAMENTO.MONTH_INICIO,AGENDAMENTO.DAY_INICIO,AGENDAMENTO.HOUR_INICIO,AGENDAMENTO.MIN_INICIO);
        printf("\n  %sEntrada:%s %s",COLOR_CYAN,COLOR_RESET,dt);
        FORMATA_DATA_HORA(&dt,AGENDAMENTO.YEAR_FIM,AGENDAMENTO.MONTH_FIM,AGENDAMENTO.DAY_FIM,AGENDAMENTO.HOUR_FIM,AGENDAMENTO.MIN_FIM);
        printf("\n  %sSaída:%s %s\n\n",COLOR_CYAN,COLOR_RESET,dt);
        //ASSUNTO
        SEPARADOR();
        printf("\n\n%s[Solicitante]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n  %sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.USUARIO.ID);
        printf("\n  %sNome:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.USUARIO.NOME_COMPLETO);
        printf("\n  %sCelular:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.USUARIO.CELULAR);
        printf("\n  %sE-mail:%s %s\n\n",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.USUARIO.USUARIO);
        //ESPAÇO
        SEPARADOR();
        printf("\n\n%s[Espaço]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n  %sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.ID);
        printf("\n  %sNome:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.NOME_ESPACO);
        printf("\n  %sCapidade:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.CAPACIDADE);
        printf("\n  %sTipo:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.TP_ESPACO);
        printf("\n  %sObservação:%s %s\n\n",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.OBSERVACAO);
        SEPARADOR();

        do{
            printf("\n\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        } while(confirm != 's' && confirm != 'n');

        if(confirm == 's'){
            BUSCAR_ID(ARQ_AGENDAMENTO,&AGENDAMENTO.ID);
            arq = fopen(ARQ_AGENDAMENTO,"a+b");
            fwrite(&AGENDAMENTO,sizeof(AGENDAMENTO),1,arq);
            fclose(arq);
            printf("\n\nEspaço criado com sucesso...");
        }

    } while(confirm != 's' && confirm != 'n');

    printf("\n\n");
    system("pause");
    return 0;

}
void LISTAR_AGENDAMENTOS(int op,int STATUS_ID, int STATUS_NOVO_ID){
    STRC_AGENDAMENTO AGENDAMENTO;
    STRC_DH DH;
    boolean fl_econtrou,fl_liberaLoop, validacao;
    long long DH_ATUAL_LONG;
    int count = 0, posicaoArq = 0,avaliacao;
    char buscar[100],confirm;
    char tipo[100];

    if (op == 2)
        strcpy(tipo,"Check-in");
    else if (op == 3)
        strcpy(tipo,"Check-out");
    else if (op == 4){
        STATUS_NOVO_ID = 0;
        strcpy(tipo,"Cancelamento");
    }
    else if (op == 5)
        strcpy(tipo,"Histórico");

    do {
        CABECALHO();
        printf("%sMenu inicial > Agendamentos >%s %s%s%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,tipo,COLOR_RESET);

        posicaoArq = 0;
        fl_liberaLoop = false;

        //CRIA LONG DT ATUAL
        DH_ATUAL(&DH);
        PREPARA_DATA_STRC(&DH_ATUAL_LONG,atoi(DH.ANO),atoi(DH.MES),atoi(DH.DIA),atoi(DH.HORAS),atoi(DH.MINUTOS));


        //SELECIONA QUAL AGENDAMENTO
        arq = fopen(ARQ_AGENDAMENTO,"rb");
        if(arq!=NULL){
            while(fread(&AGENDAMENTO, sizeof(AGENDAMENTO), 1, arq)){
                fl_econtrou = false;

                if((AGENDAMENTO.USUARIO_ID == session_usuarioID || session_nivelAcesso == 2) && (AGENDAMENTO.STATUS == STATUS_ID || STATUS_ID ==  NULL)){
                    if (op == 5) {
                        if(AGENDAMENTO.USUARIO_ID == session_usuarioID){
                            fl_econtrou = true;
                            count++;
                        }
                    } else {
                        //AGENDADO - CHECK-IN
                        if(DH_ATUAL_LONG >= AGENDAMENTO.DH_INICIO && AGENDAMENTO.STATUS == STATUS_ID && STATUS_ID == 1){
                            fl_econtrou = true;
                            count++;
                        //EM ANDAMENTO - CHECK-OUT
                        }else if(AGENDAMENTO.STATUS == STATUS_ID && STATUS_ID == 2){
                            fl_econtrou = true;
                            count++;
                        //CANCELAMENTO
                        }else if(AGENDAMENTO.STATUS != 0 && (AGENDAMENTO.STATUS != 3 || session_nivelAcesso == 2) && STATUS_ID == NULL){
                            fl_econtrou = true;
                            count++;
                        }
                    }
                }

                if(fl_econtrou == true){
                    if (count == 1) SEPARADOR();
                    PRINTAR_AGENDAMENTO(&AGENDAMENTO,false,(op == 5?true:false),(op == 5?true:false));
                    SEPARADOR();
                }
            }
        }
        fclose(arq);

        //CASO SEJA DIFERENTE DE HISTÓRICO MONTA PARA CONFIRMAÇÃO
        if (count > 0 && op != 5) {
            printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Digite o código do agendamento, %s0%s para voltar: ",COLOR_YELLOW,COLOR_RESET);
            gets(buscar);

            if (strcmp(buscar,"0") == 0) {
                return 0;
            } else if(strlen(buscar) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O código é obrigatório...\n\n");
                system("pause");
            } else {
                fl_econtrou = false;
                posicaoArq = 0;

                arq = fopen(ARQ_AGENDAMENTO,"rb");
                while(fread(&AGENDAMENTO, sizeof(AGENDAMENTO), 1, arq)){

                    if((AGENDAMENTO.USUARIO_ID == session_usuarioID || session_nivelAcesso == 2) && (AGENDAMENTO.STATUS == STATUS_ID || STATUS_ID == NULL)){
                        //AGENDADO - CHECK-IN
                        if(DH_ATUAL_LONG >= AGENDAMENTO.DH_INICIO && AGENDAMENTO.STATUS == STATUS_ID && STATUS_ID == 1 && atoi(buscar) == AGENDAMENTO.ID){
                            fl_econtrou = true;
                            break;
                        //EM ANDAMENTO - CHECK-OUT
                        } else if(AGENDAMENTO.STATUS == STATUS_ID && STATUS_ID == 2 && atoi(buscar) == AGENDAMENTO.ID){
                            fl_econtrou = true;
                            break;
                        //CANCELADO
                        } else if (AGENDAMENTO.STATUS != 0 && (AGENDAMENTO.STATUS != 3 || session_nivelAcesso == 2) && STATUS_ID == NULL && atoi(buscar) == AGENDAMENTO.ID){
                            fl_econtrou = true;
                            break;
                        }
                    }

                    posicaoArq = posicaoArq + sizeof(STRC_AGENDAMENTO);
                    fseek(arq, posicaoArq, SEEK_SET);
                }
                fclose(arq);

                if (fl_econtrou == true){
                    CABECALHO();
                    printf("%sMenu inicial > Agendamentos >%s %s%s%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,tipo,COLOR_RESET);

                    if(op == 3 || op == 4) MSG_RETORNO();

                    SEPARADOR();
                    PRINTAR_AGENDAMENTO(&AGENDAMENTO,false,true,true);
                    SEPARADOR();

                    //AVALIAÇÃO
                    if (op == 3){

                        do{
                            validacao = false;

                            printf("\n\n[%s1%s] - Péssimo",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s2%s] - Ruim",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s3%s] - Razóavel",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s4%s] - Bom",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s5%s] - Ótimo",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s6%s] - Não quero avaliar",COLOR_YELLOW,COLOR_RESET);
                            printf("\n[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

                            printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                            printf("Escolha uma opção acima, para avaliação: ");
                            avaliacao = VALIDA_ENTRADA_NUMERO();

                            switch(avaliacao)
                            {
                                case 1: case 2: case 3: case 4: case 5:
                                    validacao = true;
                                    AGENDAMENTO.AVALIACAO = avaliacao;
                                    break;
                                case 6:
                                    AGENDAMENTO.AVALIACAO = 0;
                                    validacao = true;
                                    break;
                                case 0:
                                    return 0;
                                    break;
                                default:
                                    printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n");
                                    system("pause");
                                    break;
                            }

                        } while(validacao == false);

                        printf("\n\nDeixe um comentário: ");
                        gets(AGENDAMENTO.OBSERVACAO);

                        if(strcmp(AGENDAMENTO.OBSERVACAO,"0") == 0) return 0;

                    //
                    } else if (op == 4) {

                        do{
                            validacao = false;
                            printf("\n\nDigite o motivo do cancelamento: ");
                            gets(AGENDAMENTO.OBSERVACAO);

                            if(strcmp(AGENDAMENTO.OBSERVACAO,"0") == 0) return 0;
                            else if(strlen(AGENDAMENTO.OBSERVACAO) == 0) {
                                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                                printf("Motivo do cancelamento é obrigatório...\n");
                            } else {
                                validacao = true;
                            }
                        } while (validacao == false);

                    }


                    do{
                        printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                        printf("Deseja realmente realizar o %s? %s[S/N]%s: ",strlwr(tipo),COLOR_YELLOW,COLOR_RESET);
                        confirm = tolower(getche());
                    } while(confirm != 's' && confirm != 'n');

                    if(confirm == 's'){
                        fl_liberaLoop = true;
                        AGENDAMENTO.STATUS = STATUS_NOVO_ID;
                        arq = fopen(ARQ_AGENDAMENTO,"r+b");
                        fseek(arq, posicaoArq, SEEK_SET);  //DEFINE O DESLOCAMENTO PARA ONDE ENCONTROU OS DADOS;
                        fwrite(&AGENDAMENTO,sizeof(STRC_AGENDAMENTO),1,arq) == sizeof(STRC_AGENDAMENTO); //REESCREVE OS DADOS  NO ARQUIVO;
                        fclose(arq);

                        printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                        printf("%s realizado com sucesso...\n\n",tipo);
                        system("pause");
                    }


                } else {
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Código do agendamento não encontrado...\n\n");
                    system("pause");
                }
            }

        } else {
            fl_liberaLoop = true;
            if (!strcmp(tipo,"Histórico") == 0){
                printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Nenhum agendamento liberado para %s...\n",strlwr(tipo));
            }
            printf("\n");
            system("pause");
        }

    } while (fl_liberaLoop == false);


}
int VALIDA_DADOS_AGENDAMENTO(char campo[],STRC_AGENDAMENTO *STRC_RETORNO){
    //FORMATA_DATA(AGENDAMENTO.DAY_FIM,AGENDAMENTO.MONTH_FIM,AGENDAMENTO.YEAR_FIM);

    STRC_AGENDAMENTO AGENDAMENTO;
    STRC_AGENDAMENTO AGENDAMENTO_AUX;
    STRC_DH DH;

    boolean valida, validaAux;
    int i,confirm,dt_tratamento[3],hr[2],count;
    char buscar[100], STR_ID[100];
    long long DH_ATUAL_LONG;

    if (strcmp("ASSUNTO",campo) == 0){
        //NOME DO ESPAÇO
        do{
            valida = false;
            printf("\n\nDigite o assunto: ");
            gets(AGENDAMENTO.ASSUNTO);

            if(strlen(AGENDAMENTO.ASSUNTO) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O assunto é obrigatório...\n\n");
            } else if(strlen(AGENDAMENTO.ASSUNTO) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(AGENDAMENTO.ASSUNTO,"0") == 0) return 0;
                else
                    valida = true;
            }

        }while(valida == false);
        strcpy(STRC_RETORNO->ASSUNTO,AGENDAMENTO.ASSUNTO);

    } else if (strcmp("ESPACO",campo) == 0){
        //NOME DO ESPAÇO
        do{
            valida = false;
            printf("\nDigite o código/nome do espaço ou tecle enter para listar: ");
            gets(buscar);

            if(strlen(buscar) == 0){
                arq = fopen(ARQ_ESPACO,"rb");
                if(arq  != NULL) {
                    printf("\n");
                    SEPARADOR();
                    printf("\n");
                    while(fread(&AGENDAMENTO.ESPACO, sizeof(AGENDAMENTO.ESPACO), 1, arq)){
                        if(AGENDAMENTO.ESPACO.STATUS == 1){
                            PRINTAR_ESPACO(&AGENDAMENTO.ESPACO,1);
                        }
                    }
                } else {
                    fclose(arq);
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Nenhum espaço cadastrado, contate o administrador do sistema...\n\n");
                }
                fclose(arq);
            } else if(strlen(buscar) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(buscar,"0") == 0) return 0;
                else{
                    validaAux = false;

                    arq = fopen(ARQ_ESPACO,"rb");
                    if(arq  != NULL) {
                        while(fread(&AGENDAMENTO.ESPACO, sizeof(AGENDAMENTO.ESPACO), 1, arq)){
                            sprintf(STR_ID,"%d",AGENDAMENTO.ESPACO.ID);
                            if((strcmp(strupr(buscar),STR_ID) == 0 || strcmp(strupr(buscar),AGENDAMENTO.ESPACO.NOME_ESPACO) == 0) && AGENDAMENTO.ESPACO.STATUS == 1){
                                validaAux = true;
                                fclose(arq);
                                break;
                            }
                        }
                    } else {
                        fclose(arq);
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Nenhum espaço cadastrado, contate o administrador do sistema...\n\n");
                    }
                    fclose(arq);

                    if (validaAux == true){
                        printf("\n\n");
                        SEPARADOR();
                        printf("\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                        printf("Espaço selecionado:\n");
                        PRINTAR_ESPACO(&AGENDAMENTO.ESPACO,1);
                        do {
                            printf("\n\nDeseja continuar? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
                            confirm = tolower(getche());
                        } while(confirm != 's' && confirm != 'n');

                        if (confirm == 's') valida = true;
                        else printf("\n");
                    } else {
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Nenhum espaço encontrado. Por favor, tente novamente...\n\n");
                        valida = false;
                    }

                }
            }

        }while(valida == false);
        STRC_RETORNO->ESPACO = AGENDAMENTO.ESPACO;
        STRC_RETORNO->ESPACO_ID = AGENDAMENTO.ESPACO.ID;

    } else if (strcmp("DH_FIM_FIM",campo) == 0){

        do {

            //DATA INÍCIO
            do{
                //RESET DE VARIAVEIS
                valida = false;
                memset(dt_tratamento,0,3);
                AGENDAMENTO.DAY_INICIO = 0;
                AGENDAMENTO.MONTH_INICIO = 0;
                AGENDAMENTO.YEAR_INICIO = 0;

                printf("\n\nDigite a data inicial %s[DD/MM/AAAA]%s: ",COLOR_YELLOW,COLOR_RESET);
                gets(buscar);

                if(strlen(buscar) == 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("A data inicial é obrigatória...\n\n");

                } else if(strcmp(buscar,"0") == 0){
                    return 0;
                } else if(strlen(buscar) != 10){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Data digitada inválida...\n\n");
                } else {
                    PREPARA_ENTRADA_DATA(buscar,&dt_tratamento);
                    AGENDAMENTO.DAY_INICIO = dt_tratamento[0];
                    AGENDAMENTO.MONTH_INICIO = dt_tratamento[1];
                    AGENDAMENTO.YEAR_INICIO = dt_tratamento[2];

                    if (AGENDAMENTO.DAY_INICIO == 0 || AGENDAMENTO.MONTH_INICIO == 0 || AGENDAMENTO.YEAR_INICIO == 0){
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Data digitada inválida...\n\n");
                    } else {
                        valida = VALIDA_ENTRADA_DATA(AGENDAMENTO.DAY_INICIO,AGENDAMENTO.MONTH_INICIO,AGENDAMENTO.YEAR_INICIO);
                    }
                }
            }while(valida == false);

            //HORA INÍCIO
            do{
                //RESET DE VARIAVEIS
                valida = false;
                memset(hr,0,2);
                AGENDAMENTO.HOUR_INICIO = 0;
                AGENDAMENTO.MIN_INICIO = 0;

                printf("\nDigite a hora inicial %s[HH:MM]%s: ",COLOR_YELLOW,COLOR_RESET);
                gets(buscar);

                if(strlen(buscar) == 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("A hora inicial é obrigatória...\n\n");
                } else if(strcmp(buscar,"0") == 0){
                    return 0;
                } else if(strlen(buscar) != 5){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Hora digitada inválida...\n\n");
                } else {
                    if (!VALIDA_MASCARA_HORA(buscar)){
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Hora digitada inválida...\n\n");
                    } else {
                        PREPARA_ENTRADA_HORA(buscar,&hr);
                        AGENDAMENTO.HOUR_INICIO = hr[0];
                        AGENDAMENTO.MIN_INICIO = hr[1];
                        valida = VALIDA_ENTRADA_HORA(AGENDAMENTO.HOUR_INICIO,AGENDAMENTO.MIN_INICIO);
                    }
                }
            }while(valida == false);

            //DATA FINAL
            do{
                //RESET DE VARIAVEIS
                valida = false;
                memset(dt_tratamento,0,3);
                AGENDAMENTO.DAY_FIM = 0;
                AGENDAMENTO.MONTH_FIM = 0;
                AGENDAMENTO.YEAR_FIM = 0;

                printf("\nDigite a data final %s[DD/MM/AAAA]%s: ",COLOR_YELLOW,COLOR_RESET);
                gets(buscar);

                if(strlen(buscar) == 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("A data final é obrigatória...\n\n");
                } else if(strcmp(buscar,"0") == 0){
                    return 0;
                } else if(strlen(buscar) != 10){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Data digitada inválida...\n\n");
                } else {
                    PREPARA_ENTRADA_DATA(buscar,&dt_tratamento);
                    AGENDAMENTO.DAY_FIM = dt_tratamento[0];
                    AGENDAMENTO.MONTH_FIM = dt_tratamento[1];
                    AGENDAMENTO.YEAR_FIM = dt_tratamento[2];

                    if (AGENDAMENTO.DAY_FIM == 0 || AGENDAMENTO.MONTH_FIM == 0 || AGENDAMENTO.YEAR_FIM == 0){
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Data digitada inválida...\n\n");
                    } else {
                        valida = VALIDA_ENTRADA_DATA(AGENDAMENTO.DAY_FIM,AGENDAMENTO.MONTH_FIM,AGENDAMENTO.YEAR_FIM);
                    }

                }
            }while(valida == false);

            //HORA FINAL
            do{
                //RESET DE VARIAVEIS
                valida = false;
                memset(hr,0,2);
                AGENDAMENTO.HOUR_FIM = 0;
                AGENDAMENTO.MIN_FIM = 0;

                printf("\nDigite a hora final %s[HH:MM]%s: ",COLOR_YELLOW,COLOR_RESET);
                gets(buscar);

                if(strlen(buscar) == 0){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("A hora final é obrigatória...\n\n");
                } else if(strcmp(buscar,"0") == 0){
                    return 0;
                } else if(strlen(buscar) != 5){
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Hora digitada inválida...\n\n");
                } else {
                    if (!VALIDA_MASCARA_HORA(buscar)){
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Hora digitada inválida...\n\n");
                    } else {
                        PREPARA_ENTRADA_HORA(buscar,&hr);
                        AGENDAMENTO.HOUR_FIM = hr[0];
                        AGENDAMENTO.MIN_FIM = hr[1];
                        valida = VALIDA_ENTRADA_HORA(AGENDAMENTO.HOUR_FIM,AGENDAMENTO.MIN_FIM);
                    }
                }
            }while(valida == false);


            //CRIA LONG DT INICIO
            PREPARA_DATA_STRC(&AGENDAMENTO.DH_INICIO,AGENDAMENTO.YEAR_INICIO,AGENDAMENTO.MONTH_INICIO,AGENDAMENTO.DAY_INICIO,AGENDAMENTO.HOUR_INICIO,AGENDAMENTO.MIN_INICIO);
            //CRIA LONG DT FINAL
            PREPARA_DATA_STRC(&AGENDAMENTO.DH_FINAL,AGENDAMENTO.YEAR_FIM,AGENDAMENTO.MONTH_FIM,AGENDAMENTO.DAY_FIM,AGENDAMENTO.HOUR_FIM,AGENDAMENTO.MIN_FIM);
            //CRIA LONG DT ATUAL
            DH_ATUAL(&DH);
            PREPARA_DATA_STRC(&DH_ATUAL_LONG,atoi(DH.ANO),atoi(DH.MES),atoi(DH.DIA),atoi(DH.HORAS),atoi(DH.MINUTOS));

            valida = false;

            if (DH_ATUAL_LONG > AGENDAMENTO.DH_INICIO) {
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Data retroativa indisponível...\n\n");
            } else if (AGENDAMENTO.DH_FINAL < AGENDAMENTO.DH_INICIO) {
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Data final não pode ser menor que a inicial...\n\n");
            } else {

                valida = true;


                //VALIDA DEMAIS AGENDAMENTOS
                arq = fopen(ARQ_AGENDAMENTO,"rb");
                if(arq!=NULL){
                    while(fread(&AGENDAMENTO_AUX, sizeof(AGENDAMENTO_AUX), 1, arq)){

                        if(STRC_RETORNO->ESPACO_ID == AGENDAMENTO_AUX.ESPACO_ID && (AGENDAMENTO_AUX.STATUS == 1 || AGENDAMENTO_AUX.STATUS == 2)){
                            //PRIMEIRO VALIDA SE A DT_INCIAL E FINAL ESTÁ DENTRO DE ALGUM PERÍODO
                            if(AGENDAMENTO.DH_INICIO >= AGENDAMENTO_AUX.DH_INICIO && AGENDAMENTO.DH_INICIO <= AGENDAMENTO_AUX.DH_FINAL){
                                valida = false;
                                break;
                            }
                            if( AGENDAMENTO.DH_FINAL >= AGENDAMENTO_AUX.DH_INICIO && AGENDAMENTO.DH_FINAL <= AGENDAMENTO_AUX.DH_FINAL){
                                valida = false;
                                break;
                            }
                            //SEGUNDO VALIDA SE EXISTE ALGUMA SOLICITAÇÃO EM ABERTA DENTRO DA DATA INFORMADA
                            if(AGENDAMENTO_AUX.DH_INICIO >= AGENDAMENTO.DH_INICIO && AGENDAMENTO_AUX.DH_INICIO <= AGENDAMENTO.DH_FINAL){
                                valida = false;
                                break;
                            }
                            if( AGENDAMENTO_AUX.DH_FINAL >= AGENDAMENTO.DH_INICIO && AGENDAMENTO_AUX.DH_FINAL <= AGENDAMENTO.DH_FINAL){
                                valida = false;
                                break;
                            }

                        }

                    }
                }
                fclose(arq);

                if(valida == true){

                    valida = false;

                    arq = fopen(ARQ_LOGIN,"rb");
                    while(fread(&AGENDAMENTO.USUARIO, sizeof(AGENDAMENTO.USUARIO), 1, arq)){
                        if(session_usuarioID == AGENDAMENTO.USUARIO.ID &&  AGENDAMENTO.USUARIO.STATUS == 1){
                            valida = true;
                            break;
                        }
                    }
                    fclose(arq);

                    if(valida == true){
                        STRC_RETORNO->DH_INICIO = AGENDAMENTO.DH_INICIO;
                        STRC_RETORNO->YEAR_INICIO = AGENDAMENTO.YEAR_INICIO;
                        STRC_RETORNO->MONTH_INICIO = AGENDAMENTO.MONTH_INICIO;
                        STRC_RETORNO->DAY_INICIO = AGENDAMENTO.DAY_INICIO;
                        STRC_RETORNO->HOUR_INICIO = AGENDAMENTO.HOUR_INICIO;
                        STRC_RETORNO->MIN_INICIO = AGENDAMENTO.MIN_INICIO;

                        STRC_RETORNO->DH_FINAL = AGENDAMENTO.DH_FINAL;
                        STRC_RETORNO->YEAR_FIM = AGENDAMENTO.YEAR_FIM;
                        STRC_RETORNO->MONTH_FIM = AGENDAMENTO.MONTH_FIM;
                        STRC_RETORNO->DAY_FIM = AGENDAMENTO.DAY_FIM;
                        STRC_RETORNO->HOUR_FIM = AGENDAMENTO.HOUR_FIM;
                        STRC_RETORNO->MIN_FIM = AGENDAMENTO.MIN_FIM;

                        STRC_RETORNO->USUARIO = AGENDAMENTO.USUARIO;
                        STRC_RETORNO->USUARIO_ID = AGENDAMENTO.USUARIO.ID;

                        STRC_RETORNO->STATUS = 1;

                    } else {

                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Usuário não localizado na base de dados. Por favor, contate o administrador do sistema...\n\n");
                        system("pause");
                        exit(1);
                    }
                } else {
                    printf("\n\n");
                    SEPARADOR();
                    PRINTAR_AGENDAMENTO(&AGENDAMENTO_AUX,true,false,false);
                    SEPARADOR();
                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Já existe um agendamento no período selecionado...\n\n");
                }


            }

        } while(valida == false);
    }
    return 1;
}
void REL_DETALHADO_AGENDAMENTOS(int op){
    STRC_AGENDAMENTO AGENDAMENTO;
    boolean fl_econtrou, validacao;
    int count = 0,STATUS_ID = -1;
    char tipo[100],buscar[100],STR_ID[100];

    if (op == 1){
        strcpy(tipo,"Código do coloborador solicitante");
    }else if (op == 2){
        strcpy(tipo,"Código do agendamento");
    }else if (op == 3){
        strcpy(tipo,"Código do espaço");
    }else if (op == 4){
        STATUS_ID = 1;
        strcpy(tipo,"Angendados");
    }else if (op == 5){
        STATUS_ID = 2;
        strcpy(tipo,"Em andamento");
    }else if (op == 6){
        STATUS_ID = 3;
        strcpy(tipo,"Finalizados");
    }else if (op == 7){
        STATUS_ID = 0;
        strcpy(tipo,"Cancelados");
    }else if (op == 8){
        strcpy(tipo,"Todos");
    }

    CABECALHO();
    printf("%sMenu inicial > Agendamentos >%s %s%s%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,tipo,COLOR_RESET);

    
    if(op == 1){
        MSG_RETORNO();

        do{
            validacao = false;
            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Digite o código do coloborador solicitante: ");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
            else if (strlen(buscar) == 0 ){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O código é obrigatório...\n\n");
            }else 
                validacao = true;
        }while(validacao == false);

    } else if(op == 2){
        MSG_RETORNO();

        do{
            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Digite o código do agendamento: ");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
            else if (strlen(buscar) == 0 ){ 
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O código é obrigatório...\n\n");
            }else 
                validacao = true;
        }while(validacao == false);

    } else if(op == 3){
        MSG_RETORNO();

        do{
            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Digite o código ou nome do espaço: ");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
            else if (strlen(buscar) == 0 ){ 
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("O código é obrigatório...\n\n");
            }else 
                validacao = true;
        }while(validacao == false);
    }


    //SELECIONA QUAL AGENDAMENTO
    arq = fopen(ARQ_AGENDAMENTO,"rb");
    if(arq!=NULL){
        while(fread(&AGENDAMENTO, sizeof(AGENDAMENTO), 1, arq)){
            fl_econtrou = false;

            //usuario
            if(op == 1){
                sprintf(STR_ID,"%d",AGENDAMENTO.USUARIO_ID);
                if(strcmp(strupr(buscar),STR_ID) == 0)fl_econtrou = true;
            //agendamento
            } else if(op == 2){
                sprintf(STR_ID,"%d",AGENDAMENTO.ID);
                if(strcmp(strupr(buscar),STR_ID) == 0) fl_econtrou = true;
            //espaço
            } else if(op == 3){
                sprintf(STR_ID,"%d",AGENDAMENTO.ESPACO_ID);
                if(strcmp(strupr(buscar),STR_ID) == 0 || strcmp(strupr(buscar),AGENDAMENTO.ESPACO.NOME_ESPACO) == 0) fl_econtrou = true; 
            //STATUS
            } else if(op >= 4 && op <= 7) {
                if(STATUS_ID == AGENDAMENTO.STATUS) fl_econtrou = true; 
            } else {
                fl_econtrou = true; 
            }

            if(fl_econtrou == true){
                count++;
                if (count == 1) SEPARADOR();
                PRINTAR_AGENDAMENTO(&AGENDAMENTO,false,true,true);
                SEPARADOR();
            }
        }
    }
    fclose(arq);

    if (count == 0){
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Nenhum agendamento encontrado...");
    }

    printf("\n\n");
    system("pause");
}
void REL_RANKING_AGENDAMENTOS(){
    STRC_AGENDAMENTO AGENDAMENTO;
    STRC_ESPACO ESPACO;
    int qtd_espaco = 0,i,fl_encontrou=0;
    float **matriz,count,avaliacao;

    FILE *arqAux;

    CABECALHO();
    printf("%sMenu inicial > Agendamentos >%s %sRanking espaço%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);


    //BUSCA QUANTOS ESPACOS TEM
    arq = fopen(ARQ_ESPACO,"rb");
    if(arq!=NULL){
        while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){
            if (ESPACO.STATUS == 1){
                qtd_espaco++;
            }
        }
    }
    fclose(arq);

    if (qtd_espaco > 0) {
        qtd_espaco;
        //CRIA MATRIZ DINAMICA
        matriz = malloc(qtd_espaco *sizeof(float*));
        for (i=0; i < qtd_espaco; i ++) matriz[i] = malloc(2 *sizeof(float*));
        
        //ATRIBUI IDS E QTD 
        i=0;
        arq = fopen(ARQ_ESPACO,"rb");
        if(arq!=NULL){
            while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){
                if (ESPACO.STATUS == 1){
                    
                    count = 0;
                    avaliacao = 0;
                    arqAux = fopen(ARQ_AGENDAMENTO,"rb");
                    if(arqAux!=NULL){
                        while(fread(&AGENDAMENTO, sizeof(AGENDAMENTO), 1, arqAux)){
                            if (AGENDAMENTO.STATUS == 3 && AGENDAMENTO.AVALIACAO != 0 && AGENDAMENTO.ESPACO_ID == ESPACO.ID){
                                count++;
                                avaliacao += AGENDAMENTO.AVALIACAO;
                                fl_encontrou = 1;
                            }
                        }
                    } 
                    fclose(arqAux);
    
                    matriz[i][0] = (avaliacao/count);
                    matriz[i][1] = ESPACO.ID;

                    i++;
                }
            }
        }
        fclose(arq);
    }

    float value_aux, id_aux;
    int j;
    
    for (i=0; i < qtd_espaco; i++){
        for (j=i+1; j < qtd_espaco ; j++) {
            if (matriz[j][0] > matriz[i][0]){
                value_aux = matriz[i][0];
                id_aux = matriz[i][1];
                matriz[i][0] = matriz[j][0];
                matriz[i][1] = matriz[j][1];
                matriz[j][0] = value_aux;
                matriz[j][1] = id_aux;
            }

        }
    }

    int ID_ESPACO;

    if (fl_encontrou == 1){
            
        for (i=0; i < qtd_espaco; i++){
            //printf("%d - Valor: %f | ID: %f\n",i,matriz[i][0],matriz[i][1]);

            arq = fopen(ARQ_ESPACO,"rb");
            if(arq!=NULL){
                while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){
                    ID_ESPACO = matriz[i][1];
                    
                    if (ESPACO.ID == ID_ESPACO){
                        if (i == 0) SEPARADOR();
                        printf("\n%s#%d%s %s- %s Código: %s%s%d%s%s | Avaliação: %s%s%.1f%s \n",COLOR_PURPLE,(i+1),COLOR_RESET,COLOR_CYAN,ESPACO.NOME_ESPACO,COLOR_RESET,COLOR_YELLOW,ESPACO.ID,COLOR_RESET,COLOR_CYAN,COLOR_RESET,COLOR_GREEN,matriz[i][0],COLOR_RESET);
                        SEPARADOR();
                    }
                }
            }
            fclose(arq);        
        }
    } else {
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Nenhuma avaliação encontrada...");
    }




    printf("\n\n");
    system("pause");
    
}
void PRINTAR_AGENDAMENTO(STRC_AGENDAMENTO *AGENDAMENTO, boolean fl_esconderEspaco, boolean fl_mostrarAvaliacao, boolean  fl_mostrarCancelamento){

    char dt[100],avaliacao[100];

    printf("\n%s#Código do agendamento:%s %d\n",COLOR_PURPLE,COLOR_RESET,AGENDAMENTO->ID);
    SEPARADOR();

    //ASSUNTO
    printf("\n\n%s[Informações]%s",COLOR_PURPLE,COLOR_RESET);
    printf("\n      %sAssunto:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ASSUNTO);
    FORMATA_DATA_HORA(&dt,AGENDAMENTO->YEAR_INICIO,AGENDAMENTO->MONTH_INICIO,AGENDAMENTO->DAY_INICIO,AGENDAMENTO->HOUR_INICIO,AGENDAMENTO->MIN_INICIO);
    printf("\n      %sEntrada:%s %s",COLOR_CYAN,COLOR_RESET,dt);
    FORMATA_DATA_HORA(&dt,AGENDAMENTO->YEAR_FIM,AGENDAMENTO->MONTH_FIM,AGENDAMENTO->DAY_FIM,AGENDAMENTO->HOUR_FIM,AGENDAMENTO->MIN_FIM);
    printf("\n      %sSaída:%s %s",COLOR_CYAN,COLOR_RESET,dt);
    printf("\n      %sStatus:%s ",COLOR_CYAN,COLOR_RESET);

    //>STATUS
    //>0: CANCELADO
    //>1: AGENDADO
    //>2: EM ANDAMENTO
    //>3: FINALIZADO
    if (AGENDAMENTO->STATUS == 0)
        printf("%s%s%s",COLOR_RED,"Cancelado",COLOR_RESET);
    else if (AGENDAMENTO->STATUS == 1)
        printf("%s%s%s",COLOR_YELLOW,"Agendado",COLOR_RESET);
    else if (AGENDAMENTO->STATUS == 2)
        printf("%s%s%s",COLOR_GREEN,"Em Andamento",COLOR_RESET);
    else if (AGENDAMENTO->STATUS == 3)
        printf("%s%s%s",COLOR_BLUE,"Finalizado",COLOR_RESET);

    //ASSUNTO
    printf("\n\n%s[Solicitante]%s",COLOR_PURPLE,COLOR_RESET);
    printf("\n      %sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->USUARIO.ID);
    printf("\n      %sNome:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->USUARIO.NOME_COMPLETO);
    printf("\n      %sCelular:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->USUARIO.CELULAR);
    printf("\n      %sE-mail:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->USUARIO.USUARIO);
    //ESPAÇO
    if(fl_esconderEspaco != true){
        printf("\n\n%s[Espaço]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n      %sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ESPACO.ID);
        printf("\n      %sNome:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ESPACO.NOME_ESPACO);
        printf("\n      %sCapidade:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ESPACO.CAPACIDADE);
        printf("\n      %sTipo:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ESPACO.TP_ESPACO);
        printf("\n      %sObservação:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->ESPACO.OBSERVACAO);
    }

    if((session_nivelAcesso == 2 || AGENDAMENTO->USUARIO_ID == session_usuarioID) && AGENDAMENTO->STATUS == 3 && fl_mostrarAvaliacao == true){

        if (AGENDAMENTO->AVALIACAO == 1) strcpy(avaliacao,"Péssimo");
        else if (AGENDAMENTO->AVALIACAO == 2) strcpy(avaliacao,"Ruim");
        else if (AGENDAMENTO->AVALIACAO == 3) strcpy(avaliacao,"Razóavel");
        else if (AGENDAMENTO->AVALIACAO == 4) strcpy(avaliacao,"Bom");
        else if (AGENDAMENTO->AVALIACAO == 5) strcpy(avaliacao,"Ótimo");
        else strcpy(avaliacao,"");

        printf("\n\n%s[Avaliação]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n      %sAvaliação:%s %d - %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->AVALIACAO,avaliacao);
        printf("\n      %sComentário:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->OBSERVACAO);
    }

    if((session_nivelAcesso == 2 || AGENDAMENTO->USUARIO_ID == session_usuarioID)  && AGENDAMENTO->STATUS == 0 && fl_mostrarCancelamento == true){
        printf("\n\n%s[Cancelamento]%s",COLOR_PURPLE,COLOR_RESET);
        printf("\n      %sMotivo:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO->OBSERVACAO);
    }

    printf("\n\n");
}

int main(){
    
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    system("title KING'S OFFICE CORPORATION (C).");

    boolean session = false;
  
    arq = fopen(ARQ_LOGIN,"rb");

    if(arq==NULL){
        CreateDirectory("ARQUIVOS",NULL);
        boolean cadastroFinalizado;
        CADASTRA_USUARIO(true, &cadastroFinalizado);
        if(cadastroFinalizado == false){
            printf("\n\nObrigado pela visita, até mais...\n");
            exit(1);
        }
    }
    fclose(arq);

    do{
        CABECALHO();
        LOGIN_VALIDA_ACESSO(&session);
        if (session == true){
            printf("%s\n\nAcesso permitido, seja bem-vindo!\n\n%s",COLOR_GREEN,COLOR_RESET);
        } else {
            printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("Acesso negado, usuário/senha incorreto...\n\n");
        }

        system ("pause");

    }while (session == 0);

    MENU_PRINCIPAL();   

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
