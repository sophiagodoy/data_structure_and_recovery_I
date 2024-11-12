// EXERCÍCIO 04
/*
Fazer um programa que faz a leitura de uma lista X, com N
inteiros (N deverá ser lido). Gere uma segunda lista com os
valores de X em ordem inversa. Imprimir X e a lista com a
ordem inversa.
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

// FUNÇÃO PARA INSERIR UM ELEMENTO NO INÍCIO DA LISTA (USADA PARA CRIAR A LISTA INVERSA)
No* inserirInicio(No* lista, double valor) {
    No* novo = new No; // essa linha aloca dinamicamente um novo nó na memória e atribui o ponteiro para ele à variável novo
    novo->dado = valor; // campo dado do novo nó é preenchido com o valor fornecido como argumento
    novo->proximo = lista; // o ponteiro proximo do novo nó é ajustado para apontar para o nó que antes era o primeiro da lista (o que está sendo passado como parâmetro). isso faz com que o novo nó se torne o primeiro da lista, e o antigo primeiro nó passe a ser o segundo
    return novo; // retorna o ponteiro para o novo nó, que agora é o início da lista
}

int main() {
    // INICIALIZANDO A LISTA 
    No* listaX = inicializar();
    No* listaY = inicializar(); 

    // DEFININDO VARIÁVEIS 
    int N, i;
    double valor; 

    // PEDINDO O TAMANHO DA LISTA 
    std::cout << "Digite o tamanho da lista: "; 
    std::cin >> N; 

    // PEDINDO OS ELEMENTOS DA LISTA E CRIANDO A LISTA NORMAL E INVERSA
    for (i = 0; i < N; i++) {
        std::cout << "Digite um valor: "; 
        std::cin >> valor; 
        // INSERINDO OS VALORES NA LISTA NORMAL
        listaX = inserir(listaX, valor);
        // INSERINDO OS VALORES NA LISTA INVERSA
        listaY = inserirInicio(listaY, valor);
    }

    // IMPRIMINDO A LISTA NORMAL 
    std::cout << "Lista normal: " << std::endl; 
    percorrer(listaX);
    std::cout << std::endl;

    // IMPRIMINDO LISTA INVERSA
    std::cout << "Lista inversa: " << std::endl; 
    percorrer(listaY);
    std::cout << std::endl;

    // LIBERANDO A LISTA 
    liberarLista(listaX);
    liberarLista(listaY); 

    return 0;
}
