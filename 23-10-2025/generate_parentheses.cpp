// Generate Parentheses - backtracking
// LeetCode 22 style solution: print/generate all well-formed parentheses for n pairs
#include <bits/stdc++.h>
using namespace std;
void backtrack(int open, int close, string &cur, vector<string> &res) {
    if ((int)cur.size() == open + close) return; // not used
    if (open == 0 && close == 0) {
        res.push_back(cur);
        return;
    }
    if (open > 0) {
        cur.push_back('(');
        backtrack(open-1, close+1, cur, res);
        cur.pop_back();
    }
    if (close > 0) {
        cur.push_back(')');
        backtrack(open, close-1, cur, res);
        cur.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    // We treat open as remaining '(' to place, close as available ')' to place (initially 0)
    function<void(int,int)> dfs = [&](int openRem, int closeAvail){
        if (openRem==0 && closeAvail==0) {
            res.push_back(cur);
            return;
        }
        if (openRem>0) {
            cur.push_back('(');
            dfs(openRem-1, closeAvail+1);
            cur.pop_back();
        }
        if (closeAvail>0) {
            cur.push_back(')');
            dfs(openRem, closeAvail-1);
            cur.pop_back();
        }
    };
    dfs(n,0);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    auto ans = generateParenthesis(n);
    for(auto &s: ans) cout<<s<<"\n";
    return 0;
}
