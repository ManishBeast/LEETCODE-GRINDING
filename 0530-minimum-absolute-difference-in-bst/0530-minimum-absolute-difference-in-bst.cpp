class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != -1)
            ans = min(ans, root->val - prev);

        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};