#include <iostream>
#include <vector>
using namespace std;

int main() {
    int amount;

    cout << "Enter the amount to make change for: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Amount cannot be negative." << endl;
        return 1;
    }

    vector<int> denominations = {200, 100, 50, 20, 10, 5, 1};
    int remaining = amount;
    int totalCoins = 0;

    cout << "\nCoin change breakdown:" << endl;

    for (int denom : denominations) {
        int count = remaining / denom;
        if (count > 0) {
            cout << denom << "-coin(s): " << count << endl;
            remaining -= count * denom;
            totalCoins += count;
        }
    }

    cout << "\nTotal coins used: " << totalCoins << endl;
    cout << "Remaining balance: " << remaining << endl;
    cout << "Time complexity: O(n), where n is the number of denominations." << endl;

    return 0;
}
