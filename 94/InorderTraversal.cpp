#include <iostream>
#include <vector>
#include <stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
};
class Solution {
public:
    /** recursively */
    std::vector<int> inorderTraversal1(TreeNode* root) {
       std::vector<int> vec;
       recursive(root, vec);
       return vec; 
    }

    void recursive(TreeNode* root, std::vector<int> &vec) {
      if (root!=NULL) {
        recursive(root->left, vec);
        vec.push_back(root->val);
        recursive(root->right, vec);
      }
    }

    std::vector<int> inorderTraversal2(TreeNode* root) {
      std::stack<TreeNode*> stack;
      std::vector<int> vec;
      TreeNode* tmp = root;
      while (tmp != NULL || !stack.empty()) {
        while(tmp != NULL) {
          stack.push(tmp);
          tmp = tmp -> left;
        }
        tmp = stack.top();
        stack.pop();
        vec.push_back(tmp -> val);
        tmp = tmp -> right;
      }
      return vec;
    }

};

int main() {
   TreeNode *r = new TreeNode(1);
   r->left = new TreeNode(2);
   r->right = new TreeNode(3);
   r->left->left = new TreeNode(4);
   r->right->right = new TreeNode(5);
   Solution s;
   auto vec = s.inorderTraversal1(r);
   for (auto i : vec) {
     std::cout << i << " ";
   }
   std::cout << std::endl;
   vec = s.inorderTraversal2(r);
   for (auto i : vec) {
     std::cout << i << " ";
   }
   std::cout << std::endl;
}
