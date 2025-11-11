// 10_remove_duplicates_sorted
// Problem: Remove duplicates from a sorted linked list.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: use hashset to rebuild list (O(n) space).
//
// Optimized approach:
// // Optimized: in-place remove consecutive duplicates
Node* removeDuplicates(Node* head) {
    Node* cur = head;
    while(cur && cur->next) {
        if(cur->val == cur->next->val) {
            Node* todel = cur->next;
            cur->next = todel->next;
            delete todel;
        } else cur = cur->next;
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
// Optimized: in-place remove consecutive duplicates
Node* removeDuplicates(Node* head) {
    Node* cur = head;
    while(cur && cur->next) {
        if(cur->val == cur->next->val) {
            Node* todel = cur->next;
            cur->next = todel->next;
            delete todel;
        } else cur = cur->next;
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
