// DEFINIÇÃO DA ESTRUTURA DO NÓ
struct No {
    double dado; // armazena o valor do nó 
    No* proximo; // um ponteiro para o próximo nó na lista encadeada, que pode ser nullptr se for o último nó 
};

// FUNÇÃO PARA A INICIALIZAÇÃO DE UMA LISTA VAZIA (uma lista que começa sem nenhum nó)
No* inicializar() {
    return nullptr; 
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NO FINAL DA LISTA
/*
entrada1: 10
entrada2: 20 (saída: 10, 20)
entrada3: 30 (saída: 10, 20, 30)
*/
No* inserir(No* lista, double valor) {
    No* novo = new No;  
    novo->dado = valor; 
    novo->proximo = nullptr; 
    
    if (lista == nullptr) {
        return novo; 
    } 
    else {
        No* atual = lista; 
        while (atual->proximo != nullptr) { 
            atual = atual->proximo;
        }
        atual->proximo = novo; 
        return lista; 
    }
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NO INÍCIO DA LISTA (USADA PARA CRIAR A LISTA INVERSA)
/*
entrada1: 10
entrada2: 20 (saida: 20, 10)
entrada3: 30 (saída: 10, 20, 30)
*/
No* inserirInicio(No* lista, double valor) {
    No* novo = new No; 
    novo->dado = valor; 
    novo->proximo = lista; 
    return novo; 
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

// FUNÇÃO PARA REMOLVER UM ELEMENTO DA LISTA 
No* remover(No* lista, int valor) 
{ 
    No* anterior = nullptr;
    No* atual = lista;

    while (atual != nullptr && atual->dado != valor) 
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == nullptr) 
    {
        std::cout << "Elemento " << valor << " não encontrado!" << std::endl;
        return lista;
    }
    if (anterior == nullptr) 
    {
        lista = atual->proximo;
    } 
    else 
    {
        anterior->proximo = atual->proximo;
    }

    delete atual; 
    return lista;
}
