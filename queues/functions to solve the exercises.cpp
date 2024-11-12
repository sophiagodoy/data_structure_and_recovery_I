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

// FUNÇÃO PARA REMOVER UM VALOR DA FILA 
void removeValor(Fila* f, int valor) {
    No* atual = f->first;
    No* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->data == valor) {
            if (anterior == nullptr) { // Valor está no início da fila
                f->first = atual->next;
                if (f->first == nullptr) 
                    f->last = nullptr; // A fila ficou vazia
            } else {
                anterior->next = atual->next;
                if (atual->next == nullptr) 
                    f->last = anterior; // Atualiza o último nó se o removido for o último
            }
            delete atual;
            std::cout << "Valor " << valor << " removido da fila.\n";
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
    std::cout << "Valor " << valor << " não encontrado na fila.\n";
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
