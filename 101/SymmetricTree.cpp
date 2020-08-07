#include<iostream>
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};
class Solution {
public:
  bool isSymmitric(TreeNode* root) {
    return check(root, root);
  }
  bool check(TreeNode* r1, TreeNode* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    return (r1 -> val == r2 -> val) && check(r1 -> left, r2 -> right) && check(r1 -> right, r2 -> left);
  }
};

int main() {
  //[1,2,2,3,4,4,3]
  TreeNode* root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(2);
  root -> left -> left = new TreeNode(3);
  root -> left -> right = new TreeNode(4);
  root -> right -> left = new TreeNode(4);
  root -> right -> right = new TreeNode(3);
  Solution s;
  bool r = s.isSymmitric(root);
  std::cout << std::boolalpha << r << std::endl;
}
