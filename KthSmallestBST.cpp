using namespace std;

#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> nodesToVisit;
        vector<int> unsortedNodes;
        nodesToVisit.push(root);

        while (!nodesToVisit.empty()) {
            TreeNode* curr = nodesToVisit.front();
            unsortedNodes.push_back(curr->val);
            nodesToVisit.pop();

            if (curr->left) {
                nodesToVisit.push(curr->left);
            }
            if (curr->right) {
                nodesToVisit.push(curr->right);
            }
        }

        sort(unsortedNodes.begin(), unsortedNodes.end());
        return unsortedNodes[k - 1];
    }
};
