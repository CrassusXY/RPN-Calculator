#ifndef moduly_h
#define moduly_h
#define B_STOSPUSTY -1
#define W_OK 0
#define MAX 100

typedef struct lelem{
    int dana;
    struct lelem *nxt;
} lelem_t;

typedef struct stack {
    lelem_t *head; 
} stack_t;


int isempty(stack_t *stos);

void push(stack_t *stos, int liczba);

void pop(stack_t *stos, int *out);

void print(stack_t *stos);

void duplikuj(stack_t *stos);

void clear(stack_t *stos);

void print_full(stack_t *stos);

void zamien(stack_t *stos);

void dodaj(stack_t *stos);

void odejmij(stack_t *stos);

void pomnoz(stack_t *stos);

void podziel(stack_t *stos);

#endif