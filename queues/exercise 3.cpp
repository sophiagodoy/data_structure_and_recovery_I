// EXERCÍCIO 03
/*
Fazer um programa que faz a leitura de uma lista X com N reais
(N deverá ser lido). Calcule o somatório de todos os elementos
da lista. Imprimir a lista lida e o valor do somatório.
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

double calculando_somatorio(No* lista) {
    // DEFININDO PONTEIROS 
    No* atual = lista; // cria um ponteiro (atual) que é inicializado para apontar para o início da lista 

    // DEFININDO VARIÁVEIS 
    double soma = 0;

    // REALIZANDO SOMATÓRIOS 
    while (atual != nullptr) {
        soma += atual -> dado; // pega o valor que o ponteiro atual aponta e soma com o valor da variável soma 
        atual = atual -> proximo; // passa para o próximo nó da lista 
    }

    return soma; // como retorna a soma e  ela é double a função tem que ser souble também 
}

int main () {
    // INICIALIZANDO LISTAS
    No* lista = inicializar(); 

    // DEFININDO VARIÁVEIS
    int N, i;
    double somatorio; 
    double valor; 

    // PEDINDO O TAMANHO DA LISTA 
    std::cout << "Digite o valor de N: ";
    std::cin >> N; 

    // LENDO A LISTA 
    for (i = 0; i < N; i++) {
        std::cout << "Digite o valor: "; 
        std::cin >> valor;
        lista = inserir(lista, valor); 
    }

    // IMPRIMINDO A LISTA 
    std::cout << "Os elementos da lista sao: " << std::endl; 
    percorrer(lista);
    std::cout << std::endl;

    // CHAMANDO A FUNÇÃO 
    somatorio = calculando_somatorio(lista); // o valor da soma deve ser armazenado em algum lugar nesse caso em somatorio

    // IMPRIMINDO VALOR DO SOMATÓRIO 
    std::cout << "O valor do somatorio e: " << somatorio; 

    // LIBERANDO A LISTA 
    liberarLista(lista);

    return 0; 
}
