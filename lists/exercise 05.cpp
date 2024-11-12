// EXERCÍCIO 05
/*
Ler uma lista de inteiros de N posições. Escreva a seguir o valor e
a posição do maior e menor elementos lidos
*/

// DEFININDO BIBLIOTECA 
#include <iostream>

// DEFINIÇÃO DA ESTRUTURA DO NÓ
struct No {
    double dado; // o valor da lista é armazenado em dado 
    No* proximo; // ponteiro que aponta para o próximo nó da lista
};

// FUNÇÃO PARA A INICIALIZAÇÃO DE UMA LISTA 
No* inicializar() {
    return nullptr; 
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NO FINAL DA LISTA
No* inserir(No* lista, double valor) {
    No* novo = new No;
    novo->dado = valor;
    novo->proximo = nullptr; 
    if (lista == nullptr) {
        return novo;
    } else {
        No* atual = lista;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo; 
        return lista; 
    }
}

// FUNÇÃO PARA PERCORRER A LISTA E IMPRIMIR OS ELEMENTOS 
void percorrer(No* lista) {
    No* atual = lista;
    while (atual != nullptr) {
        std::cout << atual->dado;
        atual = atual->proximo;
        if (atual != nullptr) {
            std::cout << " -> "; 
        }
    }
    std::cout << " -> nullptr"; 
}

// FUNÇÃO PARA LIBERAR A LISTA (LIBERAR A MEMÓRIA) 
void liberarLista(No* lista) {
    No* atual = lista;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp; 
    }
}

void vendo_maior_e_menor (No* lista) {
    // DEFININDO PONTEIROS 
    No* atual = lista; // cria um ponteiro (atual) que aponta para o início da lista

    // DEFININDO VARIÁVEIS
    double maior = atual -> dado; // inicializando com o primeiro nó da lista
    double menor = atual -> dado; 
    int posicao_maior = 0; // inicializados como 0, representando a posição do primeiro elemento da lista
    int posicao_menor = 0; // inicializados como 0, representando a posição do primeiro elemento da lista
    int posicao_atual = 0; // variável para rastrear a posição do nó atual durante a iteração pela lista


    // DEFININDO CONDIÇÕES 
    while (atual != nullptr) {
        if (atual -> dado > maior) { // verifica se o valor do nó atual é maior que o valor armazenado em maior 
            maior = atual -> dado; // se for maior, atualiza maior com o valor do nó atual e regustra a posicao atual em posicao_maior 
            posicao_maior = posicao_atual;
        }
        if (atual -> dado < menor) { // verifica se o valor do nó atual é menor que o valor armazenado em menor 
            menor = atual -> dado; // se for menor, atualiza menor e registra a posicao em posicao_menor
            posicao_menor = posicao_atual; 
        }
        atual = atual->proximo; // move o ponteiro para o próximo nó da lista 
        posicao_atual++; // para manter o rastreamento da posição do próximo nó 
    }
    std::cout << "O menor numero da lista e: " << menor << " na posicao " << posicao_menor << std::endl;
    std::cout << "O maior numero da lista e: " << maior << " na posicao " << posicao_maior << std::endl;
}

int main() {
    // INICIALIZANDO AS LISTAS
    No* lista = inicializar(); 

    // DEFININDO AS VARIÁVEIS 
    int N, i;
    double valor; 

    // PEDINDO O TAMANHO DA LISTA 
    std::cout << "Digite o tamanho da lista: ";
    std::cin >> N;
    
    // PEDINDO OS ELEMENTOS DA LISTA
    for (i = 0; i < N; i++) {
        std::cout << "Digite o valor: ";
        std::cin >> valor; 
        lista = inserir(lista, valor); 
    }

    // IMPRIMINDO A LISTA
    std::cout << "Lista: " << std::endl; 
    percorrer(lista);
    std::cout << std::endl;

    // IMPRIMINDO O MAIOR E O MENOR NÚMERO 
    vendo_maior_e_menor(lista);

    // LIBERANDO A LISTA
    liberarLista(lista); 

    return 0; 
}
