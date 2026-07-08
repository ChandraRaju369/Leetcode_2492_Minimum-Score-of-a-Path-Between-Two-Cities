1class Solution {
2public:
3    bool isGoodArray(vector<int>& nums) {
4        int g = 0;
5        int n = nums.size();
6        for(int i = 0; i < n ; ++i){
7            g = gcd(g,nums[i]);
8            if(g==1)
9                return true;
10        }
11        return false;
12    }
13};