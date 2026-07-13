1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int> ans;
5        string s = 123456789;
6        for(int len = 2 ; len < 10 ; ++len) {
7            for(int st = 0 ; st <= s.length()-len ; ++st){
8                int digit = stoi(s.substr(st,len));
9                if(digit >= low && digit <= high){
10                    ans.push_back(digit);
11                }
12            }
13        }
14        return ans;
15    }
16};