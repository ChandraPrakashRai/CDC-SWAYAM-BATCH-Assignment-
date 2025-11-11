// 11_detect_cycle
// Problem: Detect cycle in a linked list (Floyd's cycle detection).
//
// Notes:
// 
//
// Brute-force approach:
// Brute: mark visited nodes using hashset (O(n) space).
//
// Optimized approach:
// // Optimized: Floyd's Tortoise and Hare
bool hasCycle(Node* head) {
    if(!head) return false;
    Node* slow=head; Node* fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
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
// Optimized: Floyd's Tortoise and Hare
bool hasCycle(Node* head) {
    if(!head) return false;
    Node* slow=head; Node* fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
