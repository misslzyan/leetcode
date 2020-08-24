#include <iostream>
#include <utility>
#include <queue>
#include "../head/TreeNode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
   int minDepth(TreeNode* root) {
      if(root == NULL) {
        return 0;
      }

      if(root -> left == NULL && root -> right == NULL) {
        return 1;
      }

      int depth = INT_MAX;
      if (root -> right != NULL) {
        depth = std::min(depth, minDepth(root -> right));
      }
      if (root -> left != NULL) {
        depth = std::min(depth, minDepth(root -> left));
      }
      return depth + 1;
    }

   int minDepth2(TreeNode* root) {
     if(root == nullptr) return 0;
     if (root -> left == nullptr && root -> right == nullptr) return 1;
     std::queue<std::pair<TreeNode *, int> > queue;
     queue.emplace(root, 1);
     while(!queue.empty()) {
       TreeNode* n = queue.front().first();
       int dep = queue.front().second();
       if (n -> left == nullptr && n -> right == nullptr) return dep;
       if (n -> left != nullptr) {
         queue.emplace(n -> left, dep + 1);
       }
       if (n -> right != nullptr) {
         queue.emplace(n -> right, dep + 1);
       }
     }
     return 0;
   }
};

int main() {
//  TreeNode *t = new TreeNode(1);
  TreeNode *root = TreeNode::mkTree();
  Solution s;
  int min = s.minDepth(root); 
  std::cout << min << std::endl; 
  min = s.minDepth2(root);
  std::cout << min << std::endl;  
}
