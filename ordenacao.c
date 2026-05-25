#include <stdio.h>
#include <string.h>

struct Carta {
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

void imprimirCartas(struct Carta lista[], int tamanho) {
    printf("%-5s | %-25s | %-7s | %-7s | %-8s | %-8s\n", 
           "ID", "Nome", "Ataque", "Defesa", "Energia", "Raridade");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%-5d | %-25s | %-7d | %-7d | %-8d | %-8d\n",
               lista[i].id, lista[i].nome, lista[i].ataque, 
               lista[i].defesa, lista[i].energia, lista[i].raridade);
    }
    printf("\n");
}

void insertionSortEnergia(struct Carta mao[], int n) {
    for (int i = 1; i < n; i++) {
        struct Carta chave = mao[i];
        int j = i - 1;
        
        while (j >= 0 && mao[j].energia > chave.energia) {
            mao[j + 1] = mao[j];
            j--;
        }
        mao[j + 1] = chave;
    }
}

int main() {
    printf("=== ARENA DE CODIGO - MESTRE DOS DECKS ===\n\n");

    struct Carta mao_inicial[7] = {
        {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1},
        {107, "Anjo da Furia", 6, 5, 6, 3},
        {101, "Goblin Batedor", 1, 1, 1, 1},
        {103, "Guardiao de Pedra", 2, 5, 4, 1},
        {106, "Cavaleiro de Aco", 3, 3, 3, 2},
        {104, "Dragao das Cinzas", 7, 7, 8, 3}
    };

    printf("--- Mao Inicial (Desordenada) ---\n");
    imprimirCartas(mao_inicial, 7);

    insertionSortEnergia(mao_inicial, 7);
    
    printf("--- Nivel Novato: Mao Organizada (Por Energia) ---\n");
    imprimirCartas(mao_inicial, 7);
    printf("Mao organizada! Pronto para a batalha!\n\n");

    return 0;
}