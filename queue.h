#ifndef QUEUE_H
#define QUEUE_H

// A sor elemeit tároló struktúra
typedef struct QNode {
    int x,y;
    struct QNode* next;
} QNode;

// Funkciók deklarációi
void enqueue(QNode** head, QNode** tail, int x, int y); // sorba
int dequeue(QNode** head, QNode** tail, int* x, int* y); // sorbol -> -1 hiba, 0 siker
void print_queue(QNode* head); // kiir
int peek(QNode* head, int* x, int* y); // felso -> -1 hiba, 0 siker
int is_empty(QNode* head); // ures
void free_queue(QNode* head); // felszabadit

#endif // QUEUE_H