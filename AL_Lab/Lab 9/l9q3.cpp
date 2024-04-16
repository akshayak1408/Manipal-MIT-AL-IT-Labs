#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100; // Maximum number of items
int N; // Number of items
int capacity; // Knapsack capacity
int weight[MAX_N]; // Array to store the weights of the items
int value[MAX_N]; // Array to store the values of the items
int best_value = 0; // Best value obtained so far
bool best_items[MAX_N]; // Array to store the items in the best solution
bool current_items[MAX_N]; // Array to store the items in the current solution

bool promising(int i, int weight_sum, int value_sum) {
    // Check if we can add more items without exceeding the capacity
    if (weight_sum > capacity) {
        return false;
    }
    // Calculate the upper bound on the value of the remaining items
    int bound = value_sum;
    int j = i+1;
    int remaining_weight = capacity - weight_sum;
    while (j < N && remaining_weight >= weight[j]) {
        remaining_weight -= weight[j];
        bound += value[j];
        j++;
    }
    if (j < N) {
        bound += (double) remaining_weight / weight[j] * value[j];
    }
    return bound > best_value; // Return true if the upper bound is greater than the best value obtained so far
}

void knapsack(int i, int weight_sum, int value_sum) {
    if (weight_sum > capacity) { // If the weight of the items exceeds the capacity
        return;
    }
    if (i == N) { // If we have considered all the items
        if (value_sum > best_value) { // If this is a better solution than the previous best solution
            best_value = value_sum; // Update the best value
            copy(current_items, current_items+N, best_items); // Copy the current solution to the best solution
        }
        return;
    }
    current_items[i] = false; // Do not include item i
    if (promising(i, weight_sum, value_sum)) { // Check if the upper bound is greater than the best value obtained so far
        knapsack(i+1, weight_sum, value_sum); // Recurse without item i
    }
    current_items[i] = true; // Include item i
    if (promising(i, weight_sum+weight[i], value_sum+value[i])) { // Check if the upper bound is greater than the best value obtained so far
        knapsack(i+1, weight_sum+weight[i], value_sum+value[i]); // Recurse with item i
    }
}
int main() {
    cin >> N; // Read in the number of items
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i]; // Read in the weights and values of the items
    }
    cin >> capacity; // Read in the capacity of the knapsack
    knapsack(0, 0, 0); // Call the knapsack algorithm with the first item, no weight, and no value
    cout << "Optimal packing:" << endl;
    for (int i = 0; i < N; i++) {
        if (best_items[i]) { // If the item is included in the best solution
            cout << "Item " << i+1 << " with weight " << weight[i] << " and value " << value[i] << endl;
        }
    }
    return 0;
}