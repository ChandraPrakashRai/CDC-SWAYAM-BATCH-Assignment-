// 14_intersection_of_two_lists
// Problem: Find intersection node (by reference) of two singly linked lists.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: hash nodes of first list then traverse second (O(n) space).
//
// Optimized approach:
// // Optimized: two-pointer switching technique
Node* getIntersection(Node* a, Node* b) {
    if(!a || !b) return nullptr;
    Node* p = a; Node* q = b;
    while(p!=q) {
        p = p? p->next : b;
        q = q? q->next : a;
    }
    return p;
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
// Optimized: two-pointer switching technique
Node* getIntersection(Node* a, Node* b) {
    if(!a || !b) return nullptr;
    Node* p = a; Node* q = b;
    while(p!=q) {
        p = p? p->next : b;
        q = q? q->next : a;
    }
    return p;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
