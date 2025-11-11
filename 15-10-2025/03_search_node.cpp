// 03_search_node
// Problem: Search for a value in linked list and return position or -1.
//
// Notes:
// 
//
// Brute-force approach:
// Linear scan O(n).
//
// Optimized approach:
// int search(Node* head, int key) {
    int idx=0;
    while(head) {
        if(head->val==key) return idx;
        head = head->next; idx++;
    }
    return -1;
}
//
// Complexity:
// Time: O(n), Space: O(1)
//
// C++ implementation (custom Node / LinkedList)
// ------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

// helper to create list from vector (for tests)
Node* build(const vector<int>& a) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int x: a) {
        Node* n = new Node(x);
        if(!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

// Solution implementation
int search(Node* head, int key) {
    int idx=0;
    while(head) {
        if(head->val==key) return idx;
        head = head->next; idx++;
    }
    return -1;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
