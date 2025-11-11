// 09_rotate_list
// Problem: Rotate linked list to the right by k places.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: k times pop tail and push front (O(k*n)).
//
// Optimized approach:
// // Optimized: connect tail to head, find new tail at n - k%n -1
Node* rotateRight(Node* head, int k) {
    if(!head || !head->next || k==0) return head;
    int n=1;
    Node* tail = head;
    while(tail->next) { tail = tail->next; n++; }
    k %= n;
    if(k==0) return head;
    tail->next = head; // make circle
    int steps = n - k;
    Node* newtail = tail;
    while(steps--) newtail = newtail->next;
    Node* newhead = newtail->next;
    newtail->next = nullptr;
    return newhead;
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
// Optimized: connect tail to head, find new tail at n - k%n -1
Node* rotateRight(Node* head, int k) {
    if(!head || !head->next || k==0) return head;
    int n=1;
    Node* tail = head;
    while(tail->next) { tail = tail->next; n++; }
    k %= n;
    if(k==0) return head;
    tail->next = head; // make circle
    int steps = n - k;
    Node* newtail = tail;
    while(steps--) newtail = newtail->next;
    Node* newhead = newtail->next;
    newtail->next = nullptr;
    return newhead;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
