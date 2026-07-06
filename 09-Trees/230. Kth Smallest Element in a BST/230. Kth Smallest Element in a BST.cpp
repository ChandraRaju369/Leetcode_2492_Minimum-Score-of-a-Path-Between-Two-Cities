1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int c=0,K,ans=0;
15    void inorder(TreeNode* root){
16        if(root==NULL)
17            return;
18        inorder(root->left);
19        c++;
20        if(c==K){
21            ans=root->val;
22            return ;
23        }
24        inorder(root->right);
25    }
26    int kthSmallest(TreeNode* root, int k) {
27       K=k;
28       inorder(root);
29       return ans;
30    }
31};