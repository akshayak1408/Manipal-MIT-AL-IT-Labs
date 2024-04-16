#include <iostream>
#include <cstring>

#define MAX_V 1000 // Maximum number of vertices

using namespace std;

int V; // Number of vertices
int graph[MAX_V][MAX_V]; // Adjacency matrix of the graph
int R[MAX_V], P[MAX_V], X[MAX_V]; // Arrays to store the current clique, candidates, and excluded vertices
int clique_size; // Size of the maximum clique

void bron_kerbosch(int r_size, int p_size, int x_size) {
    if (p_size == 0 && x_size == 0) { // If there are no candidates or excluded vertices
        clique_size = max(clique_size, r_size); // Update the size of the maximum clique
        return;
    }
    int u = 0;
    while (P[u] == 0 && X[u] == 0) u++; // Find the first vertex that is not in P or X
    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1 && P[v] == 1) { // If v is adjacent to u and is in P
            R[r_size] = v; // Add v to the current clique
            int p_copy[MAX_V], x_copy[MAX_V];
            for (int i = 0; i < V; i++) {
                p_copy[i] = P[i]; // Create a copy of P
                x_copy[i] = X[i]; // Create a copy of X
            }
            // Remove all vertices that are not adjacent to v from P and X
            for (int i = 0; i < V; i++) {
                if (graph[v][i] == 0) {
                    p_copy[i] = 0;
                    x_copy[i] = 0;
                }
            }
            bron_kerbosch(r_size+1, p_size-1, x_size); // Recurse with v added to R, and P and X updated
            R[r_size] = -1; // Remove v from the current clique
            P[v] = 0; // Remove v from P
            X[v] = 1; // Add v to X
        }
    }
}

int maximum_clique() {
    for (int i = 0; i < V; i++) {
        R[i] = -1; // Initialize the current clique to be empty
        P[i] = 1; // Initialize the candidates to be all vertices
        X[i] = 0; // Initialize the excluded vertices to be empty
    }
    clique_size = 0; // Initialize the size of the maximum clique to be 0
    bron_kerbosch(0, V, 0); // Call the Bron-Kerbosch algorithm
    return clique_size; // Return the size of the maximum clique
}

int main() {
    cin >> V; // Read in the number of vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j]; // Read in the adjacency matrix of the graph
        }
    }
    cout << maximum_clique() << endl; // Print the size of the maximum clique
    return 0;
}