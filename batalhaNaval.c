#include <stdio.h>

#define LINHA 10
#define COLUNA 10

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
    int linhaD2 = 9;
    int colunaD2 = 9;

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
