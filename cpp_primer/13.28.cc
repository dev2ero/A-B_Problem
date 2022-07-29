#include <iostream>

using namespace std;

class TreeNode {
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() :
	value(""), count(1), left(nullptr), right(nullptr) {}
};

class BinStrTree {
private:
    TreeNode *root;
public:
    BinStrTree() :
	root(nullptr) {}
};
