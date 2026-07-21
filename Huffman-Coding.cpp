#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNode {
    bool operator()(Node *a, Node *b) const {
        return a->freq > b->freq;
    }
};

void buildCodes(Node *root, string code, map<char, string> &codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = code;
        return;
    }

    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    map<char, int> freqMap;
    for (int i = 0; i < n; ++i) {
        char ch;
        int freq;
        cout << "Enter character " << i + 1 << ": ";
        cin >> ch;
        cout << "Enter frequency: ";
        cin >> freq;
        freqMap[ch] = freq;
    }

    priority_queue<Node*, vector<Node*>, CompareNode> pq;
    for (const auto &entry : freqMap) {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node *root = pq.top();
    map<char, string> codes;
    buildCodes(root, "", codes);

    int weightedPathLength = 0;

    cout << "\nHuffman codes:" << endl;
    for (const auto &entry : freqMap) {
        cout << entry.first << " -> " << codes[entry.first] << endl;
        weightedPathLength += entry.second * codes[entry.first].size();
    }

    cout << "\nWeighted path length: " << weightedPathLength << endl;
    cout << "Time complexity: O(n log n)." << endl;

    return 0;
}
