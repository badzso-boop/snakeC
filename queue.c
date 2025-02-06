#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode* create_QNode(int x, int y) {
    QNode* new_node = (QNode*)malloc(sizeof(QNode));
    if (new_node == NULL) {
        printf("Memoriafoglalasi hiba");
        exit(1);
    }

    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;

    return new_node;
}

void enqueue(QNode** head, QNode** tail, int x, int y) {
    QNode* new_node = create_QNode(x, y);
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    else {
        *head = new_node;
    }

    *tail = new_node;
}

int dequeue(QNode** head, QNode** tail, int* x, int* y) {
    if (*head == NULL) {
        printf("A sor üres, nincs mit eltávolítani.\n");
        *tail = NULL; // Ha üres a lista, akkor a tail is NULL-ra áll
        return -1; // Hibaérték, ha üres a sor
    }

    QNode* temp = *head;
    *x = temp-> x;
    *y = temp->y;

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
        printf("(%d, %d)\n", head->x, head->y);
        head = head->next;
    }
}

int is_empty(QNode* head) {
    return head == NULL;
}

int peek(QNode* head, int* x, int* y) {
    if (is_empty(head)) {
        printf("A sor ures, nincs ertek.\n");
        return -1; // Hibaertek
    }
    *x = head->x;
    *y = head->y;
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