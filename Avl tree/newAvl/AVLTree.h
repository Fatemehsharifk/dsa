#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>
using namespace std;

// ساختار درخت
struct TreeNode {
    int id;
    string name;
    float average;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int i, string n, float a) : id(i), name(n), average(a), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    TreeNode* root;

    // عملیات اصلی روی درخت
    int height(TreeNode* node);
    void updateHeight(TreeNode* node);
    int balanceFactor(TreeNode* node);
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);

public:
    AVLTree();

    // متدهای عمومی
    TreeNode* getRoot();
    void setRoot(TreeNode* newRoot);
    TreeNode* rebalanceNode(TreeNode* node);
    TreeNode* findMin(TreeNode* node);

    // متد نمایش
    void display();
    void display(TreeNode* node);
};

#endif
