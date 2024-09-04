#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_EDGES 100 // Número máximo de arestas
#define MAX_VERTICES 100 // Número máximo de vértices

// Estrutura para representar uma aresta
struct Edge {
    int src, dest, weight;
};

// Estrutura para representar um grafo
struct Graph {
    int V, E; // Vértices e Arestas
    struct Edge* edges; // Array de arestas
};

// Estrutura para representar um subset para o DSU (Disjoint Set Union)
struct Subset {
    int parent;
    int rank;
};

// Função para criar um grafo com V vértices e E arestas
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// Função para encontrar o conjunto de um elemento i (usando path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Função para unir dois conjuntos x e y (usando union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Função de comparação para ordenar as arestas em ordem crescente de peso
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*) a;
    struct Edge* edgeB = (struct Edge*) b;
    return edgeA->weight - edgeB->weight;
}

// Função principal que implementa o algoritmo de Kruskal
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX_EDGES]; // Array para armazenar as arestas da MST
    int e = 0; // Contador de arestas resultantes
    int i = 0; // Contador de arestas ordenadas

    // Passo 1: Ordenar todas as arestas em ordem crescente de peso
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Alocar memória para criar V subsets
    struct Subset *subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

    // Inicializar subsets com elementos individuais
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Passo 2: Montar a MST pegando as menores arestas
    while (e < V - 1 && i < graph->E) {
        // Pegue a menor aresta e incremente o índice para a próxima
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Se a inclusão dessa aresta não causa um ciclo
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Senão, ignore essa aresta
    }

    // Imprimir as arestas da MST
    printf("Arestas na MST\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    
    // Libera a memória alocada para subsets
    free(subsets);
}

int main() {
	setlocale(LC_ALL, "");
    int V = 4; // Número de vértices
    int E = 5; // Número de arestas
    struct Graph* graph = createGraph(V, E);

    // Aresta 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    // Aresta 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    // Aresta 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    // Aresta 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    // Aresta 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);

    // Libera a memória alocada para as arestas do grafo
    free(graph->edges);
    free(graph);

    return 0;
}

