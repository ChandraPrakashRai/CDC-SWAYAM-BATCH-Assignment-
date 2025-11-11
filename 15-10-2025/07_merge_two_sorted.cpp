// 07_merge_two_sorted
// Problem: Merge two sorted linked lists into one sorted list.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: push elements into vector and sort (O(n log n)).
//
// Optimized approach:
// // Optimized: merge like merge-step of merge sort
Node* mergeTwoSorted(Node* a, Node* b) {
    Node dummy(0); Node* tail = &dummy;
    while(a && b) {
        if(a->val <= b->val) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a? a : b;
    return dummy.next;
}
//
// Complexity:
// Time: O(n+m), Space: O(1)
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
// Optimized: merge like merge-step of merge sort
Node* mergeTwoSorted(Node* a, Node* b) {
    Node dummy(0); Node* tail = &dummy;
    while(a && b) {
        if(a->val <= b->val) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a? a : b;
    return dummy.next;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
