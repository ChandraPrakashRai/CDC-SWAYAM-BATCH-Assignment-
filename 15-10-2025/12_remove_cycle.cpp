// 12_remove_cycle
// Problem: Remove cycle from linked list if present and restore list to linear.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: use visited set and break link when revisit found.
//
// Optimized approach:
// // Optimized: detect using Floyd and then find loop start
void removeCycle(Node* head) {
    if(!head) return;
    Node* slow=head; Node* fast=head;
    bool found=false;
    while(fast && fast->next) {
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) { found=true; break; }
    }
    if(!found) return;
    slow = head;
    if(slow==fast) {
        // loop starts at head -> find last node
        while(fast->next!=slow) fast=fast->next;
        fast->next = nullptr;
        return;
    }
    while(slow->next != fast->next) {
        slow=slow->next; fast=fast->next;
    }
    fast->next = nullptr;
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
// Optimized: detect using Floyd and then find loop start
void removeCycle(Node* head) {
    if(!head) return;
    Node* slow=head; Node* fast=head;
    bool found=false;
    while(fast && fast->next) {
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) { found=true; break; }
    }
    if(!found) return;
    slow = head;
    if(slow==fast) {
        // loop starts at head -> find last node
        while(fast->next!=slow) fast=fast->next;
        fast->next = nullptr;
        return;
    }
    while(slow->next != fast->next) {
        slow=slow->next; fast=fast->next;
    }
    fast->next = nullptr;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
