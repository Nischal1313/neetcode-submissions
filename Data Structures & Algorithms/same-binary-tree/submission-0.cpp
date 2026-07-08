class Solution {
public:
  int maxHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(maxHeight(root->left), maxHeight(root->right));
  }
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
