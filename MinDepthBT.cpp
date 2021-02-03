using namespace std;

#include <algorithm>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int GetMin(TreeNode* root, int currMin) {
        if (!root) {
            return currMin;
        }
        if (!root->left && root->right) {
            return GetMin(root->right, currMin + 1);
        }
        if (root->left && !root->right) {
            return GetMin(root->left, currMin + 1);
        }

        return min(GetMin(root->left, currMin) + 1, GetMin(root->right, currMin) + 1);
    }

    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return GetMin(root, 0);
    }
};
