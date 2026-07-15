1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        int odd = (1 + (n-1)/2*2)*n;
5        int even = (2 + (n-1)/2*2)*n;
6        return gcd(odd,even);
7    }
8};