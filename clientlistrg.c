#include <stdio.h>

/* Define nodes for the linked list */

typedef struct node
{
    char nome[20];
    char rg[7];
    int commaindex;
    struct node *next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n %d\n", current->nome, current->rg);
        current = current->next;
    }
}

int main()
{
    char line[40];
    int k = 0;
    char *filename = "NomeRG50.txt";
    FILE *fp = fopen(filename, "r");
    int r = 0;

    /* Handle errors on file opening*/

    if (fp == NULL)
    {
        printf("Error: Não foi possivel abrir o arquivo %s", filename);
        return 1;
    }

    

    struct node lista[100];
    while(fgets(line, sizeof line, fp))  {
        for (int i = 0; i < 50; i++) {
            if (line[i] == ',') {
                lista[k].commaindex = i;
            }
        }

        for (int j = 0; j < lista[k].commaindex; j++){
            lista[k].nome[j] = line[j];
        }
        r = 0;
        while(r < 7) {
            for (int m = lista[k].commaindex + 1; m < lista[k].commaindex + 9; m++) {
                lista[k].rg[r] = line[m];
                r++;
            }
        }

        k++;
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < lista[i].commaindex; j++){
            printf("%c", lista[i].nome[j]);
        }
        printf("\n");
        for (int m = 0; m < 8; m++) {
            printf("%c", lista[i].rg[m]);
        }
        printf("\n");
    }
    

    fclose(fp);
}

