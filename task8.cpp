#include <iostream>
using namespace std;

// Node class to represent each student
class Node {
public:
    int marks;
    char gender;
    Node* left;
    Node* right;

    Node(int m, char g) {
        marks = m;
        gender = g;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert node into the tree
    void insert(int marks, char gender) {
        root = insertRec(root, marks, gender);
    }

    // Recursive insertion function
    Node* insertRec(Node* node, int marks, char gender) {
        if (node == nullptr) {
            return new Node(marks, gender);
        }
        if (marks < node->marks) {
            node->left = insertRec(node->left, marks, gender);
        } else {
            node->right = insertRec(node->right, marks, gender);
        }
        return node;
    }

    // In-order traversal function
    void inOrder() {
        inOrderRec(root);
    }

    void inOrderRec(Node* node) {
        if (node != nullptr) {
            inOrderRec(node->left);
            cout << "Marks: " << node->marks << ", Gender: " << node->gender << endl;
            inOrderRec(node->right);
        }
    }
};

int main() {
    BST maleTree, femaleTree;

    // Sample data (marks and gender)
    int marks[] = {85, 78, 90, 70, 95, 60, 88};
    char gender[] = {'M', 'F', 'M', 'F', 'M', 'F', 'M'};

    int n = sizeof(marks) / sizeof(marks[0]);

    // Insert data into respective BSTs
    for (int i = 0; i < n; i++) {
        if (gender[i] == 'M') {
            maleTree.insert(marks[i], gender[i]);
        } else {
            femaleTree.insert(marks[i], gender[i]);
        }
    }

    // Display male students' BST
    cout << "Male Students (In-Order Traversal):\n";
    maleTree.inOrder();

    // Display female students' BST
    cout << "\nFemale Students (In-Order Traversal):\n";
    femaleTree.inOrder();

    return 0;
}

