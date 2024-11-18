#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack.\n", data);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d popped from stack.\n", temp->data);
    *top = temp->next;
    free(temp);
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued into queue.\n", data);
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = *front;
    printf("%d dequeued from queue.\n", temp->data);
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    printf("Stack: ");
    display(stackTop);
    pop(&stackTop);
    printf("Stack after pop: ");
    display(stackTop);

    enqueue(&queueFront, &queueRear, 40);
    enqueue(&queueFront, &queueRear, 50);
    enqueue(&queueFront, &queueRear, 60);
    printf("Queue: ");
    display(queueFront);
    dequeue(&queueFront, &queueRear);
    printf("Queue after dequeue: ");
    display(queueFront);

    return 0;
}
