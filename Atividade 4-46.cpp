#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <locale.h>

#define V 9 // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância que ainda não foi incluído no caminho mais curto
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Função que implementa o algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para guardar a menor distância de cada vértice até a origem
    bool sptSet[V]; // sptSet[v] será true se o vértice v estiver incluído no caminho mais curto

    // Inicializa todas as distâncias como infinitas e sptSet[] como false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // A distância do vértice de origem até ele mesmo é 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice de menor distância que ainda não foi processado
        int u = minDistance(dist, sptSet);

        // Marca o vértice escolhido como processado
        sptSet[u] = true;

        // Atualiza o valor da distância dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza dist[v] se:
            // 1) Não está em sptSet,
            // 2) Existe uma aresta de u para v,
            // 3) A distância total do caminho até v através de u é menor que o valor atual de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Imprime o array de distâncias
    printf("Vértice   Distância da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
	setlocale(LC_ALL, "");
    // Exemplo de grafo como uma matriz de adjacência
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0); // Executa o algoritmo a partir do vértice 0

    return 0;
}

