#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph node
struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

// Function to create a new graph node
struct GraphNode* createNode(int vertex) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct GraphNode** adjLists, int src, int dest) {
    struct GraphNode* newNode = createNode(dest);
    newNode->next = adjLists[src];
    adjLists[src] = newNode;
}

// Function to perform Breadth-First Search (BFS) traversal of the graph
void BFS(struct GraphNode** adjLists, int numVertices, int startVertex) {
    int* visited = (int*)calloc(numVertices, sizeof(int));

    struct GraphNode* queue = createNode(startVertex);
    visited[startVertex] = 1;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (queue != NULL) {
        int vertex = queue->vertex;
        printf("%d ", vertex);
        queue = queue->next;

        struct GraphNode* adjacentNode = adjLists[vertex];
        while (adjacentNode != NULL) {
            int adjVertex = adjacentNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                struct GraphNode* newNode = createNode(adjVertex);
                newNode->next = queue;
                queue = newNode;
            }
            adjacentNode = adjacentNode->next;
        }
    }

    printf("\n");
}

// Function to free memory allocated for the graph
void freeGraph(struct GraphNode** adjLists, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        struct GraphNode* current = adjLists[i];
        while (current != NULL) {
            struct GraphNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adjLists);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct GraphNode** adjLists = (struct GraphNode**)malloc(numVertices * sizeof(struct GraphNode*));
    for (int i = 0; i < numVertices; i++) {
        adjLists[i] = NULL;
    }

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjLists, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    BFS(adjLists, numVertices, startVertex);

    freeGraph(adjLists, numVertices);

    return 0;
}
