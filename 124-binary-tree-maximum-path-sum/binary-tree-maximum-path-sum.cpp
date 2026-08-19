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
    int dfs(TreeNode* node , int& maxsum){

        if(!node) return 0 ;

        int LH = max( 0 , dfs( node->left, maxsum));
        int RH = max( 0, dfs( node->right , maxsum) );

        maxsum = max( maxsum , LH + RH + node->val);

        return max( LH , RH )+ node->val ; 
    }




    int maxPathSum(TreeNode* root) {

      int maxsum = INT_MIN; 

      dfs( root , maxsum);

      return maxsum ;

    }
};