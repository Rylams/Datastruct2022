#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "linkedlist.c"

typedef struct pessoa
{
    char name[11];
    char rg[8];
} Pessoa;

void main(void)
{
    char line[40];
    int rows = 0;
    int k = 0;
    int menu = 1;
    char filename[15];

    /* read filename */

    int selectedfile = 0;
    printf("Digite o nome ou tamanho do arquivo.\n1 para 10 nomes\n2 para 50\n3 para 100\n4 para 1k\n5 para 10k\n6 para 1M\n7 para 100M\n");

    scanf("%d", &selectedfile);

    if (selectedfile == 1)
    {
        strcpy(filename, "NomeRG10.txt");
    }
    else if (selectedfile == 2)
    {
        strcpy(filename, "NomeRG50.txt");
    }
    else if (selectedfile == 3)
    {
        strcpy(filename, "NomeRG100.txt");
    }
    else if (selectedfile == 4)
    {
        strcpy(filename, "NomeRG1K.txt");
    }
    else if (selectedfile == 5)
    {
        strcpy(filename, "NomeRG10K.txt");
    }
    else if (selectedfile == 6)
    {
        strcpy(filename, "NomeRG1M.txt");
    }
    else if (selectedfile == 7)
    {
        strcpy(filename, "NomeRG100M.txt");
    }
    else
    {
        printf("digite um numero da lista");
        return;
    }

    printf("%s\n", filename);

    /* Handle errors on file opening*/

    FILE *fp = fopen(filename, "r");
    FILE *fp1 = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Não foi possivel abrir o arquivo %s\n", filename);
        return;
    }

    /* count rows from file */

    char buffer[128] = {0};
    while (fgets(buffer, sizeof buffer, fp1) != NULL)
    {
        if (strchr(buffer, '\n') != NULL)
        {
            rows++;
        }
        else if (feof(fp1))
        {
            rows++;
        }
    }
    rows++;
    List *linkedlist = makelist(rows);
    printf("%d rows\n", rows);

    /* read the file line by line */

    Pessoa *listasequencial = (Pessoa *)malloc(rows * sizeof(Pessoa));

    char *token = malloc(40 * sizeof(char));
    int c = 0;
    int m = 0;
    while (fgets(line, sizeof(line), fp))
    {
        token = strtok(line, ",");
        if (token != NULL)
        {
            c++;
            strcpy(listasequencial[k].name, token);
            m++;
            token = strtok(NULL, ",");
        }
        if (token != NULL)
        {
            m++;
            strcpy(listasequencial[k].rg, token);
        }
        push(linkedlist, listasequencial[k].name, listasequencial[k].rg);
        k++;
    }

    while (menu != 0)
    {
        printf("Digite 1 para inserir um nó no início da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 2 para inserir um nó no FIM da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 3 para inserir um nó na posição N da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 4 para RETIRAR um nó no início da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 5 para RETIRAR um nó no FIM da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 6 para RETIRAR um nó na posição N da lista e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 7 para Procurar um nó com o campo RG e apresentar Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.\n");
        printf("Digite 8 para salvar em um arquivo\n");
        printf("Digite 0 para sair\n");
        scanf("%d", &menu);

        if (menu == 1)
        {
            char nameinput[40] = "";
            char rginput[11] = "";
            char ch1 = '\n';
            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%s", rginput);

            strcat(rginput, &ch1);

            pushfirstnode(linkedlist, nameinput, rginput);

            clock_t t;
            t = clock();

            for (int i = sizeof(listasequencial) + 1; i > 0; i--)
            {
                listasequencial[i + 1] = listasequencial[i];
                m++;
            }

            strcpy(listasequencial[0].name, nameinput);
            m++;
            strcpy(listasequencial[0].rg, rginput);
            m++;

            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC;
            printf("lista sequencial levou %f sec \n", time_taken);
            printf("lista sequencial C(n) = %d\n", c);
            printf("lista sequencial M(n)= %d\n", m);

            printf("Nome: %s\n RG: %s\nPosição: 0\n", nameinput, rginput);
            print_list(linkedlist);
            return;
        }
        else if (menu == 2)
        {
            char *nameinput = malloc(sizeof(char));
            char *rginput = malloc(sizeof(char));

            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%s", rginput);

            clock_t t;
            t = clock();

            strcpy(listasequencial[rows + 1].name, nameinput);
            strcpy(listasequencial[rows + 1].rg, rginput);

            t = clock() - t;

            pushatn(linkedlist, listasequencial[rows + 1].name, listasequencial[rows + 1].rg, rows - 2);

            printf("teste %s\n", listasequencial[rows + 1].rg);

            double time_taken = ((double)t) / CLOCKS_PER_SEC;
            printf("lista sequencial levou %f sec \n", time_taken);
            printf("lista sequencial C(n) = %d\n", c);
            printf("lista sequencial M(n)= %d\n", m);

            printf("Nome: %s\n RG: %s\nPosição: %d\n", nameinput, rginput, rows);
            print_list(linkedlist);
            return;
        }
        else if (menu == 3)
        {

            char *nameinput = malloc(sizeof(char));
            char *rginput = malloc(sizeof(char));
            int n;

            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%s", rginput);

            printf("Digite a posição N: \n");
            scanf("%d", &n);

            pushatn(linkedlist, nameinput, rginput, n);

            printf("lista sequencial C(n) = %d\n", c);
            printf("lista sequencial M(n)= %d\n", m);

            printf("Nome: %s\n RG: %s\nPosição: %d\n", nameinput, rginput, n);
            print_list(linkedlist);
            return;
        }
        else if (menu == 4)
        {
            removefirst(linkedlist);
            print_list(linkedlist);
        }
        else if (menu == 5)
        {
            removelast(linkedlist, rows - 1);
            print_list(linkedlist);
        }
        else if (menu == 6)
        {
            int n;

            printf("Digite a posição N: \n");
            scanf("%d", &n);

            removeatn(linkedlist, n - 1);
            print_list(linkedlist);
        }
        else if (menu == 7)
        {
            char rginput[11] = "";
            char ch1 = '\n';
            char ch2 = '\0';

            printf("Digite o RG: \n");
            scanf("%s", rginput);
            strcat(rginput, &ch1);
            strcat(rginput, &ch2);

            /* busca na sequencial
            for (int i = 0; i < rows; i++)
            {
                printf("strcmp%d\n", strcmp(listasequencial[i].rg, rginput));
                if (strcmp(listasequencial[i].rg, rginput) == 0)
                {
                    printf("Nome: %s\n", listasequencial[i].name);
                }
            }
            */
            searchrg(linkedlist, rginput);

            printf("lista sequencial C(n) = %d\n", c);
            printf("lista sequencial M(n)= %d\n", m);
        }
        else if (menu == 8)
        {
            FILE *arq;

            arq = fopen("ArqGrav.txt", "wt"); // Cria um arquivo texto para gravação
            if (arq == NULL)                  // Se não conseguiu criar
            {
                printf("não foi possivel criar o arquivo\n");
                return;
            }

            for (int i = 0; i < rows + 1; i++)
            {
                fputs(listasequencial[i].name, arq);
                fputs(listasequencial[i].rg, arq);
            }

            fclose(arq);
        }
    }

    /*
    for (int l = 0; l < rows; l++)
    {
        printf("%s\n", listasequencial[l].name);
        printf("%s\n", listasequencial[l].rg);
    }

        print_list(linkedlist);
        */

    closelist(linkedlist);
}