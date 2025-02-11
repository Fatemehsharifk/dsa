#include "StudentInsert.h"

TreeNode* StudentInserter::insert(TreeNode* node, int id, std::string name, float average, AVLTree& avlTree) {
    if (!node) return new TreeNode(id, name, average);

    if (average < node->average)
        node->left = insert(node->left, id, name, average, avlTree);
    else if (average > node->average)
        node->right = insert(node->right, id, name, average, avlTree);
    else {
        if (id < node->id)
            node->left = insert(node->left, id, name, average, avlTree);
        else
            node->right = insert(node->right, id, name, average, avlTree);
    }

    return avlTree.rebalanceNode(node);
}
