#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "linkedlist.c"

typedef struct pessoa
{
    char name[11];
    int rg;
} Pessoa;

void printlista(Pessoa *listasequencial, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n %d\n", listasequencial[i].name, listasequencial[i].rg);
    }
}

Pessoa pushfirstlista(Pessoa *listasequencial, int rows, char *name, int rg)
{
    int c = 0;
    int m = 0;
    for (int i = rows - 1; i > 0; i--)
    {
        strcpy(listasequencial[i].name, listasequencial[i - 1].name);
        listasequencial[i].rg = listasequencial[i - 1].rg;
        m += 2;
    }
    strcpy(listasequencial[0].name, name);
    listasequencial[0].rg = rg;
    m += 2;

    printf("%d C(n) na lista sequencial\n", c);
    printf("%d M(n) na lista sequencial\n", m);

    return *listasequencial;
}

Pessoa pushlastlista(Pessoa *listasequencial, int rows, char *name, int rg)
{
    int c = 0;
    int m = 0;
    m++;
    m++;
    strcpy(listasequencial[rows - 1].name, name);
    listasequencial[rows - 1].rg = rg;

    printf("%d C(n) na lista sequencial\n", c);
    printf("%d M(n) na lista sequencial\n", m);

    return *listasequencial;
}

Pessoa pushatlista(Pessoa *listasequencial, int rows, int n, char *name, int rg)
{
    int c = 0;
    int m = 0;

    for (int i = rows; i >= n - 1; i--)
    {
        strcpy(listasequencial[i + 1].name, listasequencial[i].name);
        listasequencial[i + 1].rg = listasequencial[i].rg;
        m += 2;
    }
    strcpy(listasequencial[n - 1].name, name);
    listasequencial[n - 1].rg = rg;
    m += 2;

    printf("%d C(n) na lista sequencial\n", c);
    printf("%d M(n) na lista sequencial\n", m);

    return *listasequencial;
}

Pessoa removeatlista(Pessoa *listasequencial, int rows, int index)
{
    int c = 0;
    int m = 0;

    for (int i = index; i < rows - 1; i++)
    {
        m++;
        listasequencial[i] = listasequencial[i + 1];
    }

    printf("%d C(n) na lista sequencial\n", c);
    printf("%d M(n) na lista sequencial\n", m);

    return *listasequencial;
}

