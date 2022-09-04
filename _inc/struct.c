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


typedef struct
{
    char USUARIO[11];
    int NIVEL;
    char SENHA[20];
    int STATUS;

}STRC_LOGIN; 
