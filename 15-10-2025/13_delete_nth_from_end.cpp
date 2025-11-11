// 13_delete_nth_from_end
// Problem: Delete the nth node from the end of the linked list in one pass.
//
// Notes:
// 
//
// Brute-force approach:
// Brute: compute length then delete (two passes).
//
// Optimized approach:
// // Optimized: two pointers with gap n
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0); dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;
    for(int i=0;i<=n;i++) if(first) first=first->next;
    while(first) { first=first->next; second=second->next; }
    Node* todel = second->next;
    second->next = todel->next;
    delete todel;
    return dummy.next;
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
// Optimized: two pointers with gap n
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0); dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;
    for(int i=0;i<=n;i++) if(first) first=first->next;
    while(first) { first=first->next; second=second->next; }
    Node* todel = second->next;
    second->next = todel->next;
    delete todel;
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
