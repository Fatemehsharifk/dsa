#ifndef STUDENTINSERTER_H
#define STUDENTINSERTER_H

#include "AVLTree.h"

class StudentInserter {
public:
    TreeNode* insert(TreeNode* node, int id, std::string name, float average, AVLTree& avlTree);
};

#endif // STUDENTINSERTER_H
