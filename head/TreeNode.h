#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  static TreeNode*  mkTree();
};

TreeNode* TreeNode::mkTree() {
   
    TreeNode *t = new TreeNode(1);
    t -> left = new TreeNode(2);
    t -> right = new TreeNode(3);
    t -> right -> right = new TreeNode(4);
    t -> left -> left = new TreeNode(5);
    t -> right -> right = new TreeNode(6);
    return t;
}
