// EXERCÍCIO 07
/*
Ler uma lista A com 10 elementos inteiros correspondentes às
idades de um grupo de pessoas. Escreva um programa que
determine e escreva a idade média dos elementos lidos e
quantos elementos são menores que a média
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

// FUNÇÃO PARA DETERMINAR A MEDIA E QUANTAS IDADES SÃO MENORES QUE A MÉDIA 
void menor_que_a_media (No* lista) {
    // DEFININDO PONTEIRO 
    No* atual = lista; 

    // DEFININDO VARIÁVEIS
    int soma_idade = 0;
    int cont_menor_media = 0;
    int cont_elementos = 0; 
    int media; 

    // DEFININDO CONDIÇÕES 
    while (atual != nullptr) {
        soma_idade += atual -> dado; 
        cont_elementos++;
        atual = atual -> proximo; 
    }

    // CALCULANDO A MÉDIA 
    media = soma_idade / cont_elementos;

    // REINICIANDO PONTEIRO PARA CONTAR ELEMENTOS MENORES 
    atual = lista; // preciso reiniciar o ponteiro, pois após o primeiro loop que calcula a soma das idades o ponteiro estará no final da lista, e preciso que ele volte para o início 
    while (atual != nullptr) {
        if (atual -> dado < media) {
            cont_menor_media++;
        }
        atual = atual -> proximo;
    }

    // EXIBINDO 
    std::cout << "A media das idades e: " << media << std::endl;
    std::cout << "A quantidade de elementos menor que a media e: " << cont_menor_media << std::endl; 
}

int main () {
    // INICIALIZANDO A LISTA 
    No* lista = inicializar();

    // DEFININDO VARIÁVEIS
    int i; 
    double valor; 

    // PEDINDO INFORMAÇÕES 
    for (i = 0; i < 10; i++) {
        std::cout << "Essa é uma lista de 10 elementos " << std::endl;
        std::cout << "Digite um elemento: " << std::endl;
        std::cin >> valor;
        lista = inserir(lista, valor);
    }

    // IMPRINDO A LISTA
    std::cout << "Lista: " << std::endl;
    percorrer(lista);
    std::cout << std::endl;

    // CHAMANDO A FUNÇÃO 
    menor_que_a_media(lista);
    
    // LIBERANDO A LISTA 
    liberarLista(lista);

    return 0;
}
