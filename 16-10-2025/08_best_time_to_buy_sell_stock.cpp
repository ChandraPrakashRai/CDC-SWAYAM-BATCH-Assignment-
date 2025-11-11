// 08_best_time_to_buy_sell_stock.cpp
// Problem: Best Time to Buy and Sell Stock - max profit from one transaction.
//
// Brute-force idea:
//   Try every buy day and sell day -> O(n^2).
//
// Optimized approach:
//   Track min price so far and compute max profit at each day: profit = price - minPrice.
//   O(n) time, O(1) space.
//
// Complexity: O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

int maxProfitBrute(const vector<int>& prices) {
    int n=prices.size(), best=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) best = max(best, prices[j]-prices[i]);
    return best;
}

int maxProfit(const vector<int>& prices) {
    int minp = INT_MAX, best=0;
    for(int p: prices) {
        minp = min(minp, p);
        best = max(best, p - minp);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> p = {7,1,5,3,6,4};
    cout << maxProfit(p) << "\n"; // 5
    return 0;
}
