#ifndef STUDENTSEARCHER_H
#define STUDENTSEARCHER_H

#include "AVLTree.h"
#include <vector>

class StudentSearcher {
public:
    // متد برای جستجوی دانشجویان بر اساس معدل
    vector<TreeNode*> search(TreeNode* root, float average);

private:
    // جستجوی همه‌ی دانشجویان با معدل مشخص
    void searchAllNodes(TreeNode* node, float average, vector<TreeNode*>& results);
};

#endif
