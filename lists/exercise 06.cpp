// EXERCÍCIO 06
/*
Fazer um programa em C para ler uma lista de inteiros positivos
de 15 posições. Imprimir a quantidade de números pares e a
quantidade de múltiplos de 5
*/

// DEFININDO BIBLIOTECA 
#include <iostream>

// DEFINIÇÃO DA ESTRUTURA DO NÓ
struct No {
    int dado; // o valor da lista é armazenado em dado 
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

// FUNÇÃO PARA CONTAR QUANTIDADE DE PAR E MULTIPLO DE 5
void quant_par_e_impar (No* lista) {
    // DEFININDO PONTEIROS 
    No* atual = lista;

    // DEFININDO VARIÁVEIS 
    int cont_par = 0;
    int cont_cinco = 0; 

    // DEFININDO CONDIÇÕES 
    while (atual != nullptr) {
        if (atual -> dado % 2 == 0) {
            cont_par++;
        }
        if (atual -> dado % 5 == 0) {
            cont_cinco++;
        }
        atual = atual->proximo;
    }

    // IMPRIMINDO VALORES 
    std::cout << "Quantidade de numeros pares: " << cont_par << std::endl;
    std::cout << "Quantidade de multiplos de 5: " << cont_cinco << std::endl;
}

int main () {
    // INICIALIZANDO AS LISTAS 
    No* lista = inicializar();

    // DEFININDO AS VARIÁVEIS 
    int i;
    double valor; 

    // PEDINDO OS ELEMENTOS DA LISTA 
    for (i = 0; i < 15; i++) {
        std::cout << "Essa lista tem 15 elementos " << std::endl; 
        std::cout << "Digite um valor: " << std::endl; 
        std::cin >> valor; 
        lista = inserir(lista, valor); 
    }

    // IMPRIMINDO A LISTA 
    std::cout << "Lista: " << std::endl;
    percorrer(lista);
    std::cout << std::endl; 

    // CHAMANDO FUNÇÃO PARA IMPRIMIR OS VALORES 
    quant_par_e_impar(lista);

    // LIBERANDO A LISTA
    liberarLista(lista);

    return 0;
}
