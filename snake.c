#include "snake.h"
#include "map.h"

Snake* create_snake(int start_x, int start_y) {
    Snake* snake = malloc(sizeof(Snake));
    if (!snake) return NULL;

    snake->head.x = start_x;
    snake->head.y = start_y;
    snake->bodyHead = NULL;
    snake->length = 1;

    return snake;
}

void eat(Snake* snake, Map* map, char direction) {
    int head_x = snake->head.x;
    int head_y = snake->head.y;

    // Az utolsó testpozíció meghatározása
    Position new_tail;
    if (snake->bodyHead == NULL) {
        new_tail.x = head_x;
        new_tail.y = head_y;
    } else {
        QNode* temp = snake->bodyHead;
        while (temp->next != NULL) {
            temp = temp->next;  // Az utolsó testpozíció meghatározása
        }
        new_tail.x = temp->position.x;  // Az utolsó test pozíciója
        new_tail.y = temp->position.y;
    }

    // Az új test pozícióját az ellentétes irányba kell elhelyezni
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
    // Mozgatás: Irányok (pl. 'U' -> fel, 'D' -> le, 'L' -> balra, 'R' -> jobbra)
    Position new_head = snake->head;

    switch(direction) {
        case 'U': new_head.x--; break;  // Fel
        case 'D': new_head.x++; break;  // Le
        case 'L': new_head.y--; break;  // Balra
        case 'R': new_head.y++; break;  // Jobbra
        default: return 0; // Hibás irány
    }

    if (is_collision(new_head, map) == 1) {
        printf("Utkozes tortent! A jatek veget ert.\n");
        return 0; // Játék vége
    }
    else if(is_collision(new_head, map) == 2) {
        eat(snake, map, direction);
    }

    QNode* current = snake->bodyHead;
    while(current) {
        switch(direction) {
            case 'U': current->position.x--; break;  // Fel
            case 'D': current->position.x++; break;  // Le
            case 'L': current->position.y--; break;  // Balra
            case 'R': current->position.y++; break;  // Jobbra
            default: return 0; // Hibás irány
        }
        current = current->next;
    }

    current = snake->bodyHead;
    while(current) {
        set_value(map, current->position.x, current->position.y, '0');
        current = current->next;
    }
    set_value(map, snake->head.x, snake->head.y, '0');  // Kiüresíti a régi helyet
    snake->head = new_head;
    set_value(map, snake->head.x, snake->head.y, value);  // Új fej
    current = snake->bodyHead;
    while(current) {
        set_value(map, current->position.x, current->position.y, '2');
        current = current->next;
    }

    return 1; // Játék folytatódhat
}


int is_collision(Position position, Map* map) {
    if (position.x < 0 || position.x >= map->rows || position.y < 0 || position.y >= map->cols) {
        return 1;  // Ha a kígyó a térképen kívülre lép, ütközés van
    }

    char value = get_value(map, position.x, position.y);
    if (value == '@' || value == '2') {
        return 1;  // Falba vagy a saját testébe ütközik
    }
    else if(value == '5') {
        return 2;
    }

    return 0;  // Nincs ütközés
}

void delete_snake(Snake* snake) {
    if (!snake) return;

    // Töröljük a kígyó testét
    while (snake->bodyHead) {
        QNode* temp = snake->bodyHead;
        snake->bodyHead = snake->bodyHead->next;
        free(temp);
    }

    free(snake);
}