// EXERCÍCIO 01
/*
Fazer um programa que faz a leitura de duas listas X e Y, ambas com
N reais (N deve ser lido tb). Efetue a multiplicação dos respectivos
pares de elementos de X por Y, gerando uma terceira lista Z.
Imprima as listas X, Y e Z
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

// MULTIPLICANDO OS PARES DAS LISTAS 
void multiplica(No* listaX, No* listaY, No* &listaZ) { // tenho que passar a listaZ por referencia para que ela possa ser modificada dentro da função e refletir essas alterção no main 
    // DEFININDO PONTEIROS 
    // criando ponteiros que serão utilizando para apontar para o início da lista  
    No* atualX = listaX;
    No* atualY = listaY; 

    // DEFININDO VARIÁVEIS 
    double valor;

    // REALIZANDO AS MULTIPLICAÇÕES 
    while (atualX != nullptr && atualY != nullptr) {
        valor = atualX -> dado * atualY -> dado; // multiplicamos os valores que estão sendo apontados pelos ponteiros e atribuimos o resultado a variável valor
        atualX = atualX -> proximo; // avançamos para o próximo nó da lista 
        atualY = atualY -> proximo; 
        listaZ = inserir (listaZ, valor); // inserindo os valores na lista Z 
    }
}

int main () {
    // INICIALIZANDO LISTAS 
    No* listaX = inicializar();
    No* listaY = inicializar();
    No* listaZ = inicializar(); 

    // DEFININDO VERIÁVEIS 
    int N, i; 
    double valor;

    // PEDINDO O TAMANHO DAS LISTAS 
    std::cout << "Digite o tamanho de N: ";
    std::cin >> N; 

    // PEDINDO ELEMENTOS DA LISTA X
    for (i = 0; i < N; i++) {
        std::cout << "Digite um numero para a lista X: "; 
        std::cin >> valor; 
        listaX = inserir(listaX, valor); 
    }

    // PEDINDO ELEMENTOS DE Y
    for (i = 0; i < N; i++) {
        std::cout << "Digite um numero para a lista Y: ";
        std::cin >> valor;
        listaY = inserir(listaY, valor); 
    }

    // IMPRIMINDO LISTA X 
    std::cout << "Lista X: " << std::endl;
    percorrer(listaX);
    std::cout << std::endl;

    // IMPRIMINDO LISTA Y 
    std::cout << "Lista X: " << std::endl;
    percorrer(listaY);
    std::cout << std::endl;

    // CHAMANDO A FUNÇÃO MULTIPLICA 
    multiplica(listaX, listaY, listaZ);

    // IMPRIMINDO LISTA Z 
    std::cout << "Lista Z: " << std::endl;
    percorrer(listaZ);
    std::cout << std::endl;

    // LIBERANDO A MEMÓRIA DAS LISTAS 
    liberarLista(listaX);
    liberarLista(listaY);
    liberarLista(listaZ); 

    return 0; 
}
