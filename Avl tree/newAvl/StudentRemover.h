#ifndef STUDENTREMOVER_H
#define STUDENTREMOVER_H

#include "AVLTree.h"

class StudentRemover {
public:
    TreeNode* remove(TreeNode* node, float average, int id, AVLTree& avlTree);
};

#endif // STUDENTREMOVER_H
