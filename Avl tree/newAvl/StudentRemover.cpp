#include "StudentRemover.h"

TreeNode* StudentRemover::remove(TreeNode* node, float average, int id, AVLTree& avlTree) {
    if (!node) return nullptr;

    if (average < node->average) {
        node->left = remove(node->left, average, id, avlTree);
    } else if (average > node->average) {
        node->right = remove(node->right, average, id, avlTree);
    } else {
        if (id < node->id) {
            node->left = remove(node->left, average, id, avlTree);
        } else if (id > node->id) {
            node->right = remove(node->right, average, id, avlTree);
        } else {
            if (!node->left || !node->right) {
                TreeNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                TreeNode* temp = avlTree.findMin(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->average = temp->average;
                node->right = remove(node->right, temp->average, temp->id, avlTree);
            }
        }
    }

    if (!node) return nullptr;

    return avlTree.rebalanceNode(node);
}
