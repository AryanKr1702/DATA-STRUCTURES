#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createnewnode(int value) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertatleft(Node **head, int target, int value) {
    Node *newnode = createnewnode(value);
    Node *current = *head;

    while (current && current->data != target) {
        current = current->next;
    }

    if (!current) {
        free(newnode);
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;

    if (current->prev) {
        current->prev->next = newnode;
    } else {
        *head = newnode;
    }

    current->prev = newnode;
}

void insertionofvalue(Node **head, int value) {
    Node *newnode = createnewnode(value);
    if (!*head) {
        *head = newnode;
    } else {
        Node *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
    }
}

void deletevalue(Node **head, int value) {
    Node *current = *head;

    while (current && current->data != value) {
        current = current->next;
    }

    if (!current) return;

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    free(current);
}

void display(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    insertionofvalue(&head, 10);
    insertionofvalue(&head, 20);
    insertionofvalue(&head, 30);
    display(head);

    insertatleft(&head, 20, 15);
    display(head);

    deletevalue(&head, 20);
    display(head);

    return 0;
}
