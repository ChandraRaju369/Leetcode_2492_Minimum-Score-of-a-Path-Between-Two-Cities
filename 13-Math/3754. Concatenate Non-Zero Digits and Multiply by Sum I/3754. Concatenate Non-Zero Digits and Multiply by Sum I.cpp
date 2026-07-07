1class Solution {
2public:
3    using ll = long long;
4    ll digi(int n){
5        string ans = ;
6        while(n>0){
7            ll t = n%10;
8            n=n/10;
9            if(t!=0)
10            ans.push_back(t+'0');
11        }
12        reverse(ans.begin(),ans.end());
13        ll p = 0;
14        for(int i = 0 ;i< ans.size() ; ++i){
15            if(ans[i]!=0)
16                p += ans[i]-'0';
17        }
18        ll num = stoll(ans);
19        return num*p;
20    }
21    long long sumAndMultiply(int n) {
22        if(n==0) return 0;
23        return digi(n);
24    }
25};