// 17_next_greater_element.cpp
// Problem: Next greater element for each element in array (to the right).
//
// Brute-force approach:
// Brute: for each element scan right O(n^2).
//
// Optimized approach:
// // Optimized: monotonic stack O(n)
vector<int> nextGreater(const vector<int>& arr) {
    int n=arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // store indices
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] > arr[st.top()]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
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

// Optimized: monotonic stack O(n)
vector<int> nextGreater(const vector<int>& arr) {
    int n=arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // store indices
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] > arr[st.top()]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Quick run placeholder for 17_next_greater_element.cpp\n";
    return 0;
}
