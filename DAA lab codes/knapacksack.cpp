#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Item {
    int weight;
    int value;
    double ratio; 
    double fraction;
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
double fractionalKnapsack(int capacity, vector<Item>& items, vector<double>& fractions) {
    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
        item.fraction = 0.0;
    }
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < items.size(); ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            items[i].fraction = 1.0;
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            items[i].fraction = static_cast<double>(capacity - currentWeight) / items[i].weight;
            totalValue += items[i].fraction * items[i].value;
            break;
        }
    }
    for (const auto& item : items) {
        fractions.push_back(item.fraction);
    }
    return totalValue;
}
int main() {
    int n; 
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    vector<double> fractions;
    cout << "Enter the weight and profit for each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(capacity, items, fractions);
    cout << "Maximum value in the knapsack: " << maxValue << endl;
    cout << "Set of items{";
    for (int i = 0; i < n; ++i) {
        cout << i+1;
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "}=[";
    for (int i = 0; i < n; ++i) {
        cout << fractions[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}