#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
    struct ListNode *next;
};

typedef struct {
    int tam;
    struct ListNode *inicio;
} Lista;

void CriarLista(Lista *lista) {
    lista->tam = 0;
    lista->inicio = NULL;
}

void Inserir(Lista *lista, int num) {
    struct ListNode *aux, *novo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novo->val = num;

    if(novo != NULL) {

        if(lista->inicio == NULL) {
            lista->inicio = novo;
           
        } else {
            aux = lista->inicio;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = novo;   
        }
        novo->next = NULL;

    } else {
        printf("Erro ao alocar memoria!");
    }
}



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

struct ListNode *auxA = headA;
    
while(auxA != NULL) {
    struct ListNode *auxB = headB;
    while(auxB != NULL) {
        if(auxA == auxB) {
            return auxA;
        }
        auxB = auxB->next;
    }
    auxA = auxA->next;
}
return NULL;
}

int main() {

    Lista lista, lista2;
    CriarLista(&lista);
    CriarLista(&lista2);

    
    Inserir(&lista, 1);
    Inserir(&lista, 2);

    
    Inserir(&lista2, 10);
    Inserir(&lista2, 20);

    
    struct ListNode *inter = (struct ListNode*)malloc(sizeof(struct ListNode));
    inter->val = 99;
    inter->next = NULL;

    struct ListNode *aux = lista.inicio;

    while(aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = inter;

    aux = lista2.inicio;

    while(aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = inter;

    struct ListNode *novo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novo->val = 100;
    novo->next = NULL;

    inter->next = novo;

    
    struct ListNode *resultado = getIntersectionNode(lista.inicio, lista2.inicio);

    if(resultado != NULL) {
        printf("Interseccao: %d\n", resultado->val);
    } else {
        printf("Nao existe interseccao\n");
    }

    return 0;
}

