// EXERCÍCIO 01 
/*
Elabore uma função que conte quantos números
pares possui uma fila e retorne esta quantidade
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

// FUNÇÃO PARA CONTAR A QUANTIDADE DE NÚMEROS PARES DA FILA 
int cont_par(Fila* f) {
    // CRIANDO UM PONTEIRO 
    No* atual = f->first; // cria um ponteiro que aponta para o primeiro nó da lista
    
    // DEFININDO VARIÁVEIS 
    int contador_par = 0;

    // DEFININDO CONDIÇÕES  
    while (atual != nullptr) {
        if (atual->data % 2 == 0) {
            contador_par++;
        }
        atual = atual->next;
    }
    return contador_par;
}

int main() {
    // CRIANDO UMA NOVA FILA 
    Fila* f = new Fila;

    // DEFININDO VARIÁVEIS 
    int quantidade, numero;

    // PEDINDO A QUANTIDADES DE ELEMENTOS QUE TERÁ NA FILA 
    std::cout << "Digite a quantidade de elementos que deseja inserir: ";
    std::cin >> quantidade; 

    // PEDINDO OS ELEMENTOS DA FILA 
    for (int i = 0; i < quantidade; i++) {
        std::cout << "Digite um numero: ";
        std::cin >> numero;
        insert(f, numero);
    }

    // IMPRIMINDO A FILA 
    std::cout << "Fila: " << std::endl;
    print(f); 
    std::cout << std::endl;

    // IMPRIMINDO A QUANTIDADE DE NÚMEROS PARES E CHAMANDO A FUNÇÃO 
    std::cout << "Quantidade de numeros pares: " << cont_par(f) << "\n";

    // LIBERANDO A MEMÓRIA DA FILA 
    freeFila(f);
    delete f;

    return 0;
}
