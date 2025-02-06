#include <stdio.h>
#include <stdlib.h>

int main() {
    int *koord = (int*) malloc(2* sizeof(int));
    if (koord == NULL)
    {
        printf("Memoriafoglalasi hiba!");
        return 1;
    }
    float *tavolsag = (float*) malloc(sizeof(float));
    if (tavolsag == NULL)
    {
        printf("Memoriafoglalasi hiba!");
        free(tavolsag);
        return 1;
    }

    koord[0] = 0; // x
    koord[1] = 0; // y
    *tavolsag = 28.3f;

    printf("Kezdeti pozicio: (%d, %d)\n", koord[0], koord[1]);
    printf("Kezdeti tavolsag: %.2f meter\n", *tavolsag);
    printf("\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\nA robot elindul...\n");
        koord[0] += 10;  // x koordinata novelese (10 meter)
        koord[1] += 5;   // y koordinata novelese (5 meter)
        *tavolsag -= 5.5f; // erzekelo erteke frissul

        printf("uj pozicio: (%d, %d)\n", koord[0], koord[1]);
        printf("uj tavolsag: %.2f meter\n", *tavolsag);
        printf("\n\n");
    }
    
    // Memoria felszabaditasa
    free(koord);
    free(tavolsag);
}