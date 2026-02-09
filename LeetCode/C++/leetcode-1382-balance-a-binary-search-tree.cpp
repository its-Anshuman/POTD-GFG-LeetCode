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
    vector<int>vec;
    int n;
    vector<int>inorder(TreeNode* root){
        if(!root) return {};

        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);

        return vec;
    }
    TreeNode* solve(int l, int r, vector<int>& vec){
        if(l>r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solve(l,mid-1,vec);
        root->right = solve(mid+1,r, vec);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        n = vec.size();
        return solve(0,n-1,vec);
    }
};
