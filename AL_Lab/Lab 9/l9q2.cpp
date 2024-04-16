#include <iostream>
#include <climits>

#define INF INT_MAX // Infinity

using namespace std;

const int MAX_N = 20; // Maximum number of nodes
int N; // Number of nodes
int start; // Starting node
int graph[MAX_N][MAX_N]; // Adjacency matrix of the graph
int path[MAX_N]; // Array to store the current path
bool visited[MAX_N]; // Array to keep track of visited nodes
int min_cost = INF; // Minimum cost of a Hamiltonian cycle

void tsp(int current, int cost, int count) {
    if (count == N) { // If we have visited all nodes
        cost += graph[current][start]; // Add the cost of returning to the starting node
        if (cost < min_cost) { // If this is a better Hamiltonian cycle
            min_cost = cost; // Update the minimum cost
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { // If node i has not been visited yet
            visited[i] = true; // Mark node i as visited
            path[count] = i; // Add node i to the current path
            tsp(i, cost+graph[current][i], count+1); // Recurse with node i as the current node
            visited[i] = false; // Mark node i as unvisited
        }
    }
}

int main() {
    cin >> N; // Read in the number of nodes
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j]; // Read in the adjacency matrix of the graph
        }
    }
    cin >> start; // Read in the starting node
    visited[start] = true; // Mark the starting node as visited
    path[0] = start; // Add the starting node to the current path
    tsp(start, 0, 1); // Call the TSP algorithm with the starting node as the current node
    cout << "Minimum cost of a Hamiltonian cycle: " << min_cost << endl; // Print the minimum cost of a Hamiltonian cycle
    return 0;
}