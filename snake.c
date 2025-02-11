#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "snake.h"
#include "map.h"
#include "queue.h"

Snake* create_snake(int start_x, int start_y) {
    Snake* snake = malloc(sizeof(Snake));
    if (!snake) return NULL;

    snake->head.x = start_x;
    snake->head.y = start_y; // A lista elso eleme mutasson nullara

    snake->bodyHead = NULL;
    snake->bodyTail = NULL;

    Position pos = {start_x, start_y};
    enqueue(&snake->bodyHead, &snake->bodyTail, pos);

    snake->length = 1;

    return snake;
}

void eat(Snake* snake, Map* map, char direction) {
    int head_x = snake->head.x;
    int head_y = snake->head.y;

    // Az utolso testpozicio meghatarozasa
    Position new_tail;
    if (snake->bodyHead == NULL) {
        new_tail.x = head_x;
        new_tail.y = head_y;
    } else {
        QNode* temp = snake->bodyHead;
        while (temp->next != NULL) {
            temp = temp->next;  // Az utolso testpozicio meghatarozasa
        }
        new_tail.x = temp->position.x;  // Az utolso test pozicioja
        new_tail.y = temp->position.y;
    }

    // Az uj test poziciojat az ellentetes iranyba kell elhelyezni
    switch(direction) {
        case 'U': new_tail.x++; break;  
        case 'D': new_tail.x--; break;
        case 'L': new_tail.y++; break;  
        case 'R': new_tail.y--; break;
        default: return;
    }
    QNode* tail = NULL;
    enqueue(&snake->bodyHead, &tail, new_tail);

    snake->length++;
}

int move_snake(Snake* snake, char direction, Map* map, char value) {
    srand(time(NULL));
    Position pos;
    Position new_head = snake->head;

    // Iranyvalasztas
    switch (direction) {
        case 'U': new_head.x--; break;
        case 'D': new_head.x++; break;
        case 'L': new_head.y--; break;
        case 'R': new_head.y++; break;
        default: return 0; // Hibas irany
    }

    // utkozesellenorzes
    int collision = is_collision(new_head, map);
    if (collision == 1) {
        printf("Utkozes tortent a jatek a vegere ert!");
        return 0;
    }

    // uj fej hozzaadasa
    enqueue(&snake->bodyHead, &snake->bodyTail, new_head);
    if (collision == 2) {
        int x = (rand() % 8) + 1;
        int y = (rand() % 8) + 1;
        set_value(map, x, y, '5');
    }
    

    // Ha nem evett, a farok eltavolitasa
    if (collision != 2) {
        dequeue(&snake->bodyHead, &snake->bodyTail, &pos);
        set_value(map, pos.x, pos.y, '.'); // Regi farok torlese
    }

    // Fej frissitese
    snake->head = new_head;

    // Test frissitese a terkepen
    QNode* current = snake->bodyHead;
    while (current) {
        set_value(map, current->position.x, current->position.y, '2');
        current = current->next;
    }

    return 1; // Jatek folytatodik
}



int is_collision(Position position, Map* map) {
    if (position.x < 0 || position.x >= map->rows || position.y < 0 || position.y >= map->cols) {
        return 1;  // Ha a kigyo a terkepen kivulre lep, utkozes van
    }

    char value = get_value(map, position.x, position.y);
    if (value == '@' || value == '2') {
        return 1;  // Falba vagy a sajat testebe utkozik
    }
    else if(value == '5') {
        return 2;
    }

    return 0;  // Nincs utkozes
}

void delete_snake(Snake* snake) {
    if (!snake) return;

    // Toroljuk a kigyo testet
    while (snake->bodyHead) {
        QNode* temp = snake->bodyHead;
        snake->bodyHead = snake->bodyHead->next;
        free(temp);
    }

    free(snake);
}