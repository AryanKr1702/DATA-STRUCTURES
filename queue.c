#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int front = -1, rear = -1;
int arr[SIZE];

void enqueue() {
    int num;
    printf("Enter the Number to enqueue: ");
    scanf("%d", &num);
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;  
        rear++;
        arr[rear] = num;
        printf("%d has been enqueued in the Queue\n", num);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("%d has been removed from the queue\n", arr[front]);
        front++;
        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void show() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the Queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d", arr[i]);
            if (i < rear) printf(", ");
        }
        printf("\n");
    }
}

int main() {
    int choice = 1;
    while (choice) {
        printf("Enter 1 for enqueue, 2 for dequeue, 3 to show, and 4 to exit: ");
        int b;
        scanf("%d", &b);
        switch (b) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                choice = 0;
                break;
            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}
