#include <stdio.h>

#define MAX 5


void bfs(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1;


    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%d->", start);

        for (int j = 0; j < MAX; j++) {
            if (adj[start][j] && visited[j] == 0) {
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}


void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX], top = -1;


    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top--];
        printf("%d->", start);


        for (int j = 0; j < MAX; j++) {
            if (adj[start][j] && visited[j] == 0) {
                stack[++top] = j;
                visited[j] = 1;
            }
        }
    }
}

int main() {

    int adj[MAX][MAX] = {
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };


    int visited[MAX];

    printf("BFS Traversal: ");
    bfs(adj, visited, 0);
    printf("\n");


    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(adj, visited, 0);
    printf("\n");

    return 0;
}
