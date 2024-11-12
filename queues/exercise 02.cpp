// EXERCÍCIO 02 
/*
Elabore uma função que apague a informação 15 de
uma fila se ela existir
*/
#include <iostream>

// DEFININDO ESTRUTURA DO NÓ 
struct No {
    int data; // variável que armazena o valo do nó atual da fila
    No* next; // ponteiro que aponta para o próximo nó da fial
};

// ESTRUTURA DA FILA
struct Fila {
    No* first = nullptr;
    No* last = nullptr;
};

// FUNÇÃO PARA INSERIR UM NOVO VALOR NO FINAL DA FILA 
void insert(Fila* f, int valor) {
    No* novo = new No;
    novo->data = valor;
    novo->next = nullptr;
    if (f->last == nullptr) 
        f->first = novo;
    else 
        f->last->next = novo;
    f->last = novo;
}

// FUNÇÃO PARA REMOLVER O PRIMEIRO ELEMENTO DA FILA
int remove(Fila* f) {
    if (f->first == nullptr) {
        std::cout << "Fila vazia.\n";
        return -1;
    }
    No* temp = f->first;
    int valor = temp->data;
    f->first = f->first->next;
    if (f->first == nullptr) 
        f->last = nullptr;
    delete temp;
    return valor;
}

// FUNÇÃO PARA IMPRIMIR A FILA
void print(Fila* f) {
    No* atual = f->first;
    if (atual == nullptr) {
        std::cout << "Fila vazia.\n";
        return;
    }
    while (atual != nullptr) {
        std::cout << atual->data << " -> ";
        atual = atual->next;
    }
    std::cout << "NULL\n";
}

// FUNÇÃO PARA LIBERAR A MEMÓRIA DA FILA 
void freeFila(Fila* f) {
    No* atual = f->first;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->next;
        delete temp;
    }
    f->first = nullptr;
    f->last = nullptr;
}

// FUNÇÃO PARA REMOVER UM VALOR
void removeValor(Fila* f, int valor) {
    // CRIANDO PONTEIROS 
    No* atual = f->first; // aponta para o primeiro nó da fila
    No* anterior = nullptr; // aponta para o nó anterior que o ponteiro atual aponta, ele é inicializado como nullptr porque no início da busca não há nó anterior

    // BUSCANDO O VALOR 
    while (atual != nullptr) {
        if (atual->data == valor) { // se o valor que o poonteiro aponta for igual ao valor que quermos remolver 
            // REMOÇÃO DO VALOR
            if (anterior == nullptr) { // caso o valor esteja no primeiro nó 
                f->first = atual->next; // vai para o próximo nó
                if (f->first == nullptr) // se f->first for nullptr após a remoção (a fila ficou vazia), então f->last também é ajustado para nullptr
                    f->last = nullptr; 
            } 
            else { // caso o valor esteja em outro nó da fila
                anterior->next = atual->next; // o ponteiro anterior->next é atualizado para atual->next, "saltando" o nó que será removido
                if (atual->next == nullptr) // se o nó que está sendo remolvido for o último da fila 
                    f->last = anterior; // f->last é atualizado para anterior, para que f->last continue apontando para o último nó válido
            }
            delete atual; // remove o nó da memória 
            std::cout << "Valor " << valor << " removido da fila.\n";
            return;
        }
        anterior = atual; // estamos atualizando o ponteiro anterior para apontar para o nó atual. Assim, anterior sempre fica um passo atrás de atual
        atual = atual->next; // movendo o ponteiro para o próximo nó da fila 
    }
    std::cout << "Valor " << valor << " não encontrado na fila.\n";
}

int main() {
    // CRIANDO UMA NOVA FILA 
    Fila *f = new Fila; 

    // DEFININDO VARIÁVEIS 
    int tamanho, valor, i;

    // PEDINDO O TAMANHO DA FILA 
    std::cout << "Digite o tamanho da fila: " << std::endl; 
    std::cin >> tamanho;

    // PEDINDO ELEMENTOS DA FILA 
    for (i = 0; i < tamanho; i++) {
        std::cout << "Digite um valor: ";
        std::cin >> valor; 
        insert(f, valor);

    }

    // IMPRIMINDO A FILA SEM A REMOÇÃO 
    std::cout << "Fila: " << std::endl;
    print(f); 
    std::cout << std::endl; 

    // CHAMANDO A FUNÇÃO PARA REMOLVER VALOR
    removeValor(f, 15); 

    // IMPRIMINDO A FILA APÓS A REMOÇÃO 
    std::cout << "Fila apos a remocao: " << std::endl;
    print(f); 
    std::cout << std::endl; 

    // LIBERANDO A MEMÓRIA DA FILA 
    freeFila(f);
    delete(f); 

    return 0;
}
