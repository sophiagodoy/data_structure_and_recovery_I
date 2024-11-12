// EXERCÍCIO ARVORES 
/*
Elabore um procedimento que
• a) Determine a soma de elementos de uma árvore.
• b) Número de descendentes de um nó se ele existir
na árvore.
• c) Imprime o pai de um certo nó, se ele existir na
árvore.
*/

// DEFININDO BIBLIOTECAS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct NoArvore {
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
};

struct Arvore {
    struct NoArvore *raiz;
};

// FUNÇÃO PARA CRIAR UMA ÁRVORE 
struct Arvore* Criar() {
    struct Arvore *arvore = (struct Arvore *)malloc(sizeof(struct Arvore));
    arvore->raiz = NULL;
    return arvore;
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NA ÁRVORE
struct NoArvore* InserirNo(struct NoArvore *no, int valor) {
    if (no == NULL) {
        struct NoArvore *novoNo = (struct NoArvore *)malloc(sizeof(struct NoArvore));
        novoNo->info = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        return novoNo;
    }
    if (valor < no->info) {
        no->esq = InserirNo(no->esq, valor);
    } else if (valor > no->info) {
        no->dir = InserirNo(no->dir, valor);
    }
    return no;
}

// FUNÇÃO PARA INSERIR UM VALOR NA ÁRVORE A PARTIR DA RAIZ
void Inserir(struct Arvore *arvore, int valor) {
    arvore->raiz = InserirNo(arvore->raiz, valor);
}

// FUNÇÃO PARA IMPRIMIR A ÁRVORE EM ORDEM (EM UMA REPRESENTAÇÃO HIERÁRQUICA)
void ImprimirNo(struct NoArvore *no, int level) {
    if (no != NULL) {
        char txt[100];
        txt[0] = '\0';
        for (int c = 0; c < level - 1; c++) {
            strcat(txt, " ");
        }
        if (level > 0) strcat(txt, "|..");
        printf("%s%d\n", txt, no->info);
        ImprimirNo(no->esq, level + 1);
        ImprimirNo(no->dir, level + 1);
    }
}

// INTERFACE PARA IMPRIMIR A ÁRVORE 
void Imprimir(struct Arvore *arvore) {
    ImprimirNo(arvore->raiz, 0);
    printf("\n");
}

// VERIFICA SE A ÁRVORE ESTÁ VAZIA
int EstaVazia(struct Arvore *arvore) {
    return arvore->raiz == NULL;
}

// BUSCAR UM ELEMENTO NA ÁRVORE 
bool BuscarNo(struct NoArvore *no, int valor) {
    if (no == NULL) return false;
    if (no->info == valor) return true;
    return (valor < no->info) ? BuscarNo(no->esq, valor) : BuscarNo(no->dir, valor);
}

// INTERFACE PARA BUSCAR UM ELEMENTO NA ÁRVORE 
bool Buscar(struct Arvore *arvore, int valor) {
    return BuscarNo(arvore->raiz, valor);
}

// LIBERAR A MEMÓRIA DOS NÓS DE FORMA RECURSIVA
void LiberarNo(struct NoArvore *no) {
    if (no != NULL) {
        LiberarNo(no->esq);
        LiberarNo(no->dir);
        free(no);
    }
}

// LIBERA A MEMÓRIA DA ÁRVORE INTEIRA 
void Liberar(struct Arvore *arvore) {
    LiberarNo(arvore->raiz);
    free(arvore);
}

// FUNÇÃO PARA REMOLVER UM ELEMENTO
struct NoArvore* RemoverNo(struct NoArvore *no, int valor) {
    if (no == NULL) return NULL;
    if (valor < no->info) {
        no->esq = RemoverNo(no->esq, valor);
    } else if (valor > no->info) {
        no->dir = RemoverNo(no->dir, valor);
    } else {
        if (no->esq == NULL) {
            struct NoArvore *temp = no->dir;
            free(no);
            return temp;
        } else if (no->dir == NULL) {
            struct NoArvore *temp = no->esq;
            free(no);
            return temp;
        }
        struct NoArvore *temp = no->dir;
        while (temp && temp->esq != NULL) {
            temp = temp->esq;
        }
        no->info = temp->info;
        no->dir = RemoverNo(no->dir, temp->info);
    }
    return no;
}

// INTERFACE PARA REMOLVER UM ELEMENTO
void Remover(struct Arvore *arvore, int valor) {
    arvore->raiz = RemoverNo(arvore->raiz, valor);
}

// FUNÇÃO PARA SOMAR TODOS OS ELEMENTOS 
int SomaElementos(struct NoArvore *no) {
    if (no == NULL) return 0;
    return no->info + SomaElementos(no->esq) + SomaElementos(no->dir);
}

// FUNÇÃO PARA CONTAR O NÚMERO DE DESCENDENTES DE UM NO
int ContarDescendentes(struct NoArvore *no) {
    if (no == NULL) return 0;
    return 1 + ContarDescendentes(no->esq) + ContarDescendentes(no->dir);
}

// FUNÇÃO PARA ENCONTRAR O NÓ ESPECÍFICO 
struct NoArvore* EncontrarNo(struct NoArvore *no, int valor) {
    if (no == NULL || no->info == valor) {
        return no;
    }
    if (valor < no->info) {
        return EncontrarNo(no->esq, valor);
    } else {
        return EncontrarNo(no->dir, valor);
    }
}

// FUNÇÃO PARA IMPRIMIR O PAI DE UM NÓ
void ImprimirPai(struct NoArvore *no, int valor, struct NoArvore *pai) {
    if (no == NULL) return;
    if (no->info == valor) {
        if (pai != NULL) {
            printf("O pai do no %d e %d.\n", valor, pai->info);
        } else {
            printf("O no %d e a raiz e nao tem pai.\n", valor);
        }
        return;
    }
    ImprimirPai(no->esq, valor, no);
    ImprimirPai(no->dir, valor, no);
}

int main() {
    // DEFININDO VARIÁVEIS
    struct Arvore *arvore = Criar();
    int opcao, valor;
    
    // DEFININDO CONDIÇÕES 
    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Imprimir arvore\n");
        printf("3. Buscar elemento\n");
        printf("4. Remover elemento\n");
        printf("5. Soma de elementos\n");
        printf("6. Numero de descendentes de um no\n");
        printf("7. Imprimir pai de um no\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            // INSERIR ELEMENTO
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                Inserir(arvore, valor);
                break;  // Não esqueça o break
            // IMPRIMIR ÁRVORE
            case 2:
                printf("Arvore:\n");
                Imprimir(arvore);
                break;
            // BUSCAR ELEMENTO
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                printf(Buscar(arvore, valor) ? "Elemento encontrado.\n" : "Elemento nao encontrado.\n");
                break;
            // REMOLVER ELEMENTO
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                Remover(arvore, valor);
                break;
            // SOMAR ELEMENTOS
            case 5:
                printf("Soma dos elementos da arvore: %d\n", SomaElementos(arvore->raiz));
                break;
            // CONTAR DESCENDENTES 
            case 6:
                printf("Digite o valor do no para contar descendentes: ");
                scanf("%d", &valor);
                struct NoArvore *noEncontrado = EncontrarNo(arvore->raiz, valor);
                if (noEncontrado) {
                    printf("Numero de descendentes: %d\n", ContarDescendentes(noEncontrado) - 1);  // Não contar o nó em si
                } else {
                    printf("No nao encontrado.\n");
                }
                break;
            // ENCONTRAR O PAI
            case 7:
                printf("Digite o valor do no para encontrar o pai: ");
                scanf("%d", &valor);
                ImprimirPai(arvore->raiz, valor, NULL);
                break;
            // SAIR
            case 0:
                printf("Saindo...\n");
                Liberar(arvore);
                break;
            // OPÇÃO INVÁLIDA
            default:
                printf("Opcao invalida.\n");
                break;  
        }
    } while (opcao != 0);
    
    return 0;
}
