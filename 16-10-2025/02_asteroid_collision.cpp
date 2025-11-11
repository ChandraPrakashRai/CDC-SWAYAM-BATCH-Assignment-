// 02_asteroid_collision.cpp
// Problem: Asteroid Collision - given array of integers representing asteroids (positive = right, negative = left).
// When two asteroids meet, the smaller one explodes. If equal size, both explode. Return state after all collisions.
//
// Brute-force idea:
//   Simulate pairwise collisions repeatedly scanning array -> O(n^2) worst-case.
//
// Optimized approach:
//   Use stack. For each asteroid a:
//     while stack not empty and a < 0 and stack.top() > 0:
//         compare abs(a) with stack.top(); pop or discard accordingly.
//     if not destroyed, push a.
//   End result is stack contents.
//
// Complexity: O(n) time amortized, O(n) space.

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& ast) {
    vector<int> st;
    for(int a: ast) {
        bool alive = true;
        while(alive && a < 0 && !st.empty() && st.back() > 0) {
            if(abs(a) > st.back()) {
                st.pop_back();
                continue;
            } else if(abs(a) == st.back()) {
                st.pop_back();
                alive = false;
                break;
            } else {
                alive = false;
                break;
            }
        }
        if(alive) st.push_back(a);
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {5, 10, -5};
    auto res = asteroidCollision(a);
    for(int x: res) cout << x << " ";
    cout << "\n";
    vector<int> b = {8, -8};
    res = asteroidCollision(b);
    for(int x: res) cout << x << " ";
    cout << "\n";
    return 0;
}
