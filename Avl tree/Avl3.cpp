#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    void updateHeight(TreeNode* node) {
        if (node == nullptr) return;
        node->height = 1 + max(height(node->left), height(node->right));
    }

    int balanceFactor(TreeNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // تابع برای چرخش به چپ
    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    TreeNode* rebalance(TreeNode* node) {
        if (node == nullptr) return node;

        updateHeight(node);

        int balance = balanceFactor(node);

        // چپ-چپ
        if (balance > 1 && balanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // راست-راست
        if (balance < -1 && balanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

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

TreeNode* insert(TreeNode* node, int id, string name, float average) {
    if (node == nullptr) {
        return new TreeNode(id, name, average);
    }

    if (average < node->average) {
        node->left = insert(node->left, id, name, average);
    } else if (average > node->average) {
        node->right = insert(node->right, id, name, average);
    } else {
        if (id < node->id) {
            node->left = insert(node->left, id, name, average);
        } else {
            node->right = insert(node->right, id, name, average);
        }
    }

    return rebalance(node);
}


    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

TreeNode* remove(TreeNode* node, float average, int id) {
    if (node == nullptr) return node;

    if (average < node->average) {
        node->left = remove(node->left, average, id);
    } else if (average > node->average) {
        node->right = remove(node->right, average, id);
    } else {
        if (id < node->id) {
            node->left = remove(node->left, average, id);
        } else if (id > node->id) {
            node->right = remove(node->right, average, id);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode* temp = (node->left != nullptr) ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                TreeNode* temp = findMin(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->average = temp->average;
                node->right = remove(node->right, temp->average, temp->id);
            }
        }
    }

    if (node == nullptr) return node;

    return rebalance(node);
}


    void searchAllNodes(TreeNode* node, float average, vector<TreeNode*>& results) {
        if (node == nullptr) return;

        if (average == node->average) {
            results.push_back(node);
        }

        searchAllNodes(node->left, average, results);
        searchAllNodes(node->right, average, results);
    }

    void display(TreeNode* node) {
        if (node == nullptr) return;

        display(node->left);
        cout << "Name: " << node->name << ", Average: " << node->average << ", ID: " << node->id << endl;
        display(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int id, string name, float average) {
        root = insert(root, id, name, average);
    }

    void remove(float average, int id) {
        root = remove(root, average, id);
    }

    vector<TreeNode*> search(float average) {
        vector<TreeNode*> results;
        searchAllNodes(root, average, results);
        return results;
    }

    void display() {
        display(root);
    }
};

int main() {
    AVLTree avlTree;
    int choice;
    do {
        cout << "1. Add Student Information\n2. Delete Student Information\n3. Search Student Information\n4. Display Students Information\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                int id;
                float average;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student average: ";
                cin >> average;
                avlTree.insert(id, name, average);
                break;
            }
            case 2: {
                float average;
                int id;
                cout << "Enter student average to delete: ";
                cin >> average;
                cout << "Enter student ID: ";
                cin >> id;
                avlTree.remove(average, id);
                break;
            }
            case 3: {
                float average;
                cout << "Enter average to search: ";
                cin >> average;
                vector<TreeNode*> results = avlTree.search(average);
                if (!results.empty()) {
                    cout << "Students with average " << average << ":\n";
                    for (TreeNode* studentNode : results) {
                        cout << "Name: " << studentNode->name << "/t ID: " << studentNode->id << "/t Average: " << studentNode->average << endl;
                    }
                } else {
                    cout << "No student found with this average.\n";
                }
                break;
            }
            case 4: {
                cout << "Student list:\n";
                avlTree.display();
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}