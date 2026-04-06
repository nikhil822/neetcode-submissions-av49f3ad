/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if(!root)return {};
        queue<TreeNode*> q;
        unordered_map<int, int> m;
        q.push(root);
        int height = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if(m.count(height) == 0) {
                    ans.push_back(node->val);
                    m[height] = 1;
                }
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
            height++;
        }
        return ans;
    }
};
