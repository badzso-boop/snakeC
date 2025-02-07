#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode* create_QNode(Position position) {
    QNode* new_node = (QNode*)malloc(sizeof(QNode));
    if (new_node == NULL) {
        printf("Memoriafoglalasi hiba");
        exit(1);
    }

    new_node->position = position;
    new_node->next = NULL;

    return new_node;
}

void enqueue(QNode** head, QNode** tail, Position position) {
    QNode* new_node = create_QNode(position);
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    else {
        *head = new_node;
    }

    *tail = new_node;
}

int dequeue(QNode** head, QNode** tail, Position* position) {
    if (*head == NULL) {
        printf("A sor üres, nincs mit eltávolítani.\n");
        *tail = NULL; // Ha üres a lista, akkor a tail is NULL-ra áll
        return -1; // Hibaérték, ha üres a sor
    }

    QNode* temp = *head;
    *position = temp-> position;

    *head = (*head)->next; // A head a következő elemre mutat

    free(temp); // Felszabadítjuk az eltávolított elemet
    return 0;
}

void print_queue(QNode* head) {
    if (head == NULL)
    {
        printf("Ures a sor!\n");
        return;
    }
    while(head) {
        printf("(%d, %d)\n", head->position.x, head->position.y);
        head = head->next;
    }
}

void modify(QNode* head, Position* new_position) {
    if (head == NULL)
    {
        return;
    }
    
    while(head) {
        head->position.x = new_position->x;
        head->position.y = new_position->y;
        head = head->next;
    }
}

int is_empty(QNode* head) {
    return head == NULL;
}

int peek(QNode* head, Position* position) {
    if (is_empty(head)) {
        printf("A sor ures, nincs ertek.\n");
        return -1; // Hibaertek
    }
    *position = head->position;
    return 0;
}

void free_queue(QNode* head) {
    while (head)
    {
        QNode* q = head;
        head = head->next;
        free(q);
    }
}