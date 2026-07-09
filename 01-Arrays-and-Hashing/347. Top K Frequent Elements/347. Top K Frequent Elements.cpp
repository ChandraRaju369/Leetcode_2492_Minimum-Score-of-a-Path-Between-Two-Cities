1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        unordered_map<int,int> mp;
5        for(int i = 0 ; i < nums.size() ; ++i) mp[nums[i]]++;
6        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
7        for(auto it : mp) {
8            pq.push({it.second , it.first});
9            if(pq.size() > k) pq.pop();
10        }
11        vector<int> ans ;
12        while(!pq.empty()){
13            ans.push_back(pq.top().second);
14            pq.pop();
15        }
16        return ans;
17    }
18};