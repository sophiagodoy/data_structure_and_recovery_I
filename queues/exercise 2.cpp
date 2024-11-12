// EXERCÍCIO 02
/*
Fazer um programa que faz a leitura de uma lista X com N inteiros (N
deve ser lido tb). Multiplique cada elemento de X por um inteiro K
(K também deverá ser lido). Imprimir a lista lida, o valor da variável K
e a lista multiplicada por K
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

// MULTIPLICANDO LISTA X E VARIÁVEL K 
void multiplicarporK (No* lista, int K) {
    // DEFININDO PONTEIRO 
    No* atual = lista; // cria um ponteiro (atual) que é inicializado para apontar para o início da lista 
    
    // PERCORRENDO A LISTA 
    while (atual != nullptr) {
        // atual é um ponteiro que aponta para o nó atual da lista 
        // dado é onde é armazenado o valor da lista 
        // atual->dado: o ponteiro (atual) aponta para o valor que o campo dado está acessando
        atual -> dado *= K; 
        atual = atual -> proximo; // o ponteiro (atual) aponta para o próximo nó da fila (próximo)
    }
}

int main () {
    // INICIALIZANDO LISTAS  
    No* listaX = inicializar();

    // DEFININDO VARIÁVEIS 
    int N, i, K, valor; 

    // PEDINDO O TAMANHO DA LISTA 
    std::cout << "Digite o tamanho da lista: ";
    std::cin >> N;

    // PEDINDO OS ELEMENTOS DA LISTA 
    for (i = 0; i < N; i++) {
        std::cout << "Digite um numero: ";
        std::cin >> valor; 
        listaX = inserir(listaX, valor);
    }

    // PEDINDO O VALOR DO INTEIRO K 
    std::cout << "Digite o valor de K: ";
    std::cin >> K;

    // IMPRIMIR A LISTA X 
    std::cout << "Lista X: ";
    percorrer(listaX);
    std::cout << std::endl; 

    // IMPRINDO K
    std::cout << "O valor de K e: " << K << std::endl; 

    // MULTIPLICANDO A LISTA POR K 
    multiplicarporK (listaX, K); 

    // IMPRIMINDO A LISTA MULTIPLICADA
    std::cout << "Lista X multiplicada por K: ";
    percorrer(listaX);
    std::cout << std::endl;

    // LIBERANDO A MEMÓRIA 
    liberarLista(listaX);

    return 0;
}
