1class Solution {
2    using ll = long long;
3public:
4    int mySqrt(int x) {
5        if(x<2) return x;
6        long left = (long) (exp(0.5*log(x)));
7        long right = left+1;
8        return right*right>x ? left : right;
9    }
10};