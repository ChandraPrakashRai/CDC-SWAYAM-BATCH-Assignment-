// 01_min_stack.cpp
// Problem: Min Stack - design a stack that supports push, pop, top and retrieving the minimum element in constant time.
//
// Brute-force idea:
//   Keep all elements in a stack. For getMin(), traverse whole stack to find minimum -> O(n) per getMin.
//
// Optimized approach:
//   Maintain two stacks: one normal stack and one stack of current minimums.
//   On push(x): push x to normal; if minStack empty or x<=minStack.top() push x to minStack.
//   On pop(): pop from normal; if popped value == minStack.top() pop minStack.
//   getMin(): return minStack.top() in O(1).
//
// Complexity: push/pop/top/getMin O(1) time, O(n) extra space for min stack.

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    void push(int x) {
        s.push(x);
        if(mins.empty() || x <= mins.top()) mins.push(x);
    }
    void pop() {
        if(s.empty()) return;
        int v = s.top(); s.pop();
        if(!mins.empty() && mins.top() == v) mins.pop();
    }
    int top() {
        if(s.empty()) throw runtime_error("empty");
        return s.top();
    }
    int getMin() {
        if(mins.empty()) throw runtime_error("empty");
        return mins.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MinStack ms;
    ms.push(3);
    ms.push(5);
    ms.push(2);
    ms.push(2);
    cout << "Min: " << ms.getMin() << "\n"; // 2
    ms.pop();
    cout << "Min: " << ms.getMin() << "\n"; // 2
    ms.pop();
    cout << "Min: " << ms.getMin() << "\n"; // 3
    return 0;
}
