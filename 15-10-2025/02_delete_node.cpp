// 02_delete_node
// Problem: Delete node at a given position (0-indexed) from singly linked list.
//
// Notes:
// 
//
// Brute-force approach:
// Traverse to node and remove by relinking (O(n)).
//
// Optimized approach:
// // Optimized: single pass deletion
Node* deleteAtPosition(Node* head, int pos) {
    if(!head) return head;
    if(pos==0) {
        Node* nxt = head->next;
        delete head;
        return nxt;
    }
    Node* cur = head;
    int i=0;
    while(cur->next && i<pos-1) { cur = cur->next; i++; }
    if(cur->next) {
        Node* todel = cur->next;
        cur->next = todel->next;
        delete todel;
    }
    return head;
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
// Optimized: single pass deletion
Node* deleteAtPosition(Node* head, int pos) {
    if(!head) return head;
    if(pos==0) {
        Node* nxt = head->next;
        delete head;
        return nxt;
    }
    Node* cur = head;
    int i=0;
    while(cur->next && i<pos-1) { cur = cur->next; i++; }
    if(cur->next) {
        Node* todel = cur->next;
        cur->next = todel->next;
        delete todel;
    }
    return head;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
