//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //BIBLIOTECA PARA FUNÃÂÃÂES STRING
#include <locale.h> //CARACTER ESPECIAL DO PORTUGUES
#include <windows.h> //USAR COMANDOS DO WINDOWS
#include <time.h> //PEGAR DATA E HORA DO SISTEMA
#include <ctype.h> //CONTÉM FUNÇÕES DO TIPO BOOLEANN COMO ISDIGIT
#include <stdbool.h> //LÊ BOOLEANO
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
    char FEEDBACK[100];
    
    STRC_LOGIN USUARIO;
    STRC_ESPACO ESPACO;

}STRC_AGENDAMENTO;
