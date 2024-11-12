// EXERCPICIO 03
// Fazer um programa com função recursiva que retorna todos os primos de 1 até um número fornecido
// DEFININDO BIBLIOTECA 
#include <iostream> 

// FUNÇÃO RECURSIVA PARA VERIFICAR SE O NÚMERO É PRIMO 
int verifica_primo(int numero, int divisor) {
    // VERIFICANDO SE É PRIMO
    if (divisor == numero || numero == 1) {
        return 1; // verdadeiro, é primo
    } 
    // se divisor é igual a numero, ou se numero é 1, a função retorna 1, indicando que o número é primo - CONDIÇÃO DE PARADA DA RECURSIVIDADE 
    
    // VERIFICANDO SE NÃO É PRIMO
    else if (numero % divisor == 0) { 
        return 0; // falso, não é primo 
    } 
    // se numero é divisível por divisor (ou seja, numero % divisor == 0), a função retorna 0, indicando que numero não é primo
    
    // CHAMANDO FUNÇÃO RECURSIVA 
    else {
        return verifica_primo(numero, divisor + 1); 
        // se nenhuma das condições anteriores for verdadeira, a função chama a si mesma, incrementando o divisor em 1, continuando a verificação
    }
}

int main () {
    // DEFININDO VARIÁVEIS
    int limite; // O número até onde queremos verificar primos
    int resultado; // Armazenará o resultado da verificação se i é primo
    int divisor_inicial = 2; // todo numero primo é divisível por 1 e ele mesmo, por isso começamos em 2
    int i;

    // PEDINDO INFORMAÇÃO ATÉ QUE NÚMERO DESEJA VERIFICAR 
    std::cout << "Digite ate que numero deseja verificar: ";
    std::cin >> limite;

    // LOOP PARA A VERIFICAÇAÕ DOS NÚMEROS PRIMOS
    for (i = 2; i <= limite; i++) { // PQ 2?????????
        // CHAMANDO A FUNÇÃO RECURSIVA 
        // preciso igualar ela a algo, pois ela não imprime nada dentro dela
        resultado = verifica_primo(i, divisor_inicial); // passo i como argumento pois representa o número atual que está sendo verificado - i é a variável do loop que itera sobre todos os números de 2 até o limite especificado pelo usuário
        // uando você chama a função verifica_primo com i como argumento, você efetivamente está passando o número atual do loop que você deseja verificar se é primo
        /*
        EXEMPLO 
        dentro da função, numero se refere ao valor que foi passado como argumento na chamada da função. Então, por exemplo, se i for 5 na chamada verifica_primo(5, 2), o parâmetro numero dentro da função terá o valor 5
        */

        // SE O RESULTADO FOR IGUAL A 1
        if (resultado == 1) {
            std::cout << i << " ";
        }
    }

    return 0; 
}
