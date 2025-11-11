// 06_queue_using_stacks.cpp
// Problem: Implement a queue using two stacks (enqueue O(1), dequeue amortized O(1)).
//
// Brute-force idea:
//   Use single stack and reverse for dequeue -> O(n) per dequeue.
//
// Optimized approach:
//   Maintain two stacks: inbox and outbox.
//   Enqueue: push to inbox.
//   Dequeue: if outbox empty, pour all from inbox to outbox (reverses order), then pop from outbox.
//
// Complexity: amortized O(1) per operation, O(n) space.

#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
    stack<int> in, out;
    void pour() { while(!in.empty()){ out.push(in.top()); in.pop(); } }
public:
    void enqueue(int x){ in.push(x); }
    bool dequeue(){
        if(out.empty()){
            if(in.empty()) return false;
            pour();
        }
        out.pop();
        return true;
    }
    int front(){
        if(out.empty()){
            if(in.empty()) throw runtime_error("empty");
            pour();
        }
        return out.top();
    }
    bool empty(){ return in.empty() && out.empty(); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    QueueUsingStacks q;
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    return 0;
}
