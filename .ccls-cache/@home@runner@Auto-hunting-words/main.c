#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIN 20
#define COL 20

typedef struct {
  char palavra[50];
  char matriz[LIN][COL];
  char grade[LIN*COL+1]; 

} Variaveis;

typedef struct {
  int li;
  int ci;
  int lf; 
  int cf;

} Roi;

void matrizPelaString(char grade[LIN*COL+1], char matriz[LIN][COL]);
void escreverMatriz(char matriz[LIN][COL]);
int cacaPalavras(char matriz[LIN][COL]);
Roi encontraPalavra(char matriz[LIN][COL], char palavra[50]);
Roi buscaPalavra(char matriz[LIN][COL], char palavra[50], int li, int ci, int prox_lf, int prox_cf);
void escreverCoord(Roi coord);

int main() {
  Variaveis var;
  matrizPelaString(var.grade, var.matriz);
  escreverMatriz(var.matriz);
  if (!cacaPalavras(var.matriz)) {
    return 0;

  }
}

void matrizPelaString(char grade[], char matriz[][COL]) {
  int i, j;
  strcpy(grade, "AZOAAOAVAFAZOTTOAVACALPADUMVUGAOPADUMVOGTTGAAOASOETIEAAOAMOEATJOVPRARRATJLVSPARRJAOARRATSTJAOAAURPSTAOJALIVRYIAOJATPVAAIONRLMETFAOONRAMMEFUOPAPPTVAMNLPACPTAANNAOVTSTOUROAEAAAPCURAAAOTTRAASSSOLWTRAASNPAZOATOAVA--ZEQROAVAFAOPADUMVNGANPPPUMVUGTREAAOAOOETROAIZASOEARJLVMTARRARJTVPVARRJAOACAZINAGROOAREBSTAOJA-LVAAIAOJAL-PDNIONRDMEEFUOONRLMEDFOOPDEDICACAOPAPPTVAENAOZATTOURAAOVATIOTRZAAOTTRAASNPAOTTRAASNO");
  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++) {
      matriz[i][j] = grade[(i * COL + j)];

    }
  }
}

void escreverMatriz(char matriz[LIN][COL]) {
  int i, j;
  printf("\nProcure uma palavra na matriz abaixo...\n");
  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++) {
      printf("%c ", matriz[i][j]);

    }
    printf("\n");

  }
}

int cacaPalavras(char matriz[LIN][COL]) {
  Roi coord;
  int continuar = 1;

  while (continuar == 1) {
    Variaveis var;
    printf("\nDigite a palavra a ser encontrada: ");
    scanf("%s", var.palavra);
    coord = encontraPalavra(matriz, var.palavra);
    escreverCoord(coord);
    printf("\nContinuar?\n1 = sim | 0 = nao\n");
    scanf("%i", &continuar);

  }
  printf("\nTchau! Tchau! XD\nMe da um 10 Manasses!!!!\n");
  return 0;

}

Roi encontraPalavra(char matriz[LIN][COL], char palavra[50]) {
  Roi coord;
  int li, ci;
  int lf, cf;
  int prox_lf, prox_cf;

  for (li = 0; li < LIN; li++) { 
    for (ci = 0; ci < COL; ci++) { 
      if (matriz[li][ci] == palavra[0]) {
        for (prox_lf = -1; prox_lf <= 1; prox_lf++) { 
          for (prox_cf = -1; prox_cf <= 1; prox_cf++) { 
            if (prox_lf != 0 || prox_cf != 0) { 
              coord = buscaPalavra(matriz, palavra, li, ci, prox_lf, prox_cf);
              if (coord.li != 0 || coord.ci != 0 || coord.lf != 0 || coord.cf != 0) {
                return coord;

              }
            }
          }
        }
      }
    }
  }
  return coord;

}

Roi buscaPalavra(char matriz[LIN][COL], char palavra[50], int li, int ci, int prox_lf, int prox_cf) {
  Roi coord;
  coord.li = 0;
  coord.lf = 0; 
  coord.ci = 0;
  coord.cf = 0;
  int lf = li;
  int cf = ci; 
  int palavraLetras = 1; 

  while (palavra[palavraLetras] != '\0') { 
    lf += prox_lf;
    cf += prox_cf;
    if (lf < 0 || lf >= LIN || cf < 0 || cf >= COL) { 
      return coord;

    }
    if (matriz[lf][cf] != palavra[palavraLetras]) { 
      return coord;

    }
    palavraLetras++; 

  }
  coord.li = li;
  coord.lf = lf; 
  coord.ci = ci;
  coord.cf = cf;

  return coord;

}

void escreverCoord(Roi coord) {
  printf("{ %i, %i, %i, %i }\n", coord.li, coord.ci , coord.lf, coord.cf);

}
