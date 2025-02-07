#ifndef QUEUE_H
#define QUEUE_H

typedef struct Position {
    int x;
    int y;
} Position;

// A sor elemeit tároló struktúra
typedef struct QNode {
    Position position;
    struct QNode* next;
} QNode;

// Funkciók deklarációi
void enqueue(QNode** head, QNode** tail, Position position); // sorba
int dequeue(QNode** head, QNode** tail, Position* position); // sorbol -> -1 hiba, 0 siker
void print_queue(QNode* head); // kiir
int peek(QNode* head, Position* position); // felso -> -1 hiba, 0 siker
void modify(QNode* head, Position* new_position); // Minden elemet az uj positionra modositunk
int is_empty(QNode* head); // ures
void free_queue(QNode* head); // felszabadit

#endif // QUEUE_H