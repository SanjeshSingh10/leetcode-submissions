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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0 ;

        return  build( preorder , i , INT_MAX );
        
    }

    TreeNode* build( vector<int>& arr , int& ind , int bound  ){
      if(ind == arr.size() || arr[ind] > bound   ) return NULL ;

      TreeNode* root = new TreeNode( arr[ind++] );

      root->left = build( arr , ind , root->val);
      root->right = build( arr, ind , bound );

      return root ;
   
    }
};