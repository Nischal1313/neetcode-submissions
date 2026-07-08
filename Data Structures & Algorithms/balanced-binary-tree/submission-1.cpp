#include <algorithm>
#include <cmath> // Use <cmath> for std::abs in C++

class Solution {
public:
  int maxHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(maxHeight(root->left), maxHeight(root->right));
  }

  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true; 
    }
    
    int LeftValue = maxHeight(root->left);
    int RightValue = maxHeight(root->right);

    if (std::abs(LeftValue - RightValue) <= 1 && 
        isBalanced(root->left) && 
        isBalanced(root->right)) {
      return true;
    }
    
    return false;
  }
};