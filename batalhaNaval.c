#include <stdio.h>

// TABULEIRO
#define LINHA 10
#define COLUNA 10

// HABILIDADES
#define LINHAC 3
#define COLUNAC 5

int main()
{
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LINHA][COLUNA];
    int i, j;

    // transforma todas as casas em 0 (agua)
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // navio horizontal

    int linhaH = 1;
    int colunaH = 1;

    if (linhaH >= 0 && linhaH < LINHA && colunaH >= 0 && colunaH + 2 < LINHA)
    {
        int validadoH = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaH][colunaH + i] != 0)
            {
                validadoH = 0;
                break;
            }
        }

        if (validadoH)
        {
            for (j = 0; j < 3; j++)
            {
                tabuleiro[linhaH][colunaH + j] = 3;
            }
        }
        else
        {
            printf("Erro no navio horizontal \n");
        }
    }
    else
    {
        printf("Erro no navio horizontal \n");
    }

    // navio vertical

    int linhaV = 3;
    int colunaV = 4;

    if (linhaV >= 0 && linhaV + 2 < LINHA && colunaV >= 0 && colunaV < COLUNA)
    {
        int validadoV = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaV + i][colunaV] != 0)
            {
                validadoV = 0;
                break;
            }
        }

        if (validadoV)
        {
            for (j = 0; j < 3; j++)
            {
                tabuleiro[linhaV + j][colunaV] = 3;
            }
        }
        else
        {
            printf("Erro no navio vertical \n");
        }
    }
    else
    {
        printf("Erro no navio vertical \n");
    }

    // navio diagonal 1

    int linhaD1 = 7;
    int colunaD1 = 7;

    if (linhaD1 >= 0 && linhaD1 + 2 < LINHA && colunaD1 >= 0 && colunaD1 + 2 < COLUNA)
    {
        int validadoD1 = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
            {
                validadoD1 = 0;
                break;
            }
        }

        if (validadoD1)
        {
            for (j = 0; j < 3; j++)
            {
                tabuleiro[linhaD1 + j][colunaD1 + j] = 3;
            }
        }
        else
        {
            printf("Erro no navio diagonal 1 \n");
        }
    }
    else
    {
        printf("Erro no navio diagonal 1 \n");
    }

    // navio diagonal 2
    int linhaD2 = 5;
    int colunaD2 = 2;

    if (linhaD2 >= 0 && linhaD2 < LINHA && colunaD2 >= 0 && colunaD2 < COLUNA)
    {
        int validadoD1 = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaD2 - i][colunaD2 - i] != 0)
            {
                validadoD1 = 0;
                break;
            }
        }

        if (validadoD1)
        {
            for (j = 0; j < 3; j++)
            {
                tabuleiro[linhaD2 - j][colunaD2 - j] = 3;
            }
        }
        else
        {
            printf("Erro no navio diagonal 2 \n");
        }
    }
    else
    {
        printf("Erro no navio diagonal 2 \n");
    }

    //------CONE---------

    // posicoes do cone
    int linhaTabuCone = 7;
    int colunaTabuCone = 3;

    // criacao do cone
    int cone[LINHAC][COLUNAC] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5}};

    // valida cone nos limites do tabuleiro
    if (linhaTabuCone >= 0 && linhaTabuCone + 2 < LINHA && colunaTabuCone - 2 >= 0 && colunaTabuCone + 2 < COLUNA)
    {
        // aplica no tabuleiro
        tabuleiro[linhaTabuCone][colunaTabuCone] = 5;

        for (j = 0; j < 3; j++)
        {
            tabuleiro[linhaTabuCone + 1][(colunaTabuCone - 1) + j] = 5;
        }
        for (j = 0; j < COLUNAC; j++)
        {
            tabuleiro[linhaTabuCone + 2][(colunaTabuCone - 2) + j] = 5;
        }
    }
    else
    {
        printf("Posicao do cone invalida");
    }

    //-----CRUZ-------

    int linhaTabuCruz = 6;
    int colunaTabuCruz = 7;

    // criacao do cone
    int cruz[LINHAC][COLUNAC] = {
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0}};

    // valida cruz nos limites do tabuleiro
    if (linhaTabuCruz - 1 >= 0 && linhaTabuCruz + 1 < LINHA && colunaTabuCruz - 2 >= 0 && colunaTabuCruz + 2 < COLUNA)
    {
        // Aplica primeira linha
        tabuleiro[linhaTabuCruz - 1][colunaTabuCruz] = 5;

        // aplica segunda linha
        for (j = 0; j < COLUNAC; j++)
        {
            tabuleiro[linhaTabuCruz][(colunaTabuCruz - 2) + j] = 5;
        }

        // aplica terceira linha
        tabuleiro[linhaTabuCruz + 1][colunaTabuCruz] = 5;
    }
    else
    {
        printf("Posicao da cruz invalida");
    }

    //-----OCTAEDRO-------
    int linhaTabuOcta = 2;
    int colunaTabuOcta = 7;

    // criacao do octaedro
    int octa[LINHAC][COLUNAC] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0}};

    // valida octaedro nos limites do tabuleiro
    if (linhaTabuOcta - 1 >= 0 && linhaTabuOcta + 1 < LINHA && colunaTabuOcta - 1 >= 0 && colunaTabuOcta + 1 < COLUNA)
    {

        // Aplica primeira linha
        tabuleiro[linhaTabuOcta - 1][colunaTabuOcta] = 5;

        // Aplica segunda linha
        for (j = 0; j < 3; j++)
        {
            tabuleiro[linhaTabuOcta][(colunaTabuOcta - 1) + j] = 5;
        }

        // aplica terceira linha
        tabuleiro[linhaTabuOcta + 1][colunaTabuOcta] = 5;
    }
    else
    {
        printf("Posicao do octaedro invalida");
    }

    // exibe o tabuleiro
    printf("\n --- Tabuleiro --- \n  ");
    for (i = 0; i < 10; i++)
    {
        printf(" %c", linha[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("\n %d ", i + 1);
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
    }

    return 0;
}
