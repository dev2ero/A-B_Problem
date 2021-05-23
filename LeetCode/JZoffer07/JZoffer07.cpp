/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> Preorder;
    unordered_map<int, int> InIndexValue;

    TreeNode* build(int pre_root, int left, int right) {
        if(left > right) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(Preorder[pre_root]);

        int index = InIndexValue[Preorder[pre_root]];

        root->left = build(pre_root+1, left, index-1);
        root->right = build(pre_root+index-left+1, index+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        Preorder = preorder; 
        for(int i = 0; i < inorder.size(); ++i) {
            InIndexValue[inorder[i]] = i;
        }

        return build(0, 0, preorder.size()-1);
    }
};
