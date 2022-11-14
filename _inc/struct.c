//=======================================================================================================
//INCLUDES
//=======================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //BIBLIOTECA PARA FUNÃÃES STRING
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
    int LIMITE_TEMPO;

}STRC_ESPACO;

