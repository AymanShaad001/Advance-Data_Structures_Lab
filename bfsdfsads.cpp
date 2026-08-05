#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];


void display(int vertices)
{
    int i, j;

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


void BFS(int start, int vertices)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i;

    for(i = 0; i < vertices; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while(front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for(i = 0; i < vertices; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}


void DFS(int vertex, int vertices)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for(i = 0; i < vertices; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i, vertices);
        }
    }
}

int main()
{
    int vertices, edges;
    int src, dest;
    int start;
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    
    for(i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        graph[src][dest] = 1;
        graph[dest][src] = 1;   
    }

    display(vertices);

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    BFS(start, vertices);

    for(i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start, vertices);

    printf("\n");

    return 0;
}
