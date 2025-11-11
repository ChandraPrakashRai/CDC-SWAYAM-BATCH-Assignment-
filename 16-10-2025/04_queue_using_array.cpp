// 04_queue_using_array.cpp
// Problem: Implement a queue using array with enqueue, dequeue, front, isEmpty.
// Use circular buffer for efficient use of space.
//
// Brute-force idea:
//   Shift elements on dequeue -> O(n) per dequeue.
//
// Optimized approach:
//   Use head, tail indices and capacity, wrap using modulo. Track size.
//
// Complexity: enqueue/dequeue/front O(1), Space O(capacity).

#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
    int cap;
    vector<int> data;
    int head, tail, sz;
public:
    ArrayQueue(int capacity=100): cap(capacity), data(capacity), head(0), tail(0), sz(0) {}
    bool enqueue(int x) {
        if(sz==cap) return false;
        data[tail] = x;
        tail = (tail+1)%cap;
        sz++;
        return true;
    }
    bool dequeue() {
        if(sz==0) return false;
        head = (head+1)%cap;
        sz--;
        return true;
    }
    int front() {
        if(sz==0) throw runtime_error("empty");
        return data[head];
    }
    bool empty() { return sz==0; }
    int size() { return sz; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.front() << "\n"; // 10
    q.dequeue();
    cout << q.front() << "\n"; // 20
    return 0;
}
