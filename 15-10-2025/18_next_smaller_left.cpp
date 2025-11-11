// 18_next_smaller_left.cpp
// Problem: Next smaller element to the left for each element.
//
// Brute-force approach:
// Brute: for each element scan left O(n^2).
//
// Optimized approach:
// // Optimized: monotonic increasing stack
vector<int> nextSmallerLeft(const vector<int>& a) {
    int n=a.size();
    vector<int> ans(n, -1);
    stack<int> st; // will store values
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        ans[i] = st.empty()? -1 : st.top();
        st.push(a[i]);
    }
    return ans;
}
//
// Complexity:
// Time: O(n), Space: O(n)
//
// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Optimized: monotonic increasing stack
vector<int> nextSmallerLeft(const vector<int>& a) {
    int n=a.size();
    vector<int> ans(n, -1);
    stack<int> st; // will store values
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        ans[i] = st.empty()? -1 : st.top();
        st.push(a[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Quick run placeholder for 18_next_smaller_left.cpp\n";
    return 0;
}
