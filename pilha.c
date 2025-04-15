#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void empilhar(No **topo, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = *topo;
    *topo = novo;
}

void desempilhar(No **topo) {
    if(*topo == NULL) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    No *temporario = *topo;
    int valorRemovido = temporario->valor;
    *topo = temporario->proximo;
    free(temporario);
    printf("Valor removido: %d \n", valorRemovido);
}

void imprimir(No *topo) {
    printf("Itens da pilha\n");
    for(No *atual = topo; atual != NULL; atual = atual->proximo) {
        printf("%d ", atual->valor);
    }
    printf("\n");
}

int main() {
    No *pilha = NULL;
    
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    
    imprimir(pilha);
    
    desempilhar(&pilha);
    
    imprimir(pilha);
    
    return 0;
}
