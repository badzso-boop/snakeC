#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000000 // A tömb mérete

int main() {
    // Memória lefoglalása
    int *cache_miss_a = (int *)malloc(SIZE * sizeof(int));
    int *cache_miss_b = (int *)malloc(SIZE * sizeof(int));

    // Véletlenszerű értékek inicializálása
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        cache_miss_a[i] = rand() % 100;
        cache_miss_b[i] = rand() % 100;
    }

    // Cache miss példa: Két külön tömb, amelyek nem egymás után helyezkednek el
    clock_t start = clock();
    long long sum_miss = 0;
    for (int i = 0; i < SIZE; i++) {
        sum_miss += cache_miss_a[i];
        sum_miss += cache_miss_b[i];
    }
    clock_t end = clock();
    printf("Cache miss: %lf masodperc\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(cache_miss_a);
    free(cache_miss_b);

    printf("\n\n");

    int *cache_optimal = (int *)malloc(2 * SIZE * sizeof(int)); // A két tömb egymás után

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        cache_optimal[i] = rand() % 100;
        cache_optimal[i + SIZE] = rand() % 100;
    }

    // Optimalizált példa: Két tömb egymás után
    start = clock();
    long long sum_optimal = 0;
    for (int i = 0; i < SIZE; i++) {
        sum_optimal += cache_optimal[i];
        sum_optimal += cache_optimal[i + SIZE];
    }
    end = clock();
    printf("Optimalizalt: %lf masodperc\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Memória felszabadítása
    
    free(cache_optimal);

    return 0;
}
