class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the current node is null, stop recursing
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the left and right children using a temporary pointer
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;}};