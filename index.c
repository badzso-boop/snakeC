#include <stdio.h>   // Kiírás, beolvasás
#include <stdlib.h>  // Memória, véletlenszám
#include <stdbool.h> // Boolean értékek
#include <math.h>    // Matek műveletek
#include <string.h>  // Sztringek
#include <ctype.h>   // Karakterek kezelése

int main() {
    int a = 10;
    float b = 10.1;
    double c = 10.15;
    char d = 'A';
    char e[] = "Hello world!";
    bool f = true;
    printf("%i\n", a);
    printf("%f\n", b);
    printf("%f\n", c);
    printf("%c\n", d);
    printf("%s\n", e);
    printf("%d", f);


    int szam = 10;
    if (szam > 5)
    {
        printf("A szam nagyobb mint 5. \n");
    }
    else if(szam == 10) {
        printf("A szam pont 10. \n");
    }
    else
    {
        printf("A szam kisebb mint 5. \n");
    }

    int nap = 3;

    switch (nap) {
        case 1:
            printf("Hetfo\n");
            break;
        case 2:
            printf("Kedd\n");
            break;
        case 3:
            printf("Szerda\n");
            break;
        default:
            printf("Ismeretlen nap\n");
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Ez a %d. ciklus.\n", i + 1);
    }

    printf("\n\n");

    int i = 0;

    while (i < 5) {
        printf("A while ciklus %d. futasa\n", i + 1);
        i++;
    }

    printf("\n\n");

    i = 0;

    do {
        printf("A do-while ciklus legalabb egyszer lefut.\n");
        i++;
    } while (i < 5);

    printf("\n\n");

    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            printf("Megallunk az 5-nel.\n");
            break;  // kilep a ciklusból
        }
        if (i % 2 == 0) {
            continue;  // kihagyja a paros szamokat
        }
        printf("%d\n", i);
    }
}