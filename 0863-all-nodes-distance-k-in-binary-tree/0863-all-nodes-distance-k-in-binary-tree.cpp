/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // child,parent
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            if(node->left){
                parent[node->left]= node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target] = true;
         int cnt =0;
         while(!q.empty()){
            int sz = q.size();
            if(cnt==k) break;
            cnt++;

            while (sz--) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }

                if (parent.count(node) && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
        }
};