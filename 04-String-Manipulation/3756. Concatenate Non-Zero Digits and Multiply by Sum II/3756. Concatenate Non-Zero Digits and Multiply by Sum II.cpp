1class Solution {
2public:
3    int M = 1e9+7;
4    typedef long long ll;
5    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
6        int n = s.length();
7
8        vector<int> nonzerocount(n,0);
9        vector<ll> numberupto(n,0);
10        vector<ll> digitsumupto(n,0);
11        vector<ll> pow10(n+1,0);
12
13        pow10[0]=1;
14        for(int i = 1 ; i <= n ; ++i){
15            pow10[i] = (pow10[i-1]*10)%M;
16        }
17
18        nonzerocount[0]=(s[0]!='0')?1:0;
19        for(int i = 1 ;i < n ; ++i){
20            nonzerocount[i] = nonzerocount[i - 1];
21            if(s[i]!='0'){
22                int digit = s[i]-'0';
23                nonzerocount[i] = nonzerocount[i-1]+((digit!=0)?1:0);
24            }
25        }
26        
27        numberupto[0]=s[0]-'0';
28        for(int i =1 ; i < n ; ++i){
29            int digit = s[i]-'0';
30            if(digit!=0){
31                numberupto[i]=((numberupto[i-1]*10)+digit)%M;
32            }else {
33                numberupto[i]=numberupto[i-1];
34            }
35        }
36        
37        digitsumupto[0]=s[0]-'0';
38        for(int i = 1 ; i < n ; ++i) {
39            int digit = s[i]-'0';
40            digitsumupto[i] = digitsumupto[i-1]+digit;
41        }
42
43        int q = queries.size();
44        vector<int> result(q);
45        for(int i = 0; i < q ; ++i){
46            int l = queries[i][0];
47            int r = queries[i][1];
48
49            ll sum = digitsumupto[r]-((l==0)?0:digitsumupto[l-1]);
50
51            int numbefore = (l==0)?0:numberupto[l-1];
52            int k = nonzerocount[r]-((l==0)?0:nonzerocount[l-1]);
53
54            ll x = (numberupto[r] - numbefore*pow10[k]%M+M)%M;
55            result[i] = (int)((x*(sum)%M)%M);
56        }
57        return result;
58    }
59};