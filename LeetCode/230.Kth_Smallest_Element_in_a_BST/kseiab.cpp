#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int>& inorder( vector<int>& v, TreeNode* a ) {

        if( a == nullptr ) return v;

        inorder( v, a->left );
        v.push_back(a->val);
        inorder( v, a->right );

        return v;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        return inorder( vec, root )[k-1];
    }
};

int main() {
    return 0;
}
