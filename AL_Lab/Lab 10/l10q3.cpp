#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 50; // Maximum number of vertices
int N; // Number of vertices
bool graph[MAX_N][MAX_N]; // Adjacency matrix to store the edges
int current_clique[MAX_N]; // Maximum clique found so far
int max_clique_size = 0; // Size of maximum clique found so far

bool is_clique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!graph[arr[i]][arr[j]]) {
                return false;
            }
        }
    }
    return true;
}

void max_clique(int arr[], int size, int index) {
    if (size > max_clique_size && is_clique(arr, size)) {
        max_clique_size = size;
        memcpy(current_clique, arr, size * sizeof(int));
    }
    if (index == N) {
        return;
    }
    bool flag = true;
    for (int i = 0; i < size; i++) {
        if (!graph[arr[i]][index]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        arr[size] = index;
        max_clique(arr, size + 1, index + 1);
    }
    max_clique(arr, size, index + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    int arr[MAX_N];
    max_clique(arr, 0, 0);
    cout << "Maximum Clique: ";
    for (int i = 0; i < max_clique_size; i++) {
        cout << current_clique[i] << " ";
    }
    cout << "\nSize of Maximum Clique: " << max_clique_size << endl;
    return 0;
}