// N-Queens - print all solutions. Input: n. Output: each solution as board with Q and .
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> board;
vector<vector<string>> ans;
void solve(int col, vector<int>&ld, vector<int>&cols, vector<int>&rd){
    if(col==n){ ans.push_back(board); return; }
    for(int row=0;row<n;row++){
        if(cols[row]||ld[row+col]||rd[n-1 + col-row]) continue;
        cols[row]=ld[row+col]=rd[n-1 + col-row]=1;
        board[row][col]='Q';
        solve(col+1, ld, cols, rd);
        board[row][col]='.';
        cols[row]=ld[row+col]=rd[n-1 + col-row]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n)) return 0;
    board.assign(n, string(n, '.'));
    vector<int> ld(2*n,0), cols(n,0), rd(2*n,0);
    solve(0, ld, cols, rd);
    if(ans.empty()){ cout<<"NO SOLUTION\n"; return 0; }
    for(auto &sol: ans){
        for(auto &row: sol) cout<<row<<"\n";
        cout<<"\n";
    }
    return 0;
}
