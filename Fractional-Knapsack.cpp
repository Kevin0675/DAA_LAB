#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    int weight;
    int value;
    double ratio;
};

bool compareByRatio(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    int capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items;
    items.reserve(n);

    for (int i = 0; i < n; ++i) {
        Item item;
        cout << "Enter item " << i + 1 << " name: ";
        cin >> item.name;
        cout << "Enter weight: ";
        cin >> item.weight;
        cout << "Enter value: ";
        cin >> item.value;
        item.ratio = static_cast<double>(item.value) / item.weight;
        items.push_back(item);
    }

    sort(items.begin(), items.end(), compareByRatio);

    double usedCapacity = 0.0;
    double totalValue = 0.0;

    cout << "\nGreedy selection:" << endl;
    cout << fixed << setprecision(2);

    for (const Item &item : items) {
        if (usedCapacity >= capacity) {
            break;
        }

        double amountTaken;
        if (usedCapacity + item.weight <= capacity) {
            amountTaken = item.weight;
        } else {
            amountTaken = capacity - usedCapacity;
        }

        double fraction = amountTaken / item.weight;
        usedCapacity += amountTaken;
        totalValue += item.value * fraction;

        cout << item.name << " -> " << fraction * 100 << "% taken" << endl;
    }

    cout << "\nTotal value: " << totalValue << endl;
    cout << "Time complexity: O(n log n) due to sorting." << endl;

    return 0;
}
