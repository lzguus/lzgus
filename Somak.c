#include <stdio.h>
#include <stdlib.h>

struct No {
    int num;
    struct No *ant, *prox;
};

int parComSoma(struct No *p, int k) {
    if (p == NULL) return 0;

    struct No *ini = p, *fim = p;

    // vai até o fim
    while (fim->prox != NULL)
        fim = fim->prox;

    while (ini != fim) {
        int soma = ini->num + fim->num;

        if (soma == k)
            return 1; // achou!
        else if (soma < k)
            ini = ini->prox;
        else
            fim = fim->ant;
    }
    return 0; 
}

int main() {
    struct No *a, *b, *c, *d, *e, *f, *p;
    a = malloc(sizeof(struct No));
    b = malloc(sizeof(struct No));
    c = malloc(sizeof(struct No));
    d = malloc(sizeof(struct No));
    e = malloc(sizeof(struct No));
    f = malloc(sizeof(struct No));

    a->num = 1; a->ant = NULL; a->prox = b;
    b->num = 4; b->ant = a;    b->prox = c;
    c->num = 7; c->ant = b;    c->prox = d;
    d->num = 9; d->ant = c;    d->prox = e;
    e->num = 11; e->ant = d;   e->prox = f;
    f->num = 15; f->ant = e;   f->prox = NULL;

    p = a;

    int k = 15;

    if (parComSoma(p, k))
        printf("Sim, existe par com soma = %d\n", k);
    else
        printf("Nao existe par com soma = %d\n", k);

    return 0;
}
