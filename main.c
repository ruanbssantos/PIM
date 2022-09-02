#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> //CARACTER ESPECIAL DO PORTUGUES
#include <windows.h> //USAR COMANDOS DO WINDOWS
#include <time.h>


//=======================================================================================================
//FUNCTIONS CHAMADAS | PRINCIPAL
//=======================================================================================================
void HDR_FCN_CABECALHO();
void LIMPA_CONSOLE();
void DH_ATUAL();


//=======================================================================================================
//STRUNCT 
//=======================================================================================================
typedef struct {
  char DH_COMPLETA[21];
  char DT_COMPLETA[11];
  char DIA[3];
  char MES[3];
  char ANO[5]; 
  char HORAS[3]; 
  char MINUTOS[3]; 
  char SEGUNDOS[3]; 
}STRC_DH; 

int main(){
    
    setlocale(LC_ALL, "Portuguese");

    //FULL SCREEN
    //keybd_event ( VK_MENU, 0x36, 0, 0 ); 
    //keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
    //keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
    //keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
 
    HDR_FCN_CABECALHO();
     
    return 0;
}

//=======================================================================================================
//FUNCTIONS DECLARACAO | PRINCIPAL
//=======================================================================================================

//CRIA CABECALHO NO TOPO
void HDR_FCN_CABECALHO(){
 
    STRC_DH DH;

    LIMPA_CONSOLE();
 
    int x;
 
    printf("=============================================================================================\n");
    printf("======== King Consulting Corporation (c). Todos os direitos reservados [Versão 1.0] ========\n");
    printf("=============================================================================================\n");
    DH_ATUAL(&DH);
    printf("\033[0;31m"); 
    printf("\n\nDH_COMPLETA: %s",DH.DH_COMPLETA);
    printf("\nDT_COMPLETA %s",DH.DT_COMPLETA);
    printf("\nDIA %s",DH.DIA);
    printf("\nMES %s",DH.MES);
    printf("\nANO %s",DH.ANO);
    printf("\nHORAS %s",DH.HORAS);
    printf("\nMINUTOS %s",DH.MINUTOS);
    printf("\nSEGUNDOS %s",DH.SEGUNDOS) ;
    
    printf("\033[0m"); 
    printf("\n\nDigite um número: ");
    scanf("%i",&x);

    if (x==1){
        DH_ATUAL(&DH);
        printf("\033[0;32m"); 
        printf("\n\nDH_COMPLETA: %s",DH.DH_COMPLETA);
        printf("\nDT_COMPLETA %s",DH.DT_COMPLETA);
        printf("\nDIA %s",DH.DIA);
        printf("\nMES %s",DH.MES);
        printf("\nANO %s",DH.ANO);
        printf("\nHORAS %s",DH.HORAS);
        printf("\nMINUTOS %s",DH.MINUTOS);
        printf("\nSEGUNDOS %s",DH.SEGUNDOS) ;
    }

} 
//LIMPA O CONSOLE
void LIMPA_CONSOLE(){
    system("cls"); 
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