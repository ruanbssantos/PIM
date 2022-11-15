
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
    printf("Para retornar ao menu anterior, digite ""%s0%s"" a qualquer momento...\n",COLOR_YELLOW,COLOR_RESET);
}
//FORMATA DATA PARA BR
void FORMATA_DATA(int d, int m, int y){
    char day[100],month[100],year[100],resultado[100];

    if (d) sprintf(day, "%02d", d);
    if (m) sprintf(month, "%02d", m);
    if (y) sprintf(year, "%04d", y);

    // strcpy(resultado,day);
    // strcat(resultado,"/");
    // strcat(resultado,month);
    // strcat(resultado,"/");
    // strcat(resultado,year);

    printf("%s/%s/%s",day,month,year);
}
//PREPARA ENTRADA USUÁRIO
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
//PREPARA DH STRUCT LONG
// long PREPARA_DATA_STRC(int day, int month, int year, int hour, int min){
  
//     char str_day[100],str_month[100],str_year[100],str_hour[100],str_min[100],resultado[100];

//     if (day) sprintf(day, "%02d", d);
//     if (month) sprintf(month, "%02d", m);
//     if (year) sprintf(year, "%04d", y);

// }

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
            session_usuarioID = LOGIN.ID;
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
//=======================================================================================================
//MENUS
//=======================================================================================================
void MENU_PRINCIPAL_ADM(){
    int op;
    do{
        CABECALHO();
        printf("%sMenu inicial%s\n\n",COLOR_GREEN,COLOR_RESET);
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
                printf("Em CONSTRUÇÃO...");
                system("pause >nul");
                break;
            case 5:
                printf("Em CONSTRUÇÃO...");
                system("pause >nul");
                break;
            case 6:
                printf("Em CONSTRUÇÃO...");
                system("pause >nul");
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
                MENU_PRINCIPAL_ADM();
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
                MENU_PRINCIPAL_ADM();
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
        printf("[%s3%s] - Cancelamento\n",COLOR_YELLOW,COLOR_RESET);
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
                //SUB_MENU_ESPACOS();
                break;
            case 3:
                //ALTERAR_USUARIO(true);
                break;
            case 0:
                MENU_PRINCIPAL_ADM();
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
//=======================================================================================================
//COLABORADORES
//=======================================================================================================
void CADASTRA_USUARIO(boolean fl_primeiroAcesso, boolean *cadastroFinalizado){
    CABECALHO();
    printf("%sMenu inicial > Colaboradores >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

    *cadastroFinalizado = false;

    STRC_LOGIN LOGIN;

    int i = 0;
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
    strcpy(LOGIN.SENHA,senha);

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
        arq = fopen(ARQ_LOGIN,"rb");

        if(op != 3){
            printf("\nDigite o %s: ", op==1?"nome":"e-mail");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
        }

        while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){

            if (op == 1) {
                for (i=0; i < strlen(buscar); i++) {
                    buscar[i] = toupper(buscar[i]);
                }
                if(strcmp(buscar,LOGIN.NOME_COMPLETO) == 0){
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
    char buscar[100];
    int count_usuario,op,posicaoArq = 0;
    boolean validaAlteracao;

    if(fl_criaCabecalho == 1){
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    } else {
        printf("\n\n");
    }

    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Digite o e-mail do colaborador que deseja alterar: ");
    gets(buscar);

    arq = fopen(ARQ_LOGIN,"rb");

    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
        if(strcmp(buscar,LOGIN.USUARIO) == 0){
            fclose(arq);
            count_usuario++;
            do{
                validaAlteracao = false;
                CABECALHO();
                printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
                printf("\n[%s1%s] - %sNome:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NOME_COMPLETO);
                printf("\n[%s2%s] - %sEmail:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.USUARIO);
                printf("\n[%s3%s] - %sCelular:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.CELULAR);
                printf("\n[%s4%s] - %sNível:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NIVEL==1?"Comum":"Administrativo");
                printf("\n[%s5%s] - %sStatus:%s %s%s%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.STATUS==1?COLOR_GREEN:COLOR_RED,LOGIN.STATUS==1?"Ativo":"Inativo",COLOR_RESET);
                printf("\n[%s0%s] - %sVoltar%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);

                printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Escolha o filtro desejado: ");
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
    }
    return 1;
}
void PRINTAR_USUARIO(STRC_LOGIN *USER){
    printf("\n%sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,USER->ID);
    printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,USER->NOME_COMPLETO);
    printf("\n%sEmail:%s %s",COLOR_CYAN,COLOR_RESET,USER->USUARIO);
    printf("\n%sCelular:%s %s",COLOR_CYAN,COLOR_RESET,USER->CELULAR);
    printf("\n%sNível:%s %s",COLOR_CYAN,COLOR_RESET,USER->NIVEL==1?"Comum":"Administrativo");
    printf("\n%sStatus:%s %s%s%s\n\n",COLOR_CYAN,COLOR_RESET,USER->STATUS==1?COLOR_GREEN:COLOR_RED,USER->STATUS==1?"Ativo":"Inativo",COLOR_RESET);
    SEPARADOR();
    printf("\n");
}
//=======================================================================================================
//ESPAÇO
//=======================================================================================================
void CADASTRA_ESPACO(){

    CABECALHO();
    printf("%sMenu inicial > Espaços >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

    STRC_ESPACO ESPACO;
    char confirm;

    MSG_RETORNO();

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
        arq = fopen(ARQ_ESPACO,"rb");


        if(op != 3){
            printf("\nDigite o %s: ", op==1?"nome":"tipo");
            gets(buscar);
            if(strcmp(buscar,"0") == 0) return 0;
            for (i=0; i < strlen(buscar); i++) {
                buscar[i] = toupper(buscar[i]);
            }
        }

        while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){

            if (op == 1 ) {
               if(strcmp(buscar,ESPACO.NOME_ESPACO) == 0){
                   PRINTAR_ESPACO(&ESPACO,0);
                   count++;
               }
            } else if (op == 2){
               if(strcmp(buscar,ESPACO.TP_ESPACO) == 0){
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
    int i,count,op,posicaoArq = 0;
    boolean validaAlteracao;

    if(fl_criaCabecalho == 1){
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    } else {
        printf("\n\n");
    }

    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Digite o código ou nome do espaço: ");
    gets(buscar);
    for (i=0; i < strlen(buscar); i++) {
        buscar[i] = toupper(buscar[i]);
    }

    arq = fopen(ARQ_ESPACO,"rb");

    while(fread(&ESPACO, sizeof(ESPACO), 1, arq)){
        sprintf(STR_ID,"%d",ESPACO.ID);
        if(strcmp(buscar,STR_ID) == 0 || strcmp(buscar,ESPACO.NOME_ESPACO) == 0){
            fclose(arq);
            count++;
            do{
                validaAlteracao = false;
                CABECALHO();
                printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
                printf("\n[%s1%s] - %sNome:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.NOME_ESPACO);
                printf("\n[%s2%s] - %sCapacidade:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.CAPACIDADE);
                printf("\n[%s3%s] - %sTipo:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.TP_ESPACO);
                printf("\n[%s4%s] - %sObservacao:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.OBSERVACAO);
                printf("\n[%s5%s] - %sStatus:%s %s%s%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,ESPACO.STATUS==1?COLOR_GREEN:COLOR_RED,ESPACO.STATUS==1?"Ativo":"Inativo",COLOR_RESET);
                printf("\n[%s0%s] - %sVoltar%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);

                printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Escolha o filtro desejado: ");
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
//ESPAÇO
//=======================================================================================================
void CADASTRA_AGENDAMENTO(){

    CABECALHO();
    printf("%sMenu inicial > Agendamentos >%s %sSolicitar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

    STRC_AGENDAMENTO AGENDAMENTO;
    char confirm;

    MSG_RETORNO();

    //SELECIONA ESPAÇO
    //if (VALIDA_DADOS_AGENDAMENTO("ESPACO",&AGENDAMENTO) == false) return 0;

    //INFORMA DH_INICIO E DH_FINAL
    if (VALIDA_DADOS_AGENDAMENTO("DH_INICIO_FIM",&AGENDAMENTO) == false) return 0;

    do{
        CABECALHO();
        printf("%sMenu inicial > Espaços >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

        //ESPAÇO
        SEPARADOR();
        printf("\n\n%sEspaço%s\n",COLOR_PURPLE,COLOR_RESET);
        printf("\n%sCódigo:%s %d",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.ID);
        printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.NOME_ESPACO);
        printf("\n%sCapidade:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.CAPACIDADE);
        printf("\n%sTipo:%s %s",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.TP_ESPACO);
        printf("\n%sObservação:%s %s\n\n",COLOR_CYAN,COLOR_RESET,AGENDAMENTO.ESPACO.OBSERVACAO);
        SEPARADOR();

        do{
            printf("\n\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        } while(confirm != 's' && confirm != 'n');

        if(confirm == 's'){
            // BUSCAR_ID(ARQ_ESPACO,&ESPACO.ID);
            // arq = fopen(ARQ_ESPACO,"a+b");
            // fwrite(&ESPACO,sizeof(ESPACO),1,arq);
            // fclose(arq);
            // printf("\n\nEspaço criado com sucesso...");
        }

    } while(confirm != 's' && confirm != 'n');

    printf("\n\n");
    system("pause");
    return 0;

}
int VALIDA_DADOS_AGENDAMENTO(char campo[],STRC_AGENDAMENTO *STRC_RETORNO){
    STRC_AGENDAMENTO AGENDAMENTO;
    boolean valida, validaAux;
    int i,confirm,dt_tratamento[3];
    char buscar[100], STR_ID[100];

    if (strcmp("ESPACO",campo) == 0){
        //NOME DO ESPAÇO
        do{
            valida = false;
            printf("\n\nDigite o código/nome do espaço ou tecle enter para listar: ");
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
                    printf("Nenhum espaço cadastrado, contate o administrador do sistemaa...\n\n");
                }
                fclose(arq);
            } else if(strlen(buscar) > 90){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Tamanho máximo de 90 caracteres...\n\n");
            } else {
                if(strcmp(buscar,"0") == 0) return 0;
                else{
                    for (i=0; i < strlen(buscar); i++) {
                        buscar[i] = toupper(buscar[i]);
                    }

                    validaAux = false;

                    arq = fopen(ARQ_ESPACO,"rb");
                    if(arq  != NULL) {
                        while(fread(&AGENDAMENTO.ESPACO, sizeof(AGENDAMENTO.ESPACO), 1, arq)){
                            sprintf(STR_ID,"%d",AGENDAMENTO.ESPACO.ID);
                            if((strcmp(buscar,STR_ID) == 0 || strcmp(buscar,AGENDAMENTO.ESPACO.NOME_ESPACO) == 0) && AGENDAMENTO.ESPACO.STATUS == 1){
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

    } else if(strcmp("DH_INICIO_FIM",campo) == 0){

        do{
            //RESET DE VARIAVEIS
            valida = false;
            memset(dt_tratamento,0,3);
            AGENDAMENTO.DAY_INICIO = 0;
            AGENDAMENTO.MONTH_INICIO = 0;
            AGENDAMENTO.YEAR_INICIO = 0;

            printf("\n\nDigite a data início %s[DD/MM/AAAA]%s: ",COLOR_YELLOW,COLOR_RESET);
            gets(buscar);

            if(strlen(buscar) == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("A data de início é obrigatória...\n\n");
            } else if(strlen(buscar) != 10){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Data digitada inválida...\n\n");
            } else {
                if(strcmp(buscar,"0") == 0) return 0;
                else {
                    PREPARA_ENTRADA_DATA(buscar,&dt_tratamento);
                    AGENDAMENTO.DAY_INICIO = dt_tratamento[0];
                    AGENDAMENTO.MONTH_INICIO = dt_tratamento[1];
                    AGENDAMENTO.YEAR_INICIO = dt_tratamento[2];

                    printf("\nFinal: ");
                    FORMATA_DATA(AGENDAMENTO.DAY_INICIO,AGENDAMENTO.MONTH_INICIO,AGENDAMENTO.YEAR_INICIO);

                    if (AGENDAMENTO.DAY_INICIO == 0 || AGENDAMENTO.MONTH_INICIO == 0 || AGENDAMENTO.YEAR_INICIO == 0){
                        printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Data digitada inválida...\n\n");
                    } else {
                        valida = VALIDA_ENTRADA_DATA(AGENDAMENTO.DAY_INICIO,AGENDAMENTO.MONTH_INICIO,AGENDAMENTO.YEAR_INICIO);

                        printf("\nValida: %i\n", valida);

                        valida = false;
                    }
                }
                // else {
                //     //valida = true;
                // }
            }

        }while(valida == false);
    }
    return 1;
}