#include "StudentSearcher.h"

void StudentSearcher::searchAllNodes(TreeNode* node, float average, vector<TreeNode*>& results) {
    if (!node) return;

    if (average == node->average)
        results.push_back(node);

    searchAllNodes(node->left, average, results);
    searchAllNodes(node->right, average, results);
}

vector<TreeNode*> StudentSearcher::search(TreeNode* root, float average) {
    vector<TreeNode*> results;
    searchAllNodes(root, average, results);
    return results;
}
