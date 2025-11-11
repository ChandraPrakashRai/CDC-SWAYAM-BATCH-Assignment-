// Problem: MaxProductSubarray
// Description: Max product subarray
// Brute-force complexity: O(n^2)
// Optimized complexity: O(n)
// Example: 

// Brute-force implementation
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>&a){ int n=a.size(), best=INT_MIN; for(int i=0;i<n;++i){ int p=1; for(int j=i;j<n;++j){ p*=a[j]; best=max(best,p);} } return best; } int main(){ vector<int>a={2,3,-2,4}; cout<<maxProduct(a); }

// Optimized implementation
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums){ int curMax=nums[0], curMin=nums[0], ans=nums[0]; for(int i=1;i<nums.size();++i){ if(nums[i]<0) swap(curMax, curMin); curMax = max(nums[i], curMax*nums[i]); curMin = min(nums[i], curMin*nums[i]); ans = max(ans, curMax); } return ans; } int main(){ vector<int>a={2,3,-2,4}; cout<<maxProduct(a); }
