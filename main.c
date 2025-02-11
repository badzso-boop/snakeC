#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include <unistd.h>
#include "./headers/queue.h"
#include "./headers/map.h"
#include "./headers/snake.h"

int main() {
    int *numbers = malloc(4 * sizeof(int*));
    numbers[0] = 10; // rows
    numbers[1] = 10; // cols
    numbers[2] = 0; // x
    numbers[3] = 0; // y

    Map* map = create_map(numbers[0], numbers[1]);
    if (map == NULL) {
        printf("Hiba a térkép létrehozásánál.\n");
        free(numbers);
        return 1;
    }
    map_initialization(map, '.', '@');
    set_value(map, 7, 3, '5');
    print_map(map);



    Snake* snake = create_snake(1, 1);
    int game_running = 1;
    char direction = 'R';  // Kezdő irány

    while (game_running) {
        system("cls");
        print_map(map);  // Kiírja a térképet
        if (_kbhit()) {  // Ha billentyűt nyomtak
            char c = _getch();  // Elolvassa a billentyűt
            switch (c) {
                case 'a':
                    if (direction != 'R') direction = 'L';  // Balra
                    break;
                case 'd':
                    if (direction != 'L') direction = 'R';  // Jobbra
                    break;
                case 'w':
                    if (direction != 'D') direction = 'U';  // Fel
                    break;
                case 's':
                    if (direction != 'U') direction = 'D';  // Le
                    break;
            }
        }

        game_running = move_snake(snake, direction, map, '1');  // A kígyót az aktuális irányba mozgatja
        usleep(700000);  // Várakozás 0.5 másodpercig
    }

    getchar();
    
    



    QNode* current = snake->bodyHead;
    while (current)
    {
        QNode* temp = current;
        free(temp);
        current = current->next;
    }
    free(snake);   

    // Felszabadítjuk a memóriát
    for (int i = 0; i < map->rows; i++) {
        free(map->data[i]);
    }
    free(map->data);
    free(map);
    free(numbers);

    return 0;
}