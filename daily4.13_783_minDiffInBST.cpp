/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
*/

#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    void dfs(TreeNode* root, int& pre, int& ans){
        if (root == nullptr) return;
        dfs(root->left, pre, ans);
        if (pre == -1) pre = root->val;
        else{
            ans = min(pre, root->val-pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }

    int minDiffInBST(TreeNode* root){
        int pre = -1, ans = INT_MAX;
        dfs(root, pre, ans);
        return ans;
    }
};
