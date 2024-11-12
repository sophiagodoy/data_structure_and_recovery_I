// EXERCÍCIO 03
/*
Elabore uma função que dado uma fila, transforme-a
em duas filas uma com os números pares e outra com
os ímpares
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

// FUNÇÃO PARA CONTAR PAR E IMPAR 
void contando(Fila* f, Fila* fila_par, Fila* fila_impar) {
    // CRIANDO PONTEIRO 
    No* atual = f->first; 

    // DEFININDO CONDIÇÕES 
    while (atual != nullptr) {
        if (atual->data % 2 == 0) {
            insert(fila_par, atual->data); // insere o valor que o ponteiro aponta
        }
        else {
            insert(fila_impar, atual->data);
        }
        atual = atual->next;
    }
}

int main () {
    // CRIANDO AS FILAS
    Fila* f = new Fila; 
    Fila* fila_par = new Fila;
    Fila* fila_impar = new Fila;

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

    // CHAMANDO A FUNÇÃO 
    contando(f, fila_par, fila_impar);

    // IMPRIMINDO AS FILAS E CHAMANDO AS FUNÇÕES
    std::cout << "Fila original: " << std::endl;
    print(f); 
    std::cout << std::endl;

    std::cout << "Fila dos pares: " << std::endl;
    print(fila_par); 
    std::cout << std::endl;

    std::cout << "Fila dos impares: " << std::endl;
    print(fila_impar); 
    std::cout << std::endl;

    // LIBERANDO A MEMÓRIA DA FILA 
    freeFila(f);
    freeFila(fila_par);
    freeFila(fila_impar);

    delete f;
    delete fila_par;
    delete fila_impar;

    return 0;
}
