/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        helper(root, targetSum); //this will return the paths starting at the head
        pathSum(root->left, targetSum); //because we do not just want the path to start at the head
        pathSum(root->right, targetSum);
        return count;
    }
    
    void helper(TreeNode* root, int target)
    {
        if(root == NULL) return;
        if(target == root->val)
        {
          count++;   
        }
        helper(root->left, target - root->val);
        helper(root->right, target - root->val);
    }
};