#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int num, palpite, tentativas, opcao;
    int dificuldade, max, limite;

    inicio_jogo:
    tentativas = 0;

    // Menu de Dificuldade
    printf("\n--- Escolha o Nivel de Dificuldade ---\n");
    printf("1. Facil (1 a 5 - 3 tentativas)\n");
    printf("2. Medio (1 a 20 - 5 tentativas)\n");
    printf("3. Dificil (1 a 100 - 10 tentativas)\n");
    printf("Escolha: ");
    scanf("%i", &dificuldade);

    // Configura o intervalo e o limite de tentativas com base na escolha
    if(dificuldade == 2){
        max = 20;
        limite = 5;
    }else if(dificuldade == 3){
        max = 100;
        limite = 10;
    }else{
        max = 5;
        limite = 3;
    }

    num = (rand() % max) + 1;

    printf("\n--- Jogo de Adivinhar Numero ---\n");
    printf("Voce tem %i tentativas para acertar!\n\n", limite);

    do {
        printf("Digite um valor de 1 ate %i: ", max);
        scanf("%i", &palpite);
        tentativas = tentativas + 1;

        if(palpite == num){
            printf("Parabens! Voce acertou!\n");
            break; 
        }else if(palpite > num){
            printf("O numero sorteado e MENOR que seu palpite.\n");
        }else{
            printf("O numero sorteado e MAIOR que seu palpite.\n");
        }

        printf("Tentativas restantes: %i\n\n", limite - tentativas);

    } while(tentativas < limite);

    if(palpite != num){
        printf("\nSuas tentativas acabaram! Game Over.\n");
    }

    printf("O numero sorteado era: %i\n", num);
    printf("Total de tentativas usadas: %i\n", tentativas);

    // Menu para continuar jogando
    printf("\nDeseja jogar novamente? (1- Sim / 2- Nao): ");
    scanf("%i", &opcao);

    if(opcao == 1){
        goto inicio_jogo;
    }

    printf("Fim do jogo!\n");
    return 0;
}
