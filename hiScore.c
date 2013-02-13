#include <stdio.h>
#include <string.h>
#include "defs.c"

int leHighScores(int pontuacao, score scores[]) {
  
  score highScores[5];
  
  int i;
  
  FILE *arq;
  arq = fopen("highScores.bin", "rb");
  
  if (arq == NULL) {
    arq = fopen("highScores.bin", "wb");
    
    strcpy(highScores[0].nome, "Chefe");
    strcpy(highScores[1].nome, "Calegari");
    strcpy(highScores[2].nome, "Alexey");
    strcpy(highScores[3].nome, "Carmack");
    strcpy(highScores[4].nome, "Myiamoto");

    highScores[0].pontuacao = 50;
    highScores[1].pontuacao = 40;
    highScores[2].pontuacao = 30;
    highScores[3].pontuacao = 20;
    highScores[4].pontuacao = 10;

    fwrite(highScores, sizeof(score), 5, arq);  
    fclose(arq);
    arq = fopen("highScores.bin", "rb");
  }
  
  fread(scores, sizeof(score), 5, arq);
  
  fclose(arq);
  
  for (i = 0; i <= 4; i++) {
    if (pontuacao >= scores[i].pontuacao) {
      return 1;
    }
  }  
  return 0;
}



int gravaHighScores(char nome[], int pontuacao, score scores[]) {
  
  int i = 0;
  int j;
  int achou = 0;
  
  FILE *arq;

  while (!achou) {
    if (pontuacao >= scores[i].pontuacao) {
      for (j = 4; j > i; j--) {
        strcpy(scores[j].nome, scores[j-1].nome);
        scores[j].pontuacao = scores[j-1].pontuacao;
      }
      strcpy(scores[i].nome, nome);
      scores[i].pontuacao = pontuacao;
      achou = 1;
    } else {
      i++;
    }
  }
    
  arq = fopen("highScores.bin", "wb");  
  fwrite(scores, sizeof(score), 5, arq);
  fclose(arq);
}
