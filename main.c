#include <stdio.h>
#include <stdlib.h>
#include "defs.c"

score scores[5];

/* Todas as pecas em todas as posicoes */
int allTetrominoes[7][4][4][4] =
{
  /* TETROMINO I */
  {
    {
      {0,0,0,0},
      {1,1,1,1},
      {0,0,0,0},
      {0,0,0,0}
    },  
    {
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0}
    },  
    {
      {0,0,0,0},
      {1,1,1,1},
      {0,0,0,0},
      {0,0,0,0}
    },
    {
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0},
      {0,1,0,0}
    }
  },
  
  /* TETROMINO J */
  {
    {
      {0,0,0,0},
      {1,0,0,0},
      {1,1,1,0},
      {0,0,0,0}
    },  
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,0,0},
      {0,1,0,0}
    },
    {
      {0,0,0,0},
      {1,1,1,0},
      {0,0,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,1,0},
      {0,0,1,0},
      {0,1,1,0}
    }
  },
  
  /* TETROMINO L */
  {
    {
      {0,0,0,0},
      {0,0,1,0},
      {1,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,0,0},
      {0,1,0,0},
      {0,1,1,0}
    },
    {
      {0,0,0,0},
      {1,1,1,0},
      {1,0,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,0,1,0},
      {0,0,1,0}
    }
  },
  
  /* TETROMINO O */
  {
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    }
  },
  
  /* TETROMINO S */
  {
    {
      {0,0,0,0},
      {0,1,1,0},
      {1,1,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,0,0},
      {0,1,1,0},
      {0,0,1,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {1,1,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,0,0},
      {0,1,1,0},
      {0,0,1,0}
    }
  },
  
  /* TETROMINO T */
  {
    {
      {0,0,0,0},
      {0,1,0,0},
      {1,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,0,0},
      {0,1,1,0},
      {0,1,0,0}
    },
    {
      {0,0,0,0},
      {1,1,1,0},
      {0,1,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,1,0},
      {0,1,1,0},
      {0,0,1,0}
    }
  },
  
  /* TETROMINO Z */
  {
    {
      {0,0,0,0},
      {1,1,0,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,1,0},
      {0,1,1,0},
      {0,1,0,0}
    },
    {
      {0,0,0,0},
      {1,1,0,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,1,0},
      {0,1,1,0},
      {0,1,0,0}
    }
  }
};

int campoJogo[ALTURA_CAMPO][LARGURA_CAMPO] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1}
};

int campoAux[ALTURA_CAMPO][LARGURA_CAMPO] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1}
};


