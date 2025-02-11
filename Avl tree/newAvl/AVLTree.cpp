#include "AVLTree.h"

// سازنده‌ی اولیه
AVLTree::AVLTree() : root(nullptr) {}

// دریافت ریشه
TreeNode* AVLTree::getRoot() {
    return root;
}

// تنظیم ریشه
void AVLTree::setRoot(TreeNode* newRoot) {
    root = newRoot;
}

// ارتفاع یک گره
int AVLTree::height(TreeNode* node) {
    return node ? node->height : 0;
}

// به‌روزرسانی ارتفاع گره
void AVLTree::updateHeight(TreeNode* node) {
    if (node)
        node->height = 1 + max(height(node->left), height(node->right));
}

// محاسبه‌ی فاکتور تعادل
int AVLTree::balanceFactor(TreeNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// چرخش راست
TreeNode* AVLTree::rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// چرخش چپ
TreeNode* AVLTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// متعادل‌سازی درخت
TreeNode* AVLTree::rebalanceNode(TreeNode* node) {
    if (!node) return node;

    updateHeight(node);
    int balance = balanceFactor(node);

    // چپ-چپ
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);

    // راست-راست
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);

    // چپ-راست
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // راست-چپ
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// یافتن کمترین مقدار در درخت
TreeNode* AVLTree::findMin(TreeNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// نمایش اطلاعات دانشجویان
void AVLTree::display(TreeNode* node) {
    if (!node) return;

    display(node->left);
    cout << "Name: " << node->name << "\t Average: " << node->average << "\t ID: " << node->id << endl;
    display(node->right);
}

// نمایش تمام دانشجویان
void AVLTree::display() {
    display(root);
}
