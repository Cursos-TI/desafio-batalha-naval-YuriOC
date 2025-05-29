#include <stdio.h>

int main()
{
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
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

    int linhaH = 3;
    int colunaH = 4;

    if (linhaH >= 0 && linhaH < 10 && colunaH >= 0 && colunaH + 2 < 10)
    {
        int validadoH = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaH][colunaH + i] != 0)
            {
                validadoH = 0;
                break;
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
    }
    else
    {
        printf("Erro no navio horizontal \n");
    }

    // navio vertical

    int linhaV = 7;
    int colunaV = 4;

    if (linhaV >= 0 && linhaV + 2 < 10 && colunaV >= 0 && colunaV < 10)
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
