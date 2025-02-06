#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include "queue.h"






// 1 -> true, 0 -> false
int collision() {
    return 0;
}

int main() {
    int *numbers = malloc(4 * sizeof(int*));
    numbers[0] = 10; // rows
    numbers[1] = 10; // cols
    numbers[2] = 0; // x
    numbers[3] = 0; // y
    int rows = 10, cols = 10;

    // Terkep memoria foglalas
    char** map = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(cols * sizeof(char));
    }

    // Terkep inicializalasa
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            map[i][j] = '0';
    
    map[0][0] = '1';
    map[rows-1][cols-1] = '@';

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
        

    printf("\n\n");
   
    QNode* head = NULL;
    QNode* tail = NULL;

    enqueue(&head, &tail, 1, 2);
    enqueue(&head, &tail, 3, 4);
    enqueue(&head, &tail, 5, 6);
    enqueue(&head, &tail, 7, 8);

    print_queue(head);
    printf("\n\n");

    int x, y;

    if (dequeue(&head, &tail, &x, &y) == 0) {
        printf("Eltavolitott elem: (%d, %d)\n", x, y);
    }

    print_queue(head);
    printf("\n\n");

    if (dequeue(&head, &tail, &x, &y) == 0) {
        printf("Eltavolitott elem: (%d, %d)\n", x, y);
    }

    print_queue(head);
    free_queue(head);

    


    // printf("Nyomj meg egy gombot: ");
    // char c = _getch(); //melyik gombot nyomja le
    // if (c == 'a')
    // {
    //     printf("Jot nyomtal");
    // }
    // else {
    //     printf("\nA lenyomott gomb: %c\n", c);
    // }
    
    free(map);
    return 0;
}