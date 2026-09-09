#include <stdio.h>
    int current;
    visited[v] = 1;
    insertQueue(v);
    printf("\n");
    while (!isEmptyQueue()) {
        current = deleteQueue();
        printf("%d\n", current);
        p = graph[current];

        while (p != NULL) {
            if (visited[p->vertex] == 0) {
                visited[p->vertex] = 1;
                insertQueue(p->vertex);
            }

            p = p->next;
        }
	}
}

void main() {
    int N, E, s, d, i, v;
    GNODE p, q;

    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    n = N;

    for (i = 0; i < N; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (i = 1; i <= E; i++) {
        printf("Enter source: ");
        scanf("%d", &s);
        printf("Enter destination: ");
        scanf("%d", &d);

        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;

        if (graph[s] == NULL) {
            graph[s] = q;
        } else {
            p = graph[s];
            while (p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("Enter Start Vertex for BFS: ");
    scanf("%d", &v);
    printf("BFS of graph: ");
    BFS(v);
    printf("\n");
}
