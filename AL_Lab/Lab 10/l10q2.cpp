#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 10; // Maximum number of cities
int N; // Number of cities
int graph[MAX_N][MAX_N]; // Adjacency matrix to store the distances between the cities
int path[MAX_N]; // Array to store the current path
bool visited[MAX_N]; // Array to store whether a city has been visited or not
int best_path[MAX_N]; // Array to store the best path obtained so far
int best_cost = INT_MAX; // Best cost obtained so far

int calculate_lower_bound(int level, int cost) {
    // Calculate the lower bound on the remaining cost using the nearest neighbor heuristic
    int lb = 0;
    bool used[MAX_N] = { false };
    int current_city = path[level-1];
    for (int i = level; i < N; i++) {
        int next_city = -1;
        int min_distance = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!used[j] && graph[current_city][j] < min_distance) {
                next_city = j;
                min_distance = graph[current_city][j];
            }
        }
        if (next_city == -1) {
            return INT_MAX; // No feasible solution
        }
        lb += min_distance;
        current_city = next_city;
        used[next_city] = true;
    }
    lb += graph[current_city][path[0]]; // Return to the starting city
    return lb;
}

void tsp_branch_and_bound(int level, int cost) {
    if (level == N) {
        // Reached the end of the path, update the best solution if necessary
        if (cost + graph[path[level-1]][path[0]] < best_cost) {
            for (int i = 0; i < N; i++) {
                best_path[i] = path[i];
            }
            best_cost = cost + graph[path[level-1]][path[0]];
        }
        return;
    }
    int lb = calculate_lower_bound(level, cost);
    if (lb >= best_cost) {
        // Prune the search if the lower bound on the remaining cost is worse than the best solution so far
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path[level] = i;
            tsp_branch_and_bound(level+1, cost + graph[path[level-1]][i]);
            visited[i] = false;
        }
    }
}

int main() {
    // Read input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    // Initialize path and visited arrays
    path[0] = 0;
    visited[0] = true;
    // Solve TSP using branch and bound
    tsp_branch_and_bound(1, 0);
    // Print the best solution
    cout << "Best path: ";
    for (int i = 0; i < N; i++) {
        cout << best_path[i] << " ";
    }
    cout << endl;
    cout << "Best cost: " << best_cost << endl;
    return 0;
}