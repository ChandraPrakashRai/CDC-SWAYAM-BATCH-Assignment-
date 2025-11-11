// 08_add_two_numbers
// Problem: Add two numbers represented by linked lists (each node a digit, least-significant digit at head).
//
// Notes:
// 
//
// Brute-force approach:
// Brute: convert to integers (may overflow) then add.
//
// Optimized approach:
// // Optimized: digit-by-digit addition with carry
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node dummy(0); Node* tail=&dummy;
    int carry=0;
    while(l1 || l2 || carry) {
        int s = carry + (l1?l1->val:0) + (l2?l2->val:0);
        carry = s/10;
        tail->next = new Node(s%10);
        tail = tail->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return dummy.next;
}
//
// Complexity:
// Time: O(max(n,m)), Space: O(max(n,m))
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
// Optimized: digit-by-digit addition with carry
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node dummy(0); Node* tail=&dummy;
    int carry=0;
    while(l1 || l2 || carry) {
        int s = carry + (l1?l1->val:0) + (l2?l2->val:0);
        carry = s/10;
        tail->next = new Node(s%10);
        tail = tail->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
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
