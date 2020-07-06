#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
    int** dados; // vetor com a rodada

}   Lance;

typedef struct
{
    char*   nome;
    Lance** lances; // os dados todos

}   Jogador;

typedef struct
{
    int         N; // jogando nessa mesa
    int         n_dados; // dados por vez
    int         rodada; // rodada atual
    char*       mesa;   // nome da mesa
    Jogador**   J; // vetor de jogadores

}   Jogo;


int     sorteio(int, int dado[]);

int main(int argc, char** argv)
{
    int N = 5;
    time_t agora; srand((unsigned)time(&agora));
    if (argc > 1) N = atoi(argv[1]);
    if ((N < 1) || (N > 30) ) N = 5;
    int dado[30];
    int soma = sorteio(N, dado);
    printf("%d dados: ", N);
    for (int i = 0; i < N; i += 1) printf("%d ", dado[i]);
    printf("\nsoma = %d\n", soma);
    return 0;
};

int sorteio(int N, int d[])
{   int soma = 0;
    for (int i = 0; i < N; i += 1)
    {   d[i] = 1 + rand() % 6;
        soma += d[i];
    };
    return soma;
};
// fim ch 1462928