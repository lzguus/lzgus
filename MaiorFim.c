#include <stdio.h>
#include <stdlib.h>

struct No {
    int num;
    struct No *ant, *prox;
};

struct No* maiorFim(struct No *p) {
    if (p == NULL || p->prox == NULL)
        return p;

    struct No *q = p, *maior = p;

    while (q != NULL) {
        if (q->num > maior->num)
            maior = q;
        q = q->prox;
    }

    if (maior->prox == NULL)
        return p;

    if (maior->ant != NULL)
        maior->ant->prox = maior->prox;
    else
        p = maior->prox; 

    if (maior->prox != NULL)
        maior->prox->ant = maior->ant;

    struct No *fim = p;
    while (fim->prox != NULL)
        fim = fim->prox;

    fim->prox = maior;
    maior->ant = fim;
    maior->prox = NULL;

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
    struct No *a, *b, *c, *d, *e, *p;

    a = malloc(sizeof(struct No));
    b = malloc(sizeof(struct No));
    c = malloc(sizeof(struct No));
    d = malloc(sizeof(struct No));
    e = malloc(sizeof(struct No));

    a->num = 11; a->ant = NULL; a->prox = b;
    b->num = 1;  b->ant = a;    b->prox = c;
    c->num = 5;  c->ant = b;    c->prox = d;
    d->num = 9;  d->ant = c;    d->prox = e;
    e->num = 6;  e->ant = d;    e->prox = NULL;

    p = a;

    printf("Antes:\n");
    imprime(p);

    p = maiorFim(p);

    printf("Depois:\n");
    imprime(p);

    return 0;
}