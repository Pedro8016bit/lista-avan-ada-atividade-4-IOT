#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <locale.h>

#define V 9 // N�mero de v�rtices no grafo

// Fun��o para encontrar o v�rtice com a menor dist�ncia que ainda n�o foi inclu�do no caminho mais curto
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Fun��o que implementa o algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para guardar a menor dist�ncia de cada v�rtice at� a origem
    bool sptSet[V]; // sptSet[v] ser� true se o v�rtice v estiver inclu�do no caminho mais curto

    // Inicializa todas as dist�ncias como infinitas e sptSet[] como false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // A dist�ncia do v�rtice de origem at� ele mesmo � 0
    dist[src] = 0;

    // Encontra o caminho mais curto para todos os v�rtices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o v�rtice de menor dist�ncia que ainda n�o foi processado
        int u = minDistance(dist, sptSet);

        // Marca o v�rtice escolhido como processado
        sptSet[u] = true;

        // Atualiza o valor da dist�ncia dos v�rtices adjacentes ao v�rtice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza dist[v] se:
            // 1) N�o est� em sptSet,
            // 2) Existe uma aresta de u para v,
            // 3) A dist�ncia total do caminho at� v atrav�s de u � menor que o valor atual de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Imprime o array de dist�ncias
    printf("V�rtice   Dist�ncia da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
	setlocale(LC_ALL, "");
    // Exemplo de grafo como uma matriz de adjac�ncia
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

    dijkstra(graph, 0); // Executa o algoritmo a partir do v�rtice 0

    return 0;
}

