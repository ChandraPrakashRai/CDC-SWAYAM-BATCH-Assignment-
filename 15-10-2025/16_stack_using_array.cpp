// 16_stack_using_array.cpp
// Problem: Implement a stack using array with push, pop, top, isEmpty.
//
// Brute-force approach:
// Brute: use dynamic resizing manually.
//
// Optimized approach:
// // Simple array-based stack (fixed capacity with resizing)
class ArrayStack {
    vector<int> a;
public:
    ArrayStack() { a.reserve(100); }
    void push(int x) { a.push_back(x); }
    void pop() { if(!a.empty()) a.pop_back(); }
    int top() { return a.empty()? INT_MIN : a.back(); }
    bool empty() { return a.empty(); }
};
//
// Complexity:
// Operations O(1) amortized, Space O(n)
//
// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Simple array-based stack (fixed capacity with resizing)
class ArrayStack {
    vector<int> a;
public:
    ArrayStack() { a.reserve(100); }
    void push(int x) { a.push_back(x); }
    void pop() { if(!a.empty()) a.pop_back(); }
    int top() { return a.empty()? INT_MIN : a.back(); }
    bool empty() { return a.empty(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Quick run placeholder for 16_stack_using_array.cpp\n";
    return 0;
}
