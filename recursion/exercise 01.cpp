// EXERCÍCIO 01
// Elabore um programa que utilize recursividade que recebe um vetor de inteiros e retorna o mesmo vetor em ordem crescente.
// DEFININDO BIBLIOTECA
#include <iostream>

// FUNÇÃO RECURSIVA PARA ORDENAR O VETOR 
void ordenar_vetor(int vetor[], int indice_atual, int tamanho_vetor) {
    int menor_indice; // armazena o índice do menor valor encontrado em cada interação do laço for
    int valor_temporario; // variável temporária para troca de valores
    int i;

    // CONDIÇÃO DE PARADA DA RECURSÃO - para usar recursividade precisso de uma condição de parada 
    // quando a posicao atinge o valor de N (tamanho do vetor), significa que todas as posições foram ordenadas, então a função retorna e a recursão termina
    if (indice_atual == tamanho_vetor) { 
        return;
    }

    // LOCALIZAR O MENOR VALOR NO RESTANTE DO VETOR
    menor_indice = indice_atual; // estamos assumindo que o menor valor está na posição 0
    for (i = indice_atual; i < tamanho_vetor; i++) { // começa na posição 0 e vai até o último número do vetor
        if (vetor[i] < vetor[menor_indice]) {  
            menor_indice = i; // se o vetor que está na posição i, for menor que o vetor que está na posição 0, pos_troca vai valer i
        }
    }

    /*
    EXEMPLO
    vetor = [5, 2, 8, 1, 3] / pos_troca = 0 -> índice que está na posição 0 = 5
    - 2 < 5 -> menor_indice = 2
    - 2 < 8 -> menor_indice = 2
    - 2 > 1 -> menor_indice = 1
    - 1 < 3 -> menor_indice = 1
    - no final da interação: menor_indice = 1
    */

    // TROCANDO O MENOR VALOR ENCONTRADO COM O VALOR QUE ESTÁ NA POSIÇÃO ATUAL 
    valor_temporario = vetor[menor_indice]; // valor_temporário recebe o menor valor encontrado
    vetor[menor_indice] = vetor[indice_atual]; // move o valor atual da (indice_atual) do vetor para a posição onde estava o menor valor encontrado (menor_indice)
    /*
    EXEMPLO
    vetor = [5, 2, 8, 1, 3]
    - No início, posicao = 0. Então, estamos lidando com o primeiro elemento do vetor (vetor[0] = 5).
    - A busca pelo menor valor encontrou que o menor valor está na posição pos_troca = 3 (onde o valor é 1).
    - Agora, vamos trocar o valor da posição 0 (primeiro elemento, 5) com o valor da posição 3 (onde está o menor valor, 1).
    - O valor da posição posicao (neste caso, vetor[0] = 5) é copiado para a posição pos_troca (neste caso, vetor[3]).
    - Isso coloca o valor 5 no lugar do 1, na posição 3.
    - resulta: vetor = [5, 2, 8, 5, 3] -> Agora temos dois números 5 temporariamente no vetor, mas isso será corrigido no próximo passo
    */
    vetor[indice_atual] = valor_temporario; // colocar o menor valor (valor_temporario) na posicao atual (indice_atual)
    /*
    EXEMPLO
    aux_a = vetor[pos_troca];  / aux_a = 1 
    Coloca o valor armazenado em aux_a (que é 1) na posição posicao (que é a posição 0).
    resultado: vetor = [1, 2, 8, 5, 3]
    */

    // CHAMA A FUNÇÃO RECURSIVA PARA ORDENAR O RESTANTE DO VETOR
    // o indice vai aumentado 1 a cada chamada recursiva da função - até chegar no tamanho do vetor
    ordenar_vetor(vetor, indice_atual + 1, tamanho_vetor);
}

int main() {
    // DEFININDO VARIÁVEIS
    int maximo_tamanho = 20; 
    int vetor[maximo_tamanho];
    int indice_inicial = 0; // indice atual do vetor que está sendo processado 
    int tamanho_vetor;

    // SOLICITA O TAMANHO DO VETOR 
    std::cout << "Digite o tamanho do vetor: ";
    std::cin >> tamanho_vetor;

    // SOLICITA OS VALORES DO VETOR
    for (int i = 0; i < tamanho_vetor; i++) {
        std::cout << "Digite o valor para a posição " << i << ": ";
        std::cin >> vetor[i];
    }

    // EXIBE O VETOR ANTES DA ORDENAÇÃO
    std::cout << "Vetor antes da ordenação: ";
    for (int i = 0; i < tamanho_vetor; i++) {
        std::cout << vetor[i] << " ";
    }

    // CHAMA A FUNÇÃO PARA ORDENAR O VETOR
    ordenar_vetor(vetor, indice_inicial, tamanho_vetor);

    // EXIBE O VETOR APÓS A ORDENAÇÃO
    std::cout << "Vetor após a ordenação: ";
    for (int i = 0; i < tamanho_vetor; i++) {
        std::cout << vetor[i] << " ";
    }

    return 0;
}