int main(int argc, char *argv[])
{  
  int linha, coluna, tecla, codTetromino, rotTetrAux, contaFrames, rotTetromino, bateuFundo, acabou, nivel;
  int velocidade, score;
  int tetromino[4][4];
  int tetrominoAux[4][4];
  int linhaCheia;
  int niveis[10] = {19,17,15,13,11,9,7,5,3,1};  
  char nome[11];
  int pontuacao, i;
  
  RESTART:
    
  acabou = 0;
	contaFrames = 0;
  rotTetromino = 0;
  bateuFundo = 0;
  acabou = 0;
  nivel = 0;
  velocidade = 19;
  score = 0;
    
  esvaziaCampo(campoJogo);
  esvaziaCampo(campoAux);
  system("cls");
  desenhaCampo();
  
/* loop principal do jogo */  
do {
	
  /* Sorteia tetromino */
  codTetromino = rand() % 7;
  
  rotTetromino = 0;
    
  /* Faz cópia do tetromino */   
  copiaTetromino(tetromino, allTetrominoes[codTetromino][rotTetromino]);
  
  /* Posição inicial do tetromino */
  linha  = 0;
  coluna = 4;
  
  copiaCampo(campoAux, campoJogo);
  
  bateuFundo = 0;
  
  while (!bateuFundo) {
  	
	/* vê qual tecla foi apertada */	
    if (kbhit()) {
      tecla = getch();
    } 
    
    switch (tecla) {
      case 72: /* CIMA */
	    /*
	     * 1) copia a peça na nova posição pra uma variável auxiliar.
	     * 2) Vê se a peça da variável auxiliar vai colidir.
	     * 3) Caso não colida, copia a peça na nova posição pra variável de verdade.
		 */ 
        rotTetrAux = rotTetromino;
        rotTetrAux++;        
        if (rotTetrAux > 3) {rotTetrAux = 0; }
        copiaTetromino(tetrominoAux, allTetrominoes[codTetromino][rotTetrAux]);        
        if (!checkColisaoEsquerda(campoJogo, tetrominoAux, linha, coluna)) {
          if (!checkColisaoDireita(campoJogo, tetrominoAux, linha, coluna)) {
            rotTetromino = rotTetrAux;
            copiaTetromino(tetromino, allTetrominoes[codTetromino][rotTetromino]);
          }
        }        
        break;
      case 75: /* ESQUERDA */
  	    /* Se não colidir, bota peça mais pra esquerda */
        if ( !checkColisaoEsquerda(campoJogo, tetromino, linha, coluna-1) ) { coluna--; }
        break;
      case 77: /* DIREITA */
        /* Se não colidir, bota peça mais pra direita */
        if ( !checkColisaoDireita(campoJogo, tetromino, linha, coluna+1) ) { coluna++; }
        break;
      case 80: /* BAIXO */
        while ( !checkColisaoBaixo(campoJogo, tetromino, linha+1, coluna) ) {
          linha++;
          contaFrames = 33;
        }
        break;
    }    
    tecla = 0;
    
	/* Deixa a peça no lugar por 16 frames. Depois dos 16 frames, bota uma linha pra baixo.
	 * Antes de baixar a peça, verifica se vai colidir. Se for colidir, ou seja, bater no fundo,
	 * seta o flag bateuFundo como verdadeiro, para posteriormente armazenar o campo de jogo já
	 * com a peça grudada
   */
    contaFrames++;
    if (contaFrames >= ( nivel <= 9 ? niveis[nivel] : 1)) {
      if ( !checkColisaoBaixo(campoJogo, tetromino, linha+1, coluna) ) {
        linha++;
        contaFrames = 0;
      }
      else {
        bateuFundo = 1;
        contaFrames = 0;
      }      
    }

	  /* Copia o campo de jogo como ele estava antes de começar a descer a peça atual  */    
	  copiaCampo(campoAux, campoJogo);    
    
    
    /* copia a peça para o campo de jogo */
    copiaTetrominoCampo(campoAux, tetromino, linha, coluna);
    
    /* se bateu fundo, o campo de jogo vai ser atualizado com o campo auxiliar, grudando a peça
     * permanentemente
	 */
    if (bateuFundo) {
      score += eliminaLinhasCheias(campoAux);
      
      nivel = score / 10;
      
      if (linha <= 0) {
        acabou = 1;
      }
      
      copiaCampo(campoJogo, campoAux);    
    }
    testeDesenhaCampoJogo(campoAux);
    gotoxy(20,20);
    printf("PONTOS: %d", score);
    gotoxy(21,21);
    printf("Nivel: %d", nivel + 1);
    sleep(33);
  }
} while (acabou != 1);

if ( leHighScores(score, scores) ) {
  system("cls");
  printf("Digite seu nome\n: ");
  scanf("%s", &nome);
  gravaHighScores(nome, score, scores);
  printf("\nGaleria dos campeões:\n");
  for (i = 0; i <= 4; i++) {
    printf("\n%s %d\n", scores[i].nome, scores[i].pontuacao);
  }
  printf("\n");
}

gotoxy(22,22);
printf("Deseja jogar novamente? (S/N)\n: ");
int opcao = getch();
if (opcao == 115) {
  goto RESTART;
}

  return 0;
}
