//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include "_inc/function.c" //TODAS AS STRUCTS DO SISTEMA
int main(){
    
    int CPAGE_UTF8 = 65001;
    int CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    system("title KING'S OFFICE CORPORATION (C).");

    boolean session = false;
 
    session_nivelAcesso = 2;
    session_usuarioID = 1;

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
    //     LOGIN_VALIDA_ACESSO(&session);
    //     if (session == true){
    //         printf("%s\n\nAcesso permitido, seja bem-vindo!\n\n%s",COLOR_GREEN,COLOR_RESET);
    //     } else {
    //         printf("\n\n%sErro!%s\n",COLOR_RED,COLOR_RESET);
    //         printf("Acesso negado, usuário/senha incorreto...\n\n");
    //     }

    //     system ("pause");

    // }while (session == 0);

    //MENU_PRINCIPAL();  

    REL_RANKING_AGENDAMENTOS();

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
