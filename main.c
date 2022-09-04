//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include "_inc/function.c" //TODAS AS STRUCTS DO SISTEMA
  
int main(){  
    //setlocale(LC_ALL,"Portuguese"); 

    
 
    arq = fopen("ARQUIVOS/Login.txt","rb");
    fclose(arq);
 
    if(arq==NULL){
        LG_PRIMEIRO_ACESSO(true);
    }

    // int nivel_acesso;
    // if (nivel_acesso ==2){
    //     int op
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
