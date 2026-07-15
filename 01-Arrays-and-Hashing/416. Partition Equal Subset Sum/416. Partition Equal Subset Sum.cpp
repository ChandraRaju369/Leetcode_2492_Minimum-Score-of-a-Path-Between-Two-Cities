1class Solution {
2public:
3    int n , sum;
4    vector<vector<bool>> dp;
5    bool subsetsum(vector<int>& nums , int x) {
6        dp.assign(n+1,vector<bool>(x+1,false));
7        for (int i = 0; i <= n; i++)
8            dp[i][0] = true;
9        for(int i = 1 ; i < n+1 ; ++i){
10            for(int j = 1 ; j < x+1 ; ++j) {
11                if(nums[i-1]<=j) {
12                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
13                }
14                else dp[i][j] = dp[i-1][j];
15            }
16        }
17        return dp[n][x];
18    }
19    bool canPartition(vector<int>& nums) {
20        n = nums.size() ;
21        if(n==1)
22            return false;
23
24        sum = 0;
25        for(int i = 0; i < n ; ++i){
26            sum+=nums[i];
27        }
28        if(sum%2!=0)
29            return false;
30        
31        return subsetsum(nums,sum/2);
32    }
33};