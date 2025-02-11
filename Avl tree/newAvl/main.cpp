#include "AVLTree.h"
#include "StudentInsert.h"
#include "StudentRemover.h"
#include "StudentSearcher.h"

int main() {
    AVLTree avlTree;
    StudentInserter inserter;
    StudentRemover remover;
    StudentSearcher searcher;

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

                avlTree.setRoot(inserter.insert(avlTree.getRoot(), id, name, average, avlTree));
                break;
            }
            case 2: {
                float average;
                int id;
                cout << "Enter student average to delete: ";
                cin >> average;
                cout << "Enter student ID: ";
                cin >> id;

                avlTree.setRoot(remover.remove(avlTree.getRoot(), average, id, avlTree));
                break;
            }
            case 3: {
                float average;
                cout << "Enter average to search: ";
                cin >> average;

                vector<TreeNode*> results = searcher.search(avlTree.getRoot(), average);
                if (!results.empty()) {
                    cout << "Students with average " << average << ":\n";
                    for (TreeNode* studentNode : results) {
                        cout << "Name: " << studentNode->name << "\t ID: " << studentNode->id << "\t Average: " << studentNode->average << endl;
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
