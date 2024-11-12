// EXERCÍCIO 04
/*
Elabore uma função que inverta uma fila
*/
#include <iostream>

// DEFININDO ESTRUTURA DO NÓ 
struct No {
    int data; // variável que armazena o valor do nó atual da fila
    No* next; // ponteiro que aponta para o próximo nó da fila
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

// FUNÇÃO PARA REMOVER O PRIMEIRO ELEMENTO DA FILA
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

// FUNÇÃO PARA INVERTER A FILA
void inverterFila(Fila* f) {
    Fila* filaAuxiliar = new Fila;
    while (f->first != nullptr) {
        int valor = remove(f);
        No* novo = new No;
        novo->data = valor;
        novo->next = filaAuxiliar->first;
        filaAuxiliar->first = novo;
        if (filaAuxiliar->last == nullptr) 
            filaAuxiliar->last = novo;
    }
    while (filaAuxiliar->first != nullptr) {
        insert(f, remove(filaAuxiliar));
    }
    delete filaAuxiliar;
}

int main() {
    // CRIANDO UMA NOVA FILA 
    Fila* f = new Fila;

    // DEFININDO VARIÁVEIS 
    int quantidade, numero;

    // PEDINDO A QUANTIDADE DE ELEMENTOS QUE TERÁ NA FILA 
    std::cout << "Digite a quantidade de elementos que deseja inserir: ";
    std::cin >> quantidade; 

    // PEDINDO OS ELEMENTOS DA FILA 
    for (int i = 0; i < quantidade; i++) {
        std::cout << "Digite um numero: ";
        std::cin >> numero;
        insert(f, numero);
    }

    // IMPRIMINDO A FILA ORIGINAL
    std::cout << "Fila original: ";
    print(f);
    std::cout << std::endl;

    // INVERTENDO A FILA
    inverterFila(f);

    // IMPRIMINDO A FILA INVERTIDA
    std::cout << "Fila invertida: ";
    print(f);
    std::cout << std::endl;

    // LIBERANDO A MEMÓRIA DA FILA 
    freeFila(f);
    delete f;

    return 0;
}
