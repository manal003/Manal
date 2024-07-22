#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// TreeNode class to construct nodes for binary search tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// MinHeap class to construct min-heap
class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void buildHeap(vector<int> data) {
        heap = data;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Function to insert a node into the BST
void add(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        cout << val << " is inserted as root in BST" << endl;
    } else if (val < root->data) {
        if (root->left == nullptr) {
            root->left = new TreeNode(val);
            cout << val << " inserted in BST" << endl;
        } else {
            add(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new TreeNode(val);
            cout << val << " inserted in BST" << endl;
        } else {
            add(root->right, val);
        }
    }
}

// Function to populate the BST from a given array
void populateTree(TreeNode*& root, vector<int> data) {
    for (int val : data) {
        add(root, val);
    }
}

// Function for post-order traversal of BST
void postOrder(TreeNode* root, vector<int>& result) {
    if (root != nullptr) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->data);
    }
}

// Function for pre-order traversal of BST
void preOrder(TreeNode* root, vector<int>& result) {
    if (root != nullptr) {
        result.push_back(root->data);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

// Main function
int main() {
    int numNodes;
    cout << "How many nodes you want to insert into BST: ";
    cin >> numNodes;
    
    cin.ignore();  // Ignore newline character after the number input
    
    vector<int> data;
    cout << "Enter " << numNodes << " values to insert into BST: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    int value;
    while (ss >> value) {
        data.push_back(value);
    }

    TreeNode* root = nullptr;
    populateTree(root, data);

    vector<int> postOrderData;
    postOrder(root, postOrderData);

    cout << "Post-Order Traversal of BST: ";
    for (int val : postOrderData) {
        cout << val << " ";
    }
    cout << endl;

    MinHeap minHeap1;
    for (int val : postOrderData) {
        minHeap1.insert(val);
    }

    cout << "Min Heap using Insert method: ";
    minHeap1.display();

    vector<int> preOrderData;
    preOrder(root, preOrderData);

    cout << "Pre-Order Traversal of BST: ";
    for (int val : preOrderData) {
        cout << val << " ";
    }
    cout << endl;

    MinHeap minHeap2;
    minHeap2.buildHeap(preOrderData);

    cout << "Min Heap using Build method: ";
    minHeap2.display();

    return 0;
}
