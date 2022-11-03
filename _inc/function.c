
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
//=======================================================================================================
//MENUS
//=======================================================================================================
void MENU_USUARIOS(){
    int op;
    int opAux;
    boolean cadastroFinalizado;

    goto MENU_PRINCIPAL;

    MENU_PRINCIPAL:
    do{
        CABECALHO();
        printf("%sMenu inicial >%s %sColaboradores%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Cadastrar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - Pesquisar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Alterar\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha uma opção acima: ");
        scanf("%i",&op);
        fflush(stdin);

        switch(op)
        {
            case 1:
                CADASTRA_USUARIO(false, &cadastroFinalizado);
                break;
            case 2:
                goto FILTROS_USUARIOS;
                break;
            case 3:
                ALTERAR_USUARIO(true);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
            }

    }while(op!=0);


    FILTROS_USUARIOS:
    do{
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sPesquisar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
        printf("[%s1%s] - Nome\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s2%s] - E-mail\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s3%s] - Todos\n",COLOR_YELLOW,COLOR_RESET);
        printf("[%s0%s] - Voltar",COLOR_YELLOW,COLOR_RESET);

        printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Escolha o filtro desejado: ");
        scanf("%i",&opAux);
        fflush(stdin);

        switch(opAux)
        {
            case 1: case 2: case 3:
                LISTAR_USUARIOS(opAux);
                break;
            case 0:
                goto MENU_PRINCIPAL;
                break;
            default:
                printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                system("pause");
                break;
        }

    }while(opAux!=0);


    return 0;
}
//=======================================================================================================
//Colaboradores
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
        printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
        printf("Digite ""%s0%s"" para retornar ao menu anterior...\n",COLOR_YELLOW,COLOR_RESET);
    }

    //EMAIL
    boolean validaEmail = false;
    do{
        printf("\nDigite o email: ");
        gets(LOGIN.USUARIO);
        if(strcmp(LOGIN.USUARIO,"0") == 0) return 0;
        validaEmail = VALIDA_EMAIL(true,LOGIN.USUARIO);
    }while (validaEmail == false);

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
                memset(senha, 0, 100);
                memset(confirmaSenha, 0, 100);
            } else {
                validaSenha = true;
            }
        }

    }while(validaSenha == false);
    strcpy(LOGIN.SENHA,senha);

    //NOME COMPLETO
    int count_espacoBranco, count_numeros;
    boolean validaNome = false;
    do{
        i = 0, count_espacoBranco = 0, count_numeros = 0;
        printf("\n\nDigite o nome completo: ");
        gets(LOGIN.NOME_COMPLETO);
        if(strlen(LOGIN.NOME_COMPLETO) == 0){
            printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
            printf("O nome é obrigatório...\n\n");
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
                printf("Nome deve conter somente letras de A-Z...\n\n");
            }else if(count_espacoBranco == 0){
                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                printf("Nome inválido, digite o nome completo...\n\n");
            }else{
                validaNome = true;
            }
        }

    }while(validaNome == false);

    //CELULAR
    char CELULAR[15];
    boolean validaCelular;
    do{
        validaCelular = true;
        printf("\nDigite o celular com DDD (somente números): ");
        gets(LOGIN.CELULAR);
        if(strlen(LOGIN.CELULAR) > 0){
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

    //NIVEL
    if(fl_primeiroAcesso == true) {
        LOGIN.NIVEL = 2;
    } else {
        boolean validaNivel;
        do{
            printf("\nEscolha o tipo de colaborador:\n");
            printf("[%s1%s] - Comum\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Administrativo\n",COLOR_YELLOW,COLOR_RESET);

            printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
            printf("Escolha uma opção acima: ");
            scanf("%i",&LOGIN.NIVEL);
            fflush(stdin);

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
    }

    //STATUS SEMPRE ATIVO
    LOGIN.STATUS = 1;

    do{
        CABECALHO();
        printf("%sColaboradores >%s %sCadastro%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);

        printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.NOME_COMPLETO);
        printf("\n\n%sEmail:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.USUARIO);
        printf("\n\n%sCelular:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.CELULAR);
        printf("\n\n%sNível:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.NIVEL==1?"Comum":"Administrativo");
        //printf("\n\n%sSenha:%s %s",COLOR_CYAN,COLOR_RESET,LOGIN.SENHA);

        printf("\n\n\nDeseja finalizar cadastro? %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
        confirm = tolower(getche());

        if(confirm == 's'){
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
            printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
            printf("Deseja alterar algum colaborador?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        }

        if(confirm == 's'){
            ALTERAR_USUARIO(0);
        } else {
            printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
            printf("Deseja realizar uma nova consulta?  %s[S/N]%s: ",COLOR_YELLOW,COLOR_RESET);
            confirm = tolower(getche());
        }



    } while(confirm == 's');

    system("pause > null");
    return 0;
}
void ALTERAR_USUARIO(boolean fl_criaCabecalho){
    STRC_LOGIN LOGIN; 
    char buscar[100];
    int count_usuario,opAux;

    //NOME COMPLETO
    int count_espacoBranco, count_numeros,i;
    boolean validaNome = false;
    
    if(fl_criaCabecalho == 1){  
        CABECALHO();
        printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
    } else {
        printf("\n\n");
    }

    printf("\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
    printf("Digite o e-mail do colaborador que deseja alterar: ");
    gets(buscar);

    arq = fopen(ARQ_LOGIN,"r+b");
  
    while(fread(&LOGIN, sizeof(LOGIN), 1, arq)){
        if(strcmp(buscar,LOGIN.USUARIO) == 0){
            count_usuario++;
            do{
                CABECALHO();
                printf("%sMenu inicial > Colaboradores >%s %sAlterar%s\n\n",COLOR_PURPLE,COLOR_RESET,COLOR_GREEN,COLOR_RESET);
                printf("\n[%s1%s] - %sNome:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NOME_COMPLETO);
                printf("\n[%s2%s] - %sEmail:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.USUARIO);
                printf("\n[%s3%s] - %sCelular:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.CELULAR);
                printf("\n[%s4%s] - %sNível:%s %s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.NIVEL==1?"Comum":"Administrativo");
                printf("\n[%s5%s] - %sStatus:%s %s%s%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET,LOGIN.STATUS==1?COLOR_GREEN:COLOR_RED,LOGIN.STATUS==1?"Ativo":"Desativo",COLOR_RESET);
                printf("\n[%s0%s] - %sVoltar%s",COLOR_YELLOW,COLOR_RESET,COLOR_CYAN,COLOR_RESET);

                printf("\n\n\n%sAtenção!%s\n",COLOR_YELLOW,COLOR_RESET);
                printf("Escolha o filtro desejado: ");
                scanf("%i",&opAux);
                fflush(stdin);

                switch(opAux)
                {
                    case 1:  
                        do{
                            i = 0, count_espacoBranco = 0, count_numeros = 0;
                            printf("\n\nDigite o nome completo: ");
                            gets(LOGIN.NOME_COMPLETO);
                            if(strlen(LOGIN.NOME_COMPLETO) == 0){
                                printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                                printf("O nome é obrigatório...\n\n");
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
                                    printf("Nome deve conter somente letras de A-Z...\n\n");
                                }else if(count_espacoBranco == 0){
                                    printf("\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
                                    printf("Nome inválido, digite o nome completo...\n\n");
                                }else{
                                    validaNome = true;
                                }
                            }

                        }while(validaNome == false);

                        //DEFINE O DESLOCAMENTO DO ARQUIVO PARA O INÍCIO.
                        fseek(arq, 0, SEEK_SET);
                        //REESCREVE OS DADOS  NO ARQUIVO;
                        fwrite(&LOGIN,sizeof(STRC_LOGIN),1,arq) == sizeof(STRC_LOGIN);

                        break;
                    case 2: 
                        break;
                    case 3:
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                        printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                        system("pause");
                        break;
                }
            }while(opAux!=0);
            break;
        }
    }

    fclose(arq);

    system("pause");
    
}
void FORMULARIO_USUARIO(char campo[]){
    if (strcmp("NOMECOMPLETO",campo) == 0){
        printf("Teste entrou\n");
    } else {
        printf("Caiu no else");
    }
}
void PRINTAR_USUARIO(STRC_LOGIN *USER){
    printf("\n%sNome:%s %s",COLOR_CYAN,COLOR_RESET,USER->NOME_COMPLETO);
    printf("\n%sEmail:%s %s",COLOR_CYAN,COLOR_RESET,USER->USUARIO);
    printf("\n%sCelular:%s %s",COLOR_CYAN,COLOR_RESET,USER->CELULAR);
    printf("\n%sNível:%s %s",COLOR_CYAN,COLOR_RESET,USER->NIVEL==1?"Comum":"Administrativo");
    printf("\n%sStatus:%s %s%s%s\n\n",COLOR_CYAN,COLOR_RESET,USER->STATUS==1?COLOR_GREEN:COLOR_RED,USER->STATUS==1?"Ativo":"Desativo",COLOR_RESET);
    SEPARADOR();
    printf("\n");
}