// 20_evaluate_postfix.cpp
// Problem: Evaluate a postfix (Reverse Polish Notation) expression.
//
// Brute-force approach:
// Brute: recursively parse (complex).
//
// Optimized approach:
// // Optimized: use stack for operands
int evalPostfix(const vector<string>& tokens) {
    stack<int> st;
    for(const string& t: tokens) {
        if(t=="+"||t=="-"||t=="*"||t=="/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(t=="+") st.push(a+b);
            else if(t=="-") st.push(a-b);
            else if(t=="*") st.push(a*b);
            else st.push(a/b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}
//
// Complexity:
// Time: O(n), Space: O(n)
//
// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Optimized: use stack for operands
int evalPostfix(const vector<string>& tokens) {
    stack<int> st;
    for(const string& t: tokens) {
        if(t=="+"||t=="-"||t=="*"||t=="/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(t=="+") st.push(a+b);
            else if(t=="-") st.push(a-b);
            else if(t=="*") st.push(a*b);
            else st.push(a/b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Quick run placeholder for 20_evaluate_postfix.cpp\n";
    return 0;
}
