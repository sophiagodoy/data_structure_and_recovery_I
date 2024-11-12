// EXERCÍCIO 02 
// Fazer um programa com função recursiva que retorna se um inteiro é ou não primo
// DEFININDO BIBLIOTECA 
#include <iostream> 

// FUNÇÃO RECURSIVA PARA VERIFICAR NÚMERO PRIMO 
void verifica_primo(int numero, int divisor) {
    // divisor é passada como parametro pois ele é modificado a cada interação 

    // VERIFICANDO SE O NÚMERO É PRIMO 
    if (divisor == numero) {
        std::cout << "e primo";  
        // se o divisor chegou ao valor do número, isso significa que nenhum número entre 2 e numero - 1 dividiu o número, então ele é primo - CONDIÇÃO DE PARADA DA RECURSIVIDADE 
       
        /*
        EXEMPLO 
        para numero = 7, se chegarmos ao ponto em que divisor == 7, isso indica que 7 não foi divisível por nenhum número antes de 7, então é primo
        */
    }

    // VERIFICANDO SE O NÚMERO NÃO É PRIMO
    else if (numero % divisor == 0) {
        std::cout << "nao e primo";  // estou fazendo a condição em uma única linha, não precisa {}
        // verifica se o número é divisível pelo divisor. Se o número é divisível, ele não é primo, e a função imprime "não é primo
        
        /*
        EXEMPLO
        se numero = 8 e divisor = 2, como 8 % 2 == 0, a função identifica que 8 não é primo
        */
    }

    // CHAMA A FUNÇÃO RECURSIVA 
    else {
        verifica_primo(numero, divisor + 1); 
        // se o divisor atual não for igual ao número e o número não for divisível por ele, a função chama a si mesma com o próximo divisor (divisor + 1) e repete o processo, ou seja, se dividisor = 2 agora divisor = 3
    }
}

int main() {
    // DEFININDO VARIÁVEIS
    int numero; 
    int divisor_inicial = 2; // todo numero primo é divisível por 1 e ele mesmo, por isso começamos em 2

    // PEDINDO O NÚMERO QUE DESEJO VERIFICAR 
    std::cout << "Digite o numero que deseja verificar: ";
    std::cin >> numero;

    // CHAMANDO A FUNÇÃO RECURSIVA 
    verifica_primo(numero, divisor_inicial);  // divisor_inicial é definida como parametro para estabelecer o ponto de partida de verificação 
    // náo preciso passar divisor_inicial como paramentro da função, porque ela já está sendo passada como argumento quando eu chamo a função 
}
