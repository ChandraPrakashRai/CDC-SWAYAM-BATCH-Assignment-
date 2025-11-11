// 03_stock_span.cpp
// Problem: Stock Span - for each day, find the number of consecutive previous days with price <= today's price.
//
// Brute-force idea:
//   For each day i, scan left until a greater element -> O(n^2).
//
// Optimized approach:
//   Use stack of indices with decreasing prices. For day i, pop while price[st.top()] <= price[i].
//   If stack empty span = i+1 else span = i - st.top(). Push i.
//
// Complexity: O(n) time, O(n) space.

#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // indices
    for(int i=0;i<n;i++){
        while(!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty()? i+1 : i - st.top();
        st.push(i);
    }
    return span;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    auto sp = stockSpan(prices);
    for(int x: sp) cout << x << " ";
    cout << "\n";
    return 0;
}
