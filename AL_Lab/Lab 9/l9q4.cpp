#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100; // Maximum number of items
int N; // Number of items
int container_size; // Size of the container
int item_size[MAX_N]; // Array to store the sizes of the items
bool container[MAX_N]; // Array to store whether each item is in the container or not
bool best_container[MAX_N]; // Array to store the items in the best solution
int best_utilization = 0; // Best utilization obtained so far

void container_loading(int item_num, int current_utilization) {
    if (item_num == N) { // If all items have been considered
        if (current_utilization > best_utilization) { // If the current solution is better than the best solution so far
            best_utilization = current_utilization; // Update the best solution
            copy(container, container+N, best_container); // Copy the items in the container to the best container
        }
        return;
    }
    // Try adding the item to the container
    if (current_utilization + item_size[item_num] <= container_size) { // If the container can accommodate the item
        container[item_num] = true; // Add the item to the container
        container_loading(item_num+1, current_utilization+item_size[item_num]); // Recursively try the next item
        container[item_num] = false; // Remove the item from the container
    }
    // Try skipping the item
    container_loading(item_num+1, current_utilization); // Recursively try the next item
}

int main() {
    cin >> N; // Read in the number of items
    for (int i = 0; i < N; i++) {
        cin >> item_size[i]; // Read in the sizes of the items
    }
    cin >> container_size; // Read in the size of the container
    container_loading(0, 0); // Call the container loading algorithm with no items and no utilization
    cout << "Best utilization: " << best_utilization << endl;
    cout << "Items in container:" << endl;
    for (int i = 0; i < N; i++) {
        if (best_container[i]) { // If the item is in the container in the best solution
            cout << "Item " << i+1 << " with size " << item_size[i] << endl;
        }
    }
    return 0;
}