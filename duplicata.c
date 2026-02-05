#include <stdio.h>
#include <stdlib.h>

struct No {
    int num;
    struct No *ant, *prox;
};

struct No* removeDuplicatas(struct No *p) {
    if (p == NULL) return p;

    int vistos[100] = {0};
    struct No *atual = p;

    while (atual != NULL) {
        int val = atual->num;

        if (vistos[val]) {
            struct No *rem = atual;
            atual = atual->prox;

            if (rem->ant) rem->ant->prox = rem->prox;
            if (rem->prox) rem->prox->ant = rem->ant;

            free(rem);
        } else {
            vistos[val] = 1;
            atual = atual->prox;
        }
    }
    return p;
}

void imprime(struct No *p) {
    while (p) {
        printf("%d ", p->num);
        p = p->prox;
    }
    printf("\n");
}

int main() {
    struct No *a, *b, *c, *d, *p;

    a = malloc(sizeof(struct No));
    b = malloc(sizeof(struct No));
    c = malloc(sizeof(struct No));
    d = malloc(sizeof(struct No));

    a->num = 7; a->ant = NULL; a->prox = b;
    b->num = 1; b->ant = a;    b->prox = c;
    c->num = 7; c->ant = b;    c->prox = d;
    d->num = 1; d->ant = c;    d->prox = NULL;

    p = a;

    printf("Antes:\n");
    imprime(p);

    p = removeDuplicatas(p);

    printf("Depois:\n");
    imprime(p);

    return 0;
}