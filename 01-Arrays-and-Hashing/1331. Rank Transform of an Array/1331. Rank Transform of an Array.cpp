1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int> a = arr;
5        sort(a.begin(), a.end());
6
7        unordered_map<int,int> mp;
8        int rank = 1;
9
10        for (int x : a) {
11            if (mp.find(x) == mp.end()) {
12                mp[x] = rank++;
13            }
14        }
15
16        vector<int> ans;
17
18        for (int x : arr)
19            ans.push_back(mp[x]);
20
21        return ans;
22    }
23};