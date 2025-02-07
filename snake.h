#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "map.h"  // Ezt kell hozzáadni, hogy a Map struktúra elérhető legyen

typedef struct Snake {
    Position head;   // Kígyó feje
    QNode* bodyHead; // Kígyó teste, sorozatos koordináták (sor/tömb)
    QNode* bodyTail; // kígyó farka
    int length;      // Kígyó hossza
} Snake;

// Kígyó létrehozása
Snake* create_snake(int start_x, int start_y);

// Kígyó etetése
void eat(Snake* snake, Map* map, char direction);

// Kígyó mozgatása
int move_snake(Snake* snake, char direction, Map* map, char value);

// Kígyó ütközésének ellenőrzése
int is_collision(Position position, Map* map);

// Kígyó törlése
void delete_snake(Snake* snake);

#endif