// Sudoku Solver - classic backtracking
// Input: 9 lines each with 9 digits or '.' for empty. Output: solved board.
#include <bits/stdc++.h>
using namespace std;
bool solve(vector<string>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, int r, int c) {
    for(int i=r;i<9;i++){
        for(int j=(i==r?c:0); j<9; j++){
            if(board[i][j]=='.'){
                int b = (i/3)*3 + j/3;
                for(char d='1'; d<='9'; ++d){
                    int val = d - '1';
                    if(!row[i][val] && !col[j][val] && !box[b][val]){
                        board[i][j] = d;
                        row[i][val]=col[j][val]=box[b][val]=1;
                        if(solve(board, row, col, box, i, j)) return true;
                        board[i][j]='.';
                        row[i][val]=col[j][val]=box[b][val]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(9);
    for(int i=0;i<9;i++){
        if(!(cin>>board[i])) return 0;
    }
    vector<vector<int>> row(9, vector<int>(9,0)), col(9, vector<int>(9,0)), box(9, vector<int>(9,0));
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) if(board[i][j]!='.'){
        int val = board[i][j]-'1';
        row[i][val]=col[j][val]=box[(i/3)*3 + j/3][val]=1;
    }
    solve(board, row, col, box, 0, 0);
    for(auto &s: board) cout<<s<<"\n";
    return 0;
}
