#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 100; // Maximum number of items
int N; // Number of items
int container_size; // Size of the container
int item_size[MAX_N]; // Array to store the sizes of the items
bool container[MAX_N]; // Array to store whether each item is in the container or not
bool best_container[MAX_N]; // Array to store the items in the best solution
int best_utilization = 0; // Best utilization obtained so far

struct Node {
    int level;
    int utilization;
    bool container[MAX_N];
    bool operator<(const Node& other) const {
        return utilization < other.utilization;
    }
};

void container_loading() {
    priority_queue<Node> q;
    Node u, v;
    u.level = -1;
    u.utilization = 0;
    for (int i = 0; i < N; i++) {
        u.container[i] = false;
    }
    q.push(u);
    while (!q.empty()) {
        u = q.top();
        q.pop();
        if (u.level == N-1) { // If all items have been considered
            if (u.utilization > best_utilization) { // If the current solution is better than the best solution so far
                best_utilization = u.utilization; // Update the best solution
                copy(u.container, u.container+N, best_container); // Copy the items in the container to the best container
            }
            continue;
        }
        // Try adding the item to the container
        if (u.utilization + item_size[u.level+1] <= container_size) { // If the container can accommodate the item
            v.level = u.level + 1;
            v.utilization = u.utilization + item_size[v.level];
            copy(u.container, u.container+N, v.container);
            v.container[v.level] = true;
            q.push(v);
        }
        // Try skipping the item
        v.level = u.level + 1;
        v.utilization = u.utilization;
        copy(u.container, u.container+N, v.container);
        v.container[v.level] = false;
        if (v.utilization + *max_element(item_size+v.level+1, item_size+N) > best_utilization) { // If the remaining items cannot improve the solution
            q.push(v);
        }
    }
}

int main() {
    cin >> N; // Read in the number of items
    for (int i = 0; i < N; i++) {
        cin >> item_size[i]; // Read in the sizes of the items
    }
    cin >> container_size; // Read in the size of the container
    container_loading(); // Call the container loading algorithm
    cout << "Best utilization: " << best_utilization << endl;
    cout << "Items in container:" << endl;
    for (int i = 0; i < N; i++) {
        if (best_container[i]) { // If the item is in the container in the best solution
            cout << "Item " << i+1 << " with size " << item_size[i] << endl;
        }
    }
    return 0;
}