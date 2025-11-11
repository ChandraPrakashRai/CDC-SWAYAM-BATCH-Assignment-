// 05_circular_queue.cpp
// Problem: Implement circular queue with wrap-around and capacity limit.
// Similar to ArrayQueue but showcase modular arithmetic and full/empty detection.
//
// Brute-force idea: same as before shifting elements -> inefficient.
// Optimized approach: track head, tail, count.
//
// Complexity: O(1) ops.

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int cap;
    vector<int> buf;
    int head, tail, cnt;
public:
    CircularQueue(int k): cap(k), buf(k), head(0), tail(0), cnt(0) {}
    bool enQueue(int value) {
        if(cnt==cap) return false;
        buf[tail]=value;
        tail = (tail+1)%cap;
        cnt++;
        return true;
    }
    bool deQueue() {
        if(cnt==0) return false;
        head = (head+1)%cap;
        cnt--;
        return true;
    }
    int Front() {
        if(cnt==0) throw runtime_error("empty");
        return buf[head];
    }
    int Rear() {
        if(cnt==0) throw runtime_error("empty");
        return buf[(tail-1+cap)%cap];
    }
    bool isEmpty(){ return cnt==0; }
    bool isFull(){ return cnt==cap; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    CircularQueue q(3);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout<<q.isFull()<<"\n"; // 1
    q.deQueue();
    q.enQueue(4);
    cout<<q.Rear()<<"\n"; // 4
    return 0;
}
