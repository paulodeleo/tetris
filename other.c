#include <stdio.h>
#include <conio2.h>
#include "defs.c"

void desenhaCampo()
{
  gotoxy(1,1);
  printf("+----------+\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("|          |\n");
  printf("+----------+\n");
}

void copiaTetromino(int tetrDestino[][4], int tetrOrigem[][4]) {  
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      tetrDestino[i][j] = tetrOrigem[i][j];
    }
  }
}

void desenhaTetromino (int tetr[][4], int x, int y) {
  int i, j;
  gotoxy(x,y);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (tetr[i][j]) { printf("#"); } else {printf(" ");}
    }
    y++;
    gotoxy(x,y);
  }
}

/* Coloca # onde tem 1 e espaço onde tem 0 */
void testeDesenhaCampoJogo(int campoJogo[][LARGURA_CAMPO]) {
  int i, j, x, y;
  
  x = 2;
  y = 2;
  
  for (i = 1; i < ALTURA_CAMPO-1; i ++) {    
    gotoxy(x,y);
    for (j = 1; j < LARGURA_CAMPO-1; j++) {
      if (campoJogo[i][j]) {
        printf("#");
      }
      else {
        printf(" ");
      }
    }
    y++;
    x = 2;
  }
}

/* copia uma peça para dentro do campo de jogo */
void copiaTetrominoCampo(int campoJogo[][LARGURA_CAMPO], int tetromino[][4], int linInicial, int colInicial) {

  int lin = 0, col = 0, i, j;

  col = colInicial;
  lin = linInicial;
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
		if (tetromino[i][j] == 1) {
    	  campoJogo[lin][col] = tetromino[i][j];
		}      
      col++;
    }
  lin++;
  col = colInicial;
  }
}

/* compara a ponta mais á esquerda da peça com a coluna onde a peça será desenhada*/
int checkColisaoEsquerda(int campo[][LARGURA_CAMPO], int tetr[][4], int linhaCampo, int colunaCampo) {     
  int i, colunaPonta = 0;
  while (tetr[0][colunaPonta] + tetr[1][colunaPonta] + tetr[2][colunaPonta] + tetr[3][colunaPonta] == 0) {
    colunaPonta++;
  }  
  for (i = 0; i <= 3; i++) {
    if (tetr[i][colunaPonta] && campo[linhaCampo+i][colunaCampo+colunaPonta] == 1) {
      return 1;
    }
  }  
  return 0;
}

/* compara a ponta mais á direita da peça com a coluna onde a peça será desenhada*/
int checkColisaoDireita(int campo[][LARGURA_CAMPO], int tetr[][4], int linhaCampo, int colunaCampo) {     
  int i, colunaPonta = 3;
  while (tetr[0][colunaPonta] + tetr[1][colunaPonta] + tetr[2][colunaPonta] + tetr[3][colunaPonta] == 0) {
    colunaPonta--;
  }  
  for (i = 0; i <= 3; i++) {
    if (tetr[i][colunaPonta] && campo[linhaCampo+i][colunaCampo+colunaPonta] == 1) {
      return 1;
    }
  }  
  return 0;
}

/* copia um campo de jogo dentro do outro */
void copiaCampo(int campoDestino[][LARGURA_CAMPO], int campoOrigem[][LARGURA_CAMPO]) {
  int i, j; 
  for (i = 0; i < ALTURA_CAMPO; i++) {
    for (j = 0; j < LARGURA_CAMPO; j++) {
      campoDestino[i][j] = campoOrigem[i][j];
    }
  }
}

int checkPrimeiraLinhaCheia(int campoJogo[][LARGURA_CAMPO]) {  
  int i;
  for (i = 1; i < ALTURA_CAMPO - 1; i++) {
    if (
         campoJogo[i][1] &&
         campoJogo[i][2] &&
         campoJogo[i][3] &&
         campoJogo[i][4] &&
         campoJogo[i][5] &&
         campoJogo[i][6] &&
         campoJogo[i][7] &&
         campoJogo[i][8] &&
         campoJogo[i][9] &&
         campoJogo[i][10] == 1
       ) {
           return i;
    }
  }
  return -1;  
}

int checkColisaoBaixo(int campo[][LARGURA_CAMPO], int tetr[][4], int linhaCampo, int colunaCampo) {
  int pontas[4] = {-1,-1,-1,-1};
  int i, j;
  for (j = 0; j <= 3; j++) {
    for (i = 3; i >= 0; i--) {
      if (tetr[i][j] == 1) {
        pontas[j] = i;
        break;
      }
    }
  }  
  for (i = 0; i <= 3; i++) {
    if (pontas[i] != -1) {
      if (campo[linhaCampo + pontas[i]][colunaCampo + i] && tetr[pontas[i]][i] == 1) {
        return 1;
      }
    }  
  }
  return 0;
}

int eliminaLinhasCheias(int campoJogo[][LARGURA_CAMPO]) {
  int linha, i, j, contaLinhas = 0;
  while (checkPrimeiraLinhaCheia(campoJogo) != -1) {
    contaLinhas++;
    linha = checkPrimeiraLinhaCheia(campoJogo);
    for (i = linha; i > 2; i--) {
      for (j = 1; j < LARGURA_CAMPO -1; j++) {
        campoJogo[i][j] = campoJogo[i-1][j];
      }
    }    
    for (j = 1; j < LARGURA_CAMPO - 1; j++) {
      campoJogo[1][j] = 0;
    }        
  }
  return contaLinhas;
}

int checkColisaoCima(int campo[][LARGURA_CAMPO], int tetr[][4], int linhaCampo, int colunaCampo) {
  int pontas[4] = {-1,-1,-1,-1};
  int i, j;
  for (j = 0; j <= 3; j++) {
    for (i = 0; i <= 3; i++) {
      if (tetr[i][j] == 1) {
        pontas[j] = i;
        break;
      }
    }
  }  
  for (i = 0; i <= 3; i++) {
    if (pontas[i] != -1) {
      if (campo[linhaCampo + pontas[i]][colunaCampo + i] && tetr[pontas[i]][i] == 1) {
        return 1;
      }
    }  
  }
  return 0;
}

/* ZERANDO A MATRIZ*/
void esvaziaCampo(int campo[][LARGURA_CAMPO]) {
  int i, j, flagOk = 0;  
  for(i=1; i < ALTURA_CAMPO-1; i++) {
    for(j=1; j < LARGURA_CAMPO-1; j++) {
	    campo[i][j] = 0;			
	  } 		 
	}
}