Pessoa procurarlista(Pessoa *listasequencial, int rows, int rginput)
{
    int m = 0;
    int c = 0;

    m++;
    for (int i = 0; i < rows; i++)
    {
        c++;
        m++;
        if (listasequencial[i].rg == rginput)
        {
            printf("Nome: %s\n Posição: %d\n", listasequencial[i].name, i);
        }
    }

    printf("%d C(n) na lista sequencial\n", c);
    printf("%d M(n) na lista sequencial\n", m);

    return *listasequencial;
}
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
    List *linkedlist = makelist(rows);
    printf("%d rows\n", rows);

    /* read the file line by line */
    ////////////////////////////////////////////////////////////////////////////////////////////////

    Pessoa *listasequencial = (Pessoa *)malloc(2 * rows * sizeof(Pessoa));

    char *token = malloc(40 * sizeof(char));
    int c1 = 0;
    int m1 = 0;
    int c2 = 0;
    int m2 = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    while (fgets(line, sizeof(line), fp))
    {
        m1++;
        token = strtok(line, ",");
        c1++;
        if (token != NULL)
        {
            strcpy(listasequencial[k].name, token);
            m1++;
            token = strtok(NULL, ",");
            m1++;
        }
        c1++;
        if (token != NULL)
        {
            m1++;
            listasequencial[k].rg = atoi(token);
        }
        push(linkedlist, listasequencial[k].name, listasequencial[k].rg);
        c2 += 1;
        m2 += 4;
        k++;
    }

    printf("lista sequencial C(n) = %d\n", c1);
    printf("lista sequencial M(n)= %d\n", m1);
    printf("lista encadeada C(n) = %d\n", c2);
    printf("lista encadeada M(n)= %d\n", m2);

    ////////////////////////////////////////////////////////////////////////////////////////////////

    while (menu != 0)
    {
        printf("############################################################################\n");
        printf("Digite 1 para inserir um nó no início da lista.\n");
        printf("Digite 2 para inserir um nó no FIM da lista.\n");
        printf("Digite 3 para inserir um nó na posição N da lista.\n");
        printf("Digite 4 para RETIRAR um nó no início da lista.\n");
        printf("Digite 5 para RETIRAR um nó no FIM da lista.\n");
        printf("Digite 6 para RETIRAR um nó na posição N da lista.\n");
        printf("Digite 7 para Procurar um nó com o campo RG.\n");
        printf("Digite 8 para salvar em um arquivo\n");
        printf("Digite 9 para printar a lista em seu estado atual.\n");
        printf("Digite 0 para sair\n");
        printf("############################################################################\n");
        scanf("%d", &menu);

        if (menu == 1)
        // 111111111111111111111111111111
        {
            char nameinput[40] = "";
            int rginput = 0;
            rows++;
            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%d", &rginput);

            clock_t t1;
            t1 = clock();

            pushfirstnode(linkedlist, nameinput, rginput);

            t1 = clock() - t1;
            double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
            printf("comando levou %f sec na sequencial\n", time_taken1);

            clock_t t2;
            t2 = clock();

            *listasequencial = pushfirstlista(listasequencial, rows, nameinput, rginput);

            t2 = clock() - t2;
            double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
            printf("comando levou %f sec na sequencial\n", time_taken2);
            printf("Posição N: 1\n");
        }
        // 2222222222222222222222222222
        else if (menu == 2)
        {
            m1 = 0;
            c1 = 0;
            char nameinput[40] = "";
            int rginput = 0;
            rows++;

            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%d", &rginput);

            clock_t t1;
            t1 = clock();
            int c1 = 0;
            int m = 0;

            push(linkedlist, nameinput, rginput);
            c1++;
            m1 += 7;

            t1 = clock() - t1;
            double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
            printf("comando levou %f sec na encadeada\n", time_taken1);
            printf("lista encadeada C(n) = %d\n", c1);
            printf("lista encadeada M(n)= %d\n", m1);

            clock_t t2;
            t2 = clock();

            *listasequencial = pushlastlista(listasequencial, rows, nameinput, rginput);

            t2 = clock() - t2;
            double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
            printf("comando levou %f sec na sequencial\n", time_taken2);

            printf("Posição: %d\n", rows);
        }
        // 333333333333333333333333333333
        else if (menu == 3)
        {
            char nameinput[40] = "";
            int rginput = 0;
            int n;

            printf("Digite o nome: \n");
            scanf("%s", nameinput);

            printf("Digite o RG: \n");
            scanf("%d", &rginput);

            printf("Digite a posição N: \n");
            scanf("%d", &n);

            *listasequencial = pushatlista(listasequencial, rows, n, nameinput, rginput);

            pushatn(linkedlist, nameinput, rginput, n);

            printf("Nome: %s\n RG: %d\nPosição: %d\n", nameinput, rginput, n);
            rows++;
        }
        else if (menu == 4)
        // 444444444444444444444444444444444
        {
            removefirst(linkedlist);

            *listasequencial = removeatlista(listasequencial, rows, 0);
            rows--;
        }
        else if (menu == 5)
        // 555555555555555555555555
        {
            removelast(linkedlist, rows - 1);

            *listasequencial = removeatlista(listasequencial, rows, rows - 1);
            rows--;
        }
        else if (menu == 6)
        // 666666666666666666666666666666
        {
            int n;

            printf("Digite a posição N: \n");
            scanf("%d", &n);

            removeatn(linkedlist, n - 1);

            *listasequencial = removeatlista(listasequencial, rows, n);
            rows--;
        }
        else if (menu == 7)
        // 777777777777777777777777777
        {
            int rginput = 0;

            printf("Digite o RG: \n");
            scanf("%d", &rginput);

            clock_t t;
            t = clock();

            searchrg(linkedlist, rginput);

            *listasequencial = procurarlista(listasequencial, rows, rginput);

            double time_taken = ((double)t) / CLOCKS_PER_SEC;
            printf("lista levou %f sec \n", time_taken);
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
                fprintf(arq, "%d\n", listasequencial[i].rg);
            }

            fclose(arq);
        }
        else if (menu == 9)
        {
            printlista(listasequencial, rows);
        }
    }
    closelist(linkedlist);
}