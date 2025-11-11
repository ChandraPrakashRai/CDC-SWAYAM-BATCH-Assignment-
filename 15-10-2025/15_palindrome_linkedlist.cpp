// 15_palindrome_linkedlist
// Problem: Check if a linked list is palindrome (values).
//
// Notes:
// 
//
// Brute-force approach:
// Brute: copy into vector and check (O(n) time, O(n) space).
//
// Optimized approach:
// // Optimized: find middle, reverse second half, compare, restore
bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;
    Node* slow=head; Node* fast=head;
    while(fast && fast->next) { slow=slow->next; fast=fast->next->next; }
    // reverse second half
    Node* prev=nullptr; Node* cur=slow;
    while(cur) { Node* nx=cur->next; cur->next=prev; prev=cur; cur=nx; }
    Node* p=head; Node* q=prev;
    bool ok=true;
    while(q) {
        if(p->val!=q->val) { ok=false; break; }
        p=p->next; q=q->next;
    }
    // (optional) restore list by reversing second half again
    return ok;
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
// Optimized: find middle, reverse second half, compare, restore
bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;
    Node* slow=head; Node* fast=head;
    while(fast && fast->next) { slow=slow->next; fast=fast->next->next; }
    // reverse second half
    Node* prev=nullptr; Node* cur=slow;
    while(cur) { Node* nx=cur->next; cur->next=prev; prev=cur; cur=nx; }
    Node* p=head; Node* q=prev;
    bool ok=true;
    while(q) {
        if(p->val!=q->val) { ok=false; break; }
        p=p->next; q=q->next;
    }
    // (optional) restore list by reversing second half again
    return ok;
}

int main() {
    // small tests
    Node* h = build({1,2,3,4,5});
    cout << "Input: "; printList(h);
    // Call the implemented function(s) below as example
    // (Adjust per-file)
    return 0;
}
