//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include "_inc/function.c" //TODAS AS STRUCTS DO SISTEMA
int main(){

    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    //boolean session = false;
    //int session_nivelAcesso;

    boolean session = true;
    int session_nivelAcesso = 2;

    arq = fopen(ARQ_LOGIN,"rb");

    if(arq==NULL){
        boolean cadastroFinalizado;
        CADASTRA_USUARIO(true, &cadastroFinalizado);
        if(cadastroFinalizado == false){
            printf("\n\nObrigado pela visita, até mais...\n");
            exit(1);
        }
    }
    fclose(arq);

    // do{
    //     CABECALHO();
    //     LOGIN_VALIDA_ACESSO(&session,&session_nivelAcesso);
    //     if (session == true){
    //         printf("%s\n\nAcesso permitido, seja bem-vindo!\n\n%s",COLOR_GREEN,COLOR_RESET);
    //     } else {
    //         printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
    //         printf("Acesso negado, usuário/senha incorreto...\n\n");
    //     }

    //     system ("pause");

    // }while (session == 0);

    if (session_nivelAcesso == 2){
        int op;
        do{
            CABECALHO();

            printf("[%s1%s] - Colaboradores\n",COLOR_YELLOW,COLOR_RESET);
            printf("[%s2%s] - Salas\n",COLOR_YELLOW,COLOR_RESET);
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
                    printf("Em CONSTRUÇÃO...");
                    system("pause >nul");
                    break;
                case 3:
                    printf("Em CONSTRUÇÃO...");
                    system("pause >nul");
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
                    printf("\n\nObrigado pela visita, até mais...\n");
                    exit(1);
                    break;
                default:
                    printf("\n\n%sAtenção!%s\n",COLOR_RED,COLOR_RESET);
                    printf("Opção não reconhecida. Selecione uma opção correta acima...\n\n");
                    system("pause");
                    break;
            }

        }while(op!=0);
    }

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
