#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *ptr = (int*) malloc(sizeof(int)); // Egyetlen int meretu helyet foglalunk

    if (ptr == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        return 1;
    }

    *ptr = 100; // Az uj memoriateruletre beallitunk egy erteket
    printf("A foglalt memoria tartalma: %d\n", *ptr);

    *ptr = 69; // Az uj memoriateruletre beallitunk egy erteket
    printf("A foglalt memoria tartalma: %d\n", *ptr);

    free(ptr); // Fontos: a lefoglalt memoria felszabaditasa

    printf("\n\n");

    int n;
    printf("Hany elemet szeretnel? ");
    scanf("%d", &n);

    int *tomb = (int*) malloc(n * sizeof(int)); // Dinamikus foglalas

    if (tomb == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        tomb[i] = i * 2; // Feltoltjuk a tombot
    }

    printf("Tomb elemei: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }

    free(tomb); // Fontos: Memoria felszabadítasa!

    printf("\n\n");


    char *str = (char*) malloc(50 * sizeof(char)); // 50 karakter foglalása
    if (str == NULL) {
        printf("Memóriafoglalási hiba!\n");
        return 1;
    }

    strcpy(str, "Norbi kugija nagyon nagy!"); // Sztring másolása
    printf("%s\n", str);

    free(str); // Fontos felszabadítani!

    
    return 0;
}