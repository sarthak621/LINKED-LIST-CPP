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
    bool solve(TreeNode* root, int targetSum, int sum){
        // base case
        if(root==NULL){
            return false;
        }
        sum=sum+root->val;
        // 1 case ham
        if(root->left==NULL && root->right==NULL){
            // we are at the leaft node
            if(sum==targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        // baki recursion
        bool leftans= solve(root->left, targetSum,sum);
        bool rightans= solve(root->right, targetSum,sum);
        return leftans||rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans= solve(root, targetSum,sum);
        return ans ;
    }
};